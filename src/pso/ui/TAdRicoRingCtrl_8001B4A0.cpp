#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdRicoRingCtrl_8001B4A0.h"
#include "pso/ui/TAdRicoRingCtrl.h"

#include <stddef.h>
#include "pso/TAdRicoRing.h"
#include "pso/player/TObjPlayer.h"
struct Stack_8001B8AC {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_8001B8AC_lbl_8043481C {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8001B8AC___vt__15TAdRicoRingCtrl {
    s32 value;
    u8 remaining[0x14];
};

struct Obj_8001B4A0 { u8 pad0[0x1c]; u32 slot[2]; u8 pad24[4]; f32 f28; };

struct Obj_8001B824 { u8 pad[0x1c]; u32 slot[2]; };

struct Obj_8001B534 { u8 pad0[0x1c]; u32 slot[2]; u8 pad24[4]; f32 f28; };

extern "C" {
u32 create__15TAdRicoRingCtrlFPv(int);
s32 __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_8001B8AC_lbl_8043481C lbl_8043481C;
extern RecoveredGlobal_8001B8AC___vt__15TAdRicoRingCtrl __vt__15TAdRicoRingCtrl;
extern s32 TAdRicoRingCtrl__class_name;
extern s32 tl_04;
extern const f32 lbl_805D7E4C;
extern const f32 TAdRicoRingCtrl__data_805D7E50;
extern const f32 lbl_805D7E48;
void TAdRicoRingCtrl__sub_8001B4A0(Obj_8001B4A0 *self, f32 x);
extern const f32 lbl_805D7E54;
s32 test_flags_any(void *, int);

typedef char RecoveredGlobal_8001B8AC_lbl_8043481C_size[sizeof(RecoveredGlobal_8001B8AC_lbl_8043481C) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8001B8AC___vt__15TAdRicoRingCtrl_size[sizeof(RecoveredGlobal_8001B8AC___vt__15TAdRicoRingCtrl) == 0x18 ? 1 : -1];

void TAdRicoRingCtrl__sub_8001B4A0(Obj_8001B4A0 *self, f32 x) {
    s32 i;
    for (i = 0; i != 2; i++) {
        if (self->slot[i] != 0) {
            ((TAdRicoRingCtrl *)((u8 *)self->slot[i]))->start_anim(x);
            self->slot[i] = 0;
        }
    }
    f32 t = lbl_805D7E48 + x;
    if (lbl_805D7E4C != t) {
        self->f28 = TAdRicoRingCtrl__data_805D7E50 / t;
    }
}

void TAdRicoRingCtrl::start_fade_all(f32 x) {
    Obj_8001B534 *self = (Obj_8001B534 *)this;
    s32 i;
    for (i = 0; i != 2; i++) {
        if (self->slot[i] != 0) {
            ((TAdRicoRingCtrl *)((u8 *)self->slot[i]))->start_fade(x);
        }
    }
    if (lbl_805D7E4C != x) {
        this->m_28 = lbl_805D7E54 / x;
    }
}

#pragma push
#pragma opt_common_subs off
void TAdRicoRingCtrl::run_task() {
    f32 temp_f1;
    *(f32 *)&this->unk_24 = (f32) (*(f32 *)&this->unk_24 + this->m_28);
    temp_f1 = *(f32 *)&this->unk_24;
    if (temp_f1 < lbl_805D7E4C) {
        *(f32 *)&this->unk_24 = (f32) lbl_805D7E4C;
        return;
    }
    if (temp_f1 > (*(f32 *)&TAdRicoRingCtrl__data_805D7E50)) {
        *(f32 *)&this->unk_24 = (f32) (*(f32 *)&TAdRicoRingCtrl__data_805D7E50);
    }
}
#pragma pop

}
TAdRicoRingCtrl::~TAdRicoRingCtrl() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (((Obj_8001B824 *)this)->slot[i] != 0) {
            queue_destruction__7TObjectFv((void *)((Obj_8001B824 *)this)->slot[i]);
        }
    }
}

u8 *TAdRicoRingCtrl__ct(TAdRicoRingCtrl *ad_rico_ring_ctrl, s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_8001B8AC, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8001B8AC, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8001B8AC, sp10) == 0x8) ? 1 : -1];
    Stack_8001B8AC stack;
    u32 temp_r3;
    u32 temp_r3_2;
    __ct__7TObjectFP7TObject((void *)ad_rico_ring_ctrl, (void *)arg1);
    *(s32 **)((s8 *)ad_rico_ring_ctrl + 0x18) = &__vt__15TAdRicoRingCtrl.value;
    *(s32 *)((s8 *)ad_rico_ring_ctrl + 0) = (s32) TAdRicoRingCtrl__class_name;
    ad_rico_ring_ctrl->m_1c = create__15TAdRicoRingCtrlFPv(tl_04);
    temp_r3 = ad_rico_ring_ctrl->m_1c;
    if (temp_r3 != 0U) {
        TAdRicoRingCtrl__sub_8001BED0((void *)temp_r3, (f32)lbl_805D7E4C);
        ((TAdRicoRingCtrl *)(ad_rico_ring_ctrl->m_1c))->set_scale4(lbl_805D7E4C);
    }
    ad_rico_ring_ctrl->m_20 = create__15TAdRicoRingCtrlFPv(tl_04);
    temp_r3_2 = ad_rico_ring_ctrl->m_20;
    if (temp_r3_2 != 0U) {
        TAdRicoRingCtrl__sub_8001BED0((void *)temp_r3_2, (f32)lbl_805D7E4C);
        ((TAdRicoRingCtrl *)(ad_rico_ring_ctrl->m_20))->set_scale4(lbl_805D7E4C);
    }
    *(f32 *)((s8 *)ad_rico_ring_ctrl + 0x24) = (f32) TAdRicoRingCtrl__data_805D7E50;
    ad_rico_ring_ctrl->m_28 = (f32) lbl_805D7E4C;
    stack.sp8 = *(s32 *)((s8 *)&lbl_8043481C.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_8043481C.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_8043481C.value + 8);
    ad_rico_ring_ctrl->sub_8001B424((s32)((void *)&stack.sp8));
    return (u8 *)ad_rico_ring_ctrl;
}

void TAdRicoRingCtrl::start_fade(f32 farg0) {
    u8 *arg0 = (u8 *)this;
    f32 temp_f0;

    if (test_flags_any(arg0 + 0x2C, 1) != 0) {
        ((FlagWord *)(arg0 + 0x2C))->clear(1);
    }
    ((FlagWord *)(arg0 + 0x2C))->set(2);
    if (lbl_805D7E4C != farg0) {
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) ((*(f32 *)((s8 *)arg0 + 0x34) - *(f32 *)&this->m_1c) / farg0);
        temp_f0 = (*(f32 *)((s8 *)arg0 + 0x34) - *(f32 *)&this->m_20) / farg0;
        *(f32 *)((s8 *)arg0 + 0x3C) = temp_f0;
        *(f32 *)((s8 *)arg0 + 0x40) = temp_f0;
        *(f32 *)((s8 *)arg0 + 0x44) = temp_f0;
    }
}

void TAdRicoRingCtrl::start_anim(f32 farg0) {
    u8 *arg0 = (u8 *)this;
    f32 temp_f0;

    if (test_flags_any(arg0 + 0x2C, 2) != 0) {
        ((FlagWord *)(arg0 + 0x2C))->clear(2);
    }
    ((FlagWord *)(arg0 + 0x2C))->set(1);
    if (lbl_805D7E4C != farg0) {
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) ((lbl_805D7E54 - *(f32 *)&this->m_1c) / farg0);
        temp_f0 = (lbl_805D7E54 - *(f32 *)&this->m_20) / farg0;
        *(f32 *)((s8 *)arg0 + 0x3C) = temp_f0;
        *(f32 *)((s8 *)arg0 + 0x40) = temp_f0;
        *(f32 *)((s8 *)arg0 + 0x44) = temp_f0;
    }
}
