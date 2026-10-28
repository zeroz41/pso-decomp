#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TUnk_8049442C.h"
#include "pso/object/TObjGyaranzoMissile.h"
#include "pso/player/TObjPlayer.h"


struct RecoveredGlobal_800D4BD0_lbl_80494468 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_800D4BD0___vt__19TObjGyaranzoMissile {
    s32 value;
    u8 remaining[0x38];
};

typedef struct Parm_800D47B4 {
    s32 a;
    f32 b;
} Parm_800D47B4;

struct Base_800D47B4 {
    char pad[0x18];
};

struct Obj_800D47B4 : Base_800D47B4 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(void *, Parm_800D47B4, s32, s32, s32);
};

struct Target_800D4990 {
    u8 pad[0x2FC];
    Vec pos;
};

struct Col_800D4990 { u8 pad[0xC]; f32 radius; u8 pad10[0x18 - 0x10]; u32 flags; };

extern "C" {
u16 get_entity_id(void *);
s32 init_collision_body_parts(void *, void *, int);
s32 __ct__13TUnk_804AF8A0FP7TObject(void *, int);
s32 rotate_matrix_y(int, int);
s32 push_matrix_from(void *);
s32 pop_matrix();
extern f32 identity_matrix[12];
extern s32 gyaranzo_bml_resource;
extern s32 tl_04;
s32 rand();
s32 matrix_mult_vec(int, int, int);
s32 rotate_matrix_x(int, int);
extern RecoveredGlobal_800D4BD0_lbl_80494468 gyaranzo_missile_collision_body_b;
extern s32 __vt__19TObjGyaranzoMissile[];
extern s32 lbl_805D2A80;
extern f32 TObjGyaranzoMissile__speed_scale;
u8 *TObjGyaranzoMissile__ct(u8 *arg0, u8 *arg1, u8 *arg2, s16 arg3);
void queue_destruction__7TObjectFv(void *);
Obj_800D47B4 *get_battle_param__10TObjPlayerFi(s32);
void *spawn_particle_effect(void *pos, s32 id);
s32 remap_area_sound_id(s32 arg0, s32 arg1);
void *find_entity_by_id(u16);
void init_all_slots__10TObjPlayerFv(void *);
void check_enemy_body_collisions(void *);
s32 play_sound_effect(void *, void *, int, int);
extern Parm_800D47B4 lbl_8043C464[];
u32 csnVector(void *, void *, int);
Target_800D4990 *find_active_entity_by_id(u16);
}
s32 get_gyaranzo_missile_int_parameter(s32 i);
void direction_to_rotation_xy(u8 *arg0, s32 *arg1, s32 *arg2);
extern "C" {
s32 project_actor_to_ground(void *, void *, int);
int vec3_add_to(void *, void *);
f32 vector_length(void *);
int subtract_vector(void *, void *);
extern const f32 TObjGyaranzoMissile__max_range;
extern s32 gyaranzo_missile_volley_end_time;
void *__dt__19TObjGyaranzoMissileFv(void *arg0, s16 arg1);
f32 sin_table_lookup(int);
s32 post_translate_matrix(void *);
void free_collision_body_parts(void *);
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
s32 draw_chunk_object();
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 push_matrix();
void __dl__7TObjectFPv(void *);
s32 set_global_param__8TObjFishFl();

extern s32 model_render_flags;

void TObjGyaranzoMissile::sub_800D47B4() {
    void *owner;
    s32 i;
    Obj_800D47B4 *q;
    Col_800D4990 *&collision = (Col_800D4990 *&)m_a4;
    owner = find_entity_by_id(owner_id);
    collision->radius = 6.0f;
    init_all_slots__10TObjPlayerFv(owner);
    ((TObjPlayer *)this)->check_object_collisions();
    check_enemy_body_collisions(this);
    if (collision->flags & 0x180000) {
        for (i = 0; i < 0x10; i++) {
            q = get_battle_param__10TObjPlayerFi(i);
            if (q == NULL) {
                break;
            }
            if (TObjPlayer::is_valid_and_active((u32)q) != 0) {
                Parm_800D47B4 parm = lbl_8043C464[0];
                parm.b = get_gyaranzo_missile_int_parameter(2);
                q->v21(owner, parm, 0, -1, -1);
            }
        }
    }
    spawn_particle_effect(position, 0xFB);
    play_sound_effect((void *)remap_area_sound_id(0x4003A80C, 0x19), position, 0, 0);
    queue_destruction__7TObjectFv(this);
}

void TObjGyaranzoMissile::render() {
    TObjFish__sub_8001EDB0((void *)gyaranzo_bml_resource, 6);
    set_global_param__8TObjFishFl();
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_x(0, (int)this->rotation_x);
    rotate_matrix_y(0, this->rotation_y);
    translate_matrix(0, 0.0f, (f32) (this->wobble_height * sin_table_lookup((int) this->wobble_phase)), 0.0f);
    model_render_flags &= 0xFFFFFBFF;
    get_bml_model((void *)gyaranzo_bml_resource, 6);
    draw_chunk_object();
    pop_matrix();
}

void TObjGyaranzoMissile::run_task() {
    Target_800D4990 *t;
    f32 dist;
    Col_800D4990 *&collision = (Col_800D4990 *&)m_a4;
    t = find_active_entity_by_id(target_id);
    if (t != NULL) {
        Vec d = t->pos;
        subtract_vector(&d, position);
        dist = vector_length(&d);
        if (timer >= 15 && dist > TObjGyaranzoMissile__max_range) {
            vec_set_length(&d, TObjGyaranzoMissile__max_range);
            vec3_add_to(&velocity, &d);
            vec_set_length(&velocity, TObjGyaranzoMissile__speed_scale);
        }
    }
    VecCopy(&prev_position, (const Vec *)position);
    vec3_add_to(position, &velocity);
    direction_to_rotation_xy((u8 *)&velocity, &rotation_x, &rotation_y);
    wobble_phase += wobble_speed;
    if (timer >= 10) {
        if (csnVector(&prev_position, position, -1) != 0) {
            sub_800D47B4();
            return;
        }
        Vec p = *(Vec *)position;
        if (project_actor_to_ground(this, &p, 0) == 1) {
            if (position[1] - p.y < 22.0f) {
                collision->flags |= 2;
                collision->flags &= ~4;
                ((TObjPlayer *)this)->check_object_collisions();
                check_enemy_body_collisions(this);
                if (collision->flags & 0x180000) {
                    sub_800D47B4();
                    return;
                }
            } else {
                collision->flags &= ~2;
                collision->flags |= 4;
            }
        }
    }
    timer++;
    if (timer > gyaranzo_missile_volley_end_time) {
        sub_800D47B4();
    }
}

void *__dt__19TObjGyaranzoMissileFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TObjGyaranzoMissile;
        free_collision_body_parts(arg0);
        __dt__13TUnk_804AF8A0Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_800D4BD0_lbl_80494468_size[sizeof(RecoveredGlobal_800D4BD0_lbl_80494468) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_800D4BD0___vt__19TObjGyaranzoMissile_size[sizeof(RecoveredGlobal_800D4BD0___vt__19TObjGyaranzoMissile) == 0x3C ? 1 : -1];
u8 *TObjGyaranzoMissile__ct(u8 *gyaranzo_missile, u8 *arg1, u8 *arg2, s16 arg3) {
    u8 *temp_r4;
    __ct__13TUnk_804AF8A0FP7TObject(gyaranzo_missile, tl_04);
    *(s32 **)((s8 *)gyaranzo_missile + 0x18) = &(*(RecoveredGlobal_800D4BD0___vt__19TObjGyaranzoMissile *)&__vt__19TObjGyaranzoMissile).value;
    *(s32 *)((s8 *)gyaranzo_missile + 0) = (s32) lbl_805D2A80;
    init_collision_body_parts(gyaranzo_missile, &gyaranzo_missile_collision_body_b.value, 1);
    ((Col_800D4990 *)((TObjGyaranzoMissile *)gyaranzo_missile)->m_a4)->radius = (f32) 4.0f;
    VecCopy((Vec *)((TObjGyaranzoMissile *)gyaranzo_missile)->position, (const Vec *)((int) (*(s32 *)((s8 *)arg2 + 0))));
    ((TObjGyaranzoMissile *)gyaranzo_missile)->target_id = arg3;
    *(s32 *)((s8 *)gyaranzo_missile + 0x5C) = (s32) *(s32 *)((s8 *)arg2 + 4);
    ((TObjGyaranzoMissile *)gyaranzo_missile)->rotation_y = (s32) *(s32 *)((s8 *)arg2 + 8);
    ((TObjGyaranzoMissile *)gyaranzo_missile)->wobble_phase = (s32) (182.04445f * (3.6e+02f * (3.0517578e-05f * (f32) rand())));
    ((TObjGyaranzoMissile *)gyaranzo_missile)->wobble_speed = (s32) (*(f32 *)((s8 *)arg2 + 0xC) * (0.5f * ((3.0517578e-05f * (f32) rand()) + 1.0f)));
    ((TObjGyaranzoMissile *)gyaranzo_missile)->wobble_height = (f32) *(f32 *)((s8 *)arg2 + 0x10);
    *(s16 *)((s8 *)gyaranzo_missile + 0x28) = (s16) *(s16 *)((s8 *)arg1 + 0x28);
    ((TObjGyaranzoMissile *)gyaranzo_missile)->owner_id = get_entity_id(arg1);
    ((TObjGyaranzoMissile *)gyaranzo_missile)->velocity.x = (f32) 0.0f;
    ((TObjGyaranzoMissile *)gyaranzo_missile)->velocity.y = (f32) 0.0f;
    ((TObjGyaranzoMissile *)gyaranzo_missile)->velocity.z = (f32) TObjGyaranzoMissile__speed_scale;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, (int) (((TObjGyaranzoMissile *)gyaranzo_missile)->rotation_y));
    rotate_matrix_x(0, (int) (*(s32 *)((s8 *)gyaranzo_missile + 0x5C)));
    temp_r4 = (gyaranzo_missile + 0xAC);
    matrix_mult_vec(0, (int)temp_r4, (int)temp_r4);
    pop_matrix();
    ((TObjGyaranzoMissile *)gyaranzo_missile)->timer = 0;
    return gyaranzo_missile;
}
}
#pragma pop
