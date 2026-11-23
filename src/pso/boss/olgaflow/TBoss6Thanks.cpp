#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlResource.h"
#include "types.h"
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
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"
#include "pso/animation/ActorAnimationState.h"


LAYOUT_ASSERT(Thanks_state, offsetof(TBoss6Thanks,state)==0x1c);
LAYOUT_ASSERT(Thanks_current_motion, offsetof(TBoss6Thanks,current_motion)==0x20);
LAYOUT_ASSERT(Thanks_next_motion, offsetof(TBoss6Thanks,next_motion)==0x24);
LAYOUT_ASSERT(Thanks_frame0, offsetof(TBoss6Thanks,frame0)==0x28);
LAYOUT_ASSERT(Thanks_frame1, offsetof(TBoss6Thanks,frame1)==0x2c);
LAYOUT_ASSERT(Thanks_opacity, offsetof(TBoss6Thanks,opacity)==0x30);
LAYOUT_ASSERT(Thanks_model0, offsetof(TBoss6Thanks,model0)==0x38);
LAYOUT_ASSERT(Thanks_model1, offsetof(TBoss6Thanks,model1)==0x3c);
LAYOUT_ASSERT(Thanks_texture0, offsetof(TBoss6Thanks,texture0)==0x40);
LAYOUT_ASSERT(Thanks_texture1, offsetof(TBoss6Thanks,texture1)==0x44);
LAYOUT_ASSERT(Thanks_motions, offsetof(TBoss6Thanks,motions)==0x48);
LAYOUT_ASSERT(Thanks_motion1, offsetof(TBoss6Thanks,motion1)==0x50);
LAYOUT_ASSERT(Thanks_particle_emitters, offsetof(TBoss6Thanks,particle_emitters)==0x54);

// Particle effect id and the fade_frame range in which update_particle_emitters keeps it.
struct Boss6ThanksEmitter { s32 id; s32 first_frame; s32 last_frame; };

const char *TBoss6Thanks__class_name = "TBoss6Thanks";

// Where the object sits: render translates both models there, is_player_near measures the
// players' distance to it and the emitters spawn at it (boss6_thanks_position is an inferred name).
static const Vec boss6_thanks_position = {-10000.0f, 0.0f, -1.7f};

// Item type, group and index that any_player_has_listed_equipment looks for in each slot.
extern const u8 listed_equipment_table[10][3] = {
    {0, 0x2D, 0}, {0, 0x34, 0}, {0, 0x39, 0}, {0, 0x3E, 0}, {0, 0x41, 0},
    {0, 0x44, 0}, {0, 0x4C, 0}, {1, 2, 0x27}, {1, 2, 0x31}, {1, 2, 0x32},
};

static const Boss6ThanksEmitter boss6_thanks_particle_emitter_table[4] = {
    {141, 0, 50}, {178, 30, 110}, {510, 50, 90}, {450, 70, 120},
};

extern "C" f32 xyz_distance(const void *, const void *);

s32 TBoss6Thanks::is_story_flag_0x9A_set() {
    return get_story_flag(0x9A) != 0;
}
s32 TBoss6Thanks::check_ship_door() {
    return get_story_flag(0x98) != 0;
}
void TBoss6Thanks::set_story_flag_0x9A() { set_story_flag_or_send_quest_flag(154); }
void TBoss6Thanks::dispatch_darkfalz_phase() { set_story_flag_or_send_quest_flag(152); }

void TBoss6Thanks::update_particle_emitters() {
    s32 i;
    for (i = 0; i < 4; i++) {
        const Boss6ThanksEmitter *e = &boss6_thanks_particle_emitter_table[i];
        if (this->fade_frame >= e->first_frame && this->fade_frame <= e->last_frame) {
            if (particle_emitters[i] == NULL) {
                particle_emitters[i] = create_particle_emitter(&boss6_thanks_position, e->id);
                if (particle_emitters[i] != NULL) {
                    particle_emitters[i]->set_flags(0x40);
                }
            }
        } else {
            if (particle_emitters[i] != NULL) {
                TParticleCtrl::release(particle_emitters[i]);
                particle_emitters[i] = NULL;
            }
        }
    }
}

void TBoss6Thanks::destroy_effects() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (particle_emitters[i] != NULL) {
            TParticleCtrl::release(particle_emitters[i]);
            particle_emitters[i] = NULL;
        }
    }
}

void TBoss6Thanks::clear_particle_emitters() {
    s32 i;
    for (i = 0; i < 4; i++) {
        particle_emitters[i] = NULL;
    }
}

int TBoss6Thanks::is_player_near(void *) {
    s32 i;
    s32 n;
    TObjPlayer *p;
    f32 r;
    n = TLobby::get_game_mode();
    r = 30.0f;
    for (i = 0; i < n; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != NULL && TBoss6PlotFalz::is_active(p) != 0 &&
            xyz_distance(&p->position, &boss6_thanks_position) <= r) {
            return 1;
        }
    }
    return 0;
}

void TBoss6Thanks::render() {
    if (0.0f == opacity) {
        return;
    }
    TBoss6PlotFalz::set_fade_material_color(opacity);
    set_motion_packed_rotation();
    push_matrix();
    post_translate_matrix(&boss6_thanks_position.x);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texture0));
    scale_matrix(0, 1.2f, 1.2f, 1.2f);
    draw_model_motion(model0, motions[current_motion], frame0);
    pop_matrix();
    push_matrix();
    post_translate_matrix(&boss6_thanks_position.x);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texture1));
    scale_matrix(0, 1.2f, 1.2f, 1.2f);
    draw_model_motion(model1, motion1, frame1);
    pop_matrix();
    clear_motion_packed_rotation();
    TObjFish::reset_fish_globals();
}


void TBoss6Thanks::update_fade_out() {
    if ((s32) this->current_motion != 1) {
        if (this->fade_frame == 0) {
            play_sound_effect(0x40033231, 0, 0, 0);
        }
        update_particle_emitters();
        this->opacity = (f32) (0.99f * (1.0f - ((f32) this->fade_frame / 120.0f)));
        if (this->fade_frame == 120) {
            play_sound_effect(0x40033232, 0, 0, 0);
            queue_destruction();
            return;
        }
        this->fade_frame = this->fade_frame + 1;
    }
}

void TBoss6Thanks::advance_thanks_state() {
    if ((s32) this->current_motion == 1) {
        this->next_motion = 0;
        this->state = 2;
    }
}

void TBoss6Thanks::mark_done() { if (TBoss6Thanks::is_player_near(this) != 0) { this->next_motion = 1; this->state = 1; } }

void TBoss6Thanks::run_task() {
  f32 lim;
  s32 *new_var;
  switch (state)
  {
    case 0:
      mark_done();
      break;
    case 1:
      advance_thanks_state();
      break;
    case 2:
      update_fade_out();
      break;
  }
  frame0 += 0.6f;
  lim = ((f32) motions[current_motion]->frameCount) - 1.0f;
  if (frame0 >= lim)
  {
    frame0 -= lim;
    if ((*(new_var = &next_motion)) != current_motion)
    {
      current_motion = *new_var;
    }
  }
  frame1 += 0.6f;
  lim = ((f32) motion1->frameCount) - 1.0f;
  if (frame1 >= lim)
  {
    frame1 -= lim;
  }
}

TBoss6Thanks::~TBoss6Thanks() {
    TBoss6Thanks::set_story_flag_0x9A();
    destroy_effects();
}

TBoss6Thanks::TBoss6Thanks(TObject *parent) : TObject(parent) {
    BmlResource *archive;
    m_name = TBoss6Thanks__class_name;
    archive = TBoss6PlotFalz::get_scene_archive();
    model0 = get_bml_model(archive, 7);
    texture0 = get_bml_texlist(archive, 7);
    motions[0] = get_bml_motion(archive, 9);
    motions[1] = get_bml_motion(archive, 0xB);
    model1 = get_bml_model(archive, 9);
    texture1 = get_bml_texlist(archive, 9);
    motion1 = get_bml_motion(archive, 0xA);
    clear_particle_emitters();
    state = 0;
    next_motion = 0;
    current_motion = 0;
    frame0 = 0.0f;
    frame1 = 0.0f;
    opacity = 0.99f;
    fade_frame = 0;
}

void *TBoss6Thanks::create() {
    return new TBoss6Thanks(tl_02);
}

s32 TBoss6Thanks::is_ship_door_ready() {
    if ((check_ship_door() != 0) && (is_story_flag_0x9A_set() == 0)) {
        return 1;
    }
    return 0;
}

extern "C" s32 TBoss6Thanks__sub_8035D270(void) { return TBoss6Thanks::check_ship_door(); }

s32 TBoss6Thanks::try_dispatch_darkfalz_phase() {
    if (((s32) game_difficulty_selection == 0) || ((get_main_phase() == 0xE) && (is_split_screen() == 0)) || (any_player_has_listed_equipment() == 0)) {
        return 0;
    }
    TBoss6Thanks::dispatch_darkfalz_phase();
    return 1;
}

extern "C" {
void get_weapon_color__11TItemWeaponFPv(void *, void *);
}
s32 any_player_has_listed_equipment(void) {
    s32 n = TLobby::get_game_mode();
    s32 i;
    for (i = 0; i < n; i++) {
        TObjPlayer *pl = TObjPlayer::get_player_data(i);
        if (pl != NULL && TBoss6PlotFalz::is_active(pl) != 0) {
            s32 j;
            for (j = 0; j < 10; j++) {
                const u8 *e = listed_equipment_table[j];
                s32 k;
                for (k = 0; k < 13; k++) {
                    TItem *it = pl->get_equipped_item(k);
                    if (it != NULL && e[0] == it->get_item_type() &&
                        e[1] == it->get_item_group() &&
                        e[2] == it->get_item_index()) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void TUnk_804F1EC8::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    f32 color[4];
    desc->flags |= 0x1C;
    get_weapon_color__11TItemWeaponFPv(color, this);
    copy_argb(&desc->color, (NJS_ARGB *)color);
    desc->model = second_model;
    desc->wall_effect = (void *)TObjPlayer::forward_item_effect_callback;
}
