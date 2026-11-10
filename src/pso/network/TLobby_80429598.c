/* The network stack's EXI Ethernet adapter driver (a C library, built with GC/1.2.5n): register reads and writes
 * over EXI, the receive/send DMA chain and its buffers, the MAC address, the multicast filter and the link status. */
#include "pso/network/NetworkTransport.h"
#include "pso/network/TLobby_80429598.h"
#include "pso/network/ModemRuntime.h"
#include "pso/network/NetworkMessageTransport.h"

#include "types.h"
#include "pso/network/NetStackTypes.h"
#include "dolphin/hw_regs.h"

typedef struct RecoveredGlobal_80428374_lbl_805D0A40 {
    s32 value;
    u8 remaining[0x5C];
} RecoveredGlobal_80428374_lbl_805D0A40;

typedef struct RecoveredGlobal_8042839C_lbl_805D0A40 {
    s32 value;
    u8 remaining[0x5C];
} RecoveredGlobal_8042839C_lbl_805D0A40;

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

typedef struct RecoveredGlobal_8042E768_lbl_805D1D20 {
    s32 value;
    u8 remaining[0x18];
} RecoveredGlobal_8042E768_lbl_805D1D20;

typedef struct RecoveredGlobal_80427D0C_lbl_805CFC20 {
    s32 value;
    u8 remaining[0xE1C];
} RecoveredGlobal_80427D0C_lbl_805CFC20;

typedef struct RecoveredGlobal_80428360_lbl_805CFC20 {
    s16 value;
    u8 remaining[0xE1E];
} RecoveredGlobal_80428360_lbl_805CFC20;

typedef struct RecoveredGlobal_8042DD70_lbl_805D1D20 {
    s32 value;
    u8 remaining[0x18];
} RecoveredGlobal_8042DD70_lbl_805D1D20;

typedef struct Names_8042E57C {
    char *name[6];
} Names_8042E57C;

typedef struct Names_8042E628 {
    char *name[4];
} Names_8042E628;

typedef struct Names_8042E6C4 {
    char *name[5];
} Names_8042E6C4;

typedef struct Names_8042E7B8 {
    char *name[3];
} Names_8042E7B8;

typedef struct Ent_80426894 {
    s16 count;
    u8 id[6];
} Ent_80426894;

typedef struct Tbl_80426894 {
    u8 pad[6];
    Ent_80426894 ent[6];
} Tbl_80426894;

typedef struct Ent_80425870 {
    s32 used;
    u32 f4;
    u32 base;
} Ent_80425870;

typedef struct Ent_80427C6C {
    u16 pad0;
    u16 id;
    u8 rest[0xE10];
} Ent_80427C6C;

typedef struct Ent_80427D40 {
    s16 state;
    u16 id;
    u8 pad4[4];
    s32 timeout;
    s32 last;
    u8 rest[0xE14 - 0x10];
} Ent_80427D40;

extern RecoveredGlobal_80427D0C_lbl_805CFC20 lobby_pppoe_slot_table;
/* Adapter state: the receive message queue and the interrupt statistics counters (one counter per BBA
 * interrupt cause, bumped by TLobby__sub_80429B8C). */
typedef struct EthState_805D0AA0 {
    u8 queue[0x20];
    void *queue_msgs[10];
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
s32 OSWakeupThread(void *);
extern s32 network_thread_queue;
s32 EXIDeselect(s32);
s32 EXIImm(s32, void *, s32, u32, u32);
s32 EXISelect(s32, u32, s32);
s32 EXISync(s32);
s32 EXIImmEx(s32, s32, s32, s32);
extern s32 exi_send_started_flag;
extern s32 lbl_805D7C54;
extern s32 lbl_805D7C7C;
extern s32 exi_send_size;
s32 memcpy(void *, void *, int);
extern s32 exi_mac_address;
s32 OSDisableInterrupts();
s32 OSRestoreInterrupts(s32);
s32 OSSleepThread(void *);
extern u32 lbl_805D7C4C;
extern s32 exi_receive_callback;
extern s32 lbl_805D7C44;
extern s32 lbl_805D7C48;
s32 EXILock(s32, u32, u32);
s32 EXIUnlock(s32);
typedef struct Ent_804267F0 {
    s16 count;
    u8 id[6];
} Ent_804267F0;

typedef struct Tbl_804267F0 {
    u8 pad[6];
    Ent_804267F0 ent[6];
} Tbl_804267F0;

s32 EXIDma(s32, void *, s32, u32, void *);
extern s32 exi_dma_read_length;
extern u32 exi_dma_write_length;
void DCStoreRange(void *, u32);
void TLobby__sub_8042B434(s32, void *);
extern s32 lbl_805D7C84;
extern s32 lbl_805D7C88;

void DCInvalidateRange(void *, u32);
void TLobby__sub_80429648(void);
extern u16 lbl_805D7C6C[2];
extern u8 *lbl_805D7C74;
extern u16 lbl_805D7C7A;
extern u16 lbl_805D7C78;
extern u16 lbl_805D7C5C;
extern u16 lbl_805D7C70;
extern u16 lbl_805D7C60;
int memcmp(const void *, const void *, unsigned long);
u16 TLobby__sub_8042BA8C(void *);
extern s32 lbl_805D4830;
extern u8 lbl_805D4836;
extern u8 lbl_805D4838;
extern u8 lbl_805D7C36;
extern char lbl_804FD9F8[];
extern char lbl_804FDA04[];
u32 OSGetTick(void);
void OSInitThreadQueue(void *);
void OSInitMessageQueue(void *, void *, s32);
void EXISetExiCallback(s32, void *);
void TLobby__sub_80429B8C(s32 chan, void *ctx);
extern s32 lbl_805D7C58;
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void exi8_rd(u32 reg, s32 buf, s32 len) {
    u32 c = ((reg << 8) & 0xFFFF00) | 0x80000000;
    EXISelect(0, 2, 5);
    EXIImm(0, &c, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, buf, len, 0);
    EXIDeselect(0);
}
inline void exi8_w32_16(u32 cmd, u16 val) {
    u16 v = val;
    u32 c = cmd;
    EXISelect(0, 2, 5);
    EXIImm(0, &c, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, (s32)&v, 2, 1);
    EXIDeselect(0);
}
#pragma pop
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
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
inline u8 exi8_r16_8(u16 cmd) {
    u16 c = cmd;
    u8 v;
    EXISelect(0, 2, 5);
    EXIImm(0, &c, 2, 1, 0);
    EXISync(0);
    EXIImm(0, &v, 1, 0, 0);
    EXISync(0);
    EXIDeselect(0);
    return v;
}
inline u32 exi8_r16_32(u16 cmd) {
    u16 c = cmd;
    u32 v;
    EXISelect(0, 2, 5);
    EXIImm(0, &c, 2, 1, 0);
    EXISync(0);
    EXIImmEx(0, (s32)&v, 4, 0);
    EXIDeselect(0);
    return v;
}
inline void exi8_w16_32(u16 cmd, u32 val) {
    u32 v = val;
    u16 c = cmd;
    EXISelect(0, 2, 5);
    EXIImm(0, &c, 2, 1, 0);
    EXISync(0);
    EXIImmEx(0, (s32)&v, 4, 1);
    EXIDeselect(0);
}
inline void exi8_w32_8(u32 cmd, u8 val) {
    u8 v = val;
    u32 c = cmd;
    EXISelect(0, 2, 5);
    EXIImm(0, &c, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, (s32)&v, 1, 1);
    EXIDeselect(0);
}
inline u8 exi8_r32_8(u32 cmd) {
    u32 c = cmd;
    u8 v;
    EXISelect(0, 2, 5);
    EXIImm(0, &c, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, (s32)&v, 1, 0);
    EXIDeselect(0);
    return v;
}
inline u16 exi8_r32_16(u32 cmd) {
    u32 c = cmd;
    u16 v;
    EXISelect(0, 2, 5);
    EXIImm(0, &c, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, (s32)&v, 2, 0);
    EXIDeselect(0);
    return v;
}
inline u16 exi8_swap16(u16 x) {
    return __lhbrx(&x, 0);
}
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma pop

#define arg0 ((s32)argp)
#undef arg0

#pragma push
#pragma dont_inline on
#pragma pop

typedef char RecoveredGlobal_80427D0C_lbl_805CFC20_size[sizeof(RecoveredGlobal_80427D0C_lbl_805CFC20) == 0xE20 ? 1 : -1];

#define TBL_80427D40 ((Ent_80427D40 *)&lobby_pppoe_slot_table)
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma pop

typedef char RecoveredGlobal_80428374_lbl_805D0A40_size[sizeof(RecoveredGlobal_80428374_lbl_805D0A40) == 0x60 ? 1 : -1];

typedef char RecoveredGlobal_80428360_lbl_805CFC20_size[sizeof(RecoveredGlobal_80428360_lbl_805CFC20) == 0xE20 ? 1 : -1];

typedef char RecoveredGlobal_8042839C_lbl_805D0A40_size[sizeof(RecoveredGlobal_8042839C_lbl_805D0A40) == 0x60 ? 1 : -1];

void wake_network_thread(void) {
    OSWakeupThread(&network_thread_queue);
}

void exi_write(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp14;
    sp14 = ((arg0 << 8) & 0xFFFF00) | 0x80000000;
    EXISelect(0, 2U, 5);
    EXIImm(0, &sp14, 4, 1U, 0U);
    EXISync(0);
    EXIImmEx(0, arg1, arg2, 0);
    EXIDeselect(0);
}

void TLobby__sub_80429648(void)
{
  u8 reply40[4];
  u16 id46;
  s32 n;
  s32 i;
  u16 len;
  volatile u16 *new_var;
  u32 sh;
  u16 *p;
  u16 *q;
  u16 h24;
  volatile u32 t4;
  volatile u16 t2;
  volatile u8 scratch[8];
  exi_dma_write_length = 0;
  new_var = &t2;
  exi_dma_read_length = 0;
  while (lbl_805D7C7A != lbl_805D7C78)
  {
    sh = (lbl_805D7C7A & 0xFF) << 8;
    exi8_rd(sh, (s32) reply40, 4);
    p = &lbl_805D7C5C;
    p[0] = reply40[0] | ((reply40[1] & 0xF) << 8);
    p[1] = ((reply40[2] << 4) & 0xFF0) | (((len = (0, reply40[1])) >> 4) & 0xF);
    *(((u8 *) p) + 4) = reply40[3];
    t4 = *((u32 *) (&lbl_805D7C5C));
    t2 = lbl_805D7C60;
    *((u32 *) (&lbl_805D7C6C)) = t4;
    lbl_805D7C70 = *new_var;
    exi8_rd(sh + 0x10, (s32) (&id46), 2);
    n = lbl_805D7C48;
    if (n > 0)
    {
      for (i = 0; i < n; i++)
      {
        if (((u16 *) lbl_805D7C44)[i] == id46)
        {
          break;
        }
      }

      if ((i != n) && (lbl_805D7C4C != 0))
      {
        q = lbl_805D7C6C;
        lbl_805D7C74 = ((u8 *(*)(u16, u16, u8)) lbl_805D7C4C)(id46, q[1], *((u8 *) (&q[2])));
        if (lbl_805D7C74 != 0)
        {
          i = sh + 4;
          len = q[1];
          if (((sh + 4) + len) > 0x1000)
          {
            exi_dma_write_length = (sh + len) - 0xFFC;
            exi_dma_read_length = len - exi_dma_write_length;
          }
          else
          {
            exi_dma_read_length = len;
            exi_dma_write_length = 0;
          }
          start_exi_dma_read((u16) i);
          return;
        }
      }
    }
    lbl_805D7C7A = lbl_805D7C6C[0];
  }

  h24 = exi8_swap16(lbl_805D7C78);
  exi8_w32_16(0xC0001800, h24);
  exi8_w32_8(0xC0000900, 2);
  exi8_w16_8(0x4200, 0xF8);
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
    EXIDma(0, exi_dma_buffer, len, 0, exi_dma_write_length != 0 ? (void *)start_exi_dma_write : (void *)TLobby__sub_80429AC8);
}

void start_exi_dma_write(s32 chan, void *ctx) {
    u32 len;
    s32 cmd;
    len = (exi_dma_write_length + 0x1F) & ~0x1F;
    EXIDeselect(0);
    cmd = 0x80010000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 4, 1, 0);
    EXISync(0);
    EXIDma(0, exi_dma_write_buffer, len, 0, (void *)TLobby__sub_80429AC8);
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
        ((void (*)(u8 *, u16))exi_receive_callback)(lbl_805D7C74, lbl_805D7C6C[1]);
    }
    lbl_805D7C7A = lbl_805D7C6C[0];
    TLobby__sub_80429648();
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
    EXIImmEx(0, (s32)buf, len, 0);
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
    EXIImmEx(0, (s32)buf, len, 1);
    EXIDeselect(0);
}

static inline void bba_ins(u32 reg, void *buf, s32 len) {
    u32 cmd;
    cmd = ((reg << 8) & 0xFFFF00) | 0x80000000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, (s32)buf, len, 0);
    EXIDeselect(0);
}

static inline void bba_outs(u32 reg, void *buf, s32 len) {
    u32 cmd;
    cmd = ((reg << 8) & 0xFFFF00) | 0xC0000000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, (s32)buf, len, 1);
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

static inline void bba_recv(void) {
    lbl_805D0AA0.pad_48++;
    lbl_805D7C78 = bba_in16(0x16);
    lbl_805D7C7A = bba_in16(0x18);
    TLobby__sub_80429648();
}

void TLobby__sub_80429B8C(s32 chan, void *ctx) {
    u8 ir;
    s32 notify;
    u8 status;
    u8 err;
    void (*callback)(u8);

    notify = 0;
    if (EXILock(0, 2, (u32)TLobby__sub_80429B8C) == 0) {
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
        callback = (void (*)(u8))lbl_805D7C54;
        lbl_805D7C54 = 0;
        callback(status);
    }
}

u32 __OSBusClock : 0x800000F8;

static inline void bba_udelay(u32 usec) {
    u32 start;
    u32 ticks;
    start = OSGetTick();
    ticks = ((usec) * ((__OSBusClock / 4) / 125000)) / 8;
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

void OSReport(char *fmt, ...);
void *memset(void *, int, unsigned long);
s32 init_bba_exi_adapter(void *arg) {
    s32 level;
    u32 cid;
    u8 val;

    OSInitThreadQueue(&network_thread_queue);
    OSInitMessageQueue(lbl_805D0AA0.queue, lbl_805D0AA0.queue_msgs, 10);
    __SIRegs[15] &= ~0x80000000;
    level = OSDisableInterrupts();
    for (;;) {
        if (EXILock(0, 2, (u32)wake_network_thread) == 1) {
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
    bba_ins(0x20, &exi_mac_address, 6);
    if (memcmp(&exi_mac_address, &lbl_805D4830, 6) == 0) {
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
    EXISetExiCallback(2, (void *)TLobby__sub_80429B8C);
    EXIUnlock(0);
    return 1;
}
#pragma pop

void start_exi_send(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;
    s32 var_r4;
    lbl_805D7C7C = arg0;
    var_r3 = 0;
    exi_send_size = arg1;
    var_r4 = 0;
    exi_send_started_flag = 1;
    lbl_805D7C54 = arg2;
    exi_start_send_dma(0, 0);
}

s32 exi_start_send_dma(int chan, int ctx) {
    u8 pad[4];
    s32 cmd;
    if (EXILock(0, 2, (u32)exi_start_send_dma) != 0) {
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
        EXIDma(0, (void *)lbl_805D7C7C, lbl_805D7C84, 1, (void *)TLobby__sub_8042B434);
    }
}

#pragma push
#pragma cplusplus off
#pragma pop
#pragma push
#pragma cplusplus off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma dont_inline off
void TLobby__sub_8042B434(s32 chan, void *ctx)
{
  int new_var;
  s32 EXIImmEx(s32, void *, s32, u32);
  s32 EXISelect(s32, u32, u32);
  int new_var2;
  s32 EXIUnlock(s32);
  BOOL EXIImm(s32, void *, s32, u32, void *);
  BOOL EXISync(s32);
  BOOL EXIDeselect(s32);
  u8 status[4];
  u32 cmd1;
  u32 cmd2;
  u8 *p = status;
  if ((*((s32 *) (&lbl_805D7C88))) != 0)
  {
    EXIImmEx(0, (void *) ((*((s32 *) (&lbl_805D7C7C))) + (*((s32 *) (&lbl_805D7C84)))), *((s32 *) (&lbl_805D7C88)), 1);
  }
  EXIDeselect(0);
  cmd1 = 0x80000000;
  EXISelect(0, 2, 5);
  new_var = 1;
  EXIImm(0, &cmd1, 4, new_var, 0);
  EXISync(0);
  EXIImmEx(0, &status[new_var], 1, 0);
  EXIDeselect(0);
  new_var2 = status[1];
  new_var2 = new_var2 | 4;
  status[0] = new_var2;
  cmd2 = 0xc0000000;
  EXISelect(0, 2, 5);
  EXIImm(0, &cmd2, 4, new_var, 0);
  EXISync(0);
  EXIImmEx(0, &status[0], new_var, new_var);
  EXIDeselect(0);
  EXIUnlock(0);
}
#pragma pop

void copy_6_byte_config(void *out) {
    memcpy(out, &exi_mac_address, 6);
}

void copy_mac_address(void *address) {
    s32 arg0 = (s32)address;
    memcpy(&exi_mac_address, (void *)arg0, 6);
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
        if (EXILock(0, 2, (u32)wake_network_thread) == 1) {
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
        EXIImmEx(0, (s32)&sp43, 1, 1);
        EXIDeselect(0);
    } else {
        sp42 = 0xFF;
        sp38 = 0xC0000800;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp38, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, (s32)&sp42, 1, 1);
        EXIDeselect(0);
        sp40 = 0x100;
        sp34 = 0xC0000A00;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp34, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, (s32)&sp40, 2, 1);
        EXIDeselect(0);
        sp30 = 0xC0001600;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp30, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, (s32)&sp40, 2, 1);
        EXIDeselect(0);
        sp2C = 0xC0001800;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp2C, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, (s32)&sp40, 2, 1);
        EXIDeselect(0);
        sp40 = 0xF00;
        sp28 = 0xC0001A00;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp28, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, (s32)&sp40, 2, 1);
        EXIDeselect(0);
        sp20 = 0x80000100;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp20, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, (s32)&sp27, 1, 0);
        EXIDeselect(0);
        e = sp27;
        e &= ~1;
        e |= 0x12;
        sp26 = e;
        sp1C = 0xC0000100;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp1C, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, (s32)&sp26, 1, 1);
        EXIDeselect(0);
        sp18 = 0xC0000000;
        sp25 = 8;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp18, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, (s32)&sp25, 1, 1);
        EXIDeselect(0);
        sp24 = 8;
        sp14 = 0xC0003200;
        EXISelect(0, 2, 5);
        EXIImm(0, &sp14, 4, 1, 0);
        EXISync(0);
        EXIImmEx(0, (s32)&sp24, 1, 1);
        EXIDeselect(0);
    }
    EXIUnlock(0);
}

s32 poll_exi_status(s32 *status) {
    u8 buf[2];
    s32 v;
    if (EXILock(0, 2, 0) != 0) {
        exi_write(0x31, (s32)&buf[1], 1);
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

void TLobby__sub_8042BA48(s32 arg0, s32 arg1) {
    s32 e = OSDisableInterrupts();
    lbl_805D7C44 = arg0;
    lbl_805D7C48 = arg1;
    OSRestoreInterrupts(e);
}

u16 TLobby__sub_8042BA8C(void *arg0)
{
    u8 d;
    u32 crc;
    u16 ret;
    s32 i;
    s32 j;
    u8 *p;
    u32 fb;

    crc = 0xFFFFFFFF;
    p = (u8 *)arg0;
    for (i = 0; i < 6; i++) {
        d = p[i];
        for (j = 0; j < 8; j++) {
            fb = (crc >> 31) ^ (d & 1);
            crc <<= 1;
            if (fb) {
                crc ^= 0x04C11DB6;
                crc |= 1;
            }
            d >>= 1;
        }
    }
    ret = 0;
    for (i = 5, j = 31; i >= 0; i--, j--) {
        ret |= ((crc >> j) & 1) << i;
    }
    return ret;
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
  s32 bit;
  int read_command;
  s32 enabled;
  s32 isDefault;
  int filter_bits;
  isDefault = 0;
  if (memcmp(arg0, &lbl_805D4830, 6) == 0)
  {
    isDefault = 1;
  }
  enabled = OSDisableInterrupts();
  while (1)
  {
    if (EXILock(0, 2, (u32)wake_network_thread) == 1)
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
    EXIImmEx(0, (s32)&val0, 1, 0);
    EXIDeselect(0);
    val1 = val0 | 4;
    cmd1 = 0xC0000100;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd1, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, (s32)&val1, 1, 1);
    EXIDeselect(0);
  }
  else
  {
    bit = TLobby__sub_8042BA8C(arg0);
    addr = ((u32) ((u16) (((u8) (bit / 8)) + 0x26))) << 8;
    read_command = addr | 0x80000000;
    cmd2 = read_command;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd2, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, (s32)&val2, 1, 0);
    EXIDeselect(0);
    filter_bits = val2;
    filter_bits = filter_bits | (1 << ((u8) (bit % 8)));
    val3 = filter_bits;
    cmd3 = addr | 0xC0000000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd3, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, (s32)&val3, 1, 1);
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
        if (EXILock(0, 2, (u32)wake_network_thread) == 1) {
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

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_8042DD70_lbl_805D1D20_size[sizeof(RecoveredGlobal_8042DD70_lbl_805D1D20) == 0x1C ? 1 : -1];
#pragma pop

typedef char RecoveredGlobal_8042E768_lbl_805D1D20_size[sizeof(RecoveredGlobal_8042E768_lbl_805D1D20) == 0x1C ? 1 : -1];
