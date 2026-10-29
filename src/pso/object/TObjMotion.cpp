#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804A7478.h"
#include "pso/misc/TPlyPhotonChair_80142524.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/player/TObjPlayer_80141D1C.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/memory.h"

const char *TObjMotion__class_name = "TObjMotion";

void restore_actor_draw_lighting(s32) {
}

void setup_actor_draw_lighting(void) {
}

void TUnk_804A7478::draw_model() {
    draw_model_motion(get_id(), sub_80143930(), get_float_c());
}

void TUnk_804A7478::update_scale_state() {
    f32 next;
    s32 cur_state;
    cur_state = state;
    next = frame - speed;
    switch (cur_state) {
    case 0:
        if (next < 0.0f) {
            next += frame_count;
        }
        frame = next;
        return;
    case 2:
        if (next <= 0.0f) {
            next = 0.0f;
            activate();
        }
        frame = next;
    case 1:
        return;
    }
}

void TUnk_804A7478::update_bob_motion() {
    f32 count;
    f32 last;
    f32 next;
    s32 cur_state;
    cur_state = state;
    next = frame + speed;
    switch (cur_state) {
    case 0:
        count = frame_count;
        if (next >= count) {
            next -= count;
        }
        frame = next;
        return;
    case 2:
        last = frame_count - 1.0f;
        if (next >= last) {
            next = last;
            activate();
        }
        frame = next;
    case 1:
        return;
    }
}

void TUnk_804A7488::draw_model() {
    draw_chunk_object(get_id());
}

int TLobby__sub_80142944(void *motion) {
    return (((TObjMotion *)motion)->animationFlags >> 4) & 1;
}

#include "types.h"
#include "pso/enemy/TObjEneMe3Stelth.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/player/TObjPlayer.h"

typedef struct Key_80142950
{
  u32 frame;
  f32 f4;
  f32 f8;
  f32 val;
} Key_80142950;

typedef struct Joint_80142950
{
  Key_80142950 *keys;
  s32 f4;
  s32 count;
} Joint_80142950;

typedef struct Motion_80142950
{
  Joint_80142950 *joint;
} Motion_80142950;

typedef struct Actor_80142950
{
  u8 pad0[0x60];
  s32 angle;
  u8 pad64[0xC0 - 0x64];
  f32 time;
  f32 fC4;
  f32 step;
  u8 padCC[0xF8 - 0xCC];
  Motion_80142950 *motion;
} Actor_80142950;

extern "C" {
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);

f32 sample_attack_root_motion(Actor_80142950 *a, f32 *x, f32 *z);
struct E16_80142b8c_80142B08 { u8 a[4]; s32 f4; u8 b[8]; };

struct E8_80142b8c_80142B08  { u8 a[4]; s32 f4; };

struct E1_80142BB4 { s32 a; s32 idx; s32 c; s32 d; };

struct E2_80142BB4 { s32 a; s32 b; };

struct Obj_80142BB4 { u8 pad[0xd8]; E1_80142BB4 *e1; E2_80142BB4 *e2; };

struct GameObj {
    u8 _pad00[0xB0];
    u32 flags;
    u8 _pad_B4[0x4];
    s16 a;
    s16 b;
    u8 _pad_BC[0x4];
    f32 c;
    u8 _pad_C4[0x4];
    f32 d;
};

struct AnimEnt_80143504 { s16 mode; s16 next; u8 pad4[4]; f32 speed; u8 padC[4]; };

struct Anim_80143504 {
    u8 pad0[0xB0];
    s32 flags;
    u8 padB4[4];
    s16 cur;
    s16 req;
    u8 padBC[4];
    f32 frame;
    f32 end;
    f32 speed;
    u8 padCC[4];
    f32 xD0;
    u8 padD4[4];
    AnimEnt_80143504 *tbl;
    u8 padDC[0xF4 - 0xDC];
    s16 mode;
    s16 nextmode;
};

struct A_80142B3C { u32 a0; u32 idx; u32 a8; u32 aC; };

struct R_80142B3C { u32 r0; u32 val; };

struct O_80142B3C { u8 pad[0xD8]; A_80142B3C *tab; struct { u32 x; R_80142B3C *r; } *tab2; };

int set_field_d8__10TObjMotionFl(void*);
f32 get_speed__9TObjCharaFv();
s32 get_anim_entry_value__10TObjMotionFs(Obj_80142BB4 *self, s16 i);
void serialize_node_flags__10TObjPlayerFPv(u8 *arg0);
void apply_animation_transition(void *, s16);
void set_animation__10TObjMotionFs(void *arg0, s16 arg1);
void advance_animation_playback(Anim_80143504 *a);
s32 sub_80143960__10TObjMotionFl(void *, int);
s32 draw_ginja_model_tree__10TObjPlayerFPv(s32, void *, f32);
s32 draw_ginja_model__10TObjPlayerFl(s32, s32, f32);
s32 render_model_tree__12TBoss8DragonFPv(u32, s32, f32);
void set_model_node_callback(s32 arg0);
}
void setup_actor_draw_lighting(void);
void save_joint_matrix_callback(void);
void draw_motion_model_saving_joints(TObjPlayer *arg0);
void get_current_matrix(void *m);
void draw_model_blend_motion(void *arg0, void *arg1, f32 farg0);
extern "C" {
void draw_model_motion(void *arg0, void *arg1, f32 farg0);

extern s32 anim_model_matrix_array;
extern s32 player_joint_matrix_write_ptr;
extern u8 *lbl_805D5684;
extern s32 model_node_callback;
extern s32 chunk_model_node_callback;

typedef struct Actor_80142950 Actor_80142950;
typedef struct Joint_80142950 Joint_80142950;
typedef struct Key_80142950 Key_80142950;
typedef struct Motion_80142950 Motion_80142950;
f32 sample_attack_root_motion(Actor_80142950 *a, f32 *x, f32 *z) {
  f32 t;
  f32 dv;
  f32 t2;
  f32 span;
  f32 d;
  f32 end;
  f32 start;
  Joint_80142950 *j;
  Key_80142950 *k;
  s32 n;
  s32 i;
  j = a->motion->joint;
  t = a->time;
  i = 0;
  k = j->keys;
  n = j->count - 1;
  for (; i < n; i++)
  {
    if (k[1].frame > ((s32) t))
    {
      break;
    }
    k++;
  }
  if (i >= n)
  {
    *x = 0.0f;
    *z = 0.0f;
    return 0.0f;
  }
  t2 = t + a->step;
  span = (f32) (k[1].frame - k->frame);
  dv = k[1].val - k->val;
  t = a->time;
  start = k->val + ((dv * (t - ((f32) k->frame))) / span);
  for (; i < n; i++)
  {
    if (k[1].frame >= ((s32) t2))
    {
      break;
    }
    k++;
  }
  if (i >= n)
  {
    end = k->val;
  }
  else
  {
    span = (f32) (k[1].frame - k->frame);
    dv = k[1].val - k->val;
    end = k->val + ((dv * (t2 - ((f32) k->frame))) / span);
  }
  d = end - start;
  *x = d * sin_table_lookup(a->angle);
  *z = d * cos_table_lookup(a->angle);
  return d;
}

s32 TObjPlayer::is_anim_finished() {
    s32 temp_r4;

    temp_r4 = this->animationFlags;
    if ((!(temp_r4 & 4) || (temp_r4 & 1)) && ((s16) this->m_b8 == (s16) this->m_ba)) {
        return 1;
    }
    return 0;
}

f32 TObjPlayer::get_table_value_f32(s16 arg1) {
    O_80142B3C *arg0 = (O_80142B3C *)this;
    return (f32)arg0->tab2[arg0->tab[arg1].idx].r->val;
}

void TObjMotion::update_animation_frame(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    struct E16_80142b8c_80142B08 *a = *(struct E16_80142b8c_80142B08 **)(arg0 + 0xD8);
    s32 n = a[arg1].f4;
    struct E8_80142b8c_80142B08 *b = *(struct E8_80142b8c_80142B08 **)(arg0 + 0xDC);
    *(s32 *)(arg0 + 0xF8) = b[n].f4;
}

s32 TObjMotion::get_anim_entry_value(s16 i) {
    return ((Obj_80142BB4 *)this)->e2[((Obj_80142BB4 *)this)->e1[i].idx].b;
}

void serialize_node_flags__10TObjPlayerFPv(u8 *arg0) {
    u8 *temp_r4;
    u8 *test_2c;
    u8 *test_30;

    *(void **)((s8 *)lbl_805D5684 + 0) = arg0;
    *(s32 *)((s8 *)lbl_805D5684 + 4) = 0;
    if (!(*(s32 *)((s8 *)arg0 + 0) & 1)) {
        *(s32 *)((s8 *)lbl_805D5684 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D5684 + 4) | 1);
    }
    if (!(*(s32 *)((s8 *)arg0 + 0) & 2)) {
        *(s32 *)((s8 *)lbl_805D5684 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D5684 + 4) | 2);
    }
    if (!(*(s32 *)((s8 *)arg0 + 0) & 4)) {
        *(s32 *)((s8 *)lbl_805D5684 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D5684 + 4) | 4);
    }
    temp_r4 = (unsigned char *) (*(void **)((s8 *)arg0 + 4));
    if (temp_r4 != NULL) {
        *(s32 *)((s8 *)lbl_805D5684 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D5684 + 4) | 8);
        if ((u32) *(u32 *)((s8 *)temp_r4 + 0) != 0U) {
            *(s32 *)((s8 *)lbl_805D5684 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D5684 + 4) | 0x10);
        }
        if ((u32) *(u32 *)((s8 *)temp_r4 + 4) != 0U) {
            *(s32 *)((s8 *)lbl_805D5684 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D5684 + 4) | 0x20);
        }
    }
    test_2c = (unsigned char *) (*(void **)((s8 *)arg0 + 0x2C));
    if (test_2c != NULL) {
        *(s32 *)((s8 *)lbl_805D5684 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D5684 + 4) | 0x40);
        lbl_805D5684 = lbl_805D5684 + 8;
        serialize_node_flags__10TObjPlayerFPv(test_2c);
    }
    test_30 = (unsigned char *) (*(void **)((s8 *)arg0 + 0x30));
    if (test_30 != NULL) {
        *(s32 *)((s8 *)lbl_805D5684 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D5684 + 4) | 0x80);
        lbl_805D5684 = lbl_805D5684 + 8;
        serialize_node_flags__10TObjPlayerFPv(test_30);
    }
}

void TObjPlayer::clear_next_entry(s32 arg0, u8 *arg1) {
    lbl_805D5684 = arg1;
    ((s32 (*)(void))serialize_node_flags__10TObjPlayerFPv)();
    lbl_805D5684 += 8;
    *(s32 *)((s8 *)lbl_805D5684 + 0) = 0;
}

s32 TObjPlayer::draw_model_with_callback(s32 arg1, s32 arg2, f32 farg0) {
    if ((arg1 == 0) || ((u32) this->model == 0U)) {
        return 0;
    }
    TObjPlayer::set_global_flag();
    player_joint_matrix_write_ptr = arg2;
    TObjEneRe7Berura::set_global_state((s32)((s32 *)save_joint_matrix_callback));
    render_model_tree__12TBoss8DragonFPv(*(u32 *)&this->model, arg1, farg0);
    TObjEneRe7Berura::set_global_state((s32)NULL);
    TObjPlayer::clear_global_state();
    return 1;
}

s32 TObjEnemy::render_anim_model(f32 farg0) {
    if (((u32) this->unknownF8 == 0U) || ((u32) this->model == 0U)) {
        return 0;
    }
    TObjPlayer::set_global_flag();
    player_joint_matrix_write_ptr = anim_model_matrix_array;
    TObjEneRe7Berura::set_global_state((s32)((s32 *)save_joint_matrix_callback));
    ((s32 (*)(u32, u32, f32))render_model_tree__12TBoss8DragonFPv)(*(u32 *)&this->model, this->unknownF8, farg0);
    TObjEneRe7Berura::set_global_state((s32)NULL);
    TObjPlayer::clear_global_state();
    return 1;
}

f32 TObjEneDD_ST::get_speed_or_default() {
    if (this->animationFlags & 4) {
        return 0.0f;
    }
    return get_speed__9TObjCharaFv();
}
}
int objInBand(GameObj* obj, f32 v) {
    u32 flags = obj->flags;
    if (!((flags & 4) && !(flags & 1)) &&
        obj->a == obj->b &&
        v < obj->c &&
        obj->c <= v + obj->d)
        return 1;
    return 0;
}

void save_joint_matrix_callback(void) { get_current_matrix((void *)((*(int *)&player_joint_matrix_write_ptr))); (*(int *)&player_joint_matrix_write_ptr) = ((*(int *)&player_joint_matrix_write_ptr) + 0x30); }

void draw_motion_model_saving_joints(TObjPlayer *player) {
    s32 temp_r3;
    (*(int *)&player_joint_matrix_write_ptr) = *(s32 *)((s8 *)player + 0xE0);
    TObjEneRe7Berura::set_global_state((s32)((void *) save_joint_matrix_callback));
    temp_r3 = player->animationFlags;
    if ((temp_r3 & 4) && !(temp_r3 & 0x400)) {
        draw_model_blend_motion((void *)(*(s32 *)((s8 *)player + 0x34)), (u8 *)player + 0xE4, player->m_c0);
    } else {
        draw_model_motion((void *)(*(s32 *)((s8 *)player + 0x34)), (void *)player->unknownF8, player->m_c0);
    }
    TObjEneRe7Berura::set_global_state((s32)NULL);
    set_default_alpha_blend();
}

void TObjPlayer::draw_model_with_callback() {
    s32 temp_r3;
    u32 temp_r0;

    temp_r0 = *(u32 *)&this->motion_buffer;
    if (temp_r0 != 0U) {
        (*(u32 *)&player_joint_matrix_write_ptr) = temp_r0;
        TObjEneRe7Berura::set_global_state((s32)save_joint_matrix_callback);
        temp_r3 = this->animationFlags;
        if ((temp_r3 & 4) && !(temp_r3 & 0x400)) {
            draw_model_blend_motion(this->model, &this->unk_E4, this->m_c0);
        } else {
            draw_model_motion((void *)this->model, (void *)this->unknownF8, this->m_c0);
        }
        TObjEneRe7Berura::set_global_state(NULL);
        set_default_alpha_blend();
    }
}

void TObjEnemy::render_world_model() {
    TObjPlayer::set_global_flag();
    if (this->animationFlags & 4) {
        draw_model_blend_motion(this->model, &this->unk_E4, this->m_c0);
    } else {
        TObjEneRe7Berura::set_global_state(chunk_model_node_callback);
        draw_model_motion((void *)this->model, (void *)this->unknownF8, this->m_c0);
        TObjEneRe7Berura::set_global_state((s32)((s32 *)(0)));
    }
    set_default_alpha_blend();
    TObjPlayer::clear_global_state();
}

void TObjMotion::draw() {
    TObjPlayer::set_global_flag();
    setup_actor_draw_lighting();
    if (this->animationFlags & 4) {
        draw_model_blend_motion(this->model, &this->unk_E4, this->m_c0);
    } else {
        TObjEneRe7Berura::set_global_state((s32)chunk_model_node_callback);
        draw_model_motion((void *)this->model, (void *)this->unknownF8, this->m_c0);
        TObjEneRe7Berura::set_global_state(0);
    }
    set_default_alpha_blend();
    restore_actor_draw_lighting(*(s32 *)&this->m_name);
    TObjPlayer::clear_global_state();
}

void TObjEneMe3Stelth::draw_model() {
    TObjPlayer::set_global_flag();
    setup_actor_draw_lighting();
    if (this->animationFlags & 4) {
        draw_ginja_model_tree__10TObjPlayerFPv(*(s32 *)&this->model, (u8 *)&this->unk_E4, this->m_c0);
    } else {
        set_model_node_callback(model_node_callback);
        draw_ginja_model__10TObjPlayerFl(*(s32 *)&this->model, *(s32 *)&this->unknownF8, this->m_c0);
        set_model_node_callback(0);
    }
    set_default_alpha_blend();
    restore_actor_draw_lighting(*(s32 *)&this->m_name);
    TObjPlayer::clear_global_state();
}

#define self ((ActorAnimationState *)arg0)
void apply_animation_transition(void *arg0, s16 idx) {
    AnimationAction *e = self->actions + idx;

    self->flags &= ~0x10;
    self->actionFlags = e->flags;
    if ((self->flags & 1) || (self->flags & 0x80) || (self->actionFlags & 0x80000000) || (self->actions[self->currentAction].flags & 0x40000000)) {
        self->flags &= ~4;
        ((TObjMotion *)self)->update_animation_frame(idx);
        if (sub_80143960__10TObjMotionFl(self, 0x100) != 0) {
            ((TObjMotion *)self)->sub_800E2DE4(0x100);
            self->speed = self->overrideSpeed;
        } else {
            self->speed = e->speed;
        }
        self->mode = e->mode;
        self->frameCount = self->motion->frameCount;
        if (self->actionFlags & 0x20000000) {
            ((TObjMotion *)self)->set_motion_interpolation_flag();
        }
        if (self->flags & 0x80) {
            self->flags &= ~0x80;
            self->frame = self->sourceFrame;
            {
                f32 fr = self->frame;
                f32 n = self->frameCount;
                if (1.0f + fr >= n) {
                    self->frame = fr - n;
                }
            }
        } else {
            self->frame = 0.0f;
        }
    } else {
        if (self->frame >= self->frameCount - 1.0f) {
            self->frame = self->frame - 1.0f;
        }
        self->mode = 4;
        self->flags |= 6;
        self->blendSource = self->motion;
        self->sourceFrame = self->frame;
        self->previousAction = self->currentAction;
        ((TObjMotion *)self)->update_animation_frame(idx);
        self->blendTarget = self->motion;
        self->targetFrame = 0.0f;
        self->nextMode = e->mode;
        self->frame = 0.0f;
        self->frameCount = self->motion->frameCount;
        if (sub_80143960__10TObjMotionFl(self, 0x200) != 0) {
            ((TObjMotion *)self)->sub_800E2DE4(0x200);
            self->speed = self->overrideBlendSpeed;
        } else {
            self->speed = self->blendSpeed;
        }
        if (self->actionFlags & 0x20000000) {
            ((TObjMotion *)self)->set_motion_interpolation_flag();
        }
    }
    self->currentAction = idx;
}

#undef self

void TObjPlayer::init_npc_animation(void* a1, void* a2, void* a3) { set_field_d8__10TObjMotionFl(this); set_field_dc((s32)a2); ((int (*)(void*, void*))set_animation__10TObjMotionFs)(this, a3); }

void TObjMotion::set_animation(s16 arg1) {
    void *temp_r3;
    f32 conv;
    void *arg0 = (void *)this;

    ((TObjMotion *)arg0)->m_b8 = arg1;
    ((TObjMotion *)arg0)->m_ba = (s16) ((TObjMotion *)arg0)->m_b8;
    ((TObjMotion *)arg0)->update_animation_frame(((TObjMotion *)arg0)->m_b8);
    temp_r3 = ((TObjMotion *)arg0)->get_anim_entry(((TObjMotion *)arg0)->m_b8);
    ((TObjMotion *)arg0)->m_c8 = (f32) *(f32 *)((s8 *)temp_r3 + 8);
    *(s16 *)((s8 *)arg0 + 0xF4) = (s16) *(s16 *)((s8 *)temp_r3 + 0);
    conv = (f32) *(u32 *)((s8 *)(*(void **)((s8 *)arg0 + 0xF8)) + 4);
    *(f32 *)((s8 *)arg0 + 0xC4) = conv;
    ((TObjMotion *)arg0)->m_c0 = 0.0f;
    ((TObjMotion *)arg0)->animationFlags = (s32) (((TObjMotion *)arg0)->animationFlags & 0xFFFFFFFB);
    ((TObjMotion *)arg0)->m_b4 = (s32) *(s32 *)((s8 *)temp_r3 + 0xC);
    *(void **)((s8 *)arg0 + 0xE4) = (void *) *(void **)((s8 *)arg0 + 0xF8);
    *(f32 *)((s8 *)arg0 + 0xEC) = 0.0f;
    *(void **)((s8 *)arg0 + 0xE8) = (void *) *(void **)((s8 *)arg0 + 0xF8);
    *(f32 *)((s8 *)arg0 + 0xF0) = 0.0f;
    *(s16 *)((s8 *)arg0 + 0xBC) = (s16) ((TObjMotion *)arg0)->m_b8;
    if (((TObjMotion *)arg0)->m_b4 & 0x20000000) {
        ((TObjMotion *)arg0)->set_motion_interpolation_flag();
    }
}

void advance_animation_playback(Anim_80143504 *a) {
    f32 last;
    if (a->flags & 0x40) {
        return;
    }
    a->frame += a->speed;
    last = a->end - 1.0f;
    a->flags &= ~0x82A;
    if (a->cur != a->req) {
        if (a->frame >= a->end) {
            a->frame -= a->speed;
        }
        apply_animation_transition(a, a->cur);
    }
    switch (a->mode) {
    case 1:
        if (a->frame >= a->end) {
            a->frame -= a->end;
            if (sub_80143960__10TObjMotionFl(a, 0x100) != 0) {
                a->speed = a->xD0;
            }
        }
        break;
    case 2:
        if (a->frame >= last) {
            if (((u32 (*)(void *, s16))get_anim_entry_value__10TObjMotionFs)(a, a->tbl[a->cur].next) == 0) {
                a->frame -= a->end;
            } else {
                a->cur = a->tbl[a->cur].next;
                apply_animation_transition(a, a->cur);
                a->flags |= 0x800;
            }
        }
        break;
    case 3:
        if (a->frame >= last) {
            a->mode = 5;
            a->frame -= a->speed;
            a->speed = 0.0f;
            a->flags |= 0x30;
        }
        break;
    case 4:
        if (a->frame >= 1.0f) {
            a->frame = 0.0f;
            if (sub_80143960__10TObjMotionFl(a, 0x100) != 0) {
                ((TObjMotion *)a)->sub_800E2DE4(0x100);
                a->speed = a->xD0;
            } else {
                a->speed = a->tbl[a->cur].speed;
            }
            a->mode = a->nextmode;
            a->flags &= ~4;
            a->flags |= 8;
        }
        break;
    case 5:
        a->frame -= a->speed;
        break;
    }
}

void TObjMotion::reset_motion_fields() { *(int *)&this->animationFlags = 0; *(int *)&this->m_b4 = 0; this->m_ba = 0; *(short *)&this->m_b8 = 0; *(short *)&this->m_bc = 0; *(float *)&this->unk_C4 = 0.0f; *(float *)&this->m_c8 = 0.0f; *(float *)&this->m_c0 = 0.0f; *(float *)&this->unk_CC = 0.2f; *(float *)&this->m_d0 = 0.0f; *(float *)&this->unk_D4 = 0.0f; *(int*)((char*)this + 0xe4) = 0; *(int *)&this->unk_E8 = 0; *(float *)&this->m_ec = 0.0f; *(float *)&this->unk_F0 = 0.0f; *(short*)((char*)this + 0xf6) = 0; *(short *)&this->m_f4 = 0; }

TObjMotion::~TObjMotion() {
}

TObjMotion::TObjMotion(TObject *parent) : TObjCollidable(parent) {
    m_name = TObjMotion__class_name;
    reset_motion_fields();
    action_table = NULL;
    unknownF8 = 0;
    motion_list = NULL;
    motion_buffer = NULL;
    unknownAC = 0;
}

// The two part destructors are still written out by hand: their vtables
// come out ahead of TObjMotion's in the original, which the compiler only
// gives these classes when their destructors are inline.
extern "C" {
void *__dt__13TUnk_804A7478Fv(TUnk_804A7478 *self, s16 del) {
    if (self != NULL) {
        *(void **)((u8 *)self + 4) = __vt__13TUnk_804A7478;
        __dt__13TUnk_804A7488Fv(self, 0);
        if (del > 0) {
            ::operator delete(self);
        }
    }
    return self;
}

void *__dt__13TUnk_804A7488Fv(TUnk_804A7488 *self, s16 del) {
    if (self != NULL) {
        *(void **)((u8 *)self + 4) = __vt__13TUnk_804A7488;
        if (del > 0) {
            ::operator delete(self);
        }
    }
    return self;
}
}

f32 TUnk_804A7478::get_float_c() {
    return frame;
}

NJS_MOTION *TUnk_804A7478::sub_80143930() {
    return motion;
}

void *TUnk_804A7488::get_id() {
    return model;
}

void TUnk_804A7478::activate() {
    state = 1;
}

void TObjMotion::set_motion_interpolation_flag() {
    ((NJS_MOTION *)unknownF8)->inp_fn |= 0x80;
}

u8 TObjMotion::sub_80143960(s32 flags) {
    return (animationFlags & flags) != 0;
}

void *TObjMotion::get_anim_entry(int index) {
    return (TObjMotionAction *)action_table + index;
}
