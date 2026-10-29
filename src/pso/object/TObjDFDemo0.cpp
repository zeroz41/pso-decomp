#pragma push

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjDFDemo1.h"
#include "pso/system/NinjaUtil.h"
#include "pso/system/PadRumble.h"
#include "pso/misc/TCameraCtrl_800687BC.h"
#include "pso/player/TObjPlayer_80052374.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjDFDemo0.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjDFDemo1.h"

typedef struct Rec_8004E2C8 {
    s32 a;
    s32 b;
    s32 c;
} Rec_8004E2C8;

typedef struct Obj_8004E2C8 {
    u8 pad0[0xA0];
    Rec_8004E2C8 recs[6];
    u8 pade8[0x100 - 0xE8];
    f32 f100[3];
    s32 f10c;
    s32 f110;
    f32 f114;
} Obj_8004E2C8;

struct Rec_8004E068
{
  s32 a;
  s32 b;
  s32 c;
};

struct Tbl_8004E068
{
  s32 idx;
  s32 id;
  s32 slot;
};

struct Inner_8004E068
{
  u8 pad[4];
  s16 *col;
};

struct Outer_8004E068
{
  u8 pad[4];
  Inner_8004E068 *in;
};

struct Self_8004E068
{
  u8 pad0[0xE8];
  Rec_8004E068 recs[2];
  u8 f100[0xC];
  s32 f10C;
  s32 f110;
  f32 f114;
  f32 f118;
};

extern "C" {
void rotate_matrix_y(s32, s32);
void push_matrix();
void post_translate_matrix(void *);
void TObjEneRe4Sorcerer__sub_801E3F1C(f32, f32);
extern Tbl_8004E068 lbl_8048561C[];
extern s32 model_render_flags;
void *TObjDFDemo0__ct(void *, void *);
void *__nw__7TObjectFUl(int);

void *TObjDFDemo0::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x110);
    if (o != NULL) {
        o = TObjDFDemo0__ct(o, arg0);
    }
    return o;
}

typedef struct Inner_8004E068 Inner_8004E068;
typedef struct Outer_8004E068 Outer_8004E068;
typedef struct Rec_8004E068 Rec_8004E068;
typedef struct Self_8004E068 Self_8004E068;
typedef struct Tbl_8004E068 Tbl_8004E068;
void TObjDFDemo1::sub_8004E068() {
    Self_8004E068 *self = (Self_8004E068 *)this;
  f32 alpha;
  unsigned int new_var2;
  s32 hi;
  s32 i;
  s32 t;
  s16 *new_var;
  s16 *col;
  f32 f;
  Tbl_8004E068 *e;
  s32 j;
  alpha = 1.0f;
  t = self->f110;
  if (t <= 0x7C)
  {
    return;
  }
  if (t < 0x88)
  {
    alpha = (t - 0x7C) / 12.0f;
  }
  col = ((Outer_8004E068 *)find_model_node(self->recs[1].a, 0x6A))->in->col;
  t = self->f110;
  f = 0.0f;
  if (t >= 0xF0)
  {
    f = 1.0f;
  }
  else
    if (t > 0xE6)
  {
    f = (t - 0xE6) / 10.0f;
  }
  col[3] = (col[3] & 0xFF) | ((s32) (255.0f * f) << 8);
  t = self->f110;
  f = 0.0f;
  if (t >= 0x104)
  {
    f = 1.0f;
  }
  else
    if (t > 0xF0)
  {
    f = (t - 0xF0) / 20.0f;
  }
  hi = ((s32) (255.0f * f)) << 8;
  for (i = 0; i < 3; i++)
  {
    e = &lbl_8048561C[i];
    col = ((Outer_8004E068 *)find_model_node(self->recs[e->idx].a, e->id))->in->col;
    new_var = col;
    new_var2 = new_var[e->slot];
    col[e->slot] = (new_var2 & 0xFF) | hi;
  }
  t = self->f110;
  if (alpha < 1.0f)
  {
    TObjPlayer__sub_80052390(alpha);
  }
  model_render_flags |= 0x20000;
  TObjEneRe4Sorcerer__sub_801E3F1C(0.0f, self->f118);
  push_matrix();
  set_motion_packed_rotation();
  post_translate_matrix(self->f100);
  rotate_matrix_y(0, this->m_10c);
  for (j = 0; j < 2; j++)
  {
    TObjFish::set_global_param(self->recs[j].b);
    draw_model_motion((void *)((*(&self->recs[j])).a), (void *)self->recs[j].c, this->m_114);
  }
  clear_motion_packed_rotation();
  pop_matrix();
  model_render_flags &= ~0x20000;
  if (alpha < 1.0f)
  {
    TObjPlayer::sync_player_globals();
  }
}

void TObjDFDemo1::draw_fading_model() {
    Obj_8004E2C8 *arg0 = (Obj_8004E2C8 *)this;
    f32 max;
    f32 alpha;
    f32 f;
    s32 i;
    alpha = 1.0f;
    if (arg0->f110 >= 0x88) {
        return;
    }
    if (arg0->f110 > 0x7C) {
        alpha = (f32)(0x88 - arg0->f110) / 12.0f;
    }
    if (alpha < 1.0f) {
        TObjPlayer__sub_80052390(alpha);
    }
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(arg0->f100);
    rotate_matrix_y(0, this->m_10c);
    max = 30.0f;
    for (i = 0; i < 6; i++) {
        TObjFish::set_global_param(arg0->recs[i].b);
        f = this->m_114;
        switch (i) {
        case 0:
        case 1:
            if (f > max) {
                f = max;
            }
            break;
        }
        draw_model_motion((void *)arg0->recs[i].a, (void *)arg0->recs[i].c, f);
    }
    clear_motion_packed_rotation();
    pop_matrix();
    if (alpha < 1.0f) {
        TObjPlayer::sync_player_globals();
    }
}

void TObjDFDemo1::render() { draw_fading_model(); sub_8004E068(); }

}

#pragma pop

#pragma push

#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/unk/text_80087278.h"

struct DFDemo1Emitter {
    s32 effect;
    s32 start;
    s32 end;
    f32 offset[3];
};

struct DFDemo1Fields {
    u8 pad0[0x90];
    TParticleCtrl *emitters[4];
    u8 padA0[0x100 - 0xA0];
    f32 pos[3];
    s32 m_10c;
    s32 timer;
    f32 m_114;
    f32 scroll;
    TBoss4Type2 strips;
};

extern "C" {
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
void vec3_add_to(f32 *, f32 *);
void play_sound_effect(int, void *, int, int);
extern DFDemo1Emitter lbl_80485590[];
}

#pragma push
#pragma fp_contract on
void TObjDFDemo1::run_task() {
    DFDemo1Fields *self = (DFDemo1Fields *)this;
    DFDemo1Emitter *e;
    s32 i;
    for (i = 0; i < 4; i++) {
        e = &lbl_80485590[i];
        if (self->timer >= e->end) {
            if (self->emitters[i] != NULL) {
                TParticleCtrl::release(self->emitters[i]);
                self->emitters[i] = NULL;
            }
        } else if (self->timer >= e->start) {
            if (self->emitters[i] == NULL) {
                f32 s = sin_table_lookup(-m_10c);
                f32 c = cos_table_lookup(-m_10c);
                f32 p[3];
                p[0] = c * e->offset[0] + s * e->offset[2];
                p[2] = -s * e->offset[0] + c * e->offset[2];
                p[1] = e->offset[1];
                vec3_add_to(p, self->pos);
                self->emitters[i] = create_particle_emitter(p, lbl_80485590[i].effect);
                if (self->emitters[i] != NULL) {
                    self->emitters[i]->set_flags(0x40);
                }
            }
        }
    }
    if (self->timer >= 0x46 && self->timer <= 0x82) {
        TParticleCtrl *fx = (TParticleCtrl *)spawn_particle_effect(self->pos, 0x14E);
        if (fx != NULL) {
            fx->set_flags(0x40);
        }
    }
    if (self->timer == 0x46 || self->timer == 0x2C) {
        start_pad_rumble_all(0xC0, 0xF);
    }
    if (self->timer == 0x7C) {
        play_sound_effect(0x4003AA26, self->pos, 0, 1);
    }
    if ((m_114 += 0.5f) > 149.0f) {
        m_114 = 149.0f;
    }
    if ((self->scroll += 1.0f / 45.0f) >= 1.0f) {
        self->scroll -= 1.0f;
    }
    self->strips.scroll_strips();
    if (++self->timer >= 300) {
        queue_destruction();
    }
}
#pragma pop

struct S_8004E634 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x90 - 0x1c];
    void *ptr[4];
    u8 pada0[0x11c - 0xa0];
    u8 f11c[0x14];
};

extern "C" {
void fn_8004AA04(void *);
void __dl__7TObjectFPv(void *);
extern u8 __vt__11TObjDFDemo1[];
S_8004E634 *__dt__11TObjDFDemo1Fv(S_8004E634 *o, s16 flag);
}
TObjDFDemo1::~TObjDFDemo1() {
    s32 i;
    fn_8004AA04(((S_8004E634 *)this)->f11c);
    for (i = 0; i < 4; i++) {
        if (((S_8004E634 *)this)->ptr[i] != 0) {
            TParticleCtrl::release(((S_8004E634 *)this)->ptr[i]);
            ((S_8004E634 *)this)->ptr[i] = 0;
        }
    }
    restore_player_cameras();
}

#pragma pop
