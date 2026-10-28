#include "types.h"
#include "pso/enemy/TObjEneDelDepth_8031624C.h"
#include "pso/misc/TQuestListVM_8007EAF8.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneDelDepth.h"
#include "pso/enemy/TObjEneDelDepthBomb.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

typedef struct Pair_80316488 { s32 a; s32 b; } Pair_80316488;

typedef struct E8_80316488 { s32 a; f32 f; } E8_80316488;

typedef struct E14_80316488 { Pair_80316488 p0; Pair_80316488 p1; f32 f; } E14_80316488;

typedef struct Self_80316488 {
    void *obj;
    s32 id;
    s32 r8;
    s32 rC;
    u8 *r10;
    s32 r14;
    s32 r18;
    u8 *r1C;
    f32 f20;
    f32 f24;
    f32 f28;
} Self_80316488;

typedef struct {
    void *obj;
    s32 frame;
    u8 pad8[0x20 - 0x08];
    f32 step;
    f32 max;
    f32 cur;
} Anim_80316364;

extern "C" {
s32 TObjFish__sub_8001EDB0(s32, int);
s32 find_nearest_hittable_enemy__10TObjPlayerFiPvf(void *, void *, f32);
s32 get_bml_model(s32, s32);
u8 *get_bml_motion(s32, s32);
extern E8_80316488 lbl_804E8760[];
extern E14_80316488 lbl_804E8780[];
extern const f32 lbl_805DF2EC;
void advance_animation_playback(void *);
extern f32 TObjEneDelDepth__animation_end_frame;
extern u8 TObjEneDelDepth__animation_end_frame_initialized;

int TObjEneDelDepth::get_flag_bit4() { return (this->actorFlags >> 4) & 0x1; }

int TObjEneDelDepth::find_nearest_enemy_with_flag(s32 arg1, f32 farg0) {
    u8 *arg0 = (u8 *)this;
    u16 temp_r3;
    this->actorFlags = (s32) (this->actorFlags | 0x02000000);
    temp_r3 = find_nearest_hittable_enemy__10TObjPlayerFiPvf((void *)arg0, (void *)arg1, (f32)farg0);
    this->actorFlags = (s32) (this->actorFlags & 0xFDFFFFFF);
    return temp_r3;
}

s32 TObjEneDelDepth::get_type() { return *(s32 *)&this->m_flags; }

extern f32 lbl_805D6AC8;
extern u8 TObjEneDelDepth__state_complete_flag;
extern f32 lbl_805DF2E8;

#pragma push
#pragma fp_contract on
void TObjEneDelDepth::draw_model_part() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    temp_r0 = *(s32 *)&this->m_flags;
    if (temp_r0 != -1) {
        if (temp_r0 < 6) {
            TObjFish::set_global_param(TObjFish__sub_8001EDB0(TObjEneDelDepth::get_data(), 0));
            ((TObjMotion *)(*(s32 *)&this->m_name))->draw();
            return;
        }
        if (temp_r0 < 0xA) {
            TObjFish::set_global_param((int) (*(s32 *)&this->m_next));
            TObjPlayer::set_global_flag();
            draw_model_motion((void *)(*(s32 *)&this->m_prev), (void *)(*(s32 *)&this->m_up), (f32) (*(f32 *)&this->room));
            TObjPlayer::clear_global_state();
            return;
        }
        TObjPlayer::set_global_flag();
        TObjFish::set_global_param((int) (*(s32 *)&this->m_next));
        draw_model_motion((void *)(*(s32 *)&this->m_prev), (void *)(*(s32 *)&this->m_up), (f32) (*(f32 *)&this->room));
        TObjFish::set_global_param((int) (*(s32 *)((s8 *)arg0 + 0x18)));
        draw_model_motion((void *)(*(s32 *)&this->m_down), (void *)(*(s32 *)&this->entity_id), (f32) (*(f32 *)&this->room));
        TObjPlayer::clear_global_state();
    }
}
#pragma pop

void TObjEneDelDepth::update_animation_frame() {
    Anim_80316364 *a = (Anim_80316364 *)this;
    if (a->frame == -1) {
        return;
    }
    if (a->frame < 6) {
        advance_animation_playback(a->obj);
    } else if (a->frame < 10) {
        if ((a->cur += a->step) >= a->max) {
            a->cur -= a->max;
        }
    } else {
        if ((s8)TObjEneDelDepth__animation_end_frame_initialized == 0) {
            f32 m = a->max;
            TObjEneDelDepth__animation_end_frame_initialized = 1;
            TObjEneDelDepth__animation_end_frame = m - lbl_805DF2E8;
        }
        f32 lim = TObjEneDelDepth__animation_end_frame;
        if ((a->cur += a->step) >= lim) {
            a->cur = lim;
        }
    }
}

s32 TObjEneDelDepth::is_state_complete() {
    s32 temp_r0;

    temp_r0 = *(s32 *)&this->m_flags;
    if (temp_r0 == -1) {
        return 1;
    }
    if (temp_r0 < 6) {
        return 0;
    }
    if ((s8) TObjEneDelDepth__state_complete_flag == 0) {
        f32 temp_f1 = *(f32 *)&this->texlist;
        TObjEneDelDepth__state_complete_flag = 1;
        lbl_805D6AC8 = temp_f1 - lbl_805DF2E8;
    }
    if (*(f32 *)&this->room == lbl_805D6AC8) {
        return 1;
    }
    return 0;
}

void TObjEneDelDepth::set_motion(s32 arg1) {
    Self_80316488 *self = (Self_80316488 *)this;
    s32 flag;
    s32 id;
    flag = self->id;
    self->id = arg1 & ~0x1000;
    flag &= 0x1000;
    id = self->id;
    if (id == -1) {
        return;
    }
    if (id < 6) {
        if (flag != 0) {
            ((TObjEnePanarms *)(self->obj))->init((void*)((s16)id));
        } else {
            ((TObjMotion *)(self->obj))->set_field_b8((s16)id);
        }
    } else if (id < 0xA) {
        s32 data = TObjEneDelDepth::get_data();
        E8_80316488 *e = &lbl_804E8760[self->id] - 6;
        self->r8 = get_bml_model(data, 1);
        self->rC = TObjFish__sub_8001EDB0(data, 1);
        self->r10 = get_bml_motion(data, e->a);
        self->f24 = *(u32 *)(self->r10 + 4);
        self->f20 = e->f;
        self->f28 = lbl_805DF2EC;
    } else {
        s32 data = TObjEneDelDepth::get_data();
        E14_80316488 *e = &lbl_804E8780[self->id] - 10;
        Pair_80316488 *q;
        self->r8 = get_bml_model(data, e->p0.a);
        self->rC = TObjFish__sub_8001EDB0(data, e->p0.a);
        self->r10 = get_bml_motion(data, e->p0.b);
        q = &e->p1;
        self->r14 = get_bml_model(data, q->a);
        self->r18 = TObjFish__sub_8001EDB0(data, q->a);
        self->r1C = get_bml_motion(data, q->b);
        self->f24 = *(u32 *)(self->r1C + 4);
        self->f20 = e->f;
        self->f28 = lbl_805DF2EC;
    }
}

s32 TObjEneDelDepth::conditional_delete(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

void fn_80316680(void *arg0, s32 arg1) {
    *(s32 *)((s8 *)arg0 + 0) = arg1;
    *(s32 *)((s8 *)arg0 + 4) = -1;
}

}
