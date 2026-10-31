#include "types.h"
#include "pso/object/TObjMapObject.h"
#include "pso/object/TObjFish.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803E2D70.h"

void TObjMapObject::update_anim_phase() {
    f32 frame;
    f32 end;
    animation_frame = animation_frame + animation_step;
    end = animation_end_frame;
    frame = animation_frame;
    if (end < frame) {
        animation_frame = frame - end;
    }
}

s32 TObjMapObject::is_in_view_depth(f32 min_radius) {
    Vec view;
    if (bodies != NULL) {
        f32 radius = get_collision_body_radius(this, 0);
        if (radius < min_radius) {
            radius = min_radius;
        }
        matrix_mult_vec(NULL, &position, &view);
        if (view.z > -radius) {
            return 0;
        }
    }
    return 1;
}

s32 TObjMapObject::is_any_player_within_radius_xz(f32 radius_sq) {
    u16 slot;
    TObjPlayer *player;
    for (slot = 0; (s32)slot < registered_player_count; slot++) {
        player = TObjPlayer::get_player_data(slot);
        if (player != NULL && get_entity_id(player) < 0x1000) {
            if (player->get_floor() == get_current_floor() &&
                horizontal_distance_squared((const Vec *)&position, (const Vec *)&player->position) < radius_sq) {
                return 1;
            }
        }
    }
    return 0;
}

void TObjMapObject::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        sub_80158604();
        return;
    }
    if (motion != NULL) {
        update_anim_phase();
    }
}

void TObjMapObject::render() {
    f32 range = view_range;
    s32 detail = classify_actor_view_detail(0.5f * range, range, model_radius);
    if (detail != 0 && is_in_view_depth(30.0f) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        if (motion != NULL) {
            if (detail == 1) {
                draw_model_motion(model, motion, animation_frame);
            } else {
                draw_model_motion(model, motion, animation_frame);
            }
        } else if (detail == 1) {
            draw_chunk_object(model);
        } else {
            draw_chunk_object(model);
        }
        pop_matrix();
    }
}

TObjMapObject::~TObjMapObject() {
}

TObjMapObject::TObjMapObject(TObject *parent) : TObjCollidable(parent) {
    object_state = 0;
    animation_frame = 0.0f;
    animation_end_frame = 0.0f;
    animation_step = 1.0f;
    motion = NULL;
    actorFlags |= 0x40000000;
    view_range = 800.0f;
    model_radius = 30.0f;
}

void TObjMapObject::sub_80158604() {
}
