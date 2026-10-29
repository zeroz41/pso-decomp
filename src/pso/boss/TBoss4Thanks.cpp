#include "types.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_801F43B4.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/TBoss4Thanks.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss4Uro.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"


struct RecoveredGlobal_8035C83C___vt__12TBoss4Thanks { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8035C83C___vt__12TBoss4Thanks_size[sizeof(RecoveredGlobal_8035C83C___vt__12TBoss4Thanks) == 0x18 ? 1 : -1];

struct RecoveredGlobal_8035C7D4___vt__12TBoss4Thanks { s32 value; u8 remaining[0x14]; };

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
s32 get_bml_motion(void *, s32);
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_8035C83C___vt__12TBoss4Thanks __vt__12TBoss4Thanks;
extern s32 TBoss4Thanks__class_name;
u8 *TBoss4Thanks__ct(u8 *arg0, u8 *arg1);
u8 * __dt__7TObjectFv(void *, s16);
void __dl__7TObjectFPv(s32);
u8 *__dt__12TBoss4ThanksFv(u8 *arg0, s16 arg1);
void TBoss4Thanks__sub_8035C480(s32 arg0);
extern u8 TBoss4Thanks__data_80479B40[];
extern Ent_8035C35C boss4_thanks_emitter_table[];
void *get_player_data__10TObjPlayerFi(s32);
s32 get_entity_id(void *);
s32 TBoss4Type3__sub_8005254C(s32);
f32 xyz_distance(void *, void *);
void TObjPlayer__sub_80052390(void);
void push_matrix(void);
void post_translate_matrix(void *);
u8 fn_8035C2B4(void);
s32 play_sound_effect(s32, s32, s32, s32);
int dispatch_by_main_phase__14TBoss4DarkFalzFUs(void*);

u8 fn_8035C2B4(void) {
    return (u8) (get_story_flag(0x99) != 0);
}
u8 TBoss4Thanks::is_door_0x97_open() {
    return (u8) (get_story_flag(0x97) != 0);
}
int TBoss4Thanks::dispatch_main_phase_153() { return dispatch_by_main_phase__14TBoss4DarkFalzFUs((void*)(153)); }
int TBoss4Thanks::dispatch_main_phase() { return dispatch_by_main_phase__14TBoss4DarkFalzFUs((void*)(151)); }


void TBoss4Thanks::update_particle_emitters() {
    Obj_8035C35C *o = (Obj_8035C35C *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        Ent_8035C35C *e = &boss4_thanks_emitter_table[i];
        if (o->x30 >= e->lo && o->x30 <= e->hi) {
            if (o->p[i] == NULL) {
                o->p[i] = create_particle_emitter(TBoss4Thanks__data_80479B40, e->id);
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
    W_8035C424 *arg0 = (W_8035C424 *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (arg0->e[i].p != NULL) {
            TParticleCtrl::release(arg0->e[i].p);
            arg0->e[i].p = NULL;
        }
    }
}

void TBoss4Thanks__sub_8035C480(s32 arg0) {
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
    u8 *p;
    n = TLobby::get_game_mode();
    lim = 30.0f;
    for (i = 0; i < n; i++) {
        p = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (p != NULL && TBoss4Type3__sub_8005254C(get_entity_id(p)) != 0 &&
            xyz_distance(p + 0x38, TBoss4Thanks__data_80479B40) <= lim) {
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
    TObjPlayer__sub_80052390();
    push_matrix();
    TObjPlayer::set_global_flag();
    post_translate_matrix(TBoss4Thanks__data_80479B40);
    TObjFish::set_global_param(texture_list);
    draw_model_motion((void *)model, (void *)motions[current_motion], motion_frame);
    TObjPlayer::clear_global_state();
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
            queue_destruction__7TObjectFv(this);
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

u8 *__dt__12TBoss4ThanksFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8035C7D4___vt__12TBoss4Thanks *)&__vt__12TBoss4Thanks).value;
        TBoss4Thanks::dispatch_main_phase_153();
        ((TBoss4Thanks *)arg0)->destroy_effects();
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

u8 *TBoss4Thanks__ct(u8 *object, u8 *arg1) {
    u8 *instance_count;
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__12TBoss4Thanks.value;
    *(s32 *)((s8 *)object + 0) = (s32) TBoss4Thanks__class_name;
    instance_count = (u8 *)(TBoss4Uro::get_instance_count());
    *(s32 *)((s8 *)object + 0x34) = get_bml_model(instance_count, 1);
    *(s32 *)((s8 *)object + 0x38) = TObjFish__sub_8001EDB0(instance_count, 1);
    *(s32 *)((s8 *)object + 0x3C) = get_bml_motion(instance_count, 0x46);
    *(s32 *)((s8 *)object + 0x40) = get_bml_motion(instance_count, 0x47);
    TBoss4Thanks__sub_8035C480((s32)((s32) object));
    *(s32 *)((s8 *)object + 0x1C) = 0;
    *(s32 *)((s8 *)object + 0x24) = 0;
    *(s32 *)((s8 *)object + 0x20) = 0;
    *(f32 *)((s8 *)object + 0x28) = 0.0f;
    *(f32 *)((s8 *)object + 0x2C) = 0.99f;
    *(s32 *)((s8 *)object + 0x30) = 0;
    return object;
}
