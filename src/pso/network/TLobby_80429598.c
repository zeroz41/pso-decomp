/* The network stack's EXI Ethernet adapter driver (a C library, built with GC/1.2.5n): register reads and writes
 * over EXI, the receive/send DMA chain and its buffers, the MAC address, the multicast filter and the link status. */
#define PSO_SDK_COMPACT_MATH
#include "pso/network/NetworkTransport.h"
#include "pso/network/TLobby_80429598.h"
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

/* Adapter state: the receive message queue and the interrupt statistics counters (one counter per BBA
 * interrupt cause, bumped by TLobby__sub_80429B8C). */
typedef struct EthState_805D0AA0 {
    OSMessageQueue queue;
    OSMessage queue_msgs[10];
    s32 pad_48; /* receive interrupts */
    s32 pad_4C; /* receive error interrupts */
    u16 pad_50;
    u16 pad_52; /* transmit error interrupts */
    u16 pad_54; /* transmit interrupts */
    u16 pad_56;
    u16 pad_58;
    u16 pad_5A;
    u16 pad_5C;
    u16 pad_5E;
    u16 pad_60;
    u16 pad_62;
    u16 pad_64;
    u16 pad_66;
    u16 pad_68;
    u16 pad_6A;
    u8 pad_6C[0x14];
} EthState_805D0AA0;

static EthState_805D0AA0 lbl_805D0AA0;
static u8 exi_dma_buffer[0x600];
static u8 exi_dma_write_buffer[0xC00];

extern OSThreadQueue network_thread_queue;
extern s32 exi_send_started_flag;
extern void (*lbl_805D7C54)(u8); /* send-done callback */
extern s32 lbl_805D7C7C;
extern s32 exi_send_size;
extern u8 exi_mac_address[6];
extern u32 lbl_805D7C4C;
extern s32 exi_receive_callback;
extern u16 *lbl_805D7C44; /* accepted ethertypes (lbl_805D7C48 entries) */
extern s32 lbl_805D7C48;
extern s32 exi_dma_read_length;
extern u32 exi_dma_write_length;
void TLobby__sub_8042B434(s32 chan, OSContext *ctx);
extern s32 lbl_805D7C84;
extern s32 lbl_805D7C88;

/* A receive ring page header: the next page, the frame length and the receive status. */
typedef struct RecvDescriptor {
    u16 next;
    u16 length;
    u8 status;
} RecvDescriptor;

extern volatile RecvDescriptor lbl_805D7C5C;
extern RecvDescriptor lbl_805D7C6C;
extern u8 *lbl_805D7C74;
extern u16 lbl_805D7C78; /* receive ring write page */
extern u16 lbl_805D7C7A; /* receive ring read page */
extern s32 lbl_805D7C58;
extern u8 lbl_805D7C36; /* adapter revision id */
u8 lbl_805D4830[6] = {255, 255, 255, 255, 255, 255};
u16 lbl_805D4836 = 53511;
u8 lbl_805D4838 = 78;
u32 TLobby__sub_8042BA8C(void *);
void TLobby__sub_80429648(void);
void TLobby__sub_80429B8C(s32 chan, OSContext *ctx);

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
    memcpy(devid, &lbl_805D4836, 2);
    c0 = (i[0] + i[1] * 0xC1 + 0x18 + lbl_805D7C36) ^ (i[3] * i[2] + 0x90);
    c1 = (i[1] + i[2] + 0x90) ^ (i[0] + (c0 - 0xC1));
    c2 = (i[2] + 0xC8) ^ (c0 + ((devid[0] + lbl_805D7C36 * 0x23) ^ 0x19));
    c3 = (i[0] + 0xC1) ^ (i[3] + ((devid[1] + 0xC8) ^ 0x90));
    return (c0 << 24) | (c1 << 16) | (c2 << 8) | c3;
}

static inline void bba_challenge(void) {
    u32 challenge;
    u32 response;
    bba_cmd_out8(0x05, lbl_805D4838);
    bba_cmd_ins(0x08, &challenge, 4);
    response = bba_calc_response(challenge);
    bba_cmd_outs(0x09, &response, 4);
}

/* The same writes as bba_outs/bba_out8 (0xC0000000 | reg << 8) and bba_cmd_out8 (0x4000 | reg << 8), with the
   command word passed in: TLobby__sub_80429648's frame has these locals, not the bba_* ones. */
inline void exi8_w32_16(u32 cmd, u16 val) {
    u16 v = val;
    u32 c = cmd;
    EXISelect(0, 2, 5);
    EXIImm(0, &c, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, &v, 2, 1);
    EXIDeselect(0);
}

inline void exi8_w16_8(u16 cmd, u8 val) {
    u8 v = val;
    u16 c = cmd;
    EXISelect(0, 2, 5);
    EXIImm(0, &c, 2, 1, 0);
    EXISync(0);
    EXIImm(0, &v, 1, 1, 0);
    EXISync(0);
    EXIDeselect(0);
}

inline void exi8_w32_8(u32 cmd, u8 val) {
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
    lbl_805D7C5C.next = hdr[0] | ((hdr[1] & 0xF) << 8);
    lbl_805D7C5C.length = ((hdr[2] << 4) & 0xFF0) | ((hdr[1] >> 4) & 0xF);
    status = hdr[3];
    lbl_805D7C5C.status = status;
    return lbl_805D7C5C;
}

/* Drains the receive ring: hands each frame whose type is accepted to the receive callback and starts its DMA. */
void TLobby__sub_80429648(void) {
    u16 page;
    u16 type;
    s32 i;
    u16 len;
    u8 status;
    u32 data;

    exi_dma_write_length = 0;
    exi_dma_read_length = 0;
    while (lbl_805D7C7A != lbl_805D7C78) {
        page = (lbl_805D7C7A & 0xFF) << 8;
        lbl_805D7C6C = bba_read_descriptor(page);
        bba_ins(page + 0x10, &type, 2);
        if (lbl_805D7C48 > 0) {
            for (i = 0; i < lbl_805D7C48; i++) {
                if (lbl_805D7C44[i] == type) {
                    break;
                }
            }
            if (i == lbl_805D7C48) {
                goto skip;
            }
        }
        if (lbl_805D7C4C != 0) {
            status = lbl_805D7C6C.status;
            lbl_805D7C74 = ((u8 *(*)(u16, u16, u8))lbl_805D7C4C)(type, lbl_805D7C6C.length, status);
            if (lbl_805D7C74 != NULL) {
                data = page + 4;
                len = lbl_805D7C6C.length;
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
        lbl_805D7C7A = lbl_805D7C6C.next;
    }

    bba_out16(0x18, lbl_805D7C78);
    bba_out8(0x09, 2);
    bba_cmd_out8(0x02, 0xF8);
    EXIUnlock(0);
}

void start_exi_dma_read(u16 arg0) {
    u32 len;
    s32 cmd;
    len = (exi_dma_read_length + 0x1F) & ~0x1F;
    cmd = ((arg0 << 8) & 0xFFFF00) | 0x80000000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 4, 1, 0);
    EXISync(0);
    EXIDma(0, exi_dma_buffer, len, 0, exi_dma_write_length != 0 ? start_exi_dma_write : (EXICallback)TLobby__sub_80429AC8);
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
    EXIDma(0, exi_dma_write_buffer, len, 0, (EXICallback)TLobby__sub_80429AC8);
}

void TLobby__sub_80429AC8(void) {
    u8 pad[8];
    EXIDeselect(0);
    DCInvalidateRange(exi_dma_buffer, (exi_dma_read_length + 0x1F) & ~0x1F);
    if (exi_dma_write_length != 0) {
        DCInvalidateRange(exi_dma_write_buffer, (exi_dma_write_length + 0x1F) & ~0x1F);
    }
    if ((u32)exi_receive_callback != 0) {
        memcpy(lbl_805D7C74, exi_dma_buffer, exi_dma_read_length);
        if (exi_dma_write_length != 0) {
            memcpy(lbl_805D7C74 + exi_dma_read_length, exi_dma_write_buffer, exi_dma_write_length);
        }
        ((void (*)(u8 *, u16))exi_receive_callback)(lbl_805D7C74, lbl_805D7C6C.length);
    }
    lbl_805D7C7A = lbl_805D7C6C.next;
    TLobby__sub_80429648();
}
static inline void bba_recv(void) {
    lbl_805D0AA0.pad_48++;
    lbl_805D7C78 = bba_in16(0x16);
    lbl_805D7C7A = bba_in16(0x18);
    TLobby__sub_80429648();
}

void TLobby__sub_80429B8C(s32 chan, OSContext *ctx) {
    u8 ir;
    s32 notify;
    u8 status;
    u8 err;
    void (*callback)(u8);

    notify = 0;
    if (EXILock(0, 2, TLobby__sub_80429B8C) == 0) {
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
    if (lbl_805D7C58 == 1 && (ir & 0x02)) {
        bba_recv();
        return;
    }
    switch (__cntlzw(ir)) {
    case 24:
        lbl_805D0AA0.pad_58++;
        bba_out8(0x09, 0x80);
        break;
    case 25:
        bba_out8(0x09, 0x40);
        break;
    case 26:
        lbl_805D0AA0.pad_56++;
        bba_out8(0x09, 0x20);
        break;
    case 27:
        lbl_805D0AA0.pad_54++;
        exi_send_started_flag = 0;
        status = bba_in8(0x04);
        if (status & 0x10) {
            lbl_805D0AA0.pad_66++;
        }
        if (status & 0x20) {
            lbl_805D0AA0.pad_68++;
        }
        if (status & 0x40) {
            lbl_805D0AA0.pad_6A++;
        }
        notify = 1;
        bba_out8(0x09, 0x10);
        break;
    case 28:
        lbl_805D0AA0.pad_52++;
        err = bba_in8(0x05);
        if (err & 0x01) {
            lbl_805D0AA0.pad_5A++;
        }
        if (err & 0x02) {
            lbl_805D0AA0.pad_5C++;
        }
        if (err & 0x04) {
            lbl_805D0AA0.pad_5E++;
        }
        if (err & 0x08) {
            lbl_805D0AA0.pad_60++;
        }
        if (err & 0x10) {
            lbl_805D0AA0.pad_62++;
        }
        if (err & 0x40) {
            lbl_805D0AA0.pad_64++;
        }
        bba_out8(0x09, 0x08);
        break;
    case 29:
        lbl_805D0AA0.pad_4C++;
        notify = 1;
        exi_send_started_flag = 0;
        status = bba_in8(0x04);
        bba_out8(0x09, 0x04);
        break;
    case 30:
        bba_recv();
        return;
    case 31:
        lbl_805D0AA0.pad_50++;
        bba_out8(0x09, 0x01);
        break;
    }
    bba_cmd_out8(0x02, 0xF8);
    EXIUnlock(0);
    if (notify != 0) {
        callback = lbl_805D7C54;
        lbl_805D7C54 = 0;
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

s32 init_bba_exi_adapter(void *arg) {
    s32 level;
    u32 cid;
    u8 val;

    OSInitThreadQueue(&network_thread_queue);
    OSInitMessageQueue(&lbl_805D0AA0.queue, lbl_805D0AA0.queue_msgs, 10);
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
    memset(&lbl_805D0AA0.pad_48, 0, 0x24);
    lbl_805D7C44 = 0;
    lbl_805D7C48 = 0;
    lbl_805D7C4C = 0;
    exi_receive_callback = 0;
    cid = bba_cmd_in32(0x00);
    if (cid != 0x04020200) {
        EXIUnlock(0);
        OSReport("cid = %08x\n", cid);
        return -1;
    }
    bba_reset();
    bba_ins(0x20, exi_mac_address, 6);
    if (memcmp(exi_mac_address, lbl_805D4830, 6) == 0) {
        OSReport("MAC ADDRESS is 0xffffff\n");
        return -2;
    }
    lbl_805D7C36 = bba_cmd_in8(0x01);
    bba_cmd_outs(0x04, &lbl_805D4836, 2);
    bba_cmd_out8(0x05, lbl_805D4838);
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
    EXISetExiCallback(2, TLobby__sub_80429B8C);
    EXIUnlock(0);
    return 1;
}
#pragma pop

void start_exi_send(s32 arg0, s32 arg1, void (*arg2)(u8)) {
    s32 var_r3;
    s32 var_r4;
    lbl_805D7C7C = arg0;
    var_r3 = 0;
    exi_send_size = arg1;
    var_r4 = 0;
    exi_send_started_flag = 1;
    lbl_805D7C54 = arg2;
    exi_start_send_dma(0, NULL);
}

void exi_start_send_dma(s32 chan, OSContext *ctx) {
    u8 pad[4];
    s32 cmd;
    if (EXILock(0, 2, exi_start_send_dma) != 0) {
        if (exi_send_size < 0x3C) {
            exi_send_size = 0x3C;
        }
        lbl_805D7C84 = exi_send_size & ~0x1F;
        lbl_805D7C88 = exi_send_size - lbl_805D7C84;
        DCStoreRange((void *)lbl_805D7C7C, lbl_805D7C84);
        cmd = 0xC0004800;
        EXISelect(0, 2, 5);
        EXIImm(0, &cmd, 4, 1, 0);
        EXISync(0);
        EXIDma(0, (void *)lbl_805D7C7C, lbl_805D7C84, 1, TLobby__sub_8042B434);
    }
}

void TLobby__sub_8042B434(s32 chan, OSContext *ctx) {
    u8 val;
    u8 out;
    s32 cmd0;
    s32 cmd1;
    u8 pad[4];
    s32 bits;
    if (lbl_805D7C88 != 0) {
        EXIImmEx(0, (void *)(lbl_805D7C7C + lbl_805D7C84), lbl_805D7C88, 1);
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
    s32 arg0 = (s32)address;
    memcpy(exi_mac_address, (void *)arg0, 6);
}

void TLobby__sub_8042B58C(u32 arg0, s32 arg1) {
    u8 sp43;
    u8 sp42;
    s16 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    u8 sp27;
    u8 sp26;
    u8 sp25;
    u8 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 e;
    s32 pad;

    e = OSDisableInterrupts();
    for (;;) {
        if (EXILock(0, 2, (EXICallback)wake_network_thread) == 1) {
            OSRestoreInterrupts(e);
            break;
        }
        OSSleepThread(&network_thread_queue);
        OSRestoreInterrupts(e);
    }
    lbl_805D7C4C = arg0;
    exi_receive_callback = arg1;
    if (arg0 == 0U) {
        sp43 = 0;
        sp3C = 0xC0000800;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp3C, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, &sp43, 1, 1);
        EXIDeselect(0);
    } else {
        sp42 = 0xFF;
        sp38 = 0xC0000800;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp38, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, &sp42, 1, 1);
        EXIDeselect(0);
        sp40 = 0x100;
        sp34 = 0xC0000A00;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp34, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, &sp40, 2, 1);
        EXIDeselect(0);
        sp30 = 0xC0001600;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp30, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, &sp40, 2, 1);
        EXIDeselect(0);
        sp2C = 0xC0001800;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp2C, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, &sp40, 2, 1);
        EXIDeselect(0);
        sp40 = 0xF00;
        sp28 = 0xC0001A00;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp28, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, &sp40, 2, 1);
        EXIDeselect(0);
        sp20 = 0x80000100;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp20, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, &sp27, 1, 0);
        EXIDeselect(0);
        e = sp27;
        e &= ~1;
        e |= 0x12;
        sp26 = e;
        sp1C = 0xC0000100;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp1C, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, &sp26, 1, 1);
        EXIDeselect(0);
        sp18 = 0xC0000000;
        sp25 = 8;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp18, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, &sp25, 1, 1);
        EXIDeselect(0);
        sp24 = 8;
        sp14 = 0xC0003200;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp14, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, &sp24, 1, 1);
        EXIDeselect(0);
    }
    EXIUnlock(0);
}

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

void TLobby__sub_8042BA48(u16 *types, s32 count) {
    s32 e = OSDisableInterrupts();
    lbl_805D7C44 = types;
    lbl_805D7C48 = count;
    OSRestoreInterrupts(e);
}

u32 TLobby__sub_8042BA8C(void *addr) {
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

void enable_network_multicast_address(void *arg0) {
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
  if (memcmp(arg0, lbl_805D4830, 6) == 0)
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
    bit = (u16)TLobby__sub_8042BA8C(arg0);
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
