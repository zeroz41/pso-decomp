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
#include "pso/system/BmlResourceDescriptor.h"
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
extern RecoveredGlobal_8001B8AC___vt__15TAdRicoRingCtrl __vt__15TAdRicoRingCtrl;
extern s32 tl_04;
void TAdRicoRingCtrl__sub_8001B4A0(Obj_8001B4A0 *self, f32 x);
s32 test_flags_any(void *, int);
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
u32 __cvt_fp2unsigned(f32);

typedef char RecoveredGlobal_8001B8AC___vt__15TAdRicoRingCtrl_size[sizeof(RecoveredGlobal_8001B8AC___vt__15TAdRicoRingCtrl) == 0x18 ? 1 : -1];
struct RecoveredGlobal_8001BD0C___vt__11TAdRicoRing { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8001BD0C___vt__11TAdRicoRing_size[sizeof(RecoveredGlobal_8001BD0C___vt__11TAdRicoRing) == 0x18 ? 1 : -1];

s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
extern RecoveredGlobal_8001BD0C___vt__11TAdRicoRing __vt__11TAdRicoRing;
int post_translate_matrix(void*);
int push_matrix(void*);
int push_matrix(void*);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void free_bin_model_request(void*, int);
void *__nw__7TObjectFUl(int);
}

// inferred: the vertex list draw_tri_fan_2d reads (cf. VtxList_80077BC0)
struct RicoRingFan { f32 *positions; u32 *colors; s32 n; s32 count; };

// inferred: the quad draw_tri_fan_3d reads (cf. ZanzoQuad)
struct RicoRingQuad { Vec *positions; u32 *colors; void *uvs; s32 count; };

const char *rico_ring_model_names[2] = { "rico_ring.nj", NULL };
const char *rico_ring_motion_names[2] = { "rico_ring.njm", NULL };
BmlResourceDescriptor TAdRicoRingCtrl__resource_descriptor = {
    "rico_ring.bml", rico_ring_model_names, rico_ring_motion_names, 1, 1,
};
// inferred: vertex colours, corners and quad of the ring sprite TAdRicoRingCtrl::render draws in 3D
u32 rico_ring_quad_colors[4] = { 0xB0, 0xB0, 0xB0, 0xB0 };
Vec rico_ring_quad_vertices[4] = { 0.0f };
RicoRingQuad rico_ring_quad = { rico_ring_quad_vertices, rico_ring_quad_colors, NULL, 4 };
// inferred: the screen rectangle and colours of the fade TAdRicoRingCtrl::render draws in 2D
f32 rico_ring_fade_positions[8] = { 350.0f, 0.0f, 640.0f, 0.0f, 640.0f, 600.0f, 350.0f, 600.0f };
u32 rico_ring_fade_colors[4];

const char *TAdRicoRing__class_name = "TAdRicoRing";
const char *TAdRicoRingCtrl__class_name = "TAdRicoRingCtrl";

void TAdRicoRingCtrl__sub_8001BED0(void* p, f32 v) { *(f32*)((char*)p + 0x34) = v; }

void TAdRicoRingCtrl::load_static_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &TAdRicoRingCtrl__resource_descriptor, 0, 0, 0));
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
    *(f32 *)((s8 *)arg0 + 0x28) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x24) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x20) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x1C) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x44) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x40) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x3C) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x38) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x60) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x5C) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x58) = 0.0f;
    *(s32 *)((s8 *)arg0 + 0x6C) = 0;
    *(s32 *)((s8 *)arg0 + 0x68) = 0;
    *(s32 *)((s8 *)arg0 + 0x64) = 0;
    *(f32 *)((s8 *)arg0 + 0x34) = 0.0f;
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
    if ((*((f32 *) (((s8 *) arg0) + 0x1C))) <= -1.0f)
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
      *((f32 *) (((s8 *) arg0) + 0x28)) = 0.0f;
      *((f32 *) (((s8 *) arg0) + 0x24)) = 0.0f;
      *((f32 *) (((s8 *) arg0) + 0x20)) = 0.0f;
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
    if (0.0f != farg0) {
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) ((-1.0f - *(f32 *)&this->m_1c) / farg0);
        temp_f0 = (-1.0f - *(f32 *)&this->m_20) / farg0;
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
    if (0.0f != farg0) {
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) ((*(f32 *)((s8 *)arg0 + 0x34) - *(f32 *)&this->m_1c) / farg0);
        temp_f0 = (*(f32 *)((s8 *)arg0 + 0x34) - *(f32 *)&this->m_20) / farg0;
        *(f32 *)((s8 *)arg0 + 0x3C) = temp_f0;
        *(f32 *)((s8 *)arg0 + 0x40) = temp_f0;
        *(f32 *)((s8 *)arg0 + 0x44) = temp_f0;
    }
}

u8 *TAdRicoRingCtrl__ct(TAdRicoRingCtrl *ad_rico_ring_ctrl, s32 arg1) {
    u32 temp_r3;
    u32 temp_r3_2;
    __ct__7TObjectFP7TObject((void *)ad_rico_ring_ctrl, (void *)arg1);
    *(s32 **)((s8 *)ad_rico_ring_ctrl + 0x18) = &__vt__15TAdRicoRingCtrl.value;
    *(s32 *)((s8 *)ad_rico_ring_ctrl + 0) = (s32) TAdRicoRingCtrl__class_name;
    ad_rico_ring_ctrl->m_1c = create__15TAdRicoRingCtrlFPv(tl_04);
    temp_r3 = ad_rico_ring_ctrl->m_1c;
    if (temp_r3 != 0U) {
        TAdRicoRingCtrl__sub_8001BED0((void *)temp_r3, 0.0f);
        ((TAdRicoRingCtrl *)(ad_rico_ring_ctrl->m_1c))->set_scale4(0.0f);
    }
    ad_rico_ring_ctrl->m_20 = create__15TAdRicoRingCtrlFPv(tl_04);
    temp_r3_2 = ad_rico_ring_ctrl->m_20;
    if (temp_r3_2 != 0U) {
        TAdRicoRingCtrl__sub_8001BED0((void *)temp_r3_2, 0.0f);
        ((TAdRicoRingCtrl *)(ad_rico_ring_ctrl->m_20))->set_scale4(0.0f);
    }
    *(f32 *)((s8 *)ad_rico_ring_ctrl + 0x24) = 1.0f;
    ad_rico_ring_ctrl->m_28 = 0.0f;
    Vec pos = { 1.8f, 0.3f, -5.0f };
    ad_rico_ring_ctrl->sub_8001B424((s32)&pos);
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
    if (temp_f1 < 0.0f) {
        *(f32 *)&this->unk_24 = 0.0f;
        return;
    }
    if (temp_f1 > 1.0f) {
        *(f32 *)&this->unk_24 = 1.0f;
    }
}
#pragma pop

// inferred: the ring's base position the fade corners are laid out from
const f32 rico_ring_base_pos[3] = { 1.8f, 0.3f, -5.0f };

#pragma push
#pragma opt_common_subs off
void TAdRicoRingCtrl::render() {
    f32 t = *(f32 *)&this->unk_24;
    if (t >= 1.0f) {
        return;
    }
    if (lbl_805D4A08 == 0) {
        lbl_805D4A08 = 1;
        lbl_805D4A04 = rico_ring_base_pos[0] - 50.0f;
    }
    if (lbl_805D4A10 == 0) {
        lbl_805D4A10 = 1;
        lbl_805D4A0C = 50.0f + rico_ring_base_pos[0];
    }
    if (lbl_805D4A18 == 0) {
        lbl_805D4A18 = 1;
        lbl_805D4A14 = -8.75f + (rico_ring_base_pos[1] - 1.0f);
    }
    if (lbl_805D4A20 == 0) {
        lbl_805D4A20 = 1;
        lbl_805D4A1C = 0.025f + (rico_ring_base_pos[1] - 1.0f);
    }
    if (lbl_805D4A28 == 0) {
        lbl_805D4A28 = 1;
        lbl_805D4A24 = rico_ring_base_pos[2];
    }
    if (lbl_805D4A30 == 0) {
        lbl_805D4A30 = 1;
        lbl_805D4A2C = 50.0f + rico_ring_base_pos[2];
    }
    if (lbl_805D4A31 == 0) {
        f32 b = lbl_805D4A1C;
        f32 c = lbl_805D4A24;
        f32 d = lbl_805D4A0C;
        f32 a = lbl_805D4A04;
        f32 e = lbl_805D4A14;
        f32 g = lbl_805D4A2C;
        f32 *v = (f32 *)rico_ring_quad_vertices;
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
    ((TObjPlayer *)&rico_ring_quad)->draw_tri_fan_3d(4, 6);
    t = *(f32 *)&this->unk_24;
    if (t > 0.0f) {
        RicoRingFan args = { rico_ring_fade_positions, rico_ring_fade_colors, 0, 4 };
        u32 cnt = __cvt_fp2unsigned(255.0f * t);
        s32 i;
        for (i = 0; i < 4; i++) {
            rico_ring_fade_colors[i] = cnt;
        }
        ((TObjCMHairMenu *)&args)->draw_tri_fan_2d(4, 6, -2.0f);
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
    if (0.0f != x) {
        this->m_28 = -1.0f / x;
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
    f32 t = 2.0f + x;
    if (0.0f != t) {
        self->f28 = 1.0f / t;
    }
}


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
            *(f32 *)((s8 *)temp_r4 + 0x5C) = (f32) -((2.0f * *(f32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)temp_r4 + 0x4C)) + 4)) + 0x14)) - *(f32 *)((s8 *)temp_r4 + 0x5C));
        }
    }
}
#pragma pop
