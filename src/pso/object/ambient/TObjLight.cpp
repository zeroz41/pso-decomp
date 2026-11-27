#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/network/TLobby.h"
#include "pso/map/FloorArea.h"
#include "pso/math/MatrixReflect.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/render_util.h"
#include "pso/render/DebugFont.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/TObjBase.h"
#include "pso/object/base/ObjectSetData.h"
#include "pso/player/PlayerSlots.h"
#include "pso/render/NinjaUtil.h"
#include "pso/object/base/TObjCharaHelpers.h"

extern "C" {

const char *light_class_name = "TObjLight";

void TObjLight::render() {  }

// The original reaches the forward vector's initialiser with its own lis/addi, not
// from a pooled .rodata base: pool_data is off for this function.
#pragma push
#pragma fp_contract on
#pragma pool_data off
void TObjLight::run_task() {
    s32 hi;
    if (xyz_distance_squared(&position, &camera_ctrl_instance->pos) > 160000.0f) {
        queue_destruction();
        return;
    }
    {
    Vec fwd = {0.0f, 0.0f, -1.0f};
    VecCopy(&scene_direction, &scene_light_state.view_direction);
    flags = 0;
    if (scale.x >= 10000.0f) {
        color.x = scale.x - 10000.0f;
        flags |= 1;
    } else {
        color.x = scale.x;
    }
    if (scale.y >= 10000.0f) {
        color.y = scale.y - 10000.0f;
        flags |= 2;
    } else {
        color.y = scale.y;
    }
    color.z = scale.z;
    hi = set_params[0] >> 16;
    radius = 5.0f * (f32)hi;
    increment = (u16)set_params[0];
    strength = 0.1 * (f64)(set_params[1] >> 16) + 1.0;
    if (flags & 1) {
        set_params[2] += increment;
        oscillation = 0;
    } else if (flags & 2) {
        phase += increment;
        oscillation = 70.0f * sin_table_lookup(phase);
    }
    push_matrix_from(identity_matrix);
    rotate_matrix_z(NULL, set_params[2] + (s32)(182.04445f * (f32)oscillation));
    rotate_matrix_y(NULL, set_params[1]);
    matrix_mult_vec(NULL, &fwd, &direction);
    pop_matrices(1);
    }
    if (0.0f != vector_length(&direction)) {
        normalize_vector(&direction);
        if ((u8)(TLobby::get_instance() == 0) == 1) {
            direction.z = -1.0f * direction.z;
        } else if (get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_LOBBY ||
                   get_current_floor_area() == AREA_PIONEER2_EP2) {
            direction.z = -1.0f * direction.z;
        }
    }
    if (0.0f != radius) {
        s32 i;
        for (i = TLobby::get_game_mode(); i < TLobby::get_game_mode() + TObjEneDD::get_enemy_count(); i++) {
            TObjPlayer *a = TObjPlayer::get_player_data(i);
            if (a != NULL && room == a->room) {
                f32 d = horizontal_distance_squared(&a->position, &position);
                f32 r2 = radius * radius;
                if (r2 >= d) {
                    f32 t;
                    d = (1.0f) - d / r2;
                    t = d * strength;
                    if (t > (1.0f)) {
                        t = (1.0f);
                    }
                    actor_color.r = t * (color.x - scene_color.r) + scene_color.r;
                    actor_color.g = t * (color.y - scene_color.g) + scene_color.g;
                    actor_color.b = t * (color.z - scene_color.b) + scene_color.b;
                    actor_direction.x = t * (direction.x - scene_direction.x) + scene_direction.x;
                    actor_direction.y = t * (direction.y - scene_direction.y) + scene_direction.y;
                    actor_direction.z = t * (direction.z - scene_direction.z) + scene_direction.z;
                    register_actor_light(a->get_entity_id(), this);
                }
            }
        }
        for (i = 0; i < 4; i++) {
            TObjPlayer *a = get_player_by_client_id(i);
            if (a != NULL) {
                f32 d = horizontal_distance_squared(&a->position, &position);
                f32 r2 = radius * radius;
                if (r2 >= d) {
                    f32 t;
                    d = (1.0f) - d / r2;
                    t = d * strength;
                    if (t > (1.0f)) {
                        t = (1.0f);
                    }
                    actor_color.r = t * (color.x - scene_color.r) + scene_color.r;
                    actor_color.g = t * (color.y - scene_color.g) + scene_color.g;
                    actor_color.b = t * (color.z - scene_color.b) + scene_color.b;
                    actor_direction.x = t * (direction.x - scene_direction.x) + scene_direction.x;
                    actor_direction.y = t * (direction.y - scene_direction.y) + scene_direction.y;
                    actor_direction.z = t * (direction.z - scene_direction.z) + scene_direction.z;
                    if (get_current_floor_area() != AREA_LOBBY) {
                        register_actor_light(a->get_entity_id(), this);
                    }
                }
            }
        }
    }
}
#pragma pop

}
TObjLight::~TObjLight() {
    this->mask_object_set_row_flags(-3);
}


TObjLight::TObjLight(TObject *parent, ObjectSetData *set_data) : TObjBase(parent) {
    TObjLight *light = this;
    light->m_name = light_class_name;
    (light)->apply_object_set_data(set_data);
    light->light_room = (s32) set_data->room;
    light->actor_color.a = 0.5f;
    light->actor_color.r = (f32) light->scale.x;
    light->actor_color.g = (f32) light->scale.y;
    light->actor_color.b = (f32) light->scale.z;
    light->actor_direction.x = 0.0f;
    light->actor_direction.y = 0.0f;
    light->actor_direction.z = 0.0f;
    light->phase = 0;
    copy_argb(&light->scene_color, &scene_light_state.color);
    VecCopy(&light->scene_direction, &scene_light_state.view_direction);
    light->actor_color.a = 0.5f;
    light->actor_color.r = 0.0f;
    light->actor_color.g = 0.0f;
    light->actor_color.b = 0.0f;
    light->disallow_rendering();
}

void *TObjLight::create(ObjectSetData *set_data) {
    if (is_split_screen() != 0) {
        return NULL;
    }
    return new TObjLight(tl_05, set_data);
}
