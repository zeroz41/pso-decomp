/* ETHLIB, the Broadband Adapter's Ethernet driver (a C library, built with GC/1.2.5n): register reads and writes
 * over EXI, the receive/send DMA chain and its buffers, the MAC address, the multicast filter and the link status. */
#define PSO_SDK_COMPACT_MATH
#include "pso/network/NetworkTransport.h"
#include "pso/network/eth.h"
#include "pso/network/ModemRuntime.h"
#include "pso/network/NetworkMessageTransport.h"

#include "types.h"
#include "pso/network/NetStackTypes.h"
#include "dolphin/hw_regs.h"
#include <string.h>
#include <dolphin/exi.h>
#include <dolphin/os.h>
#undef PSO_SDK_COMPACT_MATH

#pragma dont_inline off

/* Adapter state: the receive message queue and the interrupt statistics, one counter per cause of the NIC's
 * interrupt register (0x09) as bba_exi_interrupt services them. */
typedef struct BbaState {
    OSMessageQueue queue;
    OSMessage queue_msgs[10];
    s32 rx_count;          /* receive interrupts (0x02) */
    s32 tx_count;          /* transmit-complete interrupts (0x04) */
    u16 frag_count;        /* 0x01 */
    u16 rx_error_count;    /* 0x08; the causes below come from the last-received-packet status (0x05) */
    u16 tx_error_count;    /* 0x10; the causes below come from the last-transmitted-packet status (0x04) */
    u16 fifo_error_count;  /* 0x20 */
    u16 rx_full_count;     /* 0x80: receive buffer full */
    u16 rx_status_counts[6]; /* status bits 0x01, 0x02, 0x04, 0x08, 0x10 and 0x40 */
    u16 tx_status_counts[3]; /* status bits 0x10, 0x20 and 0x40 */
    u8 pad_6C[0x14];
} BbaState;

static BbaState bba_state;
static u8 exi_dma_buffer[0x600];
static u8 exi_dma_write_buffer[0xC00];

void bba_send_dma_done(s32 chan, OSContext *ctx);

/* A receive ring page header: the next page, the frame length and the receive status. */
typedef struct RecvDescriptor {
    u16 next;
    u16 length;
    u8 status;
} RecvDescriptor;

/* CodeWarrior lays uninitialised globals out last-defined first, so these are in reverse address order. */
s32 exi_send_tail_length;
s32 exi_send_dma_length;
s32 exi_send_size;
u8 *exi_send_data;
u16 exi_receive_read_page; /* receive ring read page */
u16 exi_receive_write_page; /* receive ring write page */
u8 *exi_receive_buffer;
RecvDescriptor exi_receive_descriptor;
u32 exi_dma_write_length;
s32 exi_dma_read_length;
volatile RecvDescriptor bba_descriptor;
s32 bba_receive_in_interrupt; /* nonzero: a receive interrupt reads the frame at once, before the other causes */
ExiSendCompletionCallback exi_send_callback;
EthReceiveCallback exi_receive_callback;
EthReceiveAllocCallback exi_receive_alloc_callback;
s32 exi_accepted_type_count;
u16 *exi_accepted_types; /* accepted ethertypes (exi_accepted_type_count entries) */
s32 exi_send_started_flag;
OSThreadQueue network_thread_queue;
u8 bba_revision_id; /* adapter revision id */
u8 exi_mac_address[6];

u8 ethernet_broadcast_address[6] = {255, 255, 255, 255, 255, 255};
u16 bba_device_id = 53511;
u8 bba_acstart = 78;
u32 bba_multicast_hash(void *);
void bba_receive_next_frame(void);
void bba_exi_interrupt(s32 chan, OSContext *ctx);

void wake_network_thread(void) {
    OSWakeupThread(&network_thread_queue);
}

void exi_write(s32 reg, void *data, s32 len) {
    s32 cmd;
    cmd = ((reg << 8) & 0xFFFF00) | 0x80000000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, data, len, 0);
    EXIDeselect(0);
}

#pragma push
#pragma inline_depth(4)
static inline u8 bba_cmd_in8(u32 reg) {
    u16 cmd;
    u8 val;
    cmd = reg << 8;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 2, 1, 0);
    EXISync(0);
    EXIImm(0, &val, 1, 0, 0);
    EXISync(0);
    EXIDeselect(0);
    return val;
}

/* `req` keeps the full command word in the stack slot the original frames have for it. */
static inline void bba_cmd_out8(u32 reg, u8 val) {
    u32 req;
    u16 cmd;
    req = (reg << 8) | 0x4000;
    cmd = req;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 2, 1, 0);
    EXISync(0);
    EXIImm(0, &val, 1, 1, 0);
    EXISync(0);
    EXIDeselect(0);
}

static inline void bba_cmd_ins(u32 reg, void *buf, s32 len) {
    u16 cmd;
    cmd = reg << 8;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 2, 1, 0);
    EXISync(0);
    EXIImmEx(0, buf, len, 0);
    EXIDeselect(0);
}

static inline void bba_cmd_outs(u32 reg, void *buf, s32 len) {
    u32 req;
    u16 cmd;
    req = (reg << 8) | 0x4000;
    cmd = req;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 2, 1, 0);
    EXISync(0);
    EXIImmEx(0, buf, len, 1);
    EXIDeselect(0);
}

static inline void bba_ins(u16 reg, void *buf, s32 len) {
    u32 cmd;
    cmd = (reg << 8) | 0x80000000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, buf, len, 0);
    EXIDeselect(0);
}

static inline void bba_outs(u16 reg, void *buf, s32 len) {
    u32 cmd;
    cmd = (reg << 8) | 0xC0000000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, buf, len, 1);
    EXIDeselect(0);
}

static inline u8 bba_in8(u32 reg) {
    u8 val;
    bba_ins(reg, &val, 1);
    return val;
}

static inline void bba_out8(u32 reg, u8 val) {
    bba_outs(reg, &val, 1);
}

static inline u16 bba_swap16(u16 val) {
    u16 swapped;
    swapped = __lhbrx(&val, 0);
    return swapped;
}

static inline u16 bba_in16(u32 reg) {
    u16 val;
    bba_ins(reg, &val, 2);
    return bba_swap16(val);
}

static inline u32 bba_calc_response(u32 val) {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
    u8 i[4];
    u8 devid[2];
    memcpy(i, &val, 4);
    memcpy(devid, &bba_device_id, 2);
    c0 = (i[0] + i[1] * 0xC1 + 0x18 + bba_revision_id) ^ (i[3] * i[2] + 0x90);
    c1 = (i[1] + i[2] + 0x90) ^ (i[0] + (c0 - 0xC1));
    c2 = (i[2] + 0xC8) ^ (c0 + ((devid[0] + bba_revision_id * 0x23) ^ 0x19));
    c3 = (i[0] + 0xC1) ^ (i[3] + ((devid[1] + 0xC8) ^ 0x90));
    return (c0 << 24) | (c1 << 16) | (c2 << 8) | c3;
}

static inline void bba_challenge(void) {
    u32 challenge;
    u32 response;
    bba_cmd_out8(0x05, bba_acstart);
    bba_cmd_ins(0x08, &challenge, 4);
    response = bba_calc_response(challenge);
    bba_cmd_outs(0x09, &response, 4);
}

/* The same writes as bba_outs/bba_out8 (0xC0000000 | reg << 8) and bba_cmd_out8 (0x4000 | reg << 8), with the
   command word passed in: bba_receive_next_frame's frame has these locals, not the bba_* ones. */
static inline void exi8_w32_16(u32 cmd, u16 val) {
    u16 v = val;
    u32 c = cmd;
    EXISelect(0, 2, 5);
    EXIImm(0, &c, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, &v, 2, 1);
    EXIDeselect(0);
}

static inline void exi8_w16_8(u16 cmd, u8 val) {
    u8 v = val;
    u16 c = cmd;
    EXISelect(0, 2, 5);
    EXIImm(0, &c, 2, 1, 0);
    EXISync(0);
    EXIImm(0, &v, 1, 1, 0);
    EXISync(0);
    EXIDeselect(0);
}

static inline void exi8_w32_8(u32 cmd, u8 val) {
    u8 v = val;
    u32 c = cmd;
    EXISelect(0, 2, 5);
    EXIImm(0, &c, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, &v, 1, 1);
    EXIDeselect(0);
}

static inline void bba_out16(u32 reg, u16 val) {
    u16 le;
    le = bba_swap16(val);
    bba_outs(reg, &le, 2);
}

static inline RecvDescriptor bba_read_descriptor(u32 reg) {
    u8 hdr[4];
    u8 status;
    bba_ins(reg, hdr, 4);
    bba_descriptor.next = hdr[0] | ((hdr[1] & 0xF) << 8);
    bba_descriptor.length = ((hdr[2] << 4) & 0xFF0) | ((hdr[1] >> 4) & 0xF);
    status = hdr[3];
    bba_descriptor.status = status;
    return bba_descriptor;
}

/* Drains the receive ring: hands each frame whose type is accepted to the receive callback and starts its DMA. */
void bba_receive_next_frame(void) {
    u16 page;
    u16 type;
    s32 i;
    u16 len;
    u8 status;
    u32 data;

    exi_dma_write_length = 0;
    exi_dma_read_length = 0;
    while (exi_receive_read_page != exi_receive_write_page) {
        page = (exi_receive_read_page & 0xFF) << 8;
        exi_receive_descriptor = bba_read_descriptor(page);
        bba_ins(page + 0x10, &type, 2);
        if (exi_accepted_type_count > 0) {
            for (i = 0; i < exi_accepted_type_count; i++) {
                if (exi_accepted_types[i] == type) {
                    break;
                }
            }
            if (i == exi_accepted_type_count) {
                goto skip;
            }
        }
        if (exi_receive_alloc_callback != NULL) {
            status = exi_receive_descriptor.status;
            exi_receive_buffer = exi_receive_alloc_callback(type, exi_receive_descriptor.length, status);
            if (exi_receive_buffer != NULL) {
                data = page + 4;
                len = exi_receive_descriptor.length;
                if (data + len > 0x1000) {
                    exi_dma_write_length = (page - 0xFFC) + len;
                    exi_dma_read_length = len - exi_dma_write_length;
                } else {
                    exi_dma_read_length = len;
                    exi_dma_write_length = 0;
                }
                start_exi_dma_read(data);
                return;
            }
        }
    skip:
        exi_receive_read_page = exi_receive_descriptor.next;
    }

    bba_out16(0x18, exi_receive_write_page);
    bba_out8(0x09, 2);
    bba_cmd_out8(0x02, 0xF8);
    EXIUnlock(0);
}

void start_exi_dma_read(u16 reg) {
    u32 len;
    s32 cmd;
    len = (exi_dma_read_length + 0x1F) & ~0x1F;
    cmd = ((reg << 8) & 0xFFFF00) | 0x80000000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 4, 1, 0);
    EXISync(0);
    EXIDma(0, exi_dma_buffer, len, 0, exi_dma_write_length != 0 ? start_exi_dma_write : (EXICallback)bba_receive_dma_done);
}

void start_exi_dma_write(s32 chan, OSContext *ctx) {
    u32 len;
    s32 cmd;
    len = (exi_dma_write_length + 0x1F) & ~0x1F;
    EXIDeselect(0);
    cmd = 0x80010000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 4, 1, 0);
    EXISync(0);
    EXIDma(0, exi_dma_write_buffer, len, 0, (EXICallback)bba_receive_dma_done);
}

void bba_receive_dma_done(void) {
    u8 pad[8];
    EXIDeselect(0);
    DCInvalidateRange(exi_dma_buffer, (exi_dma_read_length + 0x1F) & ~0x1F);
    if (exi_dma_write_length != 0) {
        DCInvalidateRange(exi_dma_write_buffer, (exi_dma_write_length + 0x1F) & ~0x1F);
    }
    if (exi_receive_callback != NULL) {
        memcpy(exi_receive_buffer, exi_dma_buffer, exi_dma_read_length);
        if (exi_dma_write_length != 0) {
            memcpy(exi_receive_buffer + exi_dma_read_length, exi_dma_write_buffer, exi_dma_write_length);
        }
        exi_receive_callback(exi_receive_buffer, exi_receive_descriptor.length);
    }
    exi_receive_read_page = exi_receive_descriptor.next;
    bba_receive_next_frame();
}
static inline void bba_recv(void) {
    bba_state.rx_count++;
    exi_receive_write_page = bba_in16(0x16);
    exi_receive_read_page = bba_in16(0x18);
    bba_receive_next_frame();
}

void bba_exi_interrupt(s32 chan, OSContext *ctx) {
    u8 ir;
    s32 notify;
    u8 status;
    u8 err;
    ExiSendCompletionCallback callback;

    notify = 0;
    if (EXILock(0, 2, bba_exi_interrupt) == 0) {
        return;
    }
    ir = bba_cmd_in8(0x03);
    bba_cmd_out8(0x02, 0);
    switch (__cntlzw(ir)) {
    case 24:
        bba_cmd_out8(0x03, 0x80);
        break;
    case 26:
        bba_cmd_out8(0x03, 0x20);
        bba_cmd_out8(0x02, 0xF8);
        EXIUnlock(0);
        return;
    case 25:
        bba_cmd_out8(0x03, 0x40);
        bba_cmd_out8(0x02, 0xF8);
        EXIUnlock(0);
        return;
    case 27:
        bba_challenge();
        bba_cmd_out8(0x03, 0x10);
        bba_cmd_out8(0x02, 0xF8);
        EXIUnlock(0);
        return;
    case 28:
        bba_cmd_in8(0x0B);
        bba_cmd_out8(0x03, 0x08);
        bba_cmd_out8(0x02, 0xF8);
        EXIUnlock(0);
        return;
    }

    ir = bba_in8(0x09);
    if (bba_receive_in_interrupt == 1 && (ir & 0x02)) {
        bba_recv();
        return;
    }
    switch (__cntlzw(ir)) {
    case 24:
        bba_state.rx_full_count++;
        bba_out8(0x09, 0x80);
        break;
    case 25:
        bba_out8(0x09, 0x40);
        break;
    case 26:
        bba_state.fifo_error_count++;
        bba_out8(0x09, 0x20);
        break;
    case 27:
        bba_state.tx_error_count++;
        exi_send_started_flag = 0;
        status = bba_in8(0x04);
        if (status & 0x10) {
            bba_state.tx_status_counts[0]++;
        }
        if (status & 0x20) {
            bba_state.tx_status_counts[1]++;
        }
        if (status & 0x40) {
            bba_state.tx_status_counts[2]++;
        }
        notify = 1;
        bba_out8(0x09, 0x10);
        break;
    case 28:
        bba_state.rx_error_count++;
        err = bba_in8(0x05);
        if (err & 0x01) {
            bba_state.rx_status_counts[0]++;
        }
        if (err & 0x02) {
            bba_state.rx_status_counts[1]++;
        }
        if (err & 0x04) {
            bba_state.rx_status_counts[2]++;
        }
        if (err & 0x08) {
            bba_state.rx_status_counts[3]++;
        }
        if (err & 0x10) {
            bba_state.rx_status_counts[4]++;
        }
        if (err & 0x40) {
            bba_state.rx_status_counts[5]++;
        }
        bba_out8(0x09, 0x08);
        break;
    case 29:
        bba_state.tx_count++;
        notify = 1;
        exi_send_started_flag = 0;
        status = bba_in8(0x04);
        bba_out8(0x09, 0x04);
        break;
    case 30:
        bba_recv();
        return;
    case 31:
        bba_state.frag_count++;
        bba_out8(0x09, 0x01);
        break;
    }
    bba_cmd_out8(0x02, 0xF8);
    EXIUnlock(0);
    if (notify != 0) {
        callback = exi_send_callback;
        exi_send_callback = 0;
        callback(status);
    }
}

static inline void bba_udelay(u32 usec) {
    u32 start;
    u32 ticks;
    start = OSGetTick();
    ticks = OSMicrosecondsToTicks(usec);
    while (OSGetTick() - start < ticks) {
    }
}

static inline u32 bba_cmd_in32(u32 reg) {
    u32 req;
    u32 val;
    u16 cmd;
    req = reg << 8;
    cmd = req;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 2, 1, 0);
    EXISync(0);
    EXIImm(0, &val, 4, 0, 0);
    EXISync(0);
    EXIDeselect(0);
    return val;
}

static inline u8 bba_cmd_in8_slow(u32 reg) {
    u16 cmd;
    u8 val;
    cmd = reg << 8;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 2, 1, 0);
    EXISync(0);
    EXIImm(0, &val, 1, 0, 0);
    EXISync(0);
    bba_udelay(200);
    EXIDeselect(0);
    return val;
}

static inline void bba_reset(void) {
    bba_out8(0x60, 0);
    bba_udelay(10000);
    bba_cmd_in8_slow(0x0F);
    bba_udelay(10000);
    bba_out8(0x00, 1);
    bba_out8(0x00, 0);
}

s32 init_bba_exi_adapter(s32 nego_mode) {
    s32 level;
    u32 cid;
    u8 val;

    OSInitThreadQueue(&network_thread_queue);
    OSInitMessageQueue(&bba_state.queue, bba_state.queue_msgs, 10);
    __SIRegs[15] &= ~0x80000000;
    level = OSDisableInterrupts();
    for (;;) {
        if (EXILock(0, 2, (EXICallback)wake_network_thread) == 1) {
            OSRestoreInterrupts(level);
            break;
        }
        OSSleepThread(&network_thread_queue);
        OSRestoreInterrupts(level);
    }
    exi_send_started_flag = 0;
    memset(&bba_state.rx_count, 0, 0x24);
    exi_accepted_types = 0;
    exi_accepted_type_count = 0;
    exi_receive_alloc_callback = NULL;
    exi_receive_callback = NULL;
    cid = bba_cmd_in32(0x00);
    if (cid != 0x04020200) {
        EXIUnlock(0);
        OSReport("cid = %08x\n", cid);
        return -1;
    }
    bba_reset();
    bba_ins(0x20, exi_mac_address, 6);
    if (memcmp(exi_mac_address, ethernet_broadcast_address, 6) == 0) {
        OSReport("MAC ADDRESS is 0xffffff\n");
        return -2;
    }
    bba_revision_id = bba_cmd_in8(0x01);
    bba_cmd_outs(0x04, &bba_device_id, 2);
    bba_cmd_out8(0x05, bba_acstart);
    val = bba_in8(0x5B);
    val &= ~0x80;
    bba_out8(0x5B, val);
    bba_out8(0x5E, 1);
    val = bba_in8(0x5C);
    val |= 0x04;
    bba_out8(0x5C, val);
    bba_out8(0x01, 0);
    bba_out8(0x50, 0x80);
    bba_out8(0x08, 0);
    bba_cmd_out8(0x02, 0xF8);
    EXISetExiCallback(2, bba_exi_interrupt);
    EXIUnlock(0);
    return 1;
}

void start_exi_send(u8 *data, s32 len, ExiSendCompletionCallback callback) {
    exi_send_data = data;
    exi_send_size = len;
    exi_send_started_flag = 1;
    exi_send_callback = callback;
    exi_start_send_dma(0, NULL);
}

void exi_start_send_dma(s32 chan, OSContext *ctx) {
    u8 pad[4];
    s32 cmd;
    if (EXILock(0, 2, exi_start_send_dma) != 0) {
        if (exi_send_size < 0x3C) {
            exi_send_size = 0x3C;
        }
        exi_send_dma_length = exi_send_size & ~0x1F;
        exi_send_tail_length = exi_send_size - exi_send_dma_length;
        DCStoreRange(exi_send_data, exi_send_dma_length);
        cmd = 0xC0004800;
        EXISelect(0, 2, 5);
        EXIImm(0, &cmd, 4, 1, 0);
        EXISync(0);
        EXIDma(0, exi_send_data, exi_send_dma_length, 1, bba_send_dma_done);
    }
}

void bba_send_dma_done(s32 chan, OSContext *ctx) {
    u8 val;
    u8 out;
    s32 cmd0;
    s32 cmd1;
    u8 pad[4];
    s32 bits;
    if (exi_send_tail_length != 0) {
        EXIImmEx(0, exi_send_data + exi_send_dma_length, exi_send_tail_length, 1);
    }
    EXIDeselect(0);
    cmd0 = 0x80000000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd0, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, &val, 1, 0);
    EXIDeselect(0);
    bits = val;
    bits |= 4;
    out = bits;
    cmd1 = 0xC0000000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd1, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, &out, 1, 1);
    EXIDeselect(0);
    EXIUnlock(0);
}

void copy_6_byte_config(void *out) {
    memcpy(out, exi_mac_address, 6);
}

void copy_mac_address(void *address) {
    memcpy(exi_mac_address, address, 6);
}

/* Lays out the receive ring (boundary, write and read pages at page 1, the high boundary at page 0x0F; the page
 * registers are little-endian), accepts broadcasts and starts the receiver. */
static inline void bba_start_receive(void) {
    u16 page;
    s32 ncrb;
    page = 0x100;
    bba_outs(0x0A, &page, 2);
    bba_outs(0x16, &page, 2);
    bba_outs(0x18, &page, 2);
    page = 0xF00;
    bba_outs(0x1A, &page, 2);
    ncrb = bba_in8(0x01);
    ncrb &= ~1;
    ncrb |= 0x12;
    bba_out8(0x01, ncrb);
    bba_out8(0x00, 8);
    bba_out8(0x32, 8);
}

void bba_set_receive_callbacks(EthReceiveAllocCallback alloc_callback, EthReceiveCallback receive_callback) {
    s32 e;

    e = OSDisableInterrupts();
    for (;;) {
        if (EXILock(0, 2, (EXICallback)wake_network_thread) == 1) {
            OSRestoreInterrupts(e);
            break;
        }
        OSSleepThread(&network_thread_queue);
        OSRestoreInterrupts(e);
    }
    exi_receive_alloc_callback = alloc_callback;
    exi_receive_callback = receive_callback;
    if (alloc_callback == NULL) {
        bba_out8(0x08, 0);
    } else {
        bba_out8(0x08, 0xFF);
        bba_start_receive();
    }
    EXIUnlock(0);
}

#pragma pop

s32 poll_exi_status(s32 *status) {
    u8 buf[2];
    s32 v;
    if (EXILock(0, 2, 0) != 0) {
        exi_write(0x31, &buf[1], 1);
        if ((buf[1] & 1) || (buf[1] & 2)) {
            v = 1;
        } else {
            v = 0;
        }
        *status = v;
        EXIUnlock(0);
        return 1;
    }
    return 0;
}

void bba_set_receive_filter_types(u16 *types, s32 count) {
    s32 e = OSDisableInterrupts();
    exi_accepted_types = types;
    exi_accepted_type_count = count;
    OSRestoreInterrupts(e);
}

u32 bba_multicast_hash(void *addr) {
    u8 *p = (u8 *)addr;
    u32 crc;
    u8 c;
    s32 i;
    s32 j;
    u32 carry;
    u32 hash;
    crc = 0xFFFFFFFF;
    for (i = 0; i < 6; i++) {
        c = p[i];
        for (j = 0; j < 8; j++) {
            carry = (crc >> 31) ^ (c & 1);
            crc <<= 1;
            if (carry) {
                crc ^= 0x04C11DB6;
                crc |= 1;
            }
            c >>= 1;
        }
    }
    hash = 0;
    for (i = 5; i >= 0; i--) {
        hash |= ((crc >> (i + 26)) & 1) << i;
    }
    return hash;
}

void enable_network_multicast_address(void *address) {
  u8 val0;
  u8 val1;
  u8 val2;
  u8 val3;
  u32 cmd0;
  u32 cmd1;
  u32 cmd2;
  u32 cmd3;
  u32 addr;
  u16 bit;
  int read_command;
  s32 enabled;
  s32 isDefault;
  int filter_bits;
  isDefault = 0;
  if (memcmp(address, ethernet_broadcast_address, 6) == 0)
  {
    isDefault = 1;
  }
  enabled = OSDisableInterrupts();
  while (1)
  {
    if (EXILock(0, 2, (EXICallback)wake_network_thread) == 1)
    {
      OSRestoreInterrupts(enabled);
      break;
    }
    OSSleepThread(&network_thread_queue);
    OSRestoreInterrupts(enabled);
  }
  if (isDefault != 0)
  {
    cmd0 = 0x80000100;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd0, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, &val0, 1, 0);
    EXIDeselect(0);
    val1 = val0 | 4;
    cmd1 = 0xC0000100;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd1, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, &val1, 1, 1);
    EXIDeselect(0);
  }
  else
  {
    bit = (u16)bba_multicast_hash(address);
    addr = ((u32) ((u16) (((u8) (bit / 8)) + 0x26))) << 8;
    read_command = addr | 0x80000000;
    cmd2 = read_command;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd2, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, &val2, 1, 0);
    EXIDeselect(0);
    filter_bits = val2;
    filter_bits = filter_bits | (1 << ((u8) (bit % 8)));
    val3 = filter_bits;
    cmd3 = addr | 0xC0000000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd3, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, &val3, 1, 1);
    EXIDeselect(0);
  }
  EXIUnlock(0);
}

u32 exi_read_status_byte(void) {
    u8 val;
    u16 cmd;
    s16 pad;
    s32 enabled;
    u8 ret;
    enabled = OSDisableInterrupts();
    while (1) {
        if (EXILock(0, 2, (EXICallback)wake_network_thread) == 1) {
            OSRestoreInterrupts(enabled);
            break;
        }
        OSSleepThread(&network_thread_queue);
        OSRestoreInterrupts(enabled);
    }
    cmd = 0x100;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 2, 1, 0);
    EXISync(0);
    EXIImm(0, &val, 1, 0, 0);
    EXISync(0);
    EXIDeselect(0);
    ret = val;
    EXIUnlock(0);
    return ret;
}
