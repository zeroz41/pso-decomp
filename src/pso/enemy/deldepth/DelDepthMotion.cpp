#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlResource.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/deldepth/TObjEneDelDepth.h"
#include "pso/enemy/deldepth/TObjEneDelDepthBomb.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct DelDepthMotionBinding { s32 motion; f32 speed; };
struct DelDepthModelMotion { s32 model; s32 motion; };
struct DelDepthPairBinding { DelDepthModelMotion first, second; f32 speed; };

extern "C" {
AnimationMotion *get_bml_motion(BmlResource *resource, s32 index);
DelDepthMotionBinding lbl_804E8760[] = {{4, 0.3f}, {4, 0.3f}, {2, 0.6f}, {3, 0.4f}};
DelDepthPairBinding lbl_804E8780[] = {{{1, 1}, {0, 8}, 0.6f}, {{1, 0}, {0, 7}, 0.6f}};
extern const f32 lbl_805DF2EC;
extern f32 TObjEneDelDepth__animation_end_frame;
extern u8 TObjEneDelDepth__animation_end_frame_initialized;

int TObjEneDelDepth::get_flag_bit4() { return (this->actorFlags >> 4) & 0x1; }

int TObjEneDelDepth::find_nearest_enemy_with_flag(Vec *direction, f32 range) {
    s32 target_id;
    this->actorFlags = (s32) (this->actorFlags | 0x02000000);
    target_id = find_nearest_hittable_enemy__10TObjPlayerFiPvf(reinterpret_cast<saddr>(this), direction, range);
    this->actorFlags = (s32) (this->actorFlags & 0xFDFFFFFF);
    return static_cast<u16>(target_id);
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
            TObjFish::set_global_param((saddr)get_bml_texlist((BmlResource *)((saddr)TObjEneDelDepth::get_data()), 0));
            actor->draw();
            return;
        }
        if (temp_r0 < 0xA) {
            TObjFish::set_global_param(texture);
            set_motion_packed_rotation();
            draw_model_motion(model, animation, frame);
            clear_motion_packed_rotation();
            return;
        }
        set_motion_packed_rotation();
        TObjFish::set_global_param(texture);
        draw_model_motion(model, animation, frame);
        TObjFish::set_global_param(secondTexture);
        draw_model_motion(secondModel, secondAnimation, frame);
        clear_motion_packed_rotation();
    }
}
#pragma pop

void DelDepthMotion::update_animation_frame() {
    if (motion == -1) {
        return;
    }
    if (motion < 6) {
        actor->advance_animation();
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
        saddr data = (saddr)TObjEneDelDepth::get_data();
        DelDepthMotionBinding *e = &lbl_804E8760[motion] - 6;
        model = (void *)get_bml_model((BmlResource *)data, 1);
        texture = (saddr)get_bml_texlist((BmlResource *)data, 1);
        animation = (AnimationMotion *)get_bml_motion((BmlResource *)data, e->motion);
        endFrame = animation->frameCount;
        speed = e->speed;
        frame = lbl_805DF2EC;
    } else {
        saddr data = (saddr)TObjEneDelDepth::get_data();
        DelDepthPairBinding *e = &lbl_804E8780[motion] - 10;
        DelDepthModelMotion *q;
        model = (void *)get_bml_model((BmlResource *)data, e->first.model);
        texture = (saddr)get_bml_texlist((BmlResource *)data, e->first.model);
        animation = (AnimationMotion *)get_bml_motion((BmlResource *)data, e->first.motion);
        q = &e->second;
        secondModel = (void *)get_bml_model((BmlResource *)data, q->model);
        secondTexture = (saddr)get_bml_texlist((BmlResource *)data, q->model);
        secondAnimation = (AnimationMotion *)get_bml_motion((BmlResource *)data, q->motion);
        endFrame = secondAnimation->frameCount;
        speed = e->speed;
        frame = lbl_805DF2EC;
    }
}

DelDepthMotion::~DelDepthMotion() {}

DelDepthMotion::DelDepthMotion(TObjMotion *owner) : actor(owner), motion(-1) {}

}
