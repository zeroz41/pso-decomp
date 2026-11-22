#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_801F43B4.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/olgaflow/TBoss6Thanks.h"

#include <stddef.h>
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/olgaflow/TBoss6Thanks_8035D1F4.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/text_8035D2EC.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/unk/text_8035D444.h"
#include "pso/item/TItem.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/object/switch/TOSwitchItem.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/system/MatrixOps.h"


LAYOUT_ASSERT(Thanks_current_motion, offsetof(TBoss6Thanks,current_motion)==0x20);
LAYOUT_ASSERT(Thanks_frame0, offsetof(TBoss6Thanks,frame0)==0x28);
LAYOUT_ASSERT(Thanks_frame1, offsetof(TBoss6Thanks,frame1)==0x2c);
LAYOUT_ASSERT(Thanks_opacity, offsetof(TBoss6Thanks,opacity)==0x30);
LAYOUT_ASSERT(Thanks_model0, offsetof(TBoss6Thanks,model0)==0x38);
LAYOUT_ASSERT(Thanks_model1, offsetof(TBoss6Thanks,model1)==0x3c);
LAYOUT_ASSERT(Thanks_texture0, offsetof(TBoss6Thanks,texture0)==0x40);
LAYOUT_ASSERT(Thanks_texture1, offsetof(TBoss6Thanks,texture1)==0x44);
LAYOUT_ASSERT(Thanks_motions, offsetof(TBoss6Thanks,motions)==0x48);
LAYOUT_ASSERT(Thanks_motion1, offsetof(TBoss6Thanks,motion1)==0x50);
struct ThanksMotionHeader
{
  u32 x0;
  u32 count;
};

extern "C" {

s32 post_translate_matrix(const void *);

}


struct O_8035CCAC { u8 pad[0x54]; s32 arr[4]; };

struct E_8035CC50 { void *p; };

struct W_8035CC50 { u8 pad0[0x54]; E_8035CC50 e[4]; };

struct Ent_8035CB88 { s32 id; s32 lo; s32 hi; };

struct Obj_8035CB88 { u8 pad[0x34]; s32 x30; u8 pad38[0x1C]; void *p[4]; };

const char *TBoss6Thanks__class_name = "TBoss6Thanks";

// Where the object sits: render translates both models there, is_player_near measures the
// players' distance to it and the emitters spawn at it (boss6_thanks_position is an inferred name).
static const Vec boss6_thanks_position = {-10000.0f, 0.0f, -1.7f};

// Item type, group and index that any_player_has_listed_equipment looks for in each slot.
extern const u8 listed_equipment_table[10][3] = {
    {0, 0x2D, 0}, {0, 0x34, 0}, {0, 0x39, 0}, {0, 0x3E, 0}, {0, 0x41, 0},
    {0, 0x44, 0}, {0, 0x4C, 0}, {1, 2, 0x27}, {1, 2, 0x31}, {1, 2, 0x32},
};

// Particle effect id and the m_34 range in which update_particle_emitters keeps each emitter.
static const Ent_8035CB88 boss6_thanks_particle_emitter_table[4] = {
    {141, 0, 50}, {178, 30, 110}, {510, 50, 90}, {450, 70, 120},
};

extern "C" {
void TBoss6Thanks__sub_8035CB40(void);
void TBoss6Thanks__sub_8035CCAC(saddr boss6_thanks);
f32 xyz_distance(const void *, const void *);

s32 fn_8035CAE0(void) {
    return get_story_flag(0x9A) != 0;
}
s32 TBoss6Thanks::check_ship_door() {
    return get_story_flag(0x98) != 0;
}
void TBoss6Thanks__sub_8035CB40(void) { set_story_flag_or_send_quest_flag(154); }
void TBoss6Thanks::dispatch_darkfalz_phase() { set_story_flag_or_send_quest_flag(152); }

void TBoss6Thanks::update_particle_emitters() {
    Obj_8035CB88 *o = (Obj_8035CB88 *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        const Ent_8035CB88 *e = &boss6_thanks_particle_emitter_table[i];
        if (*(s32 *)&this->m_34 >= e->lo && *(s32 *)&this->m_34 <= e->hi) {
            if (o->p[i] == NULL) {
                o->p[i] = create_particle_emitter(&boss6_thanks_position, e->id);
                if (o->p[i] != NULL) {
                    ((TParticleCtrl *)(o->p[i]))->set_flags(0x40);
                }
            }
        } else {
            if (o->p[i] != NULL) {
                TParticleCtrl::release(o->p[i]);
                o->p[i] = NULL;
            }
        }
    }
}

void TBoss6Thanks::destroy_effects() {
    W_8035CC50 *self = (W_8035CC50 *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (self->e[i].p != NULL) {
            TParticleCtrl::release(self->e[i].p);
            self->e[i].p = NULL;
        }
    }
}

void TBoss6Thanks__sub_8035CCAC(saddr boss6_thanks) {
    O_8035CCAC *self = (O_8035CCAC *)boss6_thanks;
    s32 i;
    for (i = 0; i < 4; i++) {
        self->arr[i] = 0;
    }
}

int TBoss6Thanks::is_player_near(void *arg0) {
    s32 i;
    s32 n;
    u8 *p;
    f32 r;
    n = TLobby::get_game_mode();
    r = 30.0f;
    for (i = 0; i < n; i++) {
        p = (u8 *)TObjPlayer::get_player_data(i);
        if (p != NULL && TBoss6PlotFalz::is_active((TObjPlayer *)p) != 0 &&
            xyz_distance(p + 0x38, &boss6_thanks_position) <= r) {
            return 1;
        }
    }
    return 0;
}

}

void TBoss6Thanks::render() {
    TBoss6Thanks *o = this;
    if (0.0f == o->opacity) {
        return;
    }
    TBoss6PlotFalz::set_fade_material_color(o->opacity);
    set_motion_packed_rotation();
    push_matrix();
    post_translate_matrix(&boss6_thanks_position);
    TObjFish::set_global_param((saddr)(o->texture0));
    scale_matrix(0, 1.2f, 1.2f, 1.2f);
    draw_model_motion(o->model0, o->motions[o->current_motion], o->frame0);
    pop_matrix();
    push_matrix();
    post_translate_matrix(&boss6_thanks_position);
    TObjFish::set_global_param((saddr)(o->texture1));
    scale_matrix(0, 1.2f, 1.2f, 1.2f);
    draw_model_motion(o->model1, o->motion1, o->frame1);
    pop_matrix();
    clear_motion_packed_rotation();
    TObjFish::reset_fish_globals();
}


void TBoss6Thanks::update_fade_out() {
    s32 temp_r3;

    if ((s32) this->current_motion != 1) {
        if ((s32) *(s32 *)&this->m_34 == 0) {
            play_sound_effect(0x40033231, 0, 0, 0);
        }
        update_particle_emitters();
        this->opacity = (f32) (0.99f * (1.0f - ((f32) *(s32 *)&this->m_34 / 120.0f)));
        temp_r3 = *(s32 *)&this->m_34;
        if (temp_r3 == 0x78) {
            play_sound_effect(0x40033232, 0, 0, 0);
            queue_destruction();
            return;
        }
        *(s32 *)&this->m_34 = (temp_r3 + 1);
    }
}

void TBoss6Thanks::advance_thanks_state() {
    if ((s32) this->current_motion == 1) {
        this->m_24 = 0;
        this->m_1c = 2;
    }
}

void TBoss6Thanks::mark_done() { if (TBoss6Thanks::is_player_near(this) != 0) { this->m_24 = 1; this->m_1c = 1; } }

typedef struct ThanksMotionHeader ThanksMotionHeader;
typedef struct Thanks_8035CF78 Thanks_8035CF78;
void TBoss6Thanks::run_task() {
  f32 lim;
  s32 *new_var;
  TBoss6Thanks *o = this;
  switch (o->m_1c)
  {
    case 0:
      ((TBoss6Thanks *)o)->mark_done();
      break;
    case 1:
      ((TBoss6Thanks *)o)->advance_thanks_state();
      break;
    case 2:
      ((TBoss6Thanks *)o)->update_fade_out();
      break;
  }
  o->frame0 += 0.6f;
  lim = ((f32) ((ThanksMotionHeader *)o->motions[o->current_motion])->count) - 1.0f;
  if (o->frame0 >= lim)
  {
    o->frame0 -= lim;
    if ((*(new_var = &o->m_24)) != o->current_motion)
    {
      o->current_motion = *new_var;
    }
  }
  o->frame1 += 0.6f;
  lim = ((f32) ((ThanksMotionHeader *)o->motion1)->count) - 1.0f;
  if (o->frame1 >= lim)
  {
    o->frame1 -= lim;
  }
}

TBoss6Thanks::~TBoss6Thanks() {
    TBoss6Thanks__sub_8035CB40();
    ((TBoss6Thanks *)this)->destroy_effects();
}

TBoss6Thanks::TBoss6Thanks(TObject *parent) : TObject(parent) {
    TBoss6Thanks *boss6_thanks = this;
    u8 *fish_count;
    ((TBoss6Thanks *)boss6_thanks)->m_name = TBoss6Thanks__class_name;
    fish_count = (u8 *)TBoss6PlotFalz::get_scene_archive();
    *(saddr *)((s8 *)boss6_thanks + 0x38) = (saddr)get_bml_model((BmlResource *)fish_count, 7);
    boss6_thanks->texture0 = (saddr)get_bml_texlist((BmlResource *)fish_count, 7);
    *(saddr *)((s8 *)boss6_thanks + 0x48) = reinterpret_cast<saddr>(get_bml_motion((BmlResource *)(fish_count), 9));
    *(saddr *)((s8 *)boss6_thanks + 0x4C) = reinterpret_cast<saddr>(get_bml_motion((BmlResource *)(fish_count), 0xB));
    *(saddr *)((s8 *)boss6_thanks + 0x3C) = (saddr)get_bml_model((BmlResource *)fish_count, 9);
    boss6_thanks->texture1 = (saddr)get_bml_texlist((BmlResource *)fish_count, 9);
    *(saddr *)((s8 *)boss6_thanks + 0x50) = reinterpret_cast<saddr>(get_bml_motion((BmlResource *)(fish_count), 0xA));
    TBoss6Thanks__sub_8035CCAC((saddr)((saddr) boss6_thanks));
    boss6_thanks->m_1c = 0;
    boss6_thanks->m_24 = 0;
    boss6_thanks->current_motion = 0;
    boss6_thanks->frame0 = 0.0f;
    boss6_thanks->frame1 = 0.0f;
    boss6_thanks->opacity = 0.99f;
    boss6_thanks->m_34 = 0;
}

extern "C" {

extern void *tl_02;

void *TBoss6Thanks::create() {
    return new TBoss6Thanks((TObject *)tl_02);
}

s32 TBoss6Thanks::is_ship_door_ready() {
    if ((check_ship_door() != 0) && (fn_8035CAE0() == 0)) {
        return 1;
    }
    return 0;
}

s32 TBoss6Thanks__sub_8035D270(void) { return TBoss6Thanks::check_ship_door(); }

s32 TBoss6Thanks::try_dispatch_darkfalz_phase() {
    if (((s32) game_difficulty_selection == 0) || ((get_main_phase() == 0xE) && (is_split_screen() == 0)) || (any_player_has_listed_equipment() == 0)) {
        return 0;
    }
    TBoss6Thanks::dispatch_darkfalz_phase();
    return 1;
}

}

extern "C" {
void get_weapon_color__11TItemWeaponFPv(void *, void *);
}
s32 any_player_has_listed_equipment(void) {
    s32 n = TLobby::get_game_mode();
    s32 i;
    for (i = 0; i < n; i++) {
        void *pl = (void *)TObjPlayer::get_player_data(i);
        if (pl != NULL && TBoss6PlotFalz::is_active((TObjPlayer *)pl) != 0) {
            s32 j;
            for (j = 0; j < 10; j++) {
                const u8 *e = listed_equipment_table[j];
                s32 k;
                for (k = 0; k < 13; k++) {
                    void *it = ((TObjPlayer *)pl)->get_equipped_item(k);
                    if (it != NULL && e[0] == ((TItem *)it)->get_item_type() &&
                        e[1] == ((TItem *)it)->get_item_group() &&
                        e[2] == ((TItem *)it)->get_item_index()) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void TUnk_804F1EC8::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    f32 sp8[4];
    desc->flags |= 0x1C;
    get_weapon_color__11TItemWeaponFPv(sp8, this);
    copy_argb(&desc->color, (NJS_ARGB *)sp8);
    desc->model = second_model;
    desc->wall_effect = (void *)TObjPlayer::forward_item_effect_callback;
}
