#include "types.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneDelDepth.h"
#include "pso/enemy/TObjEneDelDepthBomb.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct DelDepthMotionBinding { s32 motion; f32 speed; };
struct DelDepthModelMotion { s32 model; s32 motion; };
struct DelDepthPairBinding { DelDepthModelMotion first, second; f32 speed; };

extern "C" {
s32 TObjFish__sub_8001EDB0(s32, int);
s32 find_nearest_hittable_enemy__10TObjPlayerFiPvf(void *, void *, f32);
s32 get_bml_model(s32, s32);
u8 *get_bml_motion(s32, s32);
DelDepthMotionBinding lbl_804E8760[] = {{4, 0.3f}, {4, 0.3f}, {2, 0.6f}, {3, 0.4f}};
DelDepthPairBinding lbl_804E8780[] = {{{1, 1}, {0, 8}, 0.6f}, {{1, 0}, {0, 7}, 0.6f}};
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

s32 DelDepthMotion::get_type() { return motion; }

extern f32 lbl_805D6AC8;
extern u8 TObjEneDelDepth__state_complete_flag;
extern f32 lbl_805DF2E8;

#pragma push
#pragma fp_contract on
void DelDepthMotion::draw_model_part() {
    s32 temp_r0;
    temp_r0 = motion;
    if (temp_r0 != -1) {
        if (temp_r0 < 6) {
            TObjFish::set_global_param(TObjFish__sub_8001EDB0((s32)TObjEneDelDepth::get_data(), 0));
            actor->draw();
            return;
        }
        if (temp_r0 < 0xA) {
            TObjFish::set_global_param((int) (texture));
            TObjPlayer::set_global_flag();
            draw_model_motion((void *)(model), (void *)(animation), (f32) (frame));
            TObjPlayer::clear_global_state();
            return;
        }
        TObjPlayer::set_global_flag();
        TObjFish::set_global_param((int) (texture));
        draw_model_motion((void *)(model), (void *)(animation), (f32) (frame));
        TObjFish::set_global_param((int) (secondTexture));
        draw_model_motion((void *)(secondModel), (void *)(secondAnimation), (f32) (frame));
        TObjPlayer::clear_global_state();
    }
}
#pragma pop

void DelDepthMotion::update_animation_frame() {
    if (motion == -1) {
        return;
    }
    if (motion < 6) {
        advance_animation_playback(actor);
    } else if (motion < 10) {
        if ((frame += speed) >= endFrame) {
            frame -= endFrame;
        }
    } else {
        if ((s8)TObjEneDelDepth__animation_end_frame_initialized == 0) {
            f32 m = endFrame;
            TObjEneDelDepth__animation_end_frame_initialized = 1;
            TObjEneDelDepth__animation_end_frame = m - lbl_805DF2E8;
        }
        f32 lim = TObjEneDelDepth__animation_end_frame;
        if ((frame += speed) >= lim) {
            frame = lim;
        }
    }
}

s32 DelDepthMotion::is_state_complete() {
    s32 temp_r0;

    temp_r0 = motion;
    if (temp_r0 == -1) {
        return 1;
    }
    if (temp_r0 < 6) {
        return 0;
    }
    if ((s8) TObjEneDelDepth__state_complete_flag == 0) {
        f32 temp_f1 = endFrame;
        TObjEneDelDepth__state_complete_flag = 1;
        lbl_805D6AC8 = temp_f1 - lbl_805DF2E8;
    }
    if (frame == lbl_805D6AC8) {
        return 1;
    }
    return 0;
}

void DelDepthMotion::set_motion(s32 arg1) {
    s32 flag;
    s32 id;
    flag = motion;
    motion = arg1 & ~0x1000;
    flag &= 0x1000;
    id = motion;
    if (id == -1) {
        return;
    }
    if (id < 6) {
        if (flag != 0) {
            ((TObjEnePanarms *)(actor))->init((s16)id);
        } else {
            actor->set_field_b8((s16)id);
        }
    } else if (id < 0xA) {
        s32 data = (s32)TObjEneDelDepth::get_data();
        DelDepthMotionBinding *e = &lbl_804E8760[motion] - 6;
        model = (void *)get_bml_model(data, 1);
        texture = TObjFish__sub_8001EDB0(data, 1);
        animation = (AnimationMotion *)get_bml_motion(data, e->motion);
        endFrame = animation->frameCount;
        speed = e->speed;
        frame = lbl_805DF2EC;
    } else {
        s32 data = (s32)TObjEneDelDepth::get_data();
        DelDepthPairBinding *e = &lbl_804E8780[motion] - 10;
        DelDepthModelMotion *q;
        model = (void *)get_bml_model(data, e->first.model);
        texture = TObjFish__sub_8001EDB0(data, e->first.model);
        animation = (AnimationMotion *)get_bml_motion(data, e->first.motion);
        q = &e->second;
        secondModel = (void *)get_bml_model(data, q->model);
        secondTexture = TObjFish__sub_8001EDB0(data, q->model);
        secondAnimation = (AnimationMotion *)get_bml_motion(data, q->motion);
        endFrame = secondAnimation->frameCount;
        speed = e->speed;
        frame = lbl_805DF2EC;
    }
}

DelDepthMotion::~DelDepthMotion() {}

DelDepthMotion::DelDepthMotion(TObjMotion *owner) : actor(owner), motion(-1) {}

}
