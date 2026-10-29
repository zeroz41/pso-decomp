#include "types.h"
#include "pso/enemy/TUnk_804EF130.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneMorfos.h"
#include "pso/misc/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Vec_80337500 { f32 x, y, z; };

struct P_80337500 { s32 a; f32 f; };

struct B_80337500 { u8 pad[0x18]; };

struct V_80337500 : B_80337500 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(V_80337500 *src, P_80337500 *p, s32 a, s32 b, s32 c);
};

struct O_80337500 { u8 pad[0xAC]; Vec_80337500 pos; u8 b8[4]; };

struct Vec_80337824 { f32 x, y, z; };

struct Ang_80337824 { s32 x, y, z; };

struct O_80337824 { u8 pad[0x18]; void *vt; u8 pad1[0xAC - 0x1C]; Vec_80337824 pos; Vec_80337824 vel; u8 pad2[0xDC - 0xC4]; f32 fDC; s32 fE0; Vec_80337824 pos2; u8 padF0[4]; s32 fF4; s16 fF8; };

struct Vec_80337644 { f32 x, y, z; };

struct O_80337644 {
    u8 pad[0xAC]; Vec_80337644 pos; Vec_80337644 vel;
    u8 pad2[0xDC - 0xC4]; f32 fDC; void *fE0; Vec_80337644 pos2; s32 fF0; s32 fF4; u16 fF8;
};

extern "C" {
s32 *csnVecterUnder(s32 origin, s32 mask);
f32 xz_distance_squared(void *, void *);
void subtract_vector(void *, void *);
extern P_80337500 lbl_80477B70[];
extern const f32 morfos_projectile_speed;
extern const f32 morfos_param_table_speed_copy;
extern const f32 lbl_805DF988;
void hit_target_in_range__13TObjEneMorfosFPvPvPv(O_80337500 *arg0, V_80337500 *arg1, V_80337500 *arg2);
s16 get_entity_id(void *);
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
void __ct__14TObjCollidableFP7TObject(void *, s32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern s32 lbl_804EF130[];
extern s32 tl_06;
extern const f32 lbl_805DF994;
O_80337824 *TObjEneMorfos__sub_80337824(O_80337824 *arg0, Vec_80337824 *arg1, s32 arg2, void *arg3);
int get_player_data__10TObjPlayerFi(int a0);
f32 fabs_float(f32);
void queue_destruction__7TObjectFv(void *);
u32 csnVector(void *, void *, int);
void *find_entity_by_id(u16 id);
void vec3_add_to(void *, void *);
extern s32 registered_player_count;
extern const f32 lbl_805DF98C;
extern const f32 lbl_805DF990;
void update_projectile__13TObjEneMorfosFPv(O_80337644 *arg0);
void *__dt__13TUnk_804EF130Fv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

void hit_target_in_range__13TObjEneMorfosFPvPvPv(O_80337500 *arg0, V_80337500 *arg1, V_80337500 *arg2) {
    Vec_80337500 v = arg0->pos;
    subtract_vector(&v, arg0->b8);
    if (arg1 != 0 && arg1 != arg2 && !(*(s32 *)((u8 *)arg1 + 0x30) & 0x04000A00)) {
        if (!(xz_distance_squared(&v, (u8 *)arg1 + 0x2FC) > (lbl_805DF988 * morfos_projectile_speed) * (lbl_805DF988 * morfos_projectile_speed))) {
            P_80337500 tmp = lbl_80477B70[0];
            tmp.f = morfos_param_table_speed_copy;
            P_80337500 p = tmp;
            arg1->m21(arg2, &p, 0, -1, -1);
        }
    }
}

s32 TObjEneMorfos::snap_to_ground(s32 arg0, s32 arg1) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(csnVecterUnder(arg1, 0x16EF));
    if (temp_r3 == NULL) {
        return 0;
    }
    VecCopy((Vec *)(arg1), (const Vec *)(*(s32 *)((s8 *)temp_r3 + 4)));
    return 1;
}

struct O_80337500;
struct V_80337500;
void update_projectile__13TObjEneMorfosFPv(O_80337644 *arg0) {
    s32 k;
    s32 i;
    u8 *p;
    Vec_80337644 v = arg0->pos;
    vec3_add_to(&arg0->pos, &arg0->vel);
    if (arg0->fE0 != 0) {
        ((TParticleCtrl *)arg0->fE0)->set_position(&arg0->pos);
    }
    arg0->fDC += morfos_projectile_speed;
    if (arg0->fF0 != 0) {
        VecCopy((Vec *)&arg0->pos2, (const Vec *)&arg0->pos);
        arg0->fF4++;
        if (arg0->fF4 > 4) {
            arg0->fF4 = 0;
            TObjEneMorfos::snap_to_ground((s32)arg0, (s32)&arg0->pos2);
        }
    }
    if (arg0->fDC >= lbl_805DF98C) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    if (csnVector(&v, &arg0->pos, -1) != 0) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    k = (s32)find_entity_by_id(arg0->fF8);
    if (k != 0) {
        for (i = 0; i < registered_player_count; i++) {
            p = (u8 *)get_player_data__10TObjPlayerFi(i);
            if (TObjPlayer::is_valid_and_active((u32)p) != 0 && fabs_float(arg0->pos.y - *(f32 *)(p + 0x300)) < lbl_805DF990) {
                hit_target_in_range__13TObjEneMorfosFPvPvPv((O_80337500 *)arg0, (V_80337500 *)p, (V_80337500 *)k);
            }
        }
    }
}

void *__dt__13TUnk_804EF130Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804EF130;
        if (((TUnk_804EF130 *)arg0)->m_e0 != NULL) { queue_destruction__7TObjectFv(((TUnk_804EF130 *)arg0)->m_e0); }
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
O_80337824 *TObjEneMorfos__sub_80337824(O_80337824 *arg0, Vec_80337824 *arg1, s32 arg2, void *arg3) {
    Ang_80337824 a;
    __ct__14TObjCollidableFP7TObject(arg0, tl_06);
    arg0->vt = ((u8 *)&lbl_804EF130);
    VecCopy((Vec *)(&arg0->pos), (const Vec *)(arg1));
    arg0->fDC = lbl_805DF994;
    arg0->fF8 = get_entity_id(arg3);
    a.x = 0;
    a.y = arg2 - 0x4000;
    a.z = 0x4000;
    arg0->vel.x = morfos_projectile_speed * sin_table_lookup(arg2);
    arg0->vel.y = lbl_805DF994;
    arg0->vel.z = morfos_projectile_speed * cos_table_lookup(arg2);
    arg0->fE0 = (s32)spawn_particle_effect_with_rotation(arg1, &a, 0x213, 2);
    VecCopy((Vec *)(&arg0->pos2), (const Vec *)(&arg0->pos));
    TObjEneMorfos::snap_to_ground((s32)arg0, (s32)&arg0->pos2);
    arg0->fF4 = 0;
    return arg0;
}

}
