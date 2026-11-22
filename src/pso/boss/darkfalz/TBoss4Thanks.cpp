#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/TObjPlayer_80052374.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "types.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_801F43B4.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/darkfalz/TBoss4Thanks.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TBoss4Type3_800524E8.h"
#include "pso/boss/darkfalz/TBoss4Thanks_8035C8F0.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/text_8035C9E8.h"
#include "pso/item/TItem.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/object/switch/TOSwitchItem.h"
#include "pso/system/MatrixStack.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"


struct O_8035C480 { u8 pad[0x44]; s32 arr[4]; };

struct E_8035C424 { void *p; };

struct W_8035C424 { u8 pad0[0x44]; E_8035C424 e[4]; };

struct Ent_8035C35C { s32 id; s32 lo; s32 hi; };

struct Obj_8035C35C { u8 pad[0x30]; s32 x30; u8 pad34[0x10]; void *p[4]; };

struct Anim_8035C6FC
{
  u8 pad[4];
  u32 frames;
};

struct Thanks_8035C6FC
{
  u8 pad0[0x1C];
  s32 state;
  s32 cur;
  s32 next;
  f32 frame;
  u8 pad2c[0x10];
  Anim_8035C6FC *anim[4];
};

extern "C" {
void TBoss4Thanks__sub_8035C480(saddr arg0);
const char *TBoss4Thanks__class_name = "TBoss4Thanks";
// Position of the emitters and of the proximity check (x, y, z).
extern const f32 boss4_thanks_position[3] = {-9860.0f, 29.0f, -238.9f};
// Equipment any_player_has_listed_item() (text_8035C9E8, this TU's code) looks for: {type, group, index}.
extern const u8 boss4_thanks_listed_item_table[3][3] = {{0x00, 0x9D, 0x00}, {0x00, 0x9E, 0x00}, {0x00, 0x9F, 0x00}};
extern const Ent_8035C35C boss4_thanks_emitter_table[4] = {
    {0x8D, 0x00, 0x32}, {0xA7, 0x1E, 0x6E}, {0x1FD, 0x32, 0x5A}, {0x1C2, 0x46, 0x78},
};
f32 xyz_distance(void *, const void *);
void post_translate_matrix(const f32 *);

s32 fn_8035C2B4(void) {
    return get_story_flag(0x99) != 0;
}
s32 TBoss4Thanks::is_door_0x97_open() {
    return get_story_flag(0x97) != 0;
}
void TBoss4Thanks::dispatch_main_phase_153() { set_story_flag_or_send_quest_flag(153); }
void TBoss4Thanks::dispatch_main_phase() { set_story_flag_or_send_quest_flag(151); }


void TBoss4Thanks::update_particle_emitters() {
    Obj_8035C35C *o = (Obj_8035C35C *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        const Ent_8035C35C *e = &boss4_thanks_emitter_table[i];
        if (this->fade_frame >= e->lo && this->fade_frame <= e->hi) {
            if (o->p[i] == NULL) {
                o->p[i] = create_particle_emitter((void *)boss4_thanks_position, e->id);
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

void TBoss4Thanks::destroy_effects() {
    W_8035C424 *self = (W_8035C424 *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (self->e[i].p != NULL) {
            TParticleCtrl::release(self->e[i].p);
            self->e[i].p = NULL;
        }
    }
}

void TBoss4Thanks__sub_8035C480(saddr arg0) {
    O_8035C480 *self = (O_8035C480 *)arg0;
    s32 i;
    for (i = 0; i < 4; i++) {
        self->arr[i] = 0;
    }
}

int TBoss4Thanks::is_player_nearby(void *arg0) {
    s32 n;
    s32 i;
    f32 lim;
    TObjPlayer *p;
    n = TLobby::get_game_mode();
    lim = 30.0f;
    for (i = 0; i < n; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != NULL && TBoss4Type3__sub_8005254C(get_entity_id(p)) != 0 &&
            xyz_distance(&p->position, boss4_thanks_position) <= lim) {
            return 1;
        }
    }
    return 0;
}

}

void TBoss4Thanks::render() {
  f32 fade;
  int hidden;
  fade = fade_amount;
  fade = fade;
  hidden = 0.0f == fade;
  if (hidden)
  {
    return;
  }
  {
    TObjPlayer__sub_80052390(fade);
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(boss4_thanks_position);
    TObjFish::set_global_param(reinterpret_cast<saddr>(texture_list));
    draw_model_motion(model, motions[current_motion], motion_frame);
    clear_motion_packed_rotation();
    pop_matrix();
    TObjPlayer::sync_player_globals();
  }
}

void TBoss4Thanks::update_fade_out() {
    s32 temp_r3;

    if ((s32) this->current_motion != 1) {
        if ((s32) this->fade_frame == 0) {
            play_sound_effect(0x40033231, 0, 0, 0);
        }
        update_particle_emitters();
        this->fade_amount = (f32) (0.99f * (1.0f - ((f32) this->fade_frame / 120.0f)));
        temp_r3 = this->fade_frame;
        if (temp_r3 == 0x78) {
            play_sound_effect(0x40033232, 0, 0, 0);
            queue_destruction();
            return;
        }
        this->fade_frame = (temp_r3 + 1);
    }
}

void TBoss4Thanks::advance_thanks_state() {
    if ((s32) this->current_motion == 1) {
        this->next_motion = 0;
        this->state = 2;
    }
}

void TBoss4Thanks::mark_done() { if (TBoss4Thanks::is_player_nearby(this) != 0) { this->next_motion = 1; this->state = 1; } }

typedef struct Anim_8035C6FC Anim_8035C6FC;
typedef struct Thanks_8035C6FC Thanks_8035C6FC;
void TBoss4Thanks::run_task() {
  Thanks_8035C6FC *o = (Thanks_8035C6FC *) this;
  f32 len;
  switch (o->state)
  {
    case 0:
      ((TBoss4Thanks *)o)->mark_done();
      break;
    case 1:
      ((TBoss4Thanks *)o)->advance_thanks_state();
      break;
    case 2:
      ((TBoss4Thanks *)o)->update_fade_out();
      break;
  }
  o->frame += 0.6f;
  len = ((f32) o->anim[o->cur]->frames) - 1.0f;
  if (o->frame >= len)
  {
    o->frame -= len;
    if (((Thanks_8035C6FC *) this)->cur != o->next)
    {
      ((Thanks_8035C6FC *) this)->cur = ((Thanks_8035C6FC *) this)->next;
    }
  }
}

TBoss4Thanks::~TBoss4Thanks() {
    TBoss4Thanks::dispatch_main_phase_153();
    ((TBoss4Thanks *)this)->destroy_effects();
}

TBoss4Thanks::TBoss4Thanks(TObject *parent) : TObject(parent) {
    BmlResource *archive;
    *(s32 *)((s8 *)this + 0) = (saddr) TBoss4Thanks__class_name;
    archive = reinterpret_cast<BmlResource *>(TBoss4Uro::get_instance_count());
    this->model = reinterpret_cast<NJS_OBJECT *>(get_bml_model(archive, 1));
    this->texture_list = reinterpret_cast<GinjaTextureList *>(get_bml_texlist(archive, 1));
    motions[0] = get_bml_motion(archive, 0x46);
    motions[1] = get_bml_motion(archive, 0x47);
    TBoss4Thanks__sub_8035C480((saddr)((saddr) ((u8 *)this)));
    this->state = 0;
    this->next_motion = 0;
    this->current_motion = 0;
    this->motion_frame = 0.0f;
    this->fade_amount = 0.99f;
    this->fade_frame = 0;
}

extern "C" {

extern void *tl_02;

void *TBoss4Thanks::create() {
    void *o = (void *)new TBoss4Thanks((TObject *)(u8 *)tl_02);
    return o;
}

s32 TBoss4Thanks::is_door_open_and_ready() {
    if ((is_door_0x97_open() != 0) && (fn_8035C2B4() == 0)) {
        return 1;
    }
    return 0;
}

s32 TBoss4Thanks__sub_8035C96C(void) { return TBoss4Thanks::is_door_0x97_open(); }

extern s32 game_difficulty_selection;

s32 TBoss4Thanks::check_ready() {
    if (((s32) game_difficulty_selection == 0) || ((get_main_phase() == 0xE) && (is_split_screen() == 0)) || (any_player_has_listed_item() == 0)) {
        return 0;
    }
    TBoss4Thanks::dispatch_main_phase();
    return 1;
}

}

s32 any_player_has_listed_item(void) {
    s32 n = TLobby::get_game_mode();
    s32 i;
    for (i = 0; i < n; i++) {
        TObjPlayer *pl = TObjPlayer::get_player_data(i);
        if (pl != NULL && TBoss4Type3__sub_8005254C(get_entity_id(pl)) != 0) {
            s32 j;
            for (j = 0; j < 3; j++) {
                const u8 *e = boss4_thanks_listed_item_table[j];
                s32 k;
                for (k = 0; k < 13; k++) {
                    void *it = pl->get_equipped_item(k);
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
