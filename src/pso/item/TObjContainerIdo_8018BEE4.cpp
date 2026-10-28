#include "pso/misc/RenderFadeState.h"
#include "pso/system/vector.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/item/TObjContainerJungEnemy.h"
#include "pso/item/TObjContainerIdo.h"
#include "pso/item/TUnk_804B97C0.h"
#include "pso/misc/TContainerAncient01.h"
#include "pso/misc/TContainerAncient01R.h"
#include "types.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Vec_8018BEE4 { f32 x, y, z; };

extern "C" {
s32 get_bml_model(int, int);
s32 init_collision_body_parts(void *, void *, int);

f32 xyz_distance_squared(u8 *arg0, u8 *arg1);
void matrix_mult_vec(int, void *, void *);
void project_world_to_screen(int, void *, void *, void *);
extern Vec_8018BEE4 camera_right;
extern u8 *camera_ctrl_instance;

s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);

#pragma push
#pragma fp_contract on
s32 TObjContainerIdo::update_object_view_visibility(f32 farg0, f32 farg1) {
    u8 *arg0 = (u8 *)this;
    Vec_8018BEE4 p;
    f32 out[2];
    matrix_mult_vec(0, (u8 *)&this->m_c0, &p);
    if (xyz_distance_squared((u8 *)&this->position, camera_ctrl_instance + 0x178) < farg1 * farg1) {
        return 1;
    }
    if (p.z + farg1 / 2.0f > 0.0f) {
        return 0;
    }
    if (p.z < -farg0) {
        return 0;
    }
    if (p.x < 0.0f) {
        p.x = camera_right.x * farg1 + *(f32 *)((s8 *)arg0 + 0x38);
        p.y = camera_right.y * farg1 + *(f32 *)((s8 *)arg0 + 0x3C);
        p.z = camera_right.z * farg1 + *(f32 *)((s8 *)arg0 + 0x40);
        project_world_to_screen(0, &p, out, &camera_right);
        if (out[0] < 0.0f) {
            return 0;
        }
    } else {
        p.x = *(f32 *)((s8 *)arg0 + 0x38) - camera_right.x * farg1;
        p.y = *(f32 *)((s8 *)arg0 + 0x3C) - camera_right.y * farg1;
        p.z = *(f32 *)((s8 *)arg0 + 0x40) - camera_right.z * farg1;
        project_world_to_screen(0, &p, out, &camera_right);
        if (out[0] > 6.4e+02f) {
            return 0;
        }
    }
    return 1;
}
#pragma pop

struct VOuter_8018C06C {
    char pad[0x18];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};
struct VMem_8018C06C {
    char pad[0x14];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

u8 *TObjContainerIdo__ct(u8 *arg0, s32 arg1, s32 arg2);
void render__16TObjContainerIdoFv(u8 *arg0);
s32 post_translate_matrix(void *);
void draw_ginja_object(void *);
s32 rotate_matrix_x(s32, s32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
void *__nw__7TObjectFUl(int);

extern u32 TObjContainerIdo__model_resource;

void render__16TObjContainerIdoFv(u8 *container_ido) {
    s32 var_r31;

    if (((VOuter_8018C06C*)container_ido)->m8(4e+02f, 2e+02f) != 0) {
        var_r31 = 0;
        if (TRaderMapCore::is_not_split_screen() == 0) {
            var_r31 = ((RenderFadeState*)(container_ido + 0xF0))->updateFromCamera((const f32*)(container_ido + 0x38));
        }
        if (var_r31 != 0) {
            ((VMem_8018C06C*)(container_ido + 0xF0))->m6();
        }
        {
            extern const u32 container_ido_texture_gvm_handle;
            u32 temp = (u32) container_ido_texture_gvm_handle;
            if (temp != 0U) {
                TObjFish::set_global_param(temp);
            }
        }
        push_matrix();
        post_translate_matrix(container_ido + 0xC0);
        rotate_matrix_y(0, ((TObjContainerIdo *)container_ido)->rotation_y);
        rotate_matrix_x(0, *(s32 *)((s8 *)container_ido + 0x5C));
        draw_ginja_object((void *)get_bml_model(TObjContainerIdo__model_resource, 0));
        pop_matrix();
        push_matrix();
        post_translate_matrix(container_ido + 0x38);
        rotate_matrix_y(0, ((TObjContainerIdo *)container_ido)->rotation_y);
        rotate_matrix_x(0, *(s32 *)((s8 *)container_ido + 0x5C));
        draw_ginja_object((void *)get_bml_model(TObjContainerIdo__model_resource, 1));
        pop_matrix();
        if (var_r31 != 0) {
            ((VMem_8018C06C*)(container_ido + 0xF0))->m7();
        }
    }
}

struct Vec3_8018C18C { f32 x, y, z; };
struct VObj_8018C18C {
    char pad[0x18];
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};
struct Ido_8018C18C {
    u8 pad0[0x38];
    Vec3_8018C18C pos;
    u8 pad44[0x5C - 0x44];
    s32 f5c;
    s32 f60;
    u8 pad64[0xC0 - 0x64];
    Vec3_8018C18C c0;
    s32 ids[4];
    s32 dc;
    u32 e0;
    f32 e4;
    f32 e8;
    f32 ec;
    u8 f0[4];
};
u8 is_current_floor_switch_set(u16);
f32 xyz_distance(void *, void *);
s32 push_matrix_from(void *);
void rotate_vector_by_matrix(int, void *, void *);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void play_sound_effect(s32, void *, s32, s32);
s32 rand();
void *spawn_particle_effect(void *pos, s32 id);
int update_obstruction_fade(void*);
extern const Vec3_8018C18C lbl_80445110;
extern const Vec3_8018C18C lbl_8044511C;
extern u8 identity_matrix[];

#pragma push
#pragma fp_contract on
void run_task__16TObjContainerIdoFv(Ido_8018C18C *self) {
    f32 prev;
    u32 old;
    s32 i;

    prev = self->e4;
    old = self->e0 & 0xF;
    self->e4 = 0.0f;
    for (i = 0; i < self->dc; i++) {
        if (is_current_floor_switch_set((u16)self->ids[i]) == 1) {
            self->e0 |= 1 << i;
            self->e4 += self->e8;
        } else {
            self->e0 &= ~(1 << i);
        }
    }
    if ((old ^ (self->e0 & 0xF)) != 0) {
        if (prev - self->e4 < 0.0f) {
            self->e0 &= ~0x02000000;
            self->e0 &= ~0x01000000;
        } else {
            self->e0 |= 0x02000000;
            self->e0 &= ~0x01000000;
        }
    }
    self->e0 &= ~0x04000000;
    if (self->e0 & 0x02000000) {
        if (xyz_distance(&self->c0, &self->pos) > self->e4) {
            Vec3_8018C18C v = lbl_80445110;
            v.z = -self->ec;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, self->f60);
            rotate_matrix_x(0, self->f5c);
            rotate_vector_by_matrix(0, &v, &v);
            pop_matrix();
            self->pos.x -= v.x;
            self->pos.y -= v.y;
            self->pos.z -= v.z;
            self->e0 |= 0x04000000;
            play_persistent_sound(0x4B717, (s32)self, (u32)&self->pos, 0, 0);
        } else if (!(self->e0 & 0x01000000)) {
            play_sound_effect(0x4C118, &self->pos, 0, 0);
            self->e0 |= 0x01000000;
        }
    } else {
        if (xyz_distance(&self->c0, &self->pos) < self->e4) {
            Vec3_8018C18C w = lbl_8044511C;
            w.z = -self->ec;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, self->f60);
            rotate_matrix_x(0, self->f5c);
            rotate_vector_by_matrix(0, &w, &w);
            pop_matrix();
            self->pos.x += w.x;
            self->pos.y += w.y;
            self->pos.z += w.z;
            self->e0 |= 0x04000000;
            play_persistent_sound(0x4B717, (s32)self, (u32)&self->pos, 0, 0);
        } else if (!(self->e0 & 0x01000000)) {
            play_sound_effect(0x4C118, &self->pos, 0, 0);
            self->e0 |= 0x01000000;
        }
    }
    if (!(self->e0 & 0x08000000) && (self->e0 & 0x04000000)) {
        if (3.0517578e-05f * (f32)rand() < 0.4f && ((VObj_8018C18C *)self)->m8(4e+02f, 1e+02f) != 0) {
            Vec3_8018C18C a;
            Vec3_8018C18C b;
            Vec3_8018C18C out;
            a.x = 1e+01f;
            a.y = 2.0f;
            a.z = 3e+01f * (3.0517578e-05f * (f32)rand()) - 15.0f;
            b.x = (-1e+01f);
            b.y = 2.0f;
            b.z = 3e+01f * (3.0517578e-05f * (f32)rand()) - 15.0f;
            push_matrix_from(identity_matrix);
            post_translate_matrix(&self->pos);
            rotate_matrix_y(0, self->f60);
            rotate_matrix_x(0, self->f5c);
            matrix_mult_vec(0, &a, &out);
            spawn_particle_effect(&out, 0x42);
            matrix_mult_vec(0, &b, &out);
            spawn_particle_effect(&out, 0x42);
            pop_matrix();
        }
    }
    update_obstruction_fade(self->f0);
}
#pragma pop

extern void *tl_05;

void *TObjContainerIdo::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x10C);
    if (o != NULL) {
        o = TObjContainerIdo__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

}

struct RecoveredGlobal_8019A9B8_lbl_80446184 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8019A9B8_lbl_804B8F60 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8019A880_lbl_804B8F70 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8019A880___vt__8TObjTank {
    s32 value;
    u8 remaining[0x38];
};

struct Ido_8018C7BC { u8 pad[0xCC]; s32 ids[4]; };

extern "C" {
extern u32 container_ido_texture_gvm_handle;
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
u8 * load_gvm_texture_file(s32);
extern RecoveredGlobal_8019A9B8_lbl_80446184 lbl_80445130;
extern RecoveredGlobal_8019A9B8_lbl_804B8F60 container_ido_resource_descriptor;

extern u8 container_ido_collision_parts[];
extern s32 __vt__16TObjContainerIdo[];
extern s32 obj_container_ido_class_name;
void *__dt__16TObjContainerIdoFv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
s32 release_texture_list(void*);
void *__dt__13TUnk_804949A8Fv(void *arg0, s16 arg1);

void TObjContainerIdo::free_resources() {
    if ((u32) container_ido_texture_gvm_handle != 0U) {
        release_texture_list((void*)container_ido_texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(container_ido_texture_gvm_handle);
        container_ido_texture_gvm_handle = 0U;
    }
    if ((u32) TObjContainerIdo__model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjContainerIdo__model_resource, 1);
        TObjContainerIdo__model_resource = 0U;
    }
}

typedef char RecoveredGlobal_8019A880_lbl_804B8F70_size[sizeof(RecoveredGlobal_8019A880_lbl_804B8F70) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8019A880___vt__8TObjTank_size[sizeof(RecoveredGlobal_8019A880___vt__8TObjTank) == 0x3C ? 1 : -1];
typedef char RecoveredGlobal_8019A9B8_lbl_80446184_size[sizeof(RecoveredGlobal_8019A9B8_lbl_80446184) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_8019A9B8_lbl_804B8F60_size[sizeof(RecoveredGlobal_8019A9B8_lbl_804B8F60) == 0x10 ? 1 : -1];
void TObjContainerIdo::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = ((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &container_ido_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjContainerIdo__model_resource) = var_r0;
    (*(u8 * *)&container_ido_texture_gvm_handle) = load_gvm_texture_file((s32) &lbl_80445130.value);
}

void *__dt__16TObjContainerIdoFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjContainerIdo;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804949A8Fv((s8 *)arg0 + 0xF0, -1);
        ((TUnk_804B97C0 *)arg0)->dt(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TObjContainerIdo__ct(u8 *arg0, s32 arg1, s32 arg2) {
    s32 i;
    ((TUnk_804B97C0 *)arg0)->init_positions();
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjContainerIdo;
    ((TObjPlayer *)(arg0 + 0xF0))->init_and_activate();
    *(s32 *)((s8 *)arg0 + 0) = obj_container_ido_class_name;
    ((TObjContainerIdo *)(arg0))->apply_object_set_data((void *)arg2);
    VecCopy((Vec *)(arg0 + 0xC0), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0xB4), (const Vec *)(arg0 + 0x38));
    *(f32 *)&((TObjContainerIdo *)arg0)->m_b0 = 1e+02f;
    *(s32 *)&((TObjContainerIdo *)arg0)->m_dc = *(s32 *)((s8 *)arg0 + 0x88);
    if (*(s32 *)&((TObjContainerIdo *)arg0)->m_dc < 1) {
        *(s32 *)&((TObjContainerIdo *)arg0)->m_dc = 1;
    }
    if (*(s32 *)&((TObjContainerIdo *)arg0)->m_dc > 4) {
        *(s32 *)&((TObjContainerIdo *)arg0)->m_dc = 4;
    }
    for (i = 0; i < *(s32 *)&((TObjContainerIdo *)arg0)->m_dc; i++) {
        ((Ido_8018C7BC *)arg0)->ids[i] = ((TObjContainerIdo *)arg0)->m_84 + i;
    }
    ((TObjContainerIdo *)arg0)->m_e0 = 0;
    if (*(s32 *)&((TObjContainerIdo *)arg0)->m_8c != 0) {
        ((TObjContainerIdo *)arg0)->m_e0 |= 0x08000000;
    } else {
        ((TObjContainerIdo *)arg0)->m_e0 &= ~0x08000000;
    }
    *(f32 *)((s8 *)arg0 + 0xE4) = 0.0f;
    ((TObjContainerIdo *)arg0)->m_e8 = ((TObjContainerIdo *)arg0)->scale / *(s32 *)&((TObjContainerIdo *)arg0)->m_dc;
    *(f32 *)((s8 *)arg0 + 0xEC) = ((TObjContainerIdo *)arg0)->target_scale;
    ((TObjPlayer *)(arg0 + 0xF0))->activate_and_dispatch();
    init_collision_body_parts(arg0, container_ido_collision_parts, 1);
    ((TObjContainerIdo *)arg0)->actorFlags |= 0x40000000;
    ((TObjPlayer *)arg0)->reset_photon_effect();
    return arg0;
}

}
