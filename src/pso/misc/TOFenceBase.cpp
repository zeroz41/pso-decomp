#include "types.h"
#include "pso/misc/TOFenceBase.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/misc/TSwitch.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"

// TSwitch.h declares is_current_floor_switch_set(s32); these callers saw a
// u16 id (clrlwi before the call), hence the (u16) below.

// Closed: opens once a player is within 70 (trigger 1) or the switch is set
// (trigger 2).
void TOFenceBase::check_trigger() {
    switch (trigger_mode) {
    case 0:
        break;
    case 1:
        if (is_any_player_within_radius_xz(4900.0f) == 1) {
            open();
        }
        break;
    case 2:
        if (is_current_floor_switch_set((u16)switch_id) == 1) {
            open();
        }
        break;
    }
}

// Open: closes once no player is within 100 or the switch is cleared.
void TOFenceBase::update_trigger() {
    switch (trigger_mode) {
    case 0:
        break;
    case 1:
        if (is_any_player_within_radius_xz(10000.0f) != 1) {
            close();
        }
        break;
    case 2:
        if (is_current_floor_switch_set((u16)switch_id) != 1) {
            close();
        }
        break;
    }
    play_persistent_sound(0x4004C10F, (s32)this, (u32)&position, 0, 0);
}

void TOFenceBase::run_task() {
    f32 frame;
    f32 end_frame;

    if (TObjPlayer::check_demo_mode() == 1) {
        update_demo();
        return;
    }
    switch (object_state) {
    case 0:
        check_trigger();
        break;
    case 1:
        update_trigger();
        break;
    }
    animation_frame += 1.0f;
    end_frame = animation_end_frame;
    frame = animation_frame;
    if (end_frame < frame) {
        animation_frame = frame - end_frame;
    }
}

// Closed, the fence loops its motion; open, it draws its root model in the
// root node's own pose.
void TOFenceBase::render() {
    NJS_OBJECT *node;

    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        if (is_open == 0) {
            draw_ginja_model_with_motion(model, motion, animation_frame);
        } else {
            node = (NJS_OBJECT *)model;
            push_matrix();
            post_translate_matrix(node->pos);
            rotate_matrix_z(NULL, node->ang[2]);
            rotate_matrix_x(NULL, node->ang[0]);
            rotate_matrix_y(NULL, node->ang[1]);
            scale_current_matrix(node->scl);
            draw_ginja_model((s32)node->model);
            pop_matrix();
        }
        pop_matrix();
    }
}

TOFenceBase::~TOFenceBase() {}

TOFenceBase::TOFenceBase(TObject *parent) : TObjMapObject(parent) {
    object_state = 0;
    switch_id = -1;
    trigger_mode = 0;
    is_open = 0;
    texture_variant = 0;
}

void TOFenceBase::open() {}
void TOFenceBase::close() {}
void TOFenceBase::update_demo() {}
