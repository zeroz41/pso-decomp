#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/enemy/TUnk_804E14E8.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjGyaranzoMissile.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/CurrentArea.h"

struct Vec_802CDEB4 { f32 x, y, z; };

struct Ang_802CDEB4 { s32 x; s32 y; s32 z; };

struct Rot_802CDEB4 { s32 a; s32 b; };

struct Vec_802CDB1C { f32 x, y, z; };

struct Hit_802CDB1C { s32 kind; f32 power; };

struct VBase_802CDB1C { u8 pad[0x18]; };

struct VEnt_802CDB1C : VBase_802CDB1C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(void *src, Hit_802CDB1C *hit, s32 a, s32 b, s32 c);
};

struct Shot_802CDB1C {
    u8 pad0[0xAC];
    Vec_802CDB1C pos;
    Vec_802CDB1C prev;
    Vec_802CDB1C vel;
    u8 padD0[0xEC - 0xD0];
    s32 timer;
    Vec_802CDB1C *start;
    f32 speed;
    void *ptcl0;
    void *ptcl1;
    s32 state;
    s32 f104;
    u16 target_id;
    u16 src_id;
};

extern "C" {
f32 atan2_float(f32 y, f32 x);
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
u8 *find_entity_by_id(s16);
s32 __ct__13TUnk_804AF8A0FP7TObject(void *, s32);
s32 matrix_mult_vec(void *, Vec_802CDEB4 *, void *);
s32 rotate_matrix_y(void *, s32);
s32 rotate_matrix_x(void *, s32);
s32 push_matrix_from(void *);
s32 pop_matrix();
extern Vec_802CDEB4 lbl_804722A8;
extern const f64 lbl_804722C8[];
extern s32 lbl_804E14E8[];
extern u8 identity_matrix[];
extern s32 tl_04;
extern f32 lbl_805D6844;
extern f32 lbl_805D6848;
extern const f32 lbl_805DE6C0;
extern const f32 lbl_805DE6C4;
extern const f32 lbl_805DE6C8;
u8 *TObjPlayer__sub_802CDEB4(u8 *arg0, Vec_802CDEB4 *arg1, s16 arg2, Rot_802CDEB4 *arg3, s32 arg4, s32 arg5, s16 arg6);
void queue_destruction__7TObjectFv(void *);
u32 csnVector(void *, void *, s32);
void *spawn_particle_effect(void *pos, s32 id);
VEnt_802CDB1C *find_active_entity_by_id(u16);
s32 play_sound_effect(s32, void *, s32, s32);
s32 vec3_add_to(void *, void *);
s32 subtract_vector(void *, void *);
extern Hit_802CDB1C lbl_804722B4[];
extern s32 local_client_id;
extern const f32 lbl_805D684C;
extern s32 lbl_805D6854;
void TObjPlayer__sub_802CDB1C(u8 *arg0);
void *__dt__13TUnk_804E14E8Fv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

#pragma push
#pragma opt_common_subs off
#define self ((Shot_802CDB1C *)arg0)
void TObjPlayer__sub_802CDB1C(u8 *arg0) {
    u8 *src;
    VEnt_802CDB1C *tgt;
    Vec_802CDB1C v;
    src = ((u8 *(*)(u16))find_entity_by_id)(self->src_id);
    if (src == NULL) {
        queue_destruction__7TObjectFv(self);
        return;
    }
    tgt = find_active_entity_by_id(self->target_id);
    switch (self->state) {
    case 0:
        self->timer--;
        if (self->timer <= 0) {
            self->timer = 0;
            VecCopy((Vec *)&self->pos, (const Vec *)self->start);
            self->state = 1;
            if (get_current_area() == 0x23) {
                play_sound_effect(0x4003A313, &self->pos, 0, 0);
                return;
            }
            play_sound_effect(0x3A820, &self->pos, 0, 0);
            return;
        }
        if (self->ptcl0 != NULL) {
            ((TParticleCtrl *)(self->ptcl0))->enable();
        }
        if (self->ptcl1 != NULL) {
            ((TParticleCtrl *)(self->ptcl1))->enable();
        }
        return;
    case 1:
        self->timer++;
        if (self->timer >= 0x5A) {
            queue_destruction__7TObjectFv(self);
            return;
        }
        if (tgt != NULL) {
            VecCopy((Vec *)&v, (const Vec *)((u8 *)tgt + 0x2FC));
            subtract_vector(&v, &self->pos);
            vec_set_length((Vec *)&v, self->speed);
            self->speed += lbl_805D684C;
            vec3_add_to(&self->vel, &v);
            vec_set_length((Vec *)&self->vel, lbl_805D6844);
        }
        VecCopy((Vec *)&self->prev, (const Vec *)&self->pos);
        vec3_add_to(&self->pos, &self->vel);
        if (self->ptcl0 != NULL) {
            ((TNowLoading *)(self->ptcl0))->copy_pos(&self->pos);
        }
        if (self->ptcl1 != NULL) {
            ((TNowLoading *)(self->ptcl1))->copy_pos(&self->pos);
        }
        if (csnVector(&self->prev, &self->pos, -1) != 0) {
            queue_destruction__7TObjectFv(self);
            return;
        }
        if (tgt != NULL && !(*(s32 *)((s8 *)tgt + 0x30) & 0x04000A00) &&
            xyz_distance_squared((Vec *)&self->pos, (Vec *)((u8 *)tgt + 0x2FC)) <= lbl_805D6844 * lbl_805D6844) {
            Hit_802CDB1C h = lbl_804722B4[0];
            h.power = (f32)lbl_805D6854;
            {
                Hit_802CDB1C h1 = h;
                tgt->m21(src, &h1, 0, -1, -1);
            }
            if (self->f104 == 1) {
                h.kind = 0x12;
                Hit_802CDB1C h2 = h;
                tgt->m21(src, &h2, 0, -1, -1);
            }
            spawn_particle_effect((u8 *)tgt + 0x2FC, 0x8E);
            if (local_client_id == self->target_id) {
                ((TObjEneMe1GiGue *)src)->apply_hit_shake((u32)tgt);
            }
            queue_destruction__7TObjectFv(self);
        }
        break;
    }
}
#undef self
#pragma pop

void *__dt__13TUnk_804E14E8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E14E8;
        if (*(void **)((s8 *)arg0 + 0xF8) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xF8)); ((TUnk_804E14E8 *)arg0)->m_f8 = 0; }
        if (*(void **)((s8 *)arg0 + 0xFC) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xFC)); *(s32 *)((s8 *)arg0 + 0xFC) = 0; }
        __dt__13TUnk_804AF8A0Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TObjPlayer__sub_802CDEB4(u8 *arg0, Vec_802CDEB4 *arg1, s16 arg2, Rot_802CDEB4 *arg3, s32 arg4, s32 arg5, s16 arg6) {
    Vec_802CDEB4 *pos;
    __ct__13TUnk_804AF8A0FP7TObject(arg0, tl_04);
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E14E8;
    ((TUnk_804E14E8 *)arg0)->m_108 = arg2;
    *(s16 *)((s8 *)arg0 + 0x10A) = arg6;
    *(s32 *)((s8 *)arg0 + 0x104) = arg5;
    ((TUnk_804E14E8 *)arg0)->m_f0 = arg1;
    ((TUnk_804E14E8 *)arg0)->m_e8 = lbl_805DE6C0;
    push_matrix_from(identity_matrix);
    {
        Vec_802CDEB4 v = lbl_804722A8;
        v.z = lbl_805D6844;
        rotate_matrix_y(0, arg3->b);
        rotate_matrix_x(0, arg3->a);
        matrix_mult_vec(0, &v, arg0 + 0xC4);
    }
    pop_matrix();
    *(s32 *)((s8 *)arg0 + 0xEC) = arg4;
    pos = (Vec_802CDEB4 *)(find_entity_by_id(arg2) + 0x2FC);
    {
    Ang_802CDEB4 ang;
    ang.x = 0;
    ang.y = (s32)(lbl_804722C8[0] * atan2_float(pos->x - arg1->x, pos->z - arg1->z)) + 0x4000;
    ang.z = 0x4000 - (s32)(lbl_804722C8[0] * atan2_float(pos->y - arg1->y, vec_xz_distance((Vec *)pos, (Vec *)arg1)));
    ((TUnk_804E14E8 *)arg0)->m_f8 = (s32)spawn_particle_effect_with_rotation(arg1, &ang, 0x201, 2);
    *(s32 *)((s8 *)arg0 + 0xFC) = (s32)spawn_particle_effect_with_rotation(arg1, &ang, 0x202, 2);
    }
    *(f32 *)((s8 *)arg0 + 0xF4) = lbl_805D6848;
    if (xz_distance_squared((Vec *)pos, (Vec *)arg1) < lbl_805DE6C4) {
        *(f32 *)((s8 *)arg0 + 0xF4) *= lbl_805DE6C8;
    }
    ((TUnk_804E14E8 *)arg0)->m_100 = 0;
    return arg0;
}

}
