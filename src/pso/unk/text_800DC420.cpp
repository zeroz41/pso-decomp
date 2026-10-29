#include "types.h"
#include "pso/unk/TUnk_80494E10.h"
#include "pso/system/NinjaUtil.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneNanoDrago.h"
#include "pso/unk/TUnk_80494E10.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjGyaranzoMissile.h"
#include "pso/TParticleCtrl.h"

struct D_800DC420 { u8 pad[0x18]; s32 arr[1]; };

struct E_800DC448 { s32 f0; s32 f4; s32 f8; s32 fc; };

struct D_800DC448 { u8 pad[0x42c]; E_800DC448 *entries; };

struct O_800DC448 { u8 pad[0x24]; s32 f24; u8 pad2[0xc]; s32 f34; };

typedef struct Parm_800DC4B4 {
    s32 a;
    f32 b;
} Parm_800DC4B4;

struct Base_800DC4B4 {
    char pad[0x18];
};

struct Obj_800DC4B4 : Base_800DC4B4 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(void *, Parm_800DC4B4, s32, s32, s32);
    u8 pad1C[0x30 - 0x1C];
    u32 flags;
    u8 pad34[0x2FC - 0x34];
    f32 pos[3];
};

typedef struct Src_800DC4B4 {
    u8 pad0[0xAC];
    f32 pos[3];
} Src_800DC4B4;

struct Vec_800DC648 { f32 x, y, z; };

struct Me_800DC648 {
    u8 pad0[0xAC];
    Vec_800DC648 pos;
    Vec_800DC648 vel;
    u8 padC4[0xDC - 0xC4];
    f32 timer;
    void *link0;
    void *link1;
    Vec_800DC648 prev;
    s32 trail;
    s32 cnt;
    u16 owner;
};

struct Vec_800DC83C { f32 x, y, z; };

struct Ang_800DC83C { s32 x, y, z; };

extern "C" {
s32 TObjPlayer__sub_800DC478(u8 *arg0, s32 arg1, f32 farg0);
s32 *csnVecterUnder(s32 origin, s32 mask);
extern s32 lbl_805D5254;
f32 TObjPlayer__sub_800DC434(s32 arg0, s32 arg1);
s32 TObjPlayer__sub_800DC420(void *self, s32 i);
extern D_800DC448 *nano_drago_entry_params_resource;
u16 get_entity_id(void *);
s32 is_split_screen();
s32 spawn_particle_effect(void *, int);
extern const f32 lbl_805D525C;
extern s32 lbl_805D526C;
extern s32 local_client_id;
void hit_object_in_radius__10TObjPlayerFPvPvPv(Src_800DC4B4 *arg0, Obj_800DC4B4 *obj, void *attacker);
int get_player_data__10TObjPlayerFi(int a0);
void queue_destruction__7TObjectFv(void *);
u32 csnVector(void *, void *, int);
void *find_entity_by_id(u16);
s32 is_valid_and_active__10TObjPlayerFUl();
s32 vec3_add_to(void *, void *);
extern s32 registered_player_count;
extern s32 lbl_805D5870;
extern const f32 lbl_805DA478;
f32 atan2_float(f32, f32);
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
s32 __ct__14TObjCollidableFP7TObject(void *, int);
f32 vector_length(void *);
s32 subtract_vector(void *, void *);
extern s32 __vt__13TUnk_80494E10[];
extern s32 tl_06;
extern const f32 lbl_805DA47C;
u8 *construct_beam_effect__10TObjPlayerFPvPvPviPv(u8 *arg0, Vec_800DC83C *arg1, Vec_800DC83C *arg2, s32 arg3, void *arg4);
void TObjPlayer__sub_800DC444(void);
void *__dt__13TUnk_80494E10Fv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

s32 TObjPlayer__sub_800DC420(void *self, s32 i) {
    return (*(D_800DC420 * *)&lbl_805D5254)->arr[i];
}

f32 TObjPlayer__sub_800DC434(s32 arg0, s32 arg1) {
    return *(f32 *)((s8 *)(lbl_805D5254 + (arg1 * 4)) + 0);
}

void TObjPlayer__sub_800DC444(void) {  }

void TObjEneNanoDrago::load_entry_params_nanodrago(s32 i) {
    O_800DC448 *self = (O_800DC448 *)this;
    self->f34 = nano_drago_entry_params_resource->entries[i].f8;
    self->f24 = nano_drago_entry_params_resource->entries[i].fc;
}

s32 TObjPlayer__sub_800DC478(u8 *arg0, s32 arg1, f32 farg0) {
    f32 temp_f2;
    if ((s16) *(s16 *)((s8 *)arg0 + 0xB8) == arg1) {
        temp_f2 = *(f32 *)((s8 *)arg0 + 0xC0);
        if ((temp_f2 >= farg0) && (temp_f2 < (farg0 + *(f32 *)((s8 *)arg0 + 0xC8)))) {
            return 1;
        }
    }
    return 0;
}

void hit_object_in_radius__10TObjPlayerFPvPvPv(Src_800DC4B4 *arg0, Obj_800DC4B4 *obj, void *attacker) {
    if (obj == NULL) {
        return;
    }
    if ((void *)obj == attacker) {
        return;
    }
    if (obj->flags & 0x4000A00) {
        return;
    }
    if (xyz_distance_squared((Vec *)arg0->pos, (Vec *)obj->pos) > lbl_805D525C * lbl_805D525C) {
        return;
    }
    Parm_800DC4B4 parm = {0, 0.0f};
    parm.b = lbl_805D526C;
    obj->v21(attacker, parm, 0, -1, -1);
    if (attacker != NULL) {
        if (obj->flags & 0x800) {
            ((TObjPlayer *)attacker)->set_flag_20000();
        }
        if (is_split_screen() == 0 && local_client_id == get_entity_id(obj)) {
            ((TObjPlayer *)attacker)->trigger_hit_camera_shake((u32)obj);
        }
    }
    spawn_particle_effect(obj->pos, 0xFB);
    spawn_particle_effect(obj->pos, 0xFC);
}

s32 TObjPlayer::snap_to_ground(s32 arg0, s32 arg1) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(csnVecterUnder(arg1, 0x16EF));
    if (temp_r3 == NULL) {
        return 0;
    }
    VecCopy((Vec *)(arg1), (const Vec *)(*(s32 *)((s8 *)temp_r3 + 4)));
    return 1;
}

void TUnk_80494E10::run_task() {
    Me_800DC648 *arg0 = (Me_800DC648 *)this;
    void *att;
    s32 i;
    void *pl;
    Vec_800DC648 old = arg0->pos;
    vec3_add_to(&arg0->pos, &arg0->vel);
    if (arg0->link0 != NULL) {
        ((TParticleCtrl *)arg0->link0)->set_position(&arg0->pos);
    }
    arg0->timer += lbl_805D525C;
    if (arg0->trail != 0) {
        VecCopy((Vec *)&arg0->prev, (const Vec *)&arg0->pos);
        arg0->cnt++;
        if (arg0->cnt > 4) {
            arg0->cnt = 0;
            TObjPlayer::snap_to_ground((s32)arg0, (s32)&arg0->prev);
        }
        if (arg0->link1 != NULL) {
            ((TParticleCtrl *)arg0->link1)->set_position(&arg0->prev);
        }
    }
    if (arg0->timer >= lbl_805DA478) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    if (csnVector(&old, &arg0->pos, -1) != 0) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    att = find_entity_by_id(arg0->owner);
    if (att != NULL) {
        for (i = 0; i < registered_player_count + lbl_805D5870; i++) {
            pl = (void *)get_player_data__10TObjPlayerFi(i);
            if (pl != NULL && is_valid_and_active__10TObjPlayerFUl() != 0) {
                hit_object_in_radius__10TObjPlayerFPvPvPv((Src_800DC4B4 *)arg0, (Obj_800DC4B4 *)pl, att);
            }
        }
    }
}

}
TUnk_80494E10::~TUnk_80494E10() {
    if (*(void **)((s8 *)this + 0xE0) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0xE0)); *(s32 *)((s8 *)this + 0xE0) = 0; }
    if (*(void **)((s8 *)this + 0xE4) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0xE4)); this->m_e4 = 0; }
}
extern "C" {
u8 *construct_beam_effect__10TObjPlayerFPvPvPviPv(u8 *arg0, Vec_800DC83C *arg1, Vec_800DC83C *arg2, s32 arg3, void *arg4) {
    Ang_800DC83C ang;
    f32 s;
    __ct__14TObjCollidableFP7TObject(arg0, tl_06);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_80494E10;
    ((TUnk_80494E10 *)arg0)->m_f4 = arg3;
    VecCopy((Vec *)(arg0 + 0xAC), (const Vec *)arg1);
    ((TUnk_80494E10 *)arg0)->m_dc = lbl_805DA47C;
    VecCopy((Vec *)(arg0 + 0xB8), (const Vec *)arg2);
    subtract_vector(arg0 + 0xB8, arg1);
    s = lbl_805D525C / vector_length(arg0 + 0xB8);
    ((TUnk_80494E10 *)arg0)->m_b8*= s;
    *(f32 *)((s8 *)arg0 + 0xBC) *= s;
    ((TUnk_80494E10 *)arg0)->m_c0*= s;
    ((TUnk_80494E10 *)arg0)->m_fc = get_entity_id(arg4);
    ang.x = 0;
    ang.y = (s32)(10430.38043493439 * atan2_float(arg2->x - arg1->x, arg2->z - arg1->z)) + 0x4000;
    ang.z = 0x4000 - (s32)(10430.38043493439 * atan2_float(arg2->y - arg1->y, vec_xz_distance((Vec *)arg2, (Vec *)arg1)));
    *(s32 *)((s8 *)arg0 + 0xE0) = (s32)spawn_particle_effect_with_rotation(arg1, &ang, 0xF5, 2);
    if (((TUnk_80494E10 *)arg0)->m_f4 != 0) {
        VecCopy((Vec *)(arg0 + 0xE8), (const Vec *)(arg0 + 0xAC));
        TObjPlayer::snap_to_ground((s32)arg0, (s32)(arg0 + 0xE8));
        ((TUnk_80494E10 *)arg0)->m_e4 = (s32)spawn_continuous_particle_effect_with_flags(arg0 + 0xE8, 0xF9, 2);
        *(s32 *)((s8 *)arg0 + 0xF8) = 0;
    } else {
        ((TUnk_80494E10 *)arg0)->m_e4 = 0;
    }
    return arg0;
}
}
