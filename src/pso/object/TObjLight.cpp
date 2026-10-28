#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/object/TObjLight.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjLight.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"

struct RecoveredGlobal_80194528___vt__9TObjLight {
    s32 value;
    u8 remaining[0x34];
};

struct RecoveredGlobal_80194528_TObjLight__data_80506320 {
    s32 value;
    u8 remaining[0x4C];
};

typedef struct Vec_80193FE8 { f32 x, y, z; } Vec_80193FE8;

typedef struct Actor_80193FE8 {
    u8 pad0[0x28];
    s16 room;
    u8 pad2A[0x38 - 0x2A];
    Vec_80193FE8 pos;
} Actor_80193FE8;

typedef struct Light_80193FE8 {
    u8 pad0[0x28];
    s16 room;
    u8 pad2A[0x38 - 0x2A];
    Vec_80193FE8 pos;
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
    Vec_80193FE8 color;
    f32 base_a;
    Vec_80193FE8 base_color;
    Vec_80193FE8 dir;
    Vec_80193FE8 base_dir;
    Vec_80193FE8 out_dir;
    u8 padF0[4];
    Vec_80193FE8 out_color;
} Light_80193FE8;

extern "C" {
s32 is_split_screen(void);
u8 *__nw__7TObjectFUl(s32);
extern s32 tl_05;
s32 __ct__8TObjBaseFP7TObject(void *);
extern s32 __vt__9TObjLight[];
extern RecoveredGlobal_80194528_TObjLight__data_80506320 TObjLight__scene_light_state;
extern s32 lbl_805D33B8;
Actor_80193FE8 *get_player_data__10TObjPlayerFi(s32);
u16 get_entity_id(void *);
f32 xyz_distance_squared(void *, void *);
void register_actor_light(s32, void *);
f32 horizontal_distance_squared(void *, void *);
Actor_80193FE8 *get_player_by_client_id(s32);
f32 sin_table_lookup(s32);
void matrix_mult_vec(void *, void *, void *);
f32 vector_length(void *);
void rotate_matrix_y(void *, s32);
void rotate_matrix_z(void *, s32);
void normalize_vector(void *);
extern const Vec_80193FE8 lbl_80445D44;
extern u8 identity_matrix[];
extern u8 *camera_ctrl_instance;
void __dl__7TObjectFPv(void *);

void TObjLight::render() {  }

#pragma push
#pragma fp_contract on
void TObjLight::run_task() {
    Light_80193FE8 *self = (Light_80193FE8 *)this;
    s32 hi;
    if (xyz_distance_squared(&self->pos, camera_ctrl_instance + 0x178) > 160000.0f) {
        queue_destruction__7TObjectFv(self);
        return;
    }
    {
    Vec_80193FE8 fwd = lbl_80445D44;
    VecCopy((Vec *)&self->base_dir, (const Vec *)(((u8 *)&TObjLight__scene_light_state) + 0xC));
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
        } else if (get_current_area() == 0 || get_current_area() == 0xF ||
                   get_current_area() == 0x12) {
            self->dir.z = -1.0f * self->dir.z;
        }
    }
    if (0.0f != self->radius) {
        s32 i;
        for (i = TLobby::get_game_mode(); i < TLobby::get_game_mode() + TObjEneDD::get_enemy_count(); i++) {
            Actor_80193FE8 *a = get_player_data__10TObjPlayerFi(i);
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
                    register_actor_light(get_entity_id(a), self);
                }
            }
        }
        for (i = 0; i < 4; i++) {
            Actor_80193FE8 *a = get_player_by_client_id(i);
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
                    if (get_current_area() != 0xF) {
                        register_actor_light(get_entity_id(a), self);
                    }
                }
            }
        }
    }
}
#pragma pop

}
TObjLight::~TObjLight() {
    ((TObjBase *)this)->mask_object_set_row_flags(-3);
}
extern "C" {

typedef char RecoveredGlobal_80194528___vt__9TObjLight_size[sizeof(RecoveredGlobal_80194528___vt__9TObjLight) == 0x38 ? 1 : -1];
typedef char RecoveredGlobal_80194528_TObjLight__data_80506320_size[sizeof(RecoveredGlobal_80194528_TObjLight__data_80506320) == 0x50 ? 1 : -1];
u8 *TObjLight__ct(TObjLight *light, s32 arg1, u8 *arg2) {
    __ct__8TObjBaseFP7TObject(light);
    *(s32 **)((s8 *)light + 0x18) = &(*(RecoveredGlobal_80194528___vt__9TObjLight *)&__vt__9TObjLight).value;
    *(s32 *)((s8 *)light + 0) = (s32) lbl_805D33B8;
    ((TObjLight *)(light))->apply_object_set_data(arg2);
    light->m_90 = (s32) *(s16 *)((s8 *)arg2 + 8);
    *(f32 *)((s8 *)light + 0xF0) = (f32) 0.5f;
    light->m_f4 = (f32) light->scale.x;
    *(f32 *)((s8 *)light + 0xF8) = (f32) light->scale.y;
    light->m_fc = (f32) *(f32 *)((s8 *)light + 0x70);
    light->m_e4 = (f32) (0.0f);
    *(f32 *)((s8 *)light + 0xE8) = (f32) (0.0f);
    light->m_ec = (f32) (0.0f);
    light->m_9c = 0;
    copy_argb((NJS_ARGB *)((u8 *)light + 0xBC), (NJS_ARGB *)((u8 *)&TObjLight__scene_light_state.value + 0x24));
    VecCopy((Vec *)((u8 *)light + 0xD8), (const Vec *)((u8 *)&TObjLight__scene_light_state.value + 0xC));
    *(f32 *)((s8 *)light + 0xF0) = (f32) 0.5f;
    light->m_f4 = (f32) (0.0f);
    *(f32 *)((s8 *)light + 0xF8) = (f32) (0.0f);
    light->m_fc = (f32) (0.0f);
    disallow_rendering__7TObjectFv((light));
    return (u8 *)light;
}

u8 *TObjLight__create(u8 *arg0) {
    u8 *light;
    u8 *var_r0;
    if (is_split_screen() != 0) {
        return NULL;
    }
    light = (u8 *)(__nw__7TObjectFUl(0x100));
    var_r0 = light;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TObjLight__ct((TObjLight *)light, tl_05, arg0));
    }
    return var_r0;
}

}
