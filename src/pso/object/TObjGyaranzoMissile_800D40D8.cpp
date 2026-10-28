#include "types.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneGyaranzo.h"
#include "pso/object/TUnk_8049442C.h"
#include <dolphin/mtx.h>
#include <stddef.h>
#include "pso/object/TObjGyaranzoMissile.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjMotion.h"

struct D_800D40FC { u8 pad[0x18]; s32 arr[1]; };

struct Hit_800D4200 { s32 a; f32 b; };

struct VBase_18_e08757 { char pad[0x18]; };

struct VObj_18_e08757 : VBase_18_e08757 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual s32 m21(void *, Hit_800D4200 *, s32, s32, s32);
};

struct Info_800D4200 { u8 pad[0xc]; f32 xc; u8 pad10[8]; s32 flags; };

struct Info_800D43B4 { u8 pad[0x18]; u32 flags; };

struct Missile_800D43B4 {
    u8 pad0[0x30];
    u32 flags;
    u8 pad34[0x38 - 0x34];
    Vec pos;
    u8 pad44[0xA4 - 0x44];
    Info_800D43B4 *info;
    u8 padA8[0xAC - 0xA8];
    Vec vel;
    u8 padB8[0xBC - 0xB8];
    s32 angle;
    s32 fC0;
    u8 padC4[0xCC - 0xC4];
    s32 state;
    s32 timer;
    f32 fD4;
    u8 padD8[0xDC - 0xD8];
    s32 spin;
    Vec fE0;
    s32 fEC;
};

extern "C" {
s32 project_actor_to_ground(void *, void *, int);
s32 obj_is_hit_receivable();
void queue_destruction__7TObjectFv(void *arg0);
u8 *get_battle_param__10TObjPlayerFi(s32);
void *spawn_particle_effect(void *pos, s32 id);
s32 remap_area_sound_id(s32 arg0, s32 arg1);
void *find_entity_by_id(u16 id);
void check_enemy_body_collisions(void *arg0);
s32 play_sound_effect(void *, void *, int, int);
extern Hit_800D4200 lbl_8043C440[];

s32 rotate_matrix_y(s32, s32);
s32 pop_matrix();
s32 push_matrix_from(void *src);
void rotate_vector_by_matrix(int, void *, void *);
u32 csnVector(void *, void *, int);
extern u8 identity_matrix[];

s32 post_translate_matrix(void *);
s32 rotate_matrix_x(s32, s32);
void draw_chunk_object(void *child);
s32 push_matrix();

void TObjEneGyaranzo::vfunc_61() {  }
void TObjEneGyaranzo::vfunc_59() {  }
s32 TObjEneGyaranzo::is_target_in_attack_range() { return 0; }
void TObjEneGyaranzo::vfunc_58() {  }
}

extern s32 gyaranzo_missile_param_table;
f32 get_gyaranzo_missile_float_parameter(s32 arg0);
s32 get_gyaranzo_missile_int_parameter(s32 i);

extern s32 model_render_flags;

f32 get_gyaranzo_missile_float_parameter(s32 arg0) {
    return *(f32 *)((s8 *)(gyaranzo_missile_param_table + (arg0 * 4)) + 0);
}

s32 get_gyaranzo_missile_int_parameter(s32 i) {
    return (*(D_800D40FC * *)&gyaranzo_missile_param_table)->arr[i];
}

void TUnk_8049442C::update_ground_fall(s32 *arg1, f32 farg0) {
    Vec position;
    f32 temp_f1;
    s32 temp_r31;
    VecCopy((Vec *)(&position.x), (const Vec *)(((u8 *)this) + 0x38));
    temp_r31 = project_actor_to_ground(this, &position.x, 0);
    if (arg1 != NULL) {
        VecCopy((Vec *)(arg1), (const Vec *)(&position.x));
    }
    if (temp_r31 == 1) {
        this->m_b0 += -0.10888889f;
        *(f32 *)((s8 *)((u8 *)this) + 0x3C) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x3C) + this->m_b0);
        temp_f1 = position.y + farg0;
        position.y = temp_f1;
        if (*(f32 *)((s8 *)((u8 *)this) + 0x3C) <= temp_f1) {
            *(f32 *)((s8 *)((u8 *)this) + 0x3C) = temp_f1;
            this->m_b0 = (f32) 0.0f;
            this->actorFlags = (s32) (this->actorFlags | 0x800000);
            return;
        }
        this->actorFlags = (s32) (this->actorFlags & 0xFF7FFFFF);
        return;
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFF7FFFFF);
}

void TUnk_8049442C::sub_800D4200() {
    u8 *self;
    s32 i;
    u8 *t;
    u8 *arg0 = (u8 *)this;
    self = (u8 *)find_entity_by_id(*(u16 *)((s8 *)arg0 + 0xD8));
    (*(Info_800D4200 * *)&((TUnk_8049442C *)arg0)->m_a4)->xc = 5.0f;
    TObjPlayer::init_all_slots();
    ((TObjPlayer *)arg0)->check_object_collisions();
    check_enemy_body_collisions(arg0);
    if ((*(Info_800D4200 * *)&((TUnk_8049442C *)arg0)->m_a4)->flags & 0x180000) {
        for (i = 0; i < 0x10; i++) {
            t = get_battle_param__10TObjPlayerFi(i);
            if (t == NULL) {
                break;
            }
            if (obj_is_hit_receivable() != 0 && t != self) {
                Hit_800D4200 tmp = lbl_8043C440[0];
                tmp.b = get_gyaranzo_missile_int_parameter(3);
                {
                    Hit_800D4200 h = tmp;
                    ((VObj_18_e08757 *)(t))->m21(self, &h, 0, -1, -1);
                }
            }
        }
    }
    spawn_particle_effect(arg0 + 0x38, 0xFB);
    play_sound_effect((void *)remap_area_sound_id(0x4003A80C, 0x19), arg0 + 0x38, 0, 0);
    queue_destruction__7TObjectFv(arg0);
}

void TUnk_8049442C::render() {
    u8 *arg0 = (u8 *)this;
    TObjFish::set_global_param(*(s32 *)((s8 *)arg0 + 0xC8));
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->m_bc);
    rotate_matrix_x(0, *(s32 *)&this->unk_C0);
    model_render_flags &= 0xFFFFFBFF;
    draw_chunk_object((void *)this->m_c4);
    pop_matrix();
}
void TUnk_8049442C::run_task() {
    Missile_800D43B4 *self = (Missile_800D43B4 *)this;
    self->timer++;
    switch (self->state) {
    case 0:
        self->fC0 += 0x200;
        if (self->fC0 >= 0) {
            self->fC0 = 0;
        }
        self->pos.x += self->vel.x;
        self->pos.z += self->vel.z;
        ((TUnk_8049442C *)self)->update_ground_fall(NULL, 0.0f);
        if (self->flags & 0x800000) {
            push_matrix_from(identity_matrix);
            self->vel.x = 0.0f;
            self->vel.y = 0.0f;
            self->vel.z = 0.8f;
            self->angle += self->spin;
            rotate_matrix_y(0, self->angle);
            rotate_vector_by_matrix(0, &self->vel, &self->vel);
            pop_matrix();
            self->fC0 = 0;
            spawn_particle_effect(&self->pos, 0xF3);
            self->state = 1;
        }
        break;
    case 1: {
        Vec v = self->fE0;
        v.x += self->vel.x;
        v.z += self->vel.z;
        if (csnVector(&self->fE0, &v, -1) == 0) {
            self->pos.x = v.x;
            self->pos.z = v.z;
        } else {
            self->state = 2;
        }
        ((TUnk_8049442C *)self)->update_ground_fall(NULL, 0.0f);
        if (self->fEC > 0) {
            self->fEC--;
        } else {
            ((TObjPlayer *)self)->update_collisions();
            if (self->info->flags & 0x380000) {
                ((TUnk_8049442C *)self)->sub_800D4200();
                break;
            }
        }
        self->fD4 += 0.8f;
        if (self->fD4 >= 5e+01f) {
            self->state = 2;
        }
        break;
    }
    case 2:
        ((TUnk_8049442C *)self)->update_ground_fall(NULL, 0.0f);
        break;
    }
    VecCopy(&self->fE0, &self->pos);
    self->fE0.y += 5.0f;
    if (self->timer >= 0x96) {
        ((TUnk_8049442C *)self)->sub_800D4200();
    }
}

struct RecoveredGlobal_800D4668_lbl_80494400 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_800D4668_lbl_8049442C {
    s32 value;
    u8 remaining[0x38];
};

extern "C" {
u16 get_entity_id(void *);
s32 init_collision_body_parts(void *, void *, int);
s32 __ct__13TUnk_804AF8A0FP7TObject(void *, int);

s32 push_matrix_from(void *);
s32 pop_matrix();
extern RecoveredGlobal_800D4668_lbl_80494400 gyaranzo_missile_collision_body;
extern s32 lbl_8049442C[];

extern s32 gyaranzo_bml_resource;
extern s32 tl_04;

u8 *TObjGyaranzoMissile__sub_800D4668(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4);

void queue_destruction__7TObjectFv(void *);

void *spawn_particle_effect(void *pos, s32 id);
s32 remap_area_sound_id(s32 arg0, s32 arg1);
void *find_entity_by_id(u16);
void check_enemy_body_collisions(void *);
s32 play_sound_effect(void *, void *, int, int);

u32 csnVector(void *, void *, int);
}
s32 get_gyaranzo_missile_int_parameter(s32 i);
extern "C" {
s32 project_actor_to_ground(void *, void *, int);

s32 post_translate_matrix(void *);
void free_collision_body_parts(void *);

s32 push_matrix();
void __dl__7TObjectFPv(void *);

void *TUnk_8049442C::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_8049442C;
        unregister_object_by_id();
        free_collision_body_parts(this);
        __dt__13TUnk_804AF8A0Fv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

extern s32 model_render_flags;

typedef char RecoveredGlobal_800D4668_lbl_80494400_size[sizeof(RecoveredGlobal_800D4668_lbl_80494400) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_800D4668_lbl_8049442C_size[sizeof(RecoveredGlobal_800D4668_lbl_8049442C) == 0x3C ? 1 : -1];
u8 *TObjGyaranzoMissile__sub_800D4668(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4) {
    u8 *temp_r4;
    __ct__13TUnk_804AF8A0FP7TObject(arg0, tl_04);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_800D4668_lbl_8049442C *)&lbl_8049442C).value;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg2));
    VecCopy((Vec *)(arg0 + 0xE0), (const Vec *)(arg0 + 0x38));
    ((TUnk_8049442C *)arg0)->m_e4 += 5.0f;
    ((TUnk_8049442C *)arg0)->m_dc = arg4;
    ((TUnk_8049442C *)arg0)->m_c4 = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&gyaranzo_bml_resource) + 0x42C)) + 0x58);
    *(s32 *)((s8 *)arg0 + 0xC8) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&gyaranzo_bml_resource) + 0x42C)) + 0x5C);
    *(s16 *)((s8 *)arg0 + 0x28) = (s16) *(s16 *)((s8 *)arg1 + 0x28);
    *(u16 *)((s8 *)arg0 + 0xD8) = get_entity_id(arg1);
    ((TUnk_8049442C *)arg0)->m_b8 = 0;
    ((TUnk_8049442C *)arg0)->m_bc = (arg3 + 0x8000);
    *(s32 *)((s8 *)arg0 + 0xC0) = -0x4000;
    ((TUnk_8049442C *)arg0)->m_cc = 0;
    *(s32 *)((s8 *)arg0 + 0xD0) = 0;
    push_matrix_from(identity_matrix);
    *(f32 *)((s8 *)arg0 + 0xAC) = (f32) 0.0f;
    ((TUnk_8049442C *)arg0)->m_b0 = (f32) 0.0f;
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) 0.5f;
    rotate_matrix_y(0, (int) (((TUnk_8049442C *)arg0)->m_bc));
    temp_r4 = (arg0 + 0xAC);
    rotate_vector_by_matrix(0, temp_r4, temp_r4);
    pop_matrix();
    ((TUnk_8049442C *)arg0)->m_d4 = (f32) 0.0f;
    init_collision_body_parts(arg0, &gyaranzo_missile_collision_body.value, 1);
    *(f32 *)((s8 *)(((TUnk_8049442C *)arg0)->m_a4) + 0xC) = (f32) 3.0f;
    ((TObjPlayer *)arg0)->reset_photon_effect();
    ((TUnk_8049442C *)arg0)->m_ec = 0xF;
    return arg0;
}

}
