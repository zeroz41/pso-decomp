#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlResource.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/enemy/slime/SlimeAnimationState.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/enemy/slime/TObjEneSlimeOne_800EC394.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/enemy/sorcerer/TObjEneRe4Bit.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/slime/TObjEneSlimeWaterBomb.h"
#include "pso/enemy/slime/TObjEneSlimeOne.h"
#include "pso/player/TObjPlayer.h"

struct O_800EC39C { u8 pad[0x384]; s32 state; };

extern "C" {
extern s8 slime_one_animation_end_initialized;
extern f32 slime_one_animation_end_frame;
}
void draw_chunk_model_with_shape_motion(void *child, void *motion, NJS_MOTION *shape, f32 frame);
extern s32 slime_one_part_texture_index_table[];
extern s32 model_render_flags;
#include "pso/player/TObjPlayer_801D2E20.h"
extern "C" {

s32 TObjEneSlimeOne::get_attack_target() { return variant; }

extern BmlResource *slime_bml_resource;

s32 TObjEneSlimeOne::is_in_water_bomb_states() {
    O_800EC39C *self = (O_800EC39C *)this;
    return self->state == 11 || self->state == 12 || self->state == 13;
}

BmlResource *TObjEneSlimeOne::get_instance() { return slime_bml_resource; }

int TObjEneSlimeWaterBomb::find_nearest_enemy_masked(f32 range) {
    s32 target_id;
    this->actorFlags = (s32) (this->actorFlags | 0x02000000);
    target_id = find_nearest_hittable_enemy(this, NULL, range);
    this->actorFlags = (s32) (this->actorFlags & 0xFDFFFFFF);
    return static_cast<u16>(target_id);
}

int TObjEneSlimeOne::is_timer_active() { return (this->actorFlags >> 4) & 0x1; }

int TObjEneSlimeOne::find_nearest_enemy_with_flag(Vec *direction, f32 range) {
    s32 target_id;
    this->actorFlags = (s32) (this->actorFlags | 0x02000000);
    target_id = find_nearest_hittable_enemy(this, direction, range);
    this->actorFlags = (s32) (this->actorFlags & 0xFDFFFFFF);
    return static_cast<u16>(target_id);
}

void TObjEneSlimeOne::clear_parent_slime() { parent_slime = NULL; }

s16 TObjPlayer::get_attack_stage() { return attack_state.get_validated_attack_stage(); }

extern f32 TObjEneSlimeOne__target_depth;
extern u8 TObjEneSlimeOne__target_depth_initialized;

void SlimeAnimationState::draw(s32 deferred) {
    s32 state = this->state;
    if (state == -1) {
        return;
    }
    if (state < 7) {
        TObjFish::set_global_param(get_bml_texlist(TObjEneSlimeOne::get_instance(), slime_one_part_texture_index_table[owner->get_attack_target()]));
        if (deferred != 0) {
            model_render_flags |= 0x400000;
            set_chunk_render_flags(1);
            owner->draw();
            clear_chunk_render_flags();
            model_render_flags &= ~0x400000;
            return;
        }
        set_cull_back();
        set_chunk_render_flags(2);
        owner->draw();
        set_cull_front();
        owner->draw();
        set_cull_none();
        clear_chunk_render_flags();
        return;
    }
    if (state < 9) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texture_list));
        if (deferred != 0) {
            model_render_flags |= 0x400000;
            set_chunk_render_flags(1);
            draw_chunk_model_with_shape_motion(model, motion, (NJS_MOTION *)shape_motion, frame);
            clear_chunk_render_flags();
            model_render_flags &= ~0x400000;
            return;
        }
        set_chunk_render_flags(2);
        set_cull_back();
        draw_chunk_model_with_shape_motion(model, motion, (NJS_MOTION *)shape_motion, frame);
        set_cull_front();
        draw_chunk_model_with_shape_motion(model, motion, (NJS_MOTION *)shape_motion, frame);
        set_cull_none();
        clear_chunk_render_flags();
        return;
    }
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texture_list));
    set_motion_packed_rotation();
    if (deferred != 0) {
        model_render_flags |= 0x400000;
        set_chunk_render_flags(1);
        draw_model_motion(model, motion, frame);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(second_texture_list));
        draw_model_motion(second_model, second_motion, frame);
        clear_chunk_render_flags();
        model_render_flags &= ~0x400000;
    } else {
        set_chunk_render_flags(2);
        set_cull_back();
        draw_model_motion(model, motion, frame);
        set_cull_front();
        draw_model_motion(model, motion, frame);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(second_texture_list));
        set_cull_back();
        draw_model_motion(second_model, second_motion, frame);
        set_cull_front();
        draw_model_motion(second_model, second_motion, frame);
        set_cull_none();
        clear_chunk_render_flags();
    }
    clear_motion_packed_rotation();
}

void SlimeAnimationState::advance() {
    s32 s = state;
    if (s == -1) {
        return;
    }
    if (s < 7) {
        owner->advance_animation();
    } else if (s < 9) {
        f32 v = frame + speed;
        frame = v;
        if (v >= frame_count) {
            frame = frame - frame_count;
        }
    } else {
        if (slime_one_animation_end_initialized == 0) {
            f32 tmp = frame_count;
            slime_one_animation_end_initialized = 1;
            slime_one_animation_end_frame = tmp - 1.0f;
        }
        f32 v = frame + speed;
        f32 lim = slime_one_animation_end_frame;
        frame = v;
        if (v >= lim) {
            frame = lim;
        }
    }
}

s32 SlimeAnimationState::is_finished() {
    s32 state;

    state = this->state;
    if (state == -1) {
        return 1;
    }
    if (state < 7) {
        return 0;
    }
    if ((s8) TObjEneSlimeOne__target_depth_initialized == 0) {
        f32 tmp = frame_count;
        TObjEneSlimeOne__target_depth_initialized = 1;
        TObjEneSlimeOne__target_depth = tmp - 1.0f;
    }
    if (frame == TObjEneSlimeOne__target_depth) {
        return 1;
    }
    return 0;
}

SlimeShapeMotion slime_one_motion_state_table[2] = {
    {11, 12, 0.7f}, {6, 7, 0.8f}
};
SlimePairedMotion lbl_80496C68[2] = {
    {4, 5, 0, 1, 0.6f}, {4, 0, 0, 4, 0.6f}
};
SlimePairedMotion lbl_80496C90[2] = {
    {5, 5, 2, 1, 0.6f}, {5, 0, 2, 4, 0.6f}
};
__declspec(section ".data") SlimePairedMotion *lbl_80496CB8[2] = {lbl_80496C68, lbl_80496C90};
__declspec(section ".data") s32 slime_one_attack_target_id_table[2] = {4, 5};
}
__declspec(section ".data") s32 slime_one_part_texture_index_table[2] = {0, 2};
extern "C" {
f32 TObjEneSlimeOne__target_depth;
u8 TObjEneSlimeOne__target_depth_initialized;
f32 slime_one_animation_end_frame;
s8 slime_one_animation_end_initialized;

void SlimeAnimationState::set_state(s32 next_state) {
    s32 flag = state & 0x1000;
    state = next_state & ~0x1000;
    if (state == -1) {
        return;
    }
    if (state < 7) {
        if (flag != 0) {
            owner->init(state);
        } else {
            owner->set_requested_action(state);
        }
        return;
    }
    if (state < 9) {
        BmlResource *resource = TObjEneSlimeOne::get_instance();
        SlimeShapeMotion *entry = slime_one_motion_state_table + state - 7;
        u32 id = slime_one_attack_target_id_table[owner->get_attack_target()];
        model = (NJS_OBJECT *)get_bml_model(resource, id);
        texture_list = reinterpret_cast<NJS_TEXLIST *>(get_bml_texlist(resource, id));
        motion = (AnimationMotion *)get_bml_motion(resource, entry->motion);
        shape_motion = (AnimationMotion *)get_bml_motion(resource, entry->shape_motion);
        frame_count = motion->frameCount;
        speed = entry->speed;
        frame = 0.0f;
        return;
    }
    s32 index = state - 9;
    BmlResource *resource = TObjEneSlimeOne::get_instance();
    SlimePairedMotion *entry = &lbl_80496CB8[owner->get_attack_target()][index];
    model = (NJS_OBJECT *)get_bml_model(resource, entry->model);
    texture_list = reinterpret_cast<NJS_TEXLIST *>(get_bml_texlist(resource, entry->model));
    motion = (AnimationMotion *)get_bml_motion(resource, entry->motion);
    second_model = (NJS_OBJECT *)get_bml_model(resource, entry->second_model);
    second_texture_list = reinterpret_cast<NJS_TEXLIST *>(get_bml_texlist(resource, entry->second_model));
    second_motion = (AnimationMotion *)get_bml_motion(resource, entry->second_motion);
    frame_count = second_motion->frameCount;
    speed = entry->speed;
    frame = 0.0f;
}

SlimeAnimationState::~SlimeAnimationState() {}

SlimeAnimationState::SlimeAnimationState(TObjEneSlimeOne *owner)
    : owner(owner), state(-1) {}
}

void TObjEneRe4Bit::render_demo() {  }
void TObjEneRe4Bit::run_demo_task() {  }
