#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_803F0C50.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"

struct RecoveredGlobal_803F1548_lbl_805A2720 {
    s32 value;
    u8 remaining[0x19C];
};

struct RecoveredGlobal_803F0CF4_lbl_805A2720 {
    s32 value;
    u8 remaining[0x19C];
};

struct K_803F119C { u8 pad0[0x10]; s32 f10; s32 f14; u8 pad1[0x18]; s32 f30; u8 pad2[0x34]; };

struct Pad_803F0C50 {
    u8 a;
    u8 b;
    u8 pad2[0x1A];
    s32 x1c;
    u8 queue[8];
    s32 x28;
    s32 x2c;
    u8 pad30[4];
    u8 x34[4];
    u8 x38[4];
    u8 pad3c[0x2C];
};

struct Pad_803F0E90 {
    u8 pad0[3];
    u8 x3;
    u8 pad4[0x14];
    void *x18;
    u8 pad1c[0x4C];
};

struct Pad_803F0D74 {
    u8 a;
    u8 b;
    u8 pad2;
    u8 x3;
    u8 pad4[3];
    u8 x7;
    u8 x8;
    u8 x9;
    u8 padA[0x12];
    s32 x1c;
    u8 pad20[8];
    s32 x28;
    s32 x2c;
    u8 pad30[0x38];
};

struct OSContext_803F0F84 { u8 a[0x90]; f64 fpr[32]; u8 rest[0x138]; };

struct Pad_803F0F84 {
    u8 a;
    u8 pad1[0x17];
    void (*x18)(s32, s32);
    s32 x1c;
    u8 pad20[0x10];
    void (*x30)(s32);
    u8 pad34[0x34];
};

struct Pad_803F107C {
    u8 a;
    u8 pad1[2];
    u8 out[4];
    u8 in[9];
    u32 outBytes;
    u32 inBytes;
    void (*x18)(s32, s32);
    s32 x1c;
    u8 pad20[8];
    s64 delay;
    void (*x30)(s32);
    u8 pad34[0x34];
};

struct Kbd_803F1210 {
    u8 pad0[0xB];
    u8 k0;
    u8 k1;
    u8 k2;
    u8 padE[0x26];
    u8 prev[4];
    u8 cur[4];
};

struct Kbd_803F1210;
struct Kb_803F132C {
    u8 type;
    u8 pad1[0x1B];
    s32 err;
    u8 pad20[0x14];
    u8 prev[4];
    u8 cur[4];
    u8 queue[32];
    u32 count;
    u32 head;
    u8 pad64[4];
};

struct Kb_803F1604 {
    u8 type;
    u8 pad1[6];
    u8 resp[8];
    u8 padF[0xD];
    s32 err;
    u8 pad20[0x14];
    u8 prev[4];
    u8 cur[4];
    u8 queue[32];
    u32 count;
    u32 head;
    u8 pad64[4];
};

RecoveredGlobal_803F1548_lbl_805A2720 keyboard_pad_state_table;
extern "C" {
s32 SIDisablePolling(u32);
extern s32 TKeyBoardControl__polling_channel_mask;
s32 TKeyBoardControl__polling_disabled;
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
void Dolphin_SIGetTypeAsync(s32, void *);
void OSInitThreadQueue(void *);
s32 OSRegisterResetFunction(void *);
s32 SIRefreshSamplingRate(void);
void *memset(void *, int, u32);
extern u8 lbl_804FCD38[];
void OSClearContext(OSContext_803F0F84 *);
void OSSetCurrentContext(OSContext_803F0F84 *);
void handle_pad_transfer_done__16TKeyBoardControlFiUiPv(s32 chan, u32 status, OSContext_803F0F84 *ctx);
void *memcpy(void *, const void *, u32);
s32 SITransfer(s32 chan, void *out, u32 outBytes, void *in, u32 inBytes, void (*cb)(s32, u32, OSContext_803F0F84 *), s64 delay);
OSContext_803F0F84 *OSGetCurrentContext(void);
s32 __OSReschedule(void);
void SISetCommand(s32, u32);
void SIEnablePolling(u32);
s32 SIGetResponse(s32, void *);
void *memmove(void *, const void *, u32);
s32 SIIsChanBusy(s32);
u32 SIGetStatus(s32);
typedef char RecoveredGlobal_803F0CF4_lbl_805A2720_size[sizeof(RecoveredGlobal_803F0CF4_lbl_805A2720) == 0x1A0 ? 1 : -1];

void TKeyBoardControl::init_pad_states() {
    s32 i;
    for (i = 0; i < 4; i++) {
        Pad_803F0C50 *p = &((Pad_803F0C50 *)&keyboard_pad_state_table)[i];
        p->x2c = 0;
        p->x28 = 0;
        p->a = 0;
        p->b = 0;
        p->x1c = 0;
        memset(p->x38, 0, 4);
        memset(p->x34, 0, 4);
        OSInitThreadQueue(p->queue);
    }
    SIRefreshSamplingRate();
    TKeyBoardControl__polling_disabled = 0;
    OSRegisterResetFunction(lbl_804FCD38);
}

void TKeyBoardControl::parse_pad_event(s32 arg0, u32 arg1) {
    struct Fields_temp_r4 { s8 field_0; s8 field_1; u8 pad_2[38]; s32 field_28; s32 field_2C; };
    s32 temp_r0;
    u32 temp_r6;
    u8 *temp_r4;
    temp_r6 = arg1 >> 0x10U;
    temp_r0 = (arg1 >> 0x10U) & 0xFFF0;
    temp_r4 = (u8 *)&(*(RecoveredGlobal_803F0CF4_lbl_805A2720 *)&keyboard_pad_state_table).value + (arg0 * 0x68);
    switch (temp_r0) {
    case 0x820:
        ((Fields_temp_r4*)temp_r4)->field_0 = 1;
        ((Fields_temp_r4*)temp_r4)->field_1 = (s8) (temp_r6 & 0xF);
        ((Fields_temp_r4*)temp_r4)->field_2C = 0;
        ((Fields_temp_r4*)temp_r4)->field_28 = 0;
        return;
    case 0x830:
        ((Fields_temp_r4*)temp_r4)->field_0 = 2;
        ((Fields_temp_r4*)temp_r4)->field_1 = (s8) (temp_r6 & 0xF);
        ((Fields_temp_r4*)temp_r4)->field_2C = 0;
        ((Fields_temp_r4*)temp_r4)->field_28 = 0;
        return;
    default:
        ((Fields_temp_r4*)temp_r4)->field_1 = 0;
        ((Fields_temp_r4*)temp_r4)->field_0 = 0;
        return;
    }
}

void TKeyBoardControl::detect_device_type(s32 chan) {
    Pad_803F0D74 *p = &((Pad_803F0D74 *)&keyboard_pad_state_table)[chan];
    u32 type;
    if (p->x1c != 0) {
        return;
    }
    type = (p->x7 << 24) | (p->x8 << 16);
    switch ((type >> 16) & 0xFFF0) {
    case 0x820:
        p->a = 1;
        p->b = (type >> 16) & 0xF;
        p->x2c = 0;
        p->x28 = 0;
        break;
    case 0x830:
        p->a = 2;
        p->b = (type >> 16) & 0xF;
        p->x2c = 0;
        p->x28 = 0;
        break;
    default:
        p->b = 0;
        p->a = 0;
        break;
    }
    if ((s32)p->a >= 3 || (s32)p->a < 1) {
        p->x1c = -1;
        return;
    }
    if (p->x9 & 0x10) {
        p->x1c = -0x80;
        return;
    }
    if (p->x9 & 8) {
        p->x1c = -3;
        return;
    }
    if (p->x3 == 0xFF && TKeyBoardControl__polling_disabled == 0) {
        TKeyBoardControl::enable_keyboard_polling(chan);
    }
}

void TKeyBoardControl__sub_803F0E8C(void) {

}
typedef char RecoveredGlobal_803F1548_lbl_805A2720_size[sizeof(RecoveredGlobal_803F1548_lbl_805A2720) == 0x1A0 ? 1 : -1];

s32 TKeyBoardControl__sub_803F0E90(s32 arg0, void *arg1) {
    Pad_803F0E90 *p = &((Pad_803F0E90 *)&keyboard_pad_state_table)[arg0];
    void *cb;
    s32 ret;
    s32 lvl;
    cb = arg1 != NULL ? arg1 : (void *)TKeyBoardControl__sub_803F0E8C;
    lvl = OSDisableInterrupts();
    if (p->x18 != NULL) {
        ret = -2;
    } else {
        p->x18 = cb;
        ret = 0;
    }
    OSRestoreInterrupts(lvl);
    if (ret != 0) {
        return ret;
    }
    p->x3 = 0xFF;
    return TKeyBoardControl::start_get_type_async(arg0, 1, 3, (s32)TKeyBoardControl::detect_device_type);
}

s32 TKeyBoardControl::disable_all_channels() {
    u32 v;
    while ((v = (u32)TKeyBoardControl__polling_channel_mask) != 0) {
        TKeyBoardControl::disable_channel_polling(__cntlzw(v));
    }
    TKeyBoardControl__polling_disabled = 1;
    return 1;
}

void handle_pad_transfer_done__16TKeyBoardControlFiUiPv(s32 chan, u32 status, OSContext_803F0F84 *ctx) {
    Pad_803F0F84 *p = &((Pad_803F0F84 *)&keyboard_pad_state_table)[chan];
    u8 unused[8];
    OSContext_803F0F84 tmp;
    void (*cb)(s32);
    void (*cb2)(s32, s32);
    if (TKeyBoardControl__polling_disabled != 0) {
        return;
    }
    if (status & 8) {
        p->a = 0;
        p->x1c = -1;
    } else if (status & 7) {
        p->x1c = -3;
    } else {
        p->x1c = 0;
    }
    if ((cb = p->x30) != 0) {
        p->x30 = 0;
        cb(chan);
    }
    if (p->x18 != 0) {
        OSClearContext(&tmp);
        OSSetCurrentContext(&tmp);
        cb2 = p->x18;
        p->x18 = 0;
        cb2(chan, p->x1c);
        OSClearContext(&tmp);
        OSSetCurrentContext(ctx);
    }
}

void TKeyBoardControl__sub_803F107C(s32 chan, u32 type) {
    Pad_803F107C *p = &((Pad_803F107C *)&keyboard_pad_state_table)[chan];
    u8 unused[8];
    OSContext_803F0F84 tmp;
    OSContext_803F0F84 *old;
    void (*cb)(s32);
    void (*cb2)(s32, s32);

    if (TKeyBoardControl__polling_disabled != 0) {
        return;
    }
    TKeyBoardControl::parse_pad_event(chan, type);
    if (p->a != 0) {
        if (SITransfer(chan, p->out, p->outBytes, p->in, p->inBytes, handle_pad_transfer_done__16TKeyBoardControlFiUiPv, p->delay) != 0) {
            return;
        }
        p->x1c = -2;
    } else {
        p->x1c = -1;
    }
    if ((cb = p->x30) != 0) {
        p->x30 = 0;
        cb(chan);
    }
    if (p->x18 != 0) {
        old = OSGetCurrentContext();
        OSClearContext(&tmp);
        OSSetCurrentContext(&tmp);
        cb2 = p->x18;
        p->x18 = 0;
        cb2(chan, p->x1c);
        OSClearContext(&tmp);
        OSSetCurrentContext(old);
        __OSReschedule();
    }
}
s32 TKeyBoardControl::start_get_type_async(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 en;
    K_803F119C *k = &((K_803F119C *)&keyboard_pad_state_table)[arg0];
    en = OSDisableInterrupts();
    k->f30 = arg3;
    k->f10 = arg1;
    k->f14 = arg2;
    Dolphin_SIGetTypeAsync(arg0, (void *)TKeyBoardControl__sub_803F107C);
    OSRestoreInterrupts(en);
    return 0;
}

void TKeyBoardControl::update_pressed_keys() {
    Kbd_803F1210 *p = (Kbd_803F1210 *)this;
    s32 n;
    memcpy(p->prev, p->cur, 4);
    if (p->k0 == 1 || p->k0 == 2) {
        return;
    }
    n = 0;
    if (p->k0 != 0) {
        n = 1;
        p->cur[0] = p->k0;
    }
    if (p->k1 != 0) {
        ((u8 *)p)[n++ + 0x38] = p->k1;
    }
    if (p->k2 != 0) {
        ((u8 *)p)[n++ + 0x38] = p->k2;
    }
    for (; n < 4; n++) {
        p->cur[n] = 0;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 kb_push_803F132C(Kb_803F132C *k, u8 c) {
    if (k->count < 32) {
        k->queue[(k->head + k->count) & 31] = c;
        k->count++;
        return 1;
    }
    return 0;
}
void TKeyBoardControl::update_key_events(s32 chan) {
    Kb_803F132C *k;
    u8 c;
    s32 j;
    s32 i;
    s32 j2;
    u8 c2;
    s32 i2;
    k = &((Kb_803F132C *)&keyboard_pad_state_table)[chan];
    if (k->err == -1) {
        memset(k->prev, 0, 4);
        memset(k->cur, 0, 4);
    }
    if (k->err != 0) {
        return;
    }
    switch (k->type) {
    case 1:
    case 2:
        ((TKeyBoardControl *)k)->update_pressed_keys();
        break;
    default:
        return;
    }
    for (i = 0; i < 4 && k->count < 32; i++) {
        c = k->prev[i];
        if (c != 0) {
            for (j = 0; j < 4; j++) {
                if (c == k->cur[j]) {
                    break;
                }
            }
            if (j == 4) {
                if (!kb_push_803F132C(k, c | 0x80)) {
                    k->err = -4;
                    return;
                }
            }
        }
    }
    for (i2 = 0; i2 < 4; i2++) {
        c2 = k->cur[i2];
        if (c2 != 0) {
            for (j2 = 0; j2 < 4; j2++) {
                if (c2 == k->prev[j2]) {
                    break;
                }
            }
            if (j2 == 4) {
                if (!kb_push_803F132C(k, c2)) {
                    k->err = -4;
                    return;
                }
            }
        }
    }
}
#pragma pop

u8 TKeyBoardControl__sub_803F1548(s32 arg0) {
    return *(u8 *)((s8 *)((u8 *)&keyboard_pad_state_table.value + (arg0 * 0x68)) + 1);
}

void TKeyBoardControl::enable_keyboard_polling(s32 arg0) {
    u32 cmd;
    u32 buf[2];
    u32 bit = 0x80000000U >> arg0;
    if (!(TKeyBoardControl__polling_channel_mask & bit)) {
        TKeyBoardControl__polling_channel_mask |= bit;
        SIGetResponse(arg0, buf);
        cmd = 0x540000;
        SISetCommand(arg0, cmd);
        SIEnablePolling(TKeyBoardControl__polling_channel_mask);
    }
}

void TKeyBoardControl::disable_channel_polling(s32 arg0) {
    u32 temp_r31;
    temp_r31 = 0x80000000U >> arg0;
    SIDisablePolling(temp_r31);
    TKeyBoardControl__polling_channel_mask &= ~temp_r31;
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline u32 kb_sum_803F1604(u32 *p) {
    u32 sum;
    sum = p[0] >> 24;
    sum ^= (u8)(p[0] >> 16);
    sum ^= (u8)(p[0] >> 8);
    sum ^= (u8)p[0];
    sum ^= p[1] >> 24;
    sum ^= (u8)(p[1] >> 16);
    sum ^= (u8)(p[1] >> 8);
    return sum == (u8)p[1];
}
}
s32 poll_keyboard_port(s32 chan, u8 *out) {
    u32 resp[2];
    u8 unused[4];
    u32 bit;
    s32 enabled;
    Kb_803F1604 *k;
    s32 err;
    s32 ret;
    enabled = OSDisableInterrupts();
    k = &((Kb_803F1604 *)&keyboard_pad_state_table)[chan];
    bit = 0x80000000U >> chan;
    if (k->type != 1 && k->type != 2) {
        k->err = -1;
    } else if (SIIsChanBusy(chan)) {
        k->err = -2;
    } else if (!(TKeyBoardControl__polling_channel_mask & bit)) {
        k->err = -1;
    } else if (SIGetStatus(chan) & 8) {
        SIGetResponse(chan, resp);
        SIDisablePolling(bit);
        TKeyBoardControl__polling_channel_mask &= ~bit;
        k->type = 0;
        k->err = -1;
    } else if (!SIGetResponse(chan, resp) || (resp[0] & 0x80000000)) {
        k->err = -3;
    } else {
        if (resp[0] & 0x20000000) {
            err = -128;
        } else if (resp[0] & 0x10000000) {
            err = -3;
        } else {
            if (!kb_sum_803F1604(resp)) {
                err = -3;
            } else {
                err = 0;
            }
        }
        k->err = err;
        switch (k->err) {
        case -128:
            SIDisablePolling(bit);
            TKeyBoardControl__polling_channel_mask &= ~bit;
            k->type = 0;
            break;
        case 0:
            memcpy(k->resp, resp, 8);
            break;
        }
    }
    TKeyBoardControl::update_key_events(chan);
    if (out != NULL) {
        memmove(out, k->cur, 4);
    }
    ret = k->err;
    OSRestoreInterrupts(enabled);
    return ret;
}
#pragma pop
