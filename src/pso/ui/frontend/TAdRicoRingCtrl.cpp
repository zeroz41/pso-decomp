#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdRicoRingCtrl_8001B4A0.h"
#include "pso/ui/frontend/TAdRicoRingCtrl.h"

#include <stddef.h>
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
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

struct RecoveredGlobal_8001BE80_lbl_804809C0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8001BE80_lbl_804809C0_size[sizeof(RecoveredGlobal_8001BE80_lbl_804809C0) == 0x10 ? 1 : -1];

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
extern const f32 lbl_805D7E58;
extern const f32 lbl_805D7E5C;
extern const f32 lbl_805D7E60;
extern const f32 lbl_805D7E64;
extern const f32 lbl_805D7E68;
s32 TAdRicoRing__resource_bundle;
f32 lbl_805D4A04;
s8 lbl_805D4A08;
f32 lbl_805D4A0C;
s8 lbl_805D4A10;
f32 lbl_805D4A14;
s8 lbl_805D4A18;
f32 lbl_805D4A1C;
s8 lbl_805D4A20;
f32 lbl_805D4A24;
s8 lbl_805D4A28;
f32 lbl_805D4A2C;
s8 lbl_805D4A30;
s8 lbl_805D4A31;
extern const f32 lbl_80434828[];
extern const u32 rico_ring_render_params[];
extern char lbl_804809E0[];
extern char lbl_80480A10[];
extern u32 lbl_804FE138[];
u32 __cvt_fp2unsigned(f32);

typedef char RecoveredGlobal_8001B8AC_lbl_8043481C_size[sizeof(RecoveredGlobal_8001B8AC_lbl_8043481C) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8001B8AC___vt__15TAdRicoRingCtrl_size[sizeof(RecoveredGlobal_8001B8AC___vt__15TAdRicoRingCtrl) == 0x18 ? 1 : -1];
struct RecoveredGlobal_8001BD0C___vt__11TAdRicoRing { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8001BD0C___vt__11TAdRicoRing_size[sizeof(RecoveredGlobal_8001BD0C___vt__11TAdRicoRing) == 0x18 ? 1 : -1];

s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
extern RecoveredGlobal_8001BD0C___vt__11TAdRicoRing __vt__11TAdRicoRing;
extern s32 TAdRicoRing__class_name;
int post_translate_matrix(void*);
int push_matrix(void*);
int push_matrix(void*);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8001BE80_lbl_804809C0 TAdRicoRingCtrl__resource_descriptor;
void free_bin_model_request(void*, int);
void *__nw__7TObjectFUl(int);
}

void TAdRicoRingCtrl__sub_8001BED0(void* p, f32 v) { *(f32*)((char*)p + 0x34) = v; }

void TAdRicoRingCtrl::load_static_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &TAdRicoRingCtrl__resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TAdRicoRing__resource_bundle) = var_r0;
}

void TAdRicoRingCtrl::release_global_805D4A00() {
    if ((u32) TAdRicoRing__resource_bundle != 0U) {
        free_bin_model_request((void*)TAdRicoRing__resource_bundle, 1);
        TAdRicoRing__resource_bundle = 0U;
    }
}

void *TAdRicoRingCtrl::create(void *parent) {
    void *o = __nw__7TObjectFUl(0x70);
    if (o != NULL) {
        o = __ct__11TAdRicoRingFv((u8 *)o, parent);
    }
    return o;
}

u8 *__ct__11TAdRicoRingFv(u8 *arg0, void *parent) {
    __ct__7TObjectFP7TObject(arg0, parent);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__11TAdRicoRing.value;
    __ct__8FlagWordFv((arg0 + 0x2C));
    *(s32 *)((s8 *)arg0 + 0) = (s32) TAdRicoRing__class_name;
    *(s32 *)((s8 *)arg0 + 0x4C) = get_bml_model((void *)TAdRicoRing__resource_bundle, 0);
    *(s32 *)((s8 *)arg0 + 0x50) = TObjFish__sub_8001EDB0((void *)TAdRicoRing__resource_bundle, 0);
    *(f32 *)((s8 *)arg0 + 0x28) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x24) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x20) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x1C) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x44) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x40) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x60) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x5C) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x58) = (f32) lbl_805D7E4C;
    *(s32 *)((s8 *)arg0 + 0x6C) = 0;
    *(s32 *)((s8 *)arg0 + 0x68) = 0;
    *(s32 *)((s8 *)arg0 + 0x64) = 0;
    *(f32 *)((s8 *)arg0 + 0x34) = (f32) lbl_805D7E4C;
    *(s32 *)((s8 *)arg0 + 0x30) = 0x5B0;
    ((FlagWord *)(arg0 + 0x2C))->set((s32)(4U));
    switch (TKeyBoardControl__sub_8000F828()) {
    case 0:
        *(s32 *)((s8 *)arg0 + 0x48) = 0x12;
        break;
    case 1:
        *(s32 *)((s8 *)arg0 + 0x48) = 0x15;
        break;
    }
    return arg0;
}

TAdRicoRing::~TAdRicoRing() {}
void TAdRicoRing::run_task() {
    u8 *arg0 = (u8 *)this;
  f32 temp_f1;
  if (test_flags_any(arg0 + 0x2C, 1) != 0)
  {
    update_position();
    if ((*((f32 *) (((s8 *) arg0) + 0x1C))) <= lbl_805D7E54)
    {
      ((TObject *)arg0)->queue_destruction();
      return;
    }
  }
  if (test_flags_any(arg0 + 0x2C, 2) != 0)
  {
    update_position();
    temp_f1 = *((f32 *) (((s8 *) arg0) + 0x34));
    if (temp_f1 <= (*((f32 *) (((s8 *) arg0) + 0x1C))))
    {
      *((f32 *) (((s8 *) arg0) + 0x1C)) = temp_f1;
      *((f32 *) (((s8 *) arg0) + 0x28)) = (f32) lbl_805D7E4C;
      *((f32 *) (((s8 *) arg0) + 0x24)) = (f32) lbl_805D7E4C;
      *((f32 *) (((s8 *) arg0) + 0x20)) = (f32) lbl_805D7E4C;
      ((FlagWord *)(arg0 + 0x2C))->clear(2);
    }
  }
  *((s32 *) (((s8 *) arg0) + 0x68)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x68))) + (*((s32 *) (((s8 *) arg0) + 0x30))));
  if (test_flags_any(arg0 + 0x2C, 4) != 0)
  {
    *((s32 *) (((s8 *) arg0) + 0x30)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x30))) + (*((s32 *) (((s8 *) arg0) + 0x48))));
    if (((s32) (*((s32 *) (((s8 *) arg0) + 0x30)))) >= 0xCCC)
    {
      ((FlagWord *)(arg0 + 0x2C))->clear(4);
    }
  }
  else
  {
    *((s32 *) (((s8 *) arg0) + 0x30)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x30))) - (*((s32 *) (((s8 *) arg0) + 0x48))));
    if (((s32) (*((s32 *) (((s8 *) arg0) + 0x30)))) <= 0x5B0)
    {
      ((FlagWord *)(arg0 + 0x2C))->set(4);
    }
  }
}

void TAdRicoRing::update_position() {
    *(f32 *)((s8 *)this + 0x1C) = (f32) (*(f32 *)((s8 *)this + 0x1C) + *(f32 *)((s8 *)this + 0x38));
    *(f32 *)((s8 *)this + 0x20) = (f32) (*(f32 *)((s8 *)this + 0x20) + *(f32 *)((s8 *)this + 0x3C));
    *(f32 *)((s8 *)this + 0x24) = (f32) *(f32 *)((s8 *)this + 0x20);
    *(f32 *)((s8 *)this + 0x28) = (f32) *(f32 *)((s8 *)this + 0x20);
}

void TAdRicoRingCtrl::set_scale4(f32 farg0) {
    *(f32 *)&this->m_1c = farg0;
    *(f32 *)&this->m_20 = farg0;
    *(f32 *)&this->unk_24 = farg0;
    this->m_28 = farg0;
}

void TAdRicoRing::render() { push_matrix(this); TObjFish::set_global_param((s32)(*(void**)((char*)this + 0x50))); post_translate_matrix((char*)this + 0x58); rotate_matrix_zyx((void*)0, (s32)(*(void**)((char*)this + 0x64)), (s32)(*(void**)((char*)this + 0x68)), (s32)(*(void**)((char*)this + 0x6c))); set_chunk_render_flags((s32)((void*)1)); draw_chunk_object((void *)(*(void**)((char*)this + 0x4c))); set_chunk_render_flags((s32)((void*)2)); draw_chunk_object((void *)(*(void**)((char*)this + 0x4c))); clear_chunk_render_flags(); pop_matrix(); }

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

TAdRicoRingCtrl::~TAdRicoRingCtrl() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (((Obj_8001B824 *)this)->slot[i] != 0) {
            ((TObject *)(((Obj_8001B824 *)this)->slot[i]))->queue_destruction();
        }
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

#pragma push
#pragma opt_common_subs off
void TAdRicoRingCtrl::render() {
    f32 t = *(f32 *)&this->unk_24;
    if (t >= TAdRicoRingCtrl__data_805D7E50) {
        return;
    }
    if (lbl_805D4A08 == 0) {
        lbl_805D4A08 = 1;
        lbl_805D4A04 = lbl_80434828[0] - lbl_805D7E58;
    }
    if (lbl_805D4A10 == 0) {
        lbl_805D4A10 = 1;
        lbl_805D4A0C = lbl_805D7E58 + lbl_80434828[0];
    }
    if (lbl_805D4A18 == 0) {
        lbl_805D4A18 = 1;
        lbl_805D4A14 = lbl_805D7E5C + (lbl_80434828[1] - TAdRicoRingCtrl__data_805D7E50);
    }
    if (lbl_805D4A20 == 0) {
        lbl_805D4A20 = 1;
        lbl_805D4A1C = lbl_805D7E60 + (lbl_80434828[1] - TAdRicoRingCtrl__data_805D7E50);
    }
    if (lbl_805D4A28 == 0) {
        lbl_805D4A28 = 1;
        lbl_805D4A24 = lbl_80434828[2];
    }
    if (lbl_805D4A30 == 0) {
        lbl_805D4A30 = 1;
        lbl_805D4A2C = lbl_805D7E58 + lbl_80434828[2];
    }
    if (lbl_805D4A31 == 0) {
        f32 b = lbl_805D4A1C;
        f32 c = lbl_805D4A24;
        f32 d = lbl_805D4A0C;
        f32 a = lbl_805D4A04;
        f32 e = lbl_805D4A14;
        f32 g = lbl_805D4A2C;
        f32 *v = (f32 *)lbl_804809E0;
        v[0] = a;
        v[1] = b;
        v[2] = c;
        v[3] = d;
        v[4] = b;
        v[5] = c;
        v[6] = d;
        v[7] = e;
        v[8] = g;
        v[9] = a;
        v[10] = e;
        v[11] = g;
        lbl_805D4A31 = 1;
    }
    ((TObjPlayer *)lbl_80480A10)->draw_tri_fan_3d(4, 6);
    t = *(f32 *)&this->unk_24;
    if (t > lbl_805D7E4C) {
        u32 args[4];
        args[0] = rico_ring_render_params[0];
        args[1] = rico_ring_render_params[1];
        args[2] = rico_ring_render_params[2];
        args[3] = rico_ring_render_params[3];
        u32 cnt = __cvt_fp2unsigned(lbl_805D7E64 * t);
        s32 i;
        for (i = 0; i < 4; i++) {
            lbl_804FE138[i] = cnt;
        }
        ((TObjCMHairMenu *)args)->draw_tri_fan_2d(4, 6, lbl_805D7E68);
    }
}
#pragma pop

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


extern const f32 lbl_805D7E48;
#pragma push
#pragma fp_contract on
void TAdRicoRingCtrl::sub_8001B424(s32 arg1) {
    u32 temp_r3;
    u8 *temp_r3_2;
    u8 *temp_r4;
    if (arg1 != 0) {
        temp_r3 = this->m_1c;
        if (temp_r3 != 0U) {
            VecCopy((Vec *)(temp_r3 + 0x58), (const Vec *)(arg1));
        }
        temp_r3_2 = (u8 *)this->m_20;
        if (temp_r3_2 != NULL) {
            VecCopy((Vec *)(temp_r3_2 + 0x58), (const Vec *)(arg1));
            temp_r4 = (u8 *)this->m_20;
            *(f32 *)((s8 *)temp_r4 + 0x5C) = (f32) -((lbl_805D7E48 * *(f32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)temp_r4 + 0x4C)) + 4)) + 0x14)) - *(f32 *)((s8 *)temp_r4 + 0x5C));
        }
    }
}
#pragma pop
