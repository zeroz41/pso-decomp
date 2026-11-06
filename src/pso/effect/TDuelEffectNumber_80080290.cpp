#include "types.h"
#include "pso/effect/TDuelEffectNumber.h"

struct RecoveredGlobal_80080438_lbl_80438DD4 {
    s32 value;
    u8 remaining[0x14];
};

struct Entry_800803D4 { u8 data[0x18]; };

extern "C" {
void TDuelEffectNumber__sub_800802F8(void *, void *, f32);
extern RecoveredGlobal_80080438_lbl_80438DD4 duel_number_default_layout;
extern Entry_800803D4 duel_number_pair_layout[];
}

extern void *TDuelEffectNumber__class_name;
TDuelEffectNumber::TDuelEffectNumber(TObject *object, void *arg2, void *arg3) : TObject(object) {
    *(void * *)&this->m_name = TDuelEffectNumber__class_name;
    *(f32 *)((s8 *)this + 0x1C) = *(f32 *)((s8 *)arg2 + 0x0);
    *(f32 *)((s8 *)this + 0x20) = *(f32 *)((s8 *)arg2 + 0x4);
    *(void **)((s8 *)this + 0x24) = arg3;
    *(u32 *)((s8 *)this + 0x28) = 0;
}

typedef char RecoveredGlobal_80080438_lbl_80438DD4_size[sizeof(RecoveredGlobal_80080438_lbl_80438DD4) == 0x18 ? 1 : -1];

void TDuelEffectNumber::render_pair(f32 f) {
    s32 i;
    for (i = 0; i < 2; i++) {
        TDuelEffectNumber__sub_800802F8(this, &duel_number_pair_layout[i], f);
    }
}

void TDuelEffectNumber::render_number_default(f32 farg0) {
    u8 *arg0 = (u8 *)this;
    TDuelEffectNumber__sub_800802F8(arg0, &duel_number_default_layout.value, farg0);
}
