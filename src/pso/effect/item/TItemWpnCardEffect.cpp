#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma readonly_strings on
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/weapon/TUnk_804EDC28.h"
#include "pso/player/TUnk_804EDD20.h"
#include "pso/item/TUnk_804EDD44.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemWpnCardEffect.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/vector.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/player/TObjPlayer_8032E4C8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_803D96A8.h"

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

TItem *create_guardianna(u8 *item);

const char *item_wpn_card_effect_class_name = "TItemWpnCardEffect";

extern "C" {
s32 rotate_matrix_y(int, int);
s32 scale_current_matrix(int);
s32 post_translate_matrix(int);
void draw_ginja_object(void *child);
extern RecoveredGlobal_8032DC94_lbl_8050BEC0 saved_model_draw_color;
extern RecoveredGlobal_8032DC94_lbl_8058D4C0 model_material_color;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
s16 get_validated_attack_stage(u8 *arg0);


typedef struct RecoveredGlobal_8032DC94_lbl_8050BEC0 RecoveredGlobal_8032DC94_lbl_8050BEC0;
typedef struct RecoveredGlobal_8032DC94_lbl_8058D4C0 RecoveredGlobal_8032DC94_lbl_8058D4C0;
LAYOUT_ASSERT(RecoveredGlobal_8032DC94_lbl_8050BEC0_size, (sizeof(RecoveredGlobal_8032DC94_lbl_8050BEC0)) == 0x20);
LAYOUT_ASSERT(RecoveredGlobal_8032DC94_lbl_8058D4C0_size, (sizeof(RecoveredGlobal_8032DC94_lbl_8058D4C0)) == 0x10);

#pragma push
#pragma opt_common_subs off
#pragma pop


TParticleCtrl *create_particle_emitter(const void *pos, s32 id);
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);

void *find_entity_by_id(u16 id);


#pragma push
#pragma fp_contract on
#pragma pop

#pragma push
#pragma fp_contract on
#pragma pop


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

f32 atan2_float(f32, f32);
#pragma fp_contract on
s16 get_entity_id(void *);
}


TUnk_804EDD44::TUnk_804EDD44(TObject *parent, ActorBodyHit *hit, f32 *direction, s32 tint, s32 item_id) : TObject(parent) {
    ((Eff_8032E34C *)this)->f34 = get_entity_id(hit->target);
    ((Eff_8032E34C *)this)->f60 = item_id;
    copy_actor_body_hit(&hit_target, hit);
    VecCopy((Vec *)(((Eff_8032E34C *)this)->f38), (const Vec *)direction);
    VecCopy((Vec *)(((Eff_8032E34C *)this)->f64), (const Vec *)&hit->target->bodies[hit->body].center);
    ((Eff_8032E34C *)this)->f58 = (65536.0 / (2.0 * 3.141592f)) * atan2_float(direction[0], direction[2]);
    ((Eff_8032E34C *)this)->f50 = tint;
    this->sub_8032E294();
}

TUnk_804EDD44::TUnk_804EDD44(TObject *parent, f32 *arg2, f32 *arg3, s32 arg4, s32 arg5) : TObject(parent) {
    hit_target.target = NULL;
    hit_target.body = 0;
    ((Eff_8032E34C *)this)->f34 = 0xFFFF;
    ((Eff_8032E34C *)this)->f60 = arg5;
    VecCopy((Vec *)(((Eff_8032E34C *)this)->f38), (const Vec *)arg3);
    VecCopy((Vec *)(((Eff_8032E34C *)this)->f64), (const Vec *)arg2);
    ((Eff_8032E34C *)this)->f58 = (s32)((65536.0 / (2.0 * 3.141592f)) * atan2_float(arg3[0], arg3[2]));
    ((Eff_8032E34C *)this)->f50 = arg4;
    this->sub_8032E294();
}


void TUnk_804EDD44::sub_8032E294() {
  f32 var_f0;
  f32 var_f1;
  const char *var_r4;
  u8 *var_r31;
  s32 *new_var;
  u8 *var_r3;
  var_r31 = (u8 *) this;
  new_var = &(*((s32 *) (((s8 *) var_r31) + 0x2C)));
  var_r4 = item_wpn_card_effect_class_name;
  m_name = var_r4;
  var_r3 = (var_r31 + 0x38);
  *((s32 *) (((s8 *) var_r31) + 0x30)) = 0;
  *((s32 *) (((s8 *) var_r31) + 0x1C)) = 0;
  *((s32 *) (((s8 *) var_r31) + 0x20)) = 0;
  *((s32 *) (((s8 *) var_r31) + 0x24)) = 0;
  *((s32 *) (((s8 *) var_r31) + 0x54)) = 0;
  *((s32 *) (((s8 *) var_r31) + 0x5C)) = 0;
  normalize_vector((Vec *)var_r3);
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

TUnk_804EDD44::~TUnk_804EDD44() {
    destroy_effect_objects();
}


void TUnk_804EDD44::run_task() {
    s32 i;
    u8 *arg0 = (u8 *)this;
    TItem *card = (TItem *)find_item_by_id(((TUnk_804EDD44 *)arg0)->m_60);
    if (card == NULL) {
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    if (card->get_mode() != 2) {
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    ((TUnk_804EDD44 *)arg0)->anchor_card_effect();
    for (i = 0; i != 3; i++) {
        if (particles[i] != NULL) {
            ((TParticleCtrl *)particles[i])->set_position((u8 *)&this->unk_64);
        }
    }
    if (*(s32 *)((s8 *)arg0 + 0x30) == 0) {
        ((TUnk_804EDD44 *)arg0)->start_card_effect_flash();
    } else if (*(s32 *)((s8 *)arg0 + 0x30) == 6) {
        ((TUnk_804EDD44 *)arg0)->destroy_effect_objects();
        ((TUnk_804EDD44 *)arg0)->start_card_effect_trail();
    } else if (*(s32 *)((s8 *)arg0 + 0x30) == 12) {
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    ((TUnk_804EDD44 *)arg0)->vfunc_8();
    (*(s32 *)((s8 *)arg0 + 0x30))++;
}
#pragma push
#pragma fp_contract on
void TUnk_804EDD44::start_card_effect_flash() {
    u8 *arg0 = (u8 *)this;
    uaddr p;
    u32 q;
    *(uaddr *)((s8 *)arg0 + 0x1C) = (uaddr)spawn_particle_effect_with_rotation(((u8 *)&this->unk_64), ((u8 *)&this->unk_54), 0x1B9, 0x104);
    p = *(u32 *)((s8 *)arg0 + 0x1C);
    if (p != 0U) {
        ((TParticleCtrl *)p)->set_scale(1.5f, 1.5f);
        q = this->m_50;
        if (q != 0U) {
            ((TParticleCtrl *)(*(uaddr *)((s8 *)arg0 + 0x1C)))->set_tint_color(q);
        }
    }
    spawn_particle_effect((const Vec *)&this->unk_64, 0x30);
}
#pragma pop
#pragma push
#pragma fp_contract on
void TUnk_804EDD44::start_card_effect_trail() {
    particles[2] = create_particle_emitter(((u8 *)&this->unk_64), 0x1B6);
    if ((uaddr) particles[2] != 0U) {
        ((TParticleCtrl *)(particles[2]))->set_tint_color(-0x78);
    }
}
#pragma pop
void TUnk_804EDD44::vfunc_8() {  }
void TUnk_804EDD44::destroy_effect_objects() {
    s32 i;
    for (i = 0; i != 3; i++) {
        if (particles[i] != 0) {
            ((TObject *)particles[i])->queue_destruction();
            particles[i] = 0;
        }
    }
}
void TUnk_804EDD44::anchor_card_effect() {
  u16 temp_r3;
  u8 *temp_r3_2;
  temp_r3 = this->m_34;
  if (temp_r3 != ((-1U) & 0xFFFFu))
  {
    if (find_entity_by_id(temp_r3) != 0)
    {
      temp_r3_2 = (u8 *)&hit_target.target->bodies[hit_target.body];
      *((f32 *) (((s8 *) ((u8 *)this)) + 0x64)) = (f32) ((*((f32 *) (((s8 *) temp_r3_2) + 0x1C))) - (this->m_44));
      this->m_68 = (f32) ((*((f32 *) (((s8 *) temp_r3_2) + 0x20))) - (*((f32 *) (((s8 *) ((u8 *)this)) + 0x48))));
      *((f32 *) (((s8 *) ((u8 *)this)) + 0x6C)) = (f32) ((*((f32 *) (((s8 *) temp_r3_2) + 0x24))) - (this->m_4c));
    }
  }
}
void TObjPlayer::create_and_init_effect(s32 item_id, u32 *arg1, saddr direction) {
    if ((arg1 != NULL) && ((u32) *arg1 != 0U)) {
        new TUnk_804EDD20(tl_05, (ActorBodyHit *)arg1, (f32 *)direction, 0, item_id);
    }
}
void TObjPlayer::alloc_and_init(s32 item_id, saddr arg1, saddr direction) {
    new TUnk_804EDD20(tl_05, (f32 *)arg1, (f32 *)direction, 0, item_id);
}
TUnk_804EDD20::TUnk_804EDD20(TObject *parent, ActorBodyHit *hit, f32 *direction, s32 tint, s32 item_id)
    : TUnk_804EDD44(parent, hit, direction, tint, item_id) {
    init_offset_vectors();
}
TUnk_804EDD20::TUnk_804EDD20(TObject *parent, f32 *position, f32 *direction, s32 tint, s32 item_id)
    : TUnk_804EDD44(parent, position, direction, tint, item_id) {
    init_offset_vectors();
}
void TUnk_804EDD20::init_offset_vectors() { (*(int *)&(*(u32 *)((u8 *)this + 0x70))) = 0; *(float *)&(this->m_74) = 4.0f; (*(float *)&(*(u32 *)((u8 *)this + 0x78))) = 4.0f; *(float *)&(this->m_7c) = 4.0f; (this->m_80) = (-1.0f); *(float *)&(*(s32 *)((u8 *)this + 0x84)) = 0.0f; (*(float *)&(this->m_88)) = 0.0f; *(float*)((char*)this + 0x8c) = 0.0f; }
void TUnk_804EDD20::start_card_effect_flash() { *(u32*)((char*)this + 0x70) |= 0x1; }
void TUnk_804EDD20::start_card_effect_trail() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x70) = (s32) (*(s32 *)((s8 *)arg0 + 0x70) & 0xFFFFFFFE);
}
#pragma push
#pragma opt_common_subs off
void TUnk_804EDD20::vfunc_8() {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x70) & 1) {
        this->m_80 += 0.25f;
        if (this->m_80 > 0.0f) {
            this->m_80 = 0.0f;
        }
    } else {
        this->m_80 = (f32) (this->m_80 - 0.25f);
        if (this->m_80 < (-1.0f)) {
            this->m_80 = -1.0f;
        }
    }
}
#pragma pop
void TUnk_804EDD20::render() {
  s32 *var_r30;
  s32 *equipped_item;
  s32 *id;
  s32 *var_r4;
  s32 *new_var;
  f32 var_f0;
  u8 *var_r29;
  var_f0 = (-1.0f);
  var_r29 = (u8 *) this;
  if ((!((this->m_80) <= var_f0)) && ((s32)this->all_parents_unqueued_for_destruction() != 0))
  {
    id = (s32 *) (*((s32 **) (((s8 *) var_r29) + 0x60)));
    equipped_item = (s32 *) find_equipped_item((saddr)id);
    if (equipped_item != 0)
    {
      new_var = (s32 *) (*((s32 **) (((s8 *) equipped_item) + 0x188)));
      var_r30 = new_var;
      if (var_r30 != 0)
      {
        id = &saved_model_draw_color.value;
        var_r4 = &model_material_color.value;
        saved_model_render_flags = model_render_flags;
        id = &saved_model_draw_color.value;
        var_r4 = &model_material_color.value;
        copy_argb((NJS_ARGB *)&saved_model_draw_color.value, (NJS_ARGB *)&model_material_color.value);
        id = (s32 *)(var_r29 + 0x80);
        model_render_flags |= 0x20;
        set_constant_material((const NJS_ARGB *)id);
        id = (s32 *) equipped_item;
        set_texlist(((TObjBase *)id)->get_texlist());
        push_matrix();
        id = (s32 *)(var_r29 + 0x64);
        post_translate_matrix((int) id);
        var_r4 = (s32 *) (*((s32 **) (((s8 *) var_r29) + 0x58)));
        id = (s32 *) ((u8 *) 0);
        rotate_matrix_y(0, (int) var_r4);
        id = (s32 *)(var_r29 + 0x74);
        scale_current_matrix((int) id);
        id = (s32 *) var_r30;
        draw_ginja_object(id);
        pop_matrix();
        id = &model_material_color.value;
        var_r4 = &saved_model_draw_color.value;
        id = &model_material_color.value;
        var_r4 = &saved_model_draw_color.value;
        copy_argb((NJS_ARGB *)&model_material_color.value, (NJS_ARGB *)&saved_model_draw_color.value);
        model_render_flags = saved_model_render_flags;
      }
    }
  }
}

TUnk_804EDD20::~TUnk_804EDD20() {}

TUnk_804EDC28::~TUnk_804EDC28() {}

TItem *create_guardianna(u8 *item) {
    if (item != NULL) {
        return new TUnk_804EDC28(tl_05, item);
    }
    return NULL;
}


TUnk_804EDC28::TUnk_804EDC28(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
}
void TUnk_804EDC28::emit_marker_effects() {
    s32 sp8;

    this->get_joint_position(4, &sp8);
    if (get_validated_attack_stage((u8 *)(*(saddr *)&(*(NJS_MOTION_LINK *)((u8 *)this + 0xE4)).frame[1] + 0x7CC)) == 2) {
        this->fire_shot_at_target(&sp8, (void *)*(s32 *)&(*(s16 *)((u8 *)this + 0xF4)), 0);
        this->fire_shot_at_target(&sp8, (void *)*(s32 *)&(*(s16 *)((u8 *)this + 0xF4)), 0x1555);
        this->fire_shot_at_target(&sp8, (void *)*(s32 *)&(*(s16 *)((u8 *)this + 0xF4)), -0x1555);
    } else {
        this->fire_shot_at_target(&sp8, (void *)*(s32 *)&(*(s16 *)((u8 *)this + 0xF4)), 0);
    }
    if (this->get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effect((TItem*)this, 4);
    }
}
void TUnk_804EDC28::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    desc->particle = 0x176;
    desc->hit_effect = (void *)TObjPlayer::start_guardianna_hit_card;
    desc->wall_effect = (void *)start_guardianna_wall_card;
}
