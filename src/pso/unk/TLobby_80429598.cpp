#include "pso/network/NetworkTransport.h"
#include "pso/unk/TLobby_80429598.h"
#include "pso/network/ModemRuntime.h"
#include "pso/network/NetworkMessageTransport.h"

#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TUdpSocket.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80428374_lbl_805D0A40 {
    s32 value;
    u8 remaining[0x5C];
};

struct RecoveredGlobal_8042839C_lbl_805D0A40 {
    s32 value;
    u8 remaining[0x5C];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct RecoveredGlobal_8042E768_lbl_805D1D20 {
    s32 value;
    u8 remaining[0x18];
};

struct RecoveredGlobal_80427D0C_lbl_805CFC20 {
    s32 value;
    u8 remaining[0xE1C];
};

struct RecoveredGlobal_80428360_lbl_805CFC20 {
    s16 value;
    u8 remaining[0xE1E];
};

struct RecoveredGlobal_8042DD70_lbl_805D1D20 {
    s32 value;
    u8 remaining[0x18];
};

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

extern u8 lbl_805CF240[0xA0];
extern u8 TLobby__pppoe_message_queue[0xA0];
extern u8 lbl_805CF380[0x48];
extern RecoveredGlobal_80427D0C_lbl_805CFC20 lobby_pppoe_slot_table;
u8 lbl_805D0AA0[0x80];
u8 exi_dma_buffer[0x600];
u8 exi_dma_write_buffer[0xC00];
extern "C" {
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
extern u8 lbl_805CF380[];
extern u8 TLobby__pppoe_message_queue[];
typedef struct Ent_804267F0 {
    s16 count;
    u8 id[6];
} Ent_804267F0;

typedef struct Tbl_804267F0 {
    u8 pad[6];
    Ent_804267F0 ent[6];
} Tbl_804267F0;

extern u8 lbl_805CF240[];
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
int memcmp(const void *, const void *, unsigned long);
u32 TLobby__sub_8042BA8C(void *);
extern s32 lbl_805D4830;

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

void TLobby::wake_network_thread() {
    OSWakeupThread(&network_thread_queue);
}

void TLobby::exi_write(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp14;
    sp14 = ((arg0 << 8) & 0xFFFF00) | 0x80000000;
    EXISelect(0, 2U, 5);
    EXIImm(0, &sp14, 4, 1U, 0U);
    EXISync(0);
    EXIImmEx(0, arg1, arg2, 0);
    EXIDeselect(0);
}

void TLobby::start_exi_dma_read(u16 arg0) {
    u32 len;
    s32 cmd;
    len = (exi_dma_read_length + 0x1F) & ~0x1F;
    cmd = ((arg0 << 8) & 0xFFFF00) | 0x80000000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd, 4, 1, 0);
    EXISync(0);
    EXIDma(0, exi_dma_buffer, len, 0, exi_dma_write_length != 0 ? (void *)TLobby::start_exi_dma_write : (void *)TLobby__sub_80429AC8);
}

void TLobby::start_exi_dma_write(s32 chan, void *ctx) {
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

void TLobby::start_exi_send(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;
    s32 var_r4;
    lbl_805D7C7C = arg0;
    var_r3 = 0;
    exi_send_size = arg1;
    var_r4 = 0;
    exi_send_started_flag = 1;
    lbl_805D7C54 = arg2;
    TLobby::exi_start_send_dma(0, 0);
}

s32 TLobby::exi_start_send_dma(int, int) {
    u8 pad[4];
    s32 cmd;
    if (EXILock(0, 2, (u32)TLobby::exi_start_send_dma) != 0) {
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

void TLobby__sub_8042B434(s32 chan, void *ctx) {
    u8 val;
    u8 out;
    s32 cmd0;
    s32 cmd1;
    u8 pad[4];
    s32 bits;
    if (lbl_805D7C88 != 0) {
        EXIImmEx(0, lbl_805D7C7C + lbl_805D7C84, lbl_805D7C88, 1);
    }
    EXIDeselect(0);
    cmd0 = 0x80000000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd0, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, (s32)&val, 1, 0);
    EXIDeselect(0);
    bits = val;
    bits |= 4;
    out = bits;
    cmd1 = 0xC0000000;
    EXISelect(0, 2, 5);
    EXIImm(0, &cmd1, 4, 1, 0);
    EXISync(0);
    EXIImmEx(0, (s32)&out, 1, 1);
    EXIDeselect(0);
    EXIUnlock(0);
}

void TLobby::copy_6_byte_config() {
    memcpy(this, &exi_mac_address, 6);
}

void TLobby::copy_mac_address() {
    s32 arg0 = (s32)this;
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
        if (EXILock(0, 2, (u32)TLobby::wake_network_thread) == 1) {
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

s32 TLobby::poll_exi_status() {
    s32 *arg0 = (s32 *)this;
    u8 buf[2];
    s32 v;
    if (EXILock(0, 2, 0) != 0) {
        TLobby::exi_write(0x31, (s32)&buf[1], 1);
        if ((buf[1] & 1) || (buf[1] & 2)) {
            v = 1;
        } else {
            v = 0;
        }
        *arg0 = v;
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
  if (memcmp(arg0, &lbl_805D4830, 6) == 0)
  {
    isDefault = 1;
  }
  enabled = OSDisableInterrupts();
  while (1)
  {
    if (EXILock(0, 2, (u32) TLobby::wake_network_thread) == 1)
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

u8 TLobby::exi_read_status_byte() {
    u8 val;
    u16 cmd;
    s16 pad;
    s32 enabled;
    u8 ret;
    enabled = OSDisableInterrupts();
    while (1) {
        if (EXILock(0, 2, (u32)TLobby::wake_network_thread) == 1) {
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
