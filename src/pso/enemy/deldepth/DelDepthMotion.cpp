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
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct DelDepthMotionBinding { s32 motion; f32 speed; };
struct DelDepthModelMotion { s32 model; s32 motion; };
struct DelDepthPairBinding { DelDepthModelMotion first, second; f32 speed; };

#pragma defer_codegen on

// set_motion ids 6-9: a motion of model 1 at a speed; ids 10-11: two model/motion pairs (names inferred)
DelDepthMotionBinding deldepth_part_motion_bindings[] = {{4, 0.3f}, {4, 0.3f}, {2, 0.6f}, {3, 0.4f}};
DelDepthPairBinding deldepth_pair_motion_bindings[] = {{{1, 1}, {0, 8}, 0.6f}, {{1, 0}, {0, 7}, 0.6f}};

DelDepthMotion::DelDepthMotion(TObjMotion *owner) : actor(owner), motion(-1) {}

DelDepthMotion::~DelDepthMotion() {}

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
            actor->init((s16)id);
        } else {
            actor->set_requested_action((s16)id);
        }
    } else if (id < 0xA) {
        BmlResource *data = TObjEneDelDepth::get_data();
        DelDepthMotionBinding *e = &deldepth_part_motion_bindings[motion] - 6;
        model = get_bml_model(data, 1);
        texture = get_bml_texlist(data, 1);
        animation = get_bml_motion(data, e->motion);
        endFrame = animation->frameCount;
        speed = e->speed;
        frame = 0.0f;
    } else {
        BmlResource *data = TObjEneDelDepth::get_data();
        DelDepthPairBinding *e = &deldepth_pair_motion_bindings[motion] - 10;
        DelDepthModelMotion *q;
        model = get_bml_model(data, e->first.model);
        texture = get_bml_texlist(data, e->first.model);
        animation = get_bml_motion(data, e->first.motion);
        q = &e->second;
        secondModel = get_bml_model(data, q->model);
        secondTexture = get_bml_texlist(data, q->model);
        secondAnimation = get_bml_motion(data, q->motion);
        endFrame = secondAnimation->frameCount;
        speed = e->speed;
        frame = 0.0f;
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
    static f32 last_frame = endFrame - 1.0f;
    if (frame == last_frame) {
        return 1;
    }
    return 0;
}

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
        static f32 last_frame = endFrame - 1.0f;
        f32 lim = last_frame;
        if ((frame += speed) >= lim) {
            frame = lim;
        }
    }
}

#pragma push
#pragma fp_contract on
void DelDepthMotion::draw_model_part() {
    s32 temp_r0;
    temp_r0 = motion;
    if (temp_r0 != -1) {
        if (temp_r0 < 6) {
            TObjFish::set_global_param(get_bml_texlist(TObjEneDelDepth::get_data(), 0));
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

s32 DelDepthMotion::get_type() { return motion; }

int TObjEneDelDepth::find_nearest_enemy_with_flag(Vec *direction, f32 range) {
    s32 target_id;
    this->actorFlags = (s32) (this->actorFlags | 0x02000000);
    target_id = find_nearest_hittable_enemy(this, direction, range);
    this->actorFlags = (s32) (this->actorFlags & 0xFDFFFFFF);
    return static_cast<u16>(target_id);
}

int TObjEneDelDepth::get_flag_bit4() { return (this->actorFlags >> 4) & 0x1; }
