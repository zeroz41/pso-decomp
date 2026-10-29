#include "pso/TParticleCtrl.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/player/TUnk_804EDC28.h"
#include "pso/player/TUnk_804EDD20.h"
#include "pso/item/TUnk_804EDD44.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemWpnCardEffect.h"
#include "pso/misc/TNowLoading.h"
#include "pso/system/vector.h"
#include "pso/item/TItemAttackCol.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8023E480.h"

struct RecoveredGlobal_8032DC94_lbl_8050BEC0
{
  s32 value;
  u8 remaining[0x1C];
};

struct RecoveredGlobal_8032DC94_lbl_8058D4C0
{
  s32 value;
  u8 remaining[0xC];
};

extern "C" {
u8 *__nw__5TItemFUl(s32);
}
extern s32 tl_05;
u8 *create_guardianna(u8 *arg0);

extern "C" {
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 scale_current_matrix(int);
s32 post_translate_matrix(int);
void draw_ginja_object(void *child);
extern RecoveredGlobal_8032DC94_lbl_8050BEC0 saved_model_draw_color;
extern RecoveredGlobal_8032DC94_lbl_8058D4C0 model_material_color;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void *__dt__13TUnk_804EDC28Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804EDD20Fv(void *arg0, s16 arg1);
void __ct__11TItemWeaponFP7TObjectPUc(void *);
s16 get_validated_attack_stage(u8 *arg0);
void __dl__7TObjectFPv(void *);

void TObjPlayer::launch_guardianna_colliders() {
    s32 sp8;

    ((TItemWeapon *)this)->get_joint_position(4, &sp8);
    if (get_validated_attack_stage((u8 *)(*(s32 *)&this->blend.frame[1] + 0x7CC)) == 2) {
        ((TItemWeapon *)this)->fire_shot_at_target(&sp8, (void *)*(s32 *)&this->play_mode, 0);
        ((TItemWeapon *)this)->fire_shot_at_target(&sp8, (void *)*(s32 *)&this->play_mode, 0x1555);
        ((TItemWeapon *)this)->fire_shot_at_target(&sp8, (void *)*(s32 *)&this->play_mode, -0x1555);
    } else {
        ((TItemWeapon *)this)->fire_shot_at_target(&sp8, (void *)*(s32 *)&this->play_mode, 0);
    }
    if (((TItemWeapon *)this)->get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effect((TItem*)this, 4);
    }
}

extern s32 lbl_804EDC28[];

void *TUnk_804EDC28::construct_guardianna(s32 _w1, void *_w2) {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804EDC28;
    set_weapon_flags(2);
    return this;
}
}

extern s32 lbl_804EDD20[];

u8 *create_guardianna(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_804EDC28 *)temp_r3)->construct_guardianna(tl_05, arg0)));
        }
        return var_r0;
    }
    return NULL;
}
extern "C" {

void *__dt__13TUnk_804EDC28Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804EDC28;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
void *__dt__13TUnk_804EDD20Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804EDD20;
        ((TUnk_804EDD44 *)arg0)->destroy(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef struct RecoveredGlobal_8032DC94_lbl_8050BEC0 RecoveredGlobal_8032DC94_lbl_8050BEC0;
typedef struct RecoveredGlobal_8032DC94_lbl_8058D4C0 RecoveredGlobal_8032DC94_lbl_8058D4C0;
typedef char RecoveredGlobal_8032DC94_lbl_8050BEC0_size[((sizeof(RecoveredGlobal_8032DC94_lbl_8050BEC0)) == 0x20) ? (1) : (-1)];
typedef char RecoveredGlobal_8032DC94_lbl_8058D4C0_size[((sizeof(RecoveredGlobal_8032DC94_lbl_8058D4C0)) == 0x10) ? (1) : (-1)];
void TUnk_804EDD20::render() {
  s32 *var_r30;
  s32 *var_r31;
  s32 *var_r3;
  s32 *var_r4;
  s32 *new_var;
  f32 var_f0;
  u8 *var_r29;
  var_f0 = (-1.0f);
  var_r29 = (u8 *) this;
  if ((!((this->m_80) <= var_f0)) && (all_parents_unqueued_for_destruction__7TObjectFv() != 0))
  {
    var_r3 = (s32 *) (*((s32 **) (((s8 *) var_r29) + 0x60)));
    var_r31 = (s32 *) find_equipped_item((s32)var_r3);
    if (var_r31 != 0)
    {
      new_var = (s32 *) (*((s32 **) (((s8 *) var_r31) + 0x188)));
      var_r30 = new_var;
      if (var_r30 != 0)
      {
        var_r3 = &saved_model_draw_color.value;
        var_r4 = &model_material_color.value;
        saved_model_render_flags = model_render_flags;
        var_r3 = &saved_model_draw_color.value;
        var_r4 = &model_material_color.value;
        copy_argb((NJS_ARGB *)&saved_model_draw_color.value, (NJS_ARGB *)&model_material_color.value);
        var_r3 = (s32 *)(var_r29 + 0x80);
        model_render_flags |= 0x20;
        set_constant_material((const NJS_ARGB *)var_r3);
        var_r3 = (s32 *) var_r31;
        set_texlist(((TObjBase *)var_r3)->get_texlist());
        push_matrix();
        var_r3 = (s32 *)(var_r29 + 0x64);
        post_translate_matrix((int) var_r3);
        var_r4 = (s32 *) (*((s32 **) (((s8 *) var_r29) + 0x58)));
        var_r3 = (s32 *) ((u8 *) 0);
        rotate_matrix_y(0, (int) var_r4);
        var_r3 = (s32 *)(var_r29 + 0x74);
        scale_current_matrix((int) var_r3);
        var_r3 = (s32 *) var_r30;
        draw_ginja_object(var_r3);
        pop_matrix();
        var_r3 = &model_material_color.value;
        var_r4 = &saved_model_draw_color.value;
        var_r3 = &model_material_color.value;
        var_r4 = &saved_model_draw_color.value;
        copy_argb((NJS_ARGB *)&model_material_color.value, (NJS_ARGB *)&saved_model_draw_color.value);
        model_render_flags = saved_model_render_flags;
      }
    }
  }
}

#pragma push
#pragma opt_common_subs off
void TUnk_804EDD20::vfunc_8() {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x70) & 1) {
        this->m_80 += 0.25f;
        if (this->m_80 > 0.0f) {
            this->m_80 = (f32) 0.0f;
        }
    } else {
        this->m_80 = (f32) (this->m_80 - 0.25f);
        if (this->m_80 < (-1.0f)) {
            this->m_80 = (f32) (-1.0f);
        }
    }
}
#pragma pop

void TUnk_804EDD20::start_card_effect_trail() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x70) = (s32) (*(s32 *)((s8 *)arg0 + 0x70) & 0xFFFFFFFE);
}

void TUnk_804EDD20::start_card_effect_flash() { *(u32*)((char*)this + 0x70) |= 0x1; }

void TUnk_804EDD20::init_offset_vectors() { (*(int *)&(*(u32 *)((u8 *)this + 0x70))) = 0; *(float *)&(this->m_74) = 4.0f; (*(float *)&(*(u32 *)((u8 *)this + 0x78))) = 4.0f; *(float *)&(this->m_7c) = 4.0f; (this->m_80) = (-1.0f); *(float *)&(*(s32 *)((u8 *)this + 0x84)) = 0.0f; (*(float *)&(this->m_88)) = 0.0f; *(float*)((char*)this + 0x8c) = 0.0f; }

void *init_offsets_object__13TUnk_804EDD20Fv(void *arg0);
void *init_effect_object__13TUnk_804EDD20Fv(void *arg0);
void __ct__13TUnk_804EDD44FP7TObjectPfPfll(void *);
struct Vec_8032E400 { f32 x, y, z; };

struct Rec_8032E400 { u8 pad[0x1C]; Vec_8032E400 pos; u8 pad2[4]; };

struct Owner_8032E400 { u8 pad[0xA4]; Rec_8032E400 *recs; };

struct Ref_8032E400 { Owner_8032E400 *owner; s32 idx; };

struct Obj_8032E400 { u8 pad[0x18]; void *vt; u8 pad1[0xC]; u8 col[0xC]; s16 f34; u8 pad2[2]; Vec_8032E400 pos; u8 pad3[0xC]; s32 f50; u8 pad4[4]; s32 f58; u8 pad5[4]; s32 f60; Vec_8032E400 rpos; };

Obj_8032E400 *construct_card_effect_on_target(Obj_8032E400 *arg0, void *arg1, Ref_8032E400 *arg2, Vec_8032E400 *arg3, s32 arg4, s32 arg5);

void *TUnk_804EDD20::init_offsets_object() {
    __ct__13TUnk_804EDD44FP7TObjectPfPfll(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804EDD20;
    this->init_offset_vectors();
    return this;
}

void *TUnk_804EDD20::init_effect_object() {
    ((void (*)(void *))construct_card_effect_on_target)(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804EDD20;
    this->init_offset_vectors();
    return this;
}

void *__nw__7TObjectFUl(s32);

void TObjPlayer::alloc_and_init(s32 arg0, s32 arg1, s32 arg2) {
    void* obj = __nw__7TObjectFUl(0x90);
    if (obj != 0) {
        ((s32 (*)(void *, s32, s32, s32, s32, s32))init_offsets_object__13TUnk_804EDD20Fv)(obj, tl_05, arg1, arg2, 0, arg0);
    }
}

void TObjPlayer::create_and_init_effect(s32 arg0, u32 *arg1, s32 arg2) {
    void *obj;

    if ((arg1 != NULL) && ((u32) *arg1 != 0U)) {
        obj = __nw__7TObjectFUl(0x90);
        if (obj != NULL) {
            ((s32 (*)(void *, s32, u32 *, s32, s32, s32))init_effect_object__13TUnk_804EDD20Fv)(obj, tl_05, arg1, arg2, 0, arg0);
        }
    }
}
}

struct O_8032DFF8 { u8 pad[0x1C]; void *o[3]; };

extern "C" {
void *create_particle_emitter(void *pos, s32 id);
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
void *spawn_particle_effect(void *pos, s32 id);

void *find_entity_by_id(u16 id);
void queue_destruction__7TObjectFv(void *);
s8 get_mode__5TItemFv();

void TUnk_804EDD44::anchor_card_effect() {
  u16 temp_r3;
  u8 *temp_r3_2;
  temp_r3 = this->m_34;
  if (temp_r3 != ((-1U) & 0xFFFFu))
  {
    if (find_entity_by_id(temp_r3) != 0)
    {
      temp_r3_2 = (u8 *) ((*((s32 *) (((s8 *) (*((u8 **) (((s8 *) ((u8 *)this)) + 0x28)))) + 0xA4))) + ((this->m_2c) * 0x2C));
      *((f32 *) (((s8 *) ((u8 *)this)) + 0x64)) = (f32) ((*((f32 *) (((s8 *) temp_r3_2) + 0x1C))) - (this->m_44));
      this->m_68 = (f32) ((*((f32 *) (((s8 *) temp_r3_2) + 0x20))) - (*((f32 *) (((s8 *) ((u8 *)this)) + 0x48))));
      *((f32 *) (((s8 *) ((u8 *)this)) + 0x6C)) = (f32) ((*((f32 *) (((s8 *) temp_r3_2) + 0x24))) - (this->m_4c));
    }
  }
}

void TObjPlayer::destroy_effect_objects() {
    O_8032DFF8 *arg0 = (O_8032DFF8 *)this;
    s32 i;
    for (i = 0; i != 3; i++) {
        if (arg0->o[i] != 0) {
            queue_destruction__7TObjectFv(arg0->o[i]);
            arg0->o[i] = 0;
        }
    }
}

void TUnk_804EDD44::vfunc_8() {  }
#pragma push
#pragma fp_contract on
void TUnk_804EDD44::start_card_effect_trail() {
    this->m_24 = (u32)create_particle_emitter(((u8 *)&this->unk_64), 0x1B6);
    if ((u32) this->m_24 != 0U) {
        ((TParticleCtrl *)(this->m_24))->set_tint_color(-0x78);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TUnk_804EDD44::start_card_effect_flash() {
    u8 *arg0 = (u8 *)this;
    u32 p;
    u32 q;
    *(u32 *)((s8 *)arg0 + 0x1C) = (u32)spawn_particle_effect_with_rotation(((u8 *)&this->unk_64), ((u8 *)&this->unk_54), 0x1B9, 0x104);
    p = *(u32 *)((s8 *)arg0 + 0x1C);
    if (p != 0U) {
        ((TParticleCtrl *)p)->set_scale(1.5f, 1.5f);
        q = this->m_50;
        if (q != 0U) {
            ((TParticleCtrl *)(*(u32 *)((s8 *)arg0 + 0x1C)))->set_tint_color(q);
        }
    }
    spawn_particle_effect(((u8 *)&this->unk_64), 0x30);
}
#pragma pop

void TUnk_804EDD44::run_task() {
    s32 i;
    u8 *arg0 = (u8 *)this;
    if (find_item_by_id(((TUnk_804EDD44 *)arg0)->m_60) == 0U) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    if (get_mode__5TItemFv() != 2) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    ((TUnk_804EDD44 *)arg0)->anchor_card_effect();
    for (i = 0; i != 3; i++) {
        if (((O_8032DFF8 *)arg0)->o[i] != NULL) {
            ((TParticleCtrl *)((O_8032DFF8 *)arg0)->o[i])->set_position((u8 *)&this->unk_64);
        }
    }
    if (*(s32 *)((s8 *)arg0 + 0x30) == 0) {
        ((TUnk_804EDD44 *)arg0)->start_card_effect_flash();
    } else if (*(s32 *)((s8 *)arg0 + 0x30) == 6) {
        ((TObjPlayer *)arg0)->destroy_effect_objects();
        ((TUnk_804EDD44 *)arg0)->start_card_effect_trail();
    } else if (*(s32 *)((s8 *)arg0 + 0x30) == 12) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    ((TUnk_804EDD44 *)arg0)->vfunc_8();
    (*(s32 *)((s8 *)arg0 + 0x30))++;
}

}

extern "C" {

void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void destroy_effect_objects__10TObjPlayerFv(void *);

extern s32 __vt__13TUnk_804EDD44[];

void *TUnk_804EDD44::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804EDD44;
        destroy_effect_objects__10TObjPlayerFv(this);
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}

struct Eff_8032E34C {
    u8 pad0[0x18];
    void *vt;
    u8 pad1C[0x28 - 0x1C];
    s32 f28;
    s32 f2C;
    u8 pad30[4];
    u16 f34;
    u8 pad36[2];
    u8 f38[0x50 - 0x38];
    s32 f50;
    u8 pad54[4];
    s32 f58;
    u8 pad5C[4];
    s32 f60;
    u8 f64[0xC];
};

extern "C" {
s32 normalize_vector(int, int);
extern s32 item_wpn_card_effect_class_name;

f32 atan2_float(f32, f32);
extern const f64 lbl_804773A8[];
#pragma fp_contract on
void TUnk_804EDD44::sub_8032E294() {
  f32 var_f0;
  f32 var_f1;
  s32 var_r4;
  u8 *var_r31;
  s32 *new_var;
  u8 *var_r3;
  var_r31 = (u8 *) this;
  new_var = &(*((s32 *) (((s8 *) var_r31) + 0x2C)));
  var_r4 = item_wpn_card_effect_class_name;
  *((s32 *) (((s8 *) ((u8 *)this)) + 0)) = var_r4;
  var_r3 = (var_r31 + 0x38);
  *((s32 *) (((s8 *) var_r31) + 0x30)) = 0;
  *((s32 *) (((s8 *) var_r31) + 0x1C)) = 0;
  *((s32 *) (((s8 *) var_r31) + 0x20)) = 0;
  *((s32 *) (((s8 *) var_r31) + 0x24)) = 0;
  *((s32 *) (((s8 *) var_r31) + 0x54)) = 0;
  *((s32 *) (((s8 *) var_r31) + 0x5C)) = 0;
  normalize_vector((int) var_r3, (int) var_r4);
  if (((u16) (*((u16 *) (((s8 *) var_r31) + 0x34)))) != ((-1U) & 0xFFFFu))
  {
    var_r3 = (u8 *) (*((u8 **) (((s8 *) var_r31) + 0x28)));
    var_f0 = *((f32 *) (((s8 *) var_r31) + 0x38));
    var_r3 = (u8 *) (*((u8 **) (((s8 *) var_r3) + 0xA4)));
    var_r3 += (*new_var) * 0x2C;
    var_f1 = *((f32 *) (((s8 *) var_r3) + 0xC));
    var_f0 *= var_f1;
    *((f32 *) (((s8 *) var_r31) + 0x44)) = var_f0;
    var_f0 = *((f32 *) (((s8 *) var_r31) + 0x3C));
    var_f0 *= var_f1;
    *((f32 *) (((s8 *) var_r31) + 0x48)) = var_f0;
    var_f0 = *((f32 *) (((s8 *) var_r31) + 0x40));
    var_f0 *= var_f1;
    *((f32 *) (((s8 *) var_r31) + 0x4C)) = var_f0;
  }
  else
  {
    var_f0 = 0.0f;
    *((f32 *) (((s8 *) var_r31) + 0x44)) = var_f0;
    *((f32 *) (((s8 *) var_r31) + 0x48)) = var_f0;
    *((f32 *) (((s8 *) var_r31) + 0x4C)) = var_f0;
  }
  var_r3 = (u8 *) var_r31;
  ((TUnk_804EDD44 *)var_r3)->anchor_card_effect();
}
}
TUnk_804EDD44::TUnk_804EDD44(TObject *parent, f32 *arg2, f32 *arg3, s32 arg4, s32 arg5) : TObject(parent) {
    ((Eff_8032E34C *)this)->f28 = 0;
    ((Eff_8032E34C *)this)->f2C = 0;
    ((Eff_8032E34C *)this)->f34 = 0xFFFF;
    ((Eff_8032E34C *)this)->f60 = arg5;
    VecCopy((Vec *)(((Eff_8032E34C *)this)->f38), (const Vec *)arg3);
    VecCopy((Vec *)(((Eff_8032E34C *)this)->f64), (const Vec *)arg2);
    ((Eff_8032E34C *)this)->f58 = (s32)(lbl_804773A8[0] * atan2_float(arg3[0], arg3[2]));
    ((Eff_8032E34C *)this)->f50 = arg4;
    this->sub_8032E294();
}

extern "C" {
s16 get_entity_id(void *);
f32 atan2_float(f32, f32);
void __ct__7TObjectFP7TObject(void *, void *);
extern const f64 lbl_804773A8[];

Obj_8032E400 *construct_card_effect_on_target(Obj_8032E400 *arg0, void *arg1, Ref_8032E400 *arg2, Vec_8032E400 *arg3, s32 arg4, s32 arg5) {
    __ct__7TObjectFP7TObject(arg0, arg1);
    arg0->vt = __vt__13TUnk_804EDD44;
    arg0->f34 = get_entity_id(arg2->owner);
    arg0->f60 = arg5;
    ((TItemAttackCol *)(arg0->col))->copy_pos(arg2);
    VecCopy((Vec *)&arg0->pos, (const Vec *)arg3);
    VecCopy((Vec *)&arg0->rpos, (const Vec *)&arg2->owner->recs[arg2->idx].pos);
    arg0->f58 = lbl_804773A8[0] * atan2_float(arg3->x, arg3->z);
    arg0->f50 = arg4;
    ((TUnk_804EDD44 *)arg0)->sub_8032E294();
    return arg0;
}

}
