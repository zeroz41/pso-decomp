#include "pso/system/vector.h"
#include "pso/boss/barbaray/TBoss7LaserPtcl.h"
#include "pso/boss/TUnk_804F1C88.h"
#include "types.h"
#include "pso/unk/text_8035A860.h"
#include "pso/boss/barbaray/TBoss7LaserPtcl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/boss/barbaray/TBoss7PhotonBullet.h"
#include "pso/boss/TUnk_804F1C88.h"
#include <stddef.h>
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ending/TObjOnlineEnding.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_80087278.h"

extern const f32 lbl_805DE9F0;
extern "C" {

s32 subtract_vector(void *, void *);

}

typedef char Laser_state_offset[offsetof(TBoss7LaserPtcl, state) == 0x1C ? 1 : -1];
typedef char Laser_position_offset[offsetof(TBoss7LaserPtcl, position) == 0x20 ? 1 : -1];
typedef char Laser_direction_offset[offsetof(TBoss7LaserPtcl, direction) == 0x2C ? 1 : -1];
typedef char Laser_displacement_offset[offsetof(TBoss7LaserPtcl, displacement) == 0x38 ? 1 : -1];
typedef char Laser_particles_offset[offsetof(TBoss7LaserPtcl, particles) == 0x44 ? 1 : -1];
typedef char Laser_distance_offset[offsetof(TBoss7LaserPtcl, travel_distance) == 0x4C ? 1 : -1];
typedef char Laser_last_known_offset[offsetof(TBoss7LaserPtcl, m_54) == 0x54 ? 1 : -1];

typedef TBoss7LaserPtclVector Vec_8035AAEC;
struct Ang_8035AAEC { s32 x, y, z; };
extern "C" {

void vec3_add_to(void *, void *);
void normalize_vector(void *);
}
void *create_oneshot_particle_emitter(void *pos, void *dir, s32 id, s32 flags);
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);

struct RecoveredGlobal_8035ACBC___vt__15TBoss7LaserPtcl { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8035ACBC___vt__15TBoss7LaserPtcl_size[sizeof(RecoveredGlobal_8035ACBC___vt__15TBoss7LaserPtcl) == 0x18 ? 1 : -1];

struct Ptcl_8035AD68 {
    u8 pad0[0x10];
    void *x10;
    u8 pad14[0x8];
    u8 x1c[0x24];
    f32 x40;
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__15TBoss7LaserPtcl[];
extern s32 TBoss7LaserPtcl__class_name;

u8 *TBoss7LaserPtcl__ct(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
extern s32 __vt__13TUnk_804F1C88[];

void queue_destruction__7TObjectFv(void *);
void reset_global_table(void);

void *__dt__13TUnk_804F1C88Fv(void *arg0, s16 arg1);
void *__dt__15TBoss7LaserPtclFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

}

#pragma defer_codegen on

TUnk_804F1C88::~TUnk_804F1C88() {

}

void TUnk_804F1C88::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 i;
    Ptcl_8035AD68 *o = (Ptcl_8035AD68 *)arg0;
    o->x40 += 2e+01f;
    reset_global_table();
    TObjPlayer::apply_status_effect((s32)o->x1c);
    for (i = 0; i != TObjOnlineEnding::get_instance(); i++) {
        u8 **e = (u8 **)TObjOnlineEnding::get_attack_entry(i);
        ((TBoss7PhotonBullet *)(o->x10))->emit_hit_effect(*e + 0x38);
    }
    reset_global_table();
    if (6e+01f < o->x40) {
        queue_destruction__7TObjectFv(o);
    }
}

void TUnk_804F1C88::render() {  }

u8 *TBoss7LaserPtcl__ct(u8 *boss7_laser_ptcl, u8 *arg1, u8 *arg2, u8 *arg3) {
    __ct__7TObjectFP7TObject(boss7_laser_ptcl, arg1);
    *(s32 **)((s8 *)boss7_laser_ptcl + 0x18) = &(*(RecoveredGlobal_8035ACBC___vt__15TBoss7LaserPtcl *)&__vt__15TBoss7LaserPtcl).value;
    *(s32 *)((s8 *)boss7_laser_ptcl + 0) = (s32) TBoss7LaserPtcl__class_name;
    *(f32 *)((s8 *)boss7_laser_ptcl + 0x4C) = (f32) 8e+01f;
    *(s32 *)((s8 *)boss7_laser_ptcl + 0x54) = 0;
    *(s32 *)((s8 *)boss7_laser_ptcl + 0x1C) = 0;
    VecCopy((Vec *)(boss7_laser_ptcl + 0x20), (const Vec *)arg2);
    VecCopy((Vec *)(boss7_laser_ptcl + 0x2C), (const Vec *)arg3);
    ((TBoss7LaserPtcl *)boss7_laser_ptcl)->update_position();
    *(s32 *)((s8 *)boss7_laser_ptcl + 0x44) = (s32)spawn_continuous_particle_effect_with_flags(arg2, 0x204, 0x40);
    *(s32 *)((s8 *)boss7_laser_ptcl + 0x48) = (s32)spawn_continuous_particle_effect_with_flags(arg2, 0x205, 0x40);
    return boss7_laser_ptcl;
}

TBoss7LaserPtcl::~TBoss7LaserPtcl() {
    this->destroy_particles();
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void TBoss7LaserPtcl::run_task() {
    TBoss7LaserPtcl *o = this;
    Vec_8035AAEC v;
    Vec_8035AAEC w;
    Ang_8035AAEC a;
    void **p;
    s32 i;
    s32 n;

    p = o->particles;
    for (i = 2; i != 0; i--) {
        if (*p != NULL) {
            ((TParticleCtrl *)*p++)->set_position(&o->position);
        }
    }
    if (o->state == 1) {
        o->travel_distance += 3e+01f;
        ((TBoss7LaserPtcl *)o)->update_position();
        VecCopy((Vec *)&v, (const Vec *)&o->displacement);
        VecCopy((Vec *)&w, (const Vec *)&o->position);
        normalize_vector(&v);
        v.x *= 8.0f;
        v.y *= 8.0f;
        v.z *= 8.0f;
        a.y = (s32)(10430.38043493439 * atan2_float(v.x, v.z));
        direction_to_rotation_xz((u8 *)&v, (s32 *)((s32 *)&a.x), (s32 *)((s32 *)&a.z));
        for (n = (s32)o->travel_distance / 8; n != 0; n--) {
            create_oneshot_particle_emitter(&w, &a, 0x206, 0x40);
            create_oneshot_particle_emitter(&w, &a, 0x207, 0x40);
            vec3_add_to(&w, &v);
        }
        if (5e+02f <= o->travel_distance) {
            o->state = 2;
            ((TBoss7LaserPtcl *)o)->destroy_particles();
        }
    }
}
#pragma pop

void TBoss7LaserPtcl::render() {  }

void TBoss7LaserPtcl::destroy_particles() {
    s32 arg0 = (s32)this;
  void **var_r30;
  s32 var_r29;
  u8 *object;
  var_r30 = (void **) (arg0 + 0x44);
  var_r29 = 2;
  do
  {
    object = (u8 *) (*((u8 **) (((s8 *) var_r30) + 0)));
    if (object != 0)
    {
      queue_destruction__7TObjectFv(object);
      *((u8 **) (((s8 *) var_r30) + 0)) = 0;
    }
    var_r29 -= 1;
    var_r30 = (void **) ((u8 *) ((void **) (((u8 *) var_r30) + 4)));
  }
  while (var_r29 != 0);
}

#pragma push
#pragma fp_contract on
void TBoss7LaserPtcl::calc_position(u8 *arg1, u8 *arg2) {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x20) = (f32) ((2.0f * (5.0f * *(f32 *)((s8 *)arg2 + 0))) + *(f32 *)((s8 *)arg1 + 0));
    *(f32 *)((s8 *)arg0 + 0x24) = (f32) ((5.0f * *(f32 *)((s8 *)arg2 + 4)) + *(f32 *)((s8 *)arg1 + 4));
    *(f32 *)((s8 *)arg0 + 0x28) = (f32) ((5.0f * *(f32 *)((s8 *)arg2 + 8)) + *(f32 *)((s8 *)arg1 + 8));
}
#pragma pop

void TBoss7LaserPtcl::init_laser() {
    u8 *arg0 = (u8 *)this;
    this->destroy_particles();
    subtract_vector(arg0 + 0x2C, arg0 + 0x20);
    normalize_vector_xz((Vec *)(arg0 + 0x2C));
    *(f32 *)((s8 *)arg0 + 0x30) = (f32) 0.0f;
    this->m_54 = (s32) (10430.38043493439 * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0x2C)), (f32) (*(f32 *)((s8 *)arg0 + 0x34))));
    spawn_particle_effect_with_flags((arg0 + 0x20), 0x20A, 0x40);
    *(s32 *)((s8 *)arg0 + 0x44) = (s32)spawn_continuous_particle_effect_with_flags((arg0 + 0x20), 0x177, 0x40);
    this->state = 1;
}

u8 TBoss7LaserPtcl::is_state_2() {
    return (u8) (this->state == 2);
}

void TBoss7LaserPtcl::update_position() {
    *(f32 *)((s8 *)this + 0x38) = (f32) (*(f32 *)((s8 *)this + 0x2C) * this->travel_distance);
    *(f32 *)((s8 *)this + 0x3C) = (f32) (lbl_805DE9F0 - *(f32 *)((s8 *)this + 0x24));
    *(f32 *)((s8 *)this + 0x40) = (f32) (*(f32 *)((s8 *)this + 0x34) * this->travel_distance);
}

void TBoss7LaserPtcl::calc_world_position(void *arg1) {
    if (arg1 != NULL) {
        *(f32 *)((s8 *)arg1 + 0) = (f32) (*(f32 *)((s8 *)this + 0x20) + *(f32 *)((s8 *)this + 0x38));
        *(f32 *)((s8 *)arg1 + 4) = (f32) (*(f32 *)((s8 *)this + 0x24) + *(f32 *)((s8 *)this + 0x3C));
        *(f32 *)((s8 *)arg1 + 8) = (f32) (*(f32 *)((s8 *)this + 0x28) + *(f32 *)((s8 *)this + 0x40));
    }
}

#pragma push
#pragma fp_contract on
void calc_laser_ray_hit_point(u8 *arg0, u8 *arg1) {
    f32 temp_f2;
    f32 temp_f2_2;
    if (arg1 != NULL) {
        temp_f2 = *(f32 *)((s8 *)arg0 + 0x24);
        temp_f2_2 = (10.0f - temp_f2) / (lbl_805DE9F0 - temp_f2);
        *(f32 *)((s8 *)arg1 + 0) = (f32) ((*(f32 *)((s8 *)arg0 + 0x38) * temp_f2_2) + *(f32 *)((s8 *)arg0 + 0x20));
        *(f32 *)((s8 *)arg1 + 4) = (f32) ((*(f32 *)((s8 *)arg0 + 0x3C) * temp_f2_2) + *(f32 *)((s8 *)arg0 + 0x24));
        *(f32 *)((s8 *)arg1 + 8) = (f32) ((*(f32 *)((s8 *)arg0 + 0x40) * temp_f2_2) + *(f32 *)((s8 *)arg0 + 0x28));
    }
}
#pragma pop
