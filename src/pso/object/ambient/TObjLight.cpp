#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/TLobby.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D853C.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

typedef struct Actor_80193FE8 {
    u8 pad0[0x28];
    s16 room;
    u8 pad2A[0x38 - 0x2A];
    Vec pos;
} Actor_80193FE8;

typedef struct Light_80193FE8 {
    u8 pad0[0x28];
    s16 room;
    u8 pad2A[0x38 - 0x2A];
    Vec pos;
    u8 pad44[0x68 - 0x44];
    f32 param[3];
    u8 pad74[0x84 - 0x74];
    s32 packed0;
    s32 packed1;
    s32 angle;
    u8 pad90[0x94 - 0x90];
    s32 osc;
    f32 radius;
    s32 phase;
    u32 flags;
    u32 increment;
    f32 strength;
    u8 padAC[4];
    Vec color;
    f32 base_a;
    Vec base_color;
    Vec dir;
    Vec base_dir;
    Vec out_dir;
    u8 padF0[4];
    Vec out_color;
} Light_80193FE8;

extern "C" {
s32 is_split_screen(void);

const char *TObjLight__class_name = "TObjLight";

void TObjLight::render() {  }

// The original reaches the forward vector's initialiser with its own lis/addi, not
// from a pooled .rodata base: pool_data is off for this function.
#pragma push
#pragma fp_contract on
#pragma pool_data off
void TObjLight::run_task() {
    Light_80193FE8 *self = (Light_80193FE8 *)this;
    s32 hi;
    if (xyz_distance_squared(&self->pos, &camera_ctrl_instance->pos) > 160000.0f) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    {
    Vec fwd = {0.0f, 0.0f, -1.0f};
    VecCopy((Vec *)&self->base_dir, &scene_light_state.view_direction);
    self->flags = 0;
    if (self->param[0] >= 10000.0f) {
        self->color.x = self->param[0] - 10000.0f;
        self->flags |= 1;
    } else {
        self->color.x = self->param[0];
    }
    if (self->param[1] >= 10000.0f) {
        self->color.y = self->param[1] - 10000.0f;
        self->flags |= 2;
    } else {
        self->color.y = self->param[1];
    }
    self->color.z = self->param[2];
    hi = self->packed0 >> 16;
    self->radius = 5.0f * (f32)hi;
    self->increment = (u16)self->packed0;
    self->strength = 0.1 * (f64)(self->packed1 >> 16) + 1.0;
    if (self->flags & 1) {
        self->angle += self->increment;
        self->osc = 0;
    } else if (self->flags & 2) {
        self->phase += self->increment;
        self->osc = 70.0f * sin_table_lookup(self->phase);
    }
    push_matrix_from(identity_matrix);
    rotate_matrix_z(NULL, self->angle + (s32)(182.04445f * (f32)self->osc));
    rotate_matrix_y(NULL, self->packed1);
    matrix_mult_vec(NULL, &fwd, &self->dir);
    pop_matrices(1);
    }
    if (0.0f != vector_length(&self->dir)) {
        normalize_vector(&self->dir);
        if ((u8)(TLobby::get_instance() == 0) == 1) {
            self->dir.z = -1.0f * self->dir.z;
        } else if (get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_LOBBY ||
                   get_current_floor_area() == AREA_PIONEER2_EP2) {
            self->dir.z = -1.0f * self->dir.z;
        }
    }
    if (0.0f != self->radius) {
        s32 i;
        for (i = TLobby::get_game_mode(); i < TLobby::get_game_mode() + TObjEneDD::get_enemy_count(); i++) {
            Actor_80193FE8 *a = (Actor_80193FE8 *)TObjPlayer::get_player_data(i);
            if (a != NULL && self->room == a->room) {
                f32 d = horizontal_distance_squared(&a->pos, &self->pos);
                f32 r2 = self->radius * self->radius;
                if (r2 >= d) {
                    f32 t;
                    d = (1.0f) - d / r2;
                    t = d * self->strength;
                    if (t > (1.0f)) {
                        t = (1.0f);
                    }
                    self->out_color.x = t * (self->color.x - self->base_color.x) + self->base_color.x;
                    self->out_color.y = t * (self->color.y - self->base_color.y) + self->base_color.y;
                    self->out_color.z = t * (self->color.z - self->base_color.z) + self->base_color.z;
                    self->out_dir.x = t * (self->dir.x - self->base_dir.x) + self->base_dir.x;
                    self->out_dir.y = t * (self->dir.y - self->base_dir.y) + self->base_dir.y;
                    self->out_dir.z = t * (self->dir.z - self->base_dir.z) + self->base_dir.z;
                    register_actor_light(((TObjBase *)(a))->get_entity_id(), this);
                }
            }
        }
        for (i = 0; i < 4; i++) {
            Actor_80193FE8 *a = (Actor_80193FE8 *)get_player_by_client_id(i);
            if (a != NULL) {
                f32 d = horizontal_distance_squared(&a->pos, &self->pos);
                f32 r2 = self->radius * self->radius;
                if (r2 >= d) {
                    f32 t;
                    d = (1.0f) - d / r2;
                    t = d * self->strength;
                    if (t > (1.0f)) {
                        t = (1.0f);
                    }
                    self->out_color.x = t * (self->color.x - self->base_color.x) + self->base_color.x;
                    self->out_color.y = t * (self->color.y - self->base_color.y) + self->base_color.y;
                    self->out_color.z = t * (self->color.z - self->base_color.z) + self->base_color.z;
                    self->out_dir.x = t * (self->dir.x - self->base_dir.x) + self->base_dir.x;
                    self->out_dir.y = t * (self->dir.y - self->base_dir.y) + self->base_dir.y;
                    self->out_dir.z = t * (self->dir.z - self->base_dir.z) + self->base_dir.z;
                    if (get_current_floor_area() != AREA_LOBBY) {
                        register_actor_light(((TObjBase *)(a))->get_entity_id(), this);
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


TObjLight::TObjLight(TObject *parent, u8 *set_data) : TObjBase(parent) {
    TObjLight *light = this;
    light->m_name = TObjLight__class_name;
    ((TObjLight *)(light))->apply_object_set_data(set_data);
    light->m_90 = (s32) *(s16 *)((s8 *)set_data + 8);
    light->actor_color.a = 0.5f;
    light->actor_color.r = (f32) light->scale.x;
    light->actor_color.g = (f32) light->scale.y;
    light->actor_color.b = (f32) light->scale.z;
    light->actor_direction.x = 0.0f;
    light->actor_direction.y = 0.0f;
    light->actor_direction.z = 0.0f;
    light->m_9c = 0;
    copy_argb(&light->scene_color, &scene_light_state.color);
    VecCopy(&light->scene_direction, &scene_light_state.view_direction);
    light->actor_color.a = 0.5f;
    light->actor_color.r = 0.0f;
    light->actor_color.g = 0.0f;
    light->actor_color.b = 0.0f;
    light->disallow_rendering();
}

void *TObjLight::create(void *set_data) {
    if (is_split_screen() != 0) {
        return NULL;
    }
    return new TObjLight(tl_05, (u8 *)set_data);
}
