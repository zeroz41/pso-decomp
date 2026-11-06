#include "types.h"
#include "pso/unk/TLobby.h"

typedef s32 (*RecoveredCallback_4873a87e26d6)(s32, s32 *, s32);
struct RecoveredGlobal_803D39F8_lbl_8047E0C8 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_803CFEA0_lbl_8047DAE4 {
    s32 value;
    u8 remaining[0x14];
};

typedef s32 (*RecoveredCallback_803D3B2C)(s32, s32 *, s32);
struct S_803D3B2C { u8 pad; s8 f; };

struct G_803D3B2C { s32 value; u8 remaining[0x14]; };

struct G_803D3A4C { s32 value; u8 remaining[0x14]; };

struct S_803D3A4C {
    s32 f0;
    s32 unit;
    s32 total;
    s32 count;
    s32 pos;
    s32 size;
    s32 stride;
};

extern RecoveredGlobal_803D39F8_lbl_8047E0C8 lbl_8047E0C8;
extern RecoveredCallback_4873a87e26d6 mfci_error_callback;
extern s32 mfci_error_callback_context;
extern RecoveredGlobal_803CFEA0_lbl_8047DAE4 lbl_8047E0F8;
extern G_803D3A4C lbl_8047E0E0;

typedef char RecoveredGlobal_803D39F8_lbl_8047E0C8_size[sizeof(RecoveredGlobal_803D39F8_lbl_8047E0C8) == 0x18 ? 1 : -1];
s32 TLobby::get_handle_field_checked() {
    u8 *arg0 = (u8 *)this;
    if (arg0 == NULL) {
        if (((s32 (*)(s32, s32 *, s32)) mfci_error_callback) != NULL) {
            mfci_error_callback(mfci_error_callback_context, &lbl_8047E0C8.value, 0);
        }
        return 0;
    }
    return *(s32 *)&this->m_down;
}
typedef char RecoveredGlobal_803CFEA0_lbl_8047DAE4_size[sizeof(RecoveredGlobal_803CFEA0_lbl_8047DAE4) == 0x18 ? 1 : -1];

typedef s32 (*RecoveredCallback_4873a87e26d6)(s32, s32 *, s32);
void TLobby::set_list_unit(s32 unit) {
    S_803D3A4C *s = (S_803D3A4C *)this;
    if (s == NULL) {
        if (mfci_error_callback != NULL) {
            mfci_error_callback(mfci_error_callback_context, &lbl_8047E0E0.value, 0);
        }
    } else {
        s32 old = s->pos * s->unit;
        s->unit = unit;
        s->count = (s->unit - 1 + s->total) / s->unit;
        s->pos = old / s->unit;
        s->size = s->stride * unit;
    }
}

s32 TLobby::get_field4_or_report() {
    u8 *arg0 = (u8 *)this;
    if (arg0 == NULL) {
        if (((s32 (*)(s32, s32 *, s32)) mfci_error_callback) != NULL) {
            mfci_error_callback(mfci_error_callback_context, &lbl_8047E0F8.value, 0);
        }
        return 0;
    }
    return *(s32 *)&this->m_flags;
}
s32 TLobby::get_handle_value_checked_b() {
    S_803D3B2C *arg0 = (S_803D3B2C *)this;
    if (arg0 == 0) {
        if ((*(RecoveredCallback_803D3B2C *)&mfci_error_callback) != 0) {
            (*(RecoveredCallback_803D3B2C *)&mfci_error_callback)(mfci_error_callback_context, &(*(G_803D3B2C *)&lbl_8047E0C8).value, 0);
        }
        return 0;
    }
    return arg0->f;
}
