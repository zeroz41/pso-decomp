#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/vector.h"
#include "pso/boss/barbaray/TBoss7LaserPtcl.h"
#include "pso/boss/TUnk_804F1C88.h"
#include "types.h"

#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/boss/barbaray/TBoss7DeRolLeC.h"

#include <stddef.h>
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ending/TObjOnlineEnding.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/text_803D96A8.h"

#pragma readonly_strings on

extern const f32 lbl_805DE9F0;

LAYOUT_ASSERT(Laser_state_offset, offsetof(TBoss7LaserPtcl, state) == 0x1C);
LAYOUT_ASSERT(Laser_position_offset, offsetof(TBoss7LaserPtcl, position) == 0x20);
LAYOUT_ASSERT(Laser_direction_offset, offsetof(TBoss7LaserPtcl, direction) == 0x2C);
LAYOUT_ASSERT(Laser_displacement_offset, offsetof(TBoss7LaserPtcl, displacement) == 0x38);
LAYOUT_ASSERT(Laser_particles_offset, offsetof(TBoss7LaserPtcl, particles) == 0x44);
LAYOUT_ASSERT(Laser_distance_offset, offsetof(TBoss7LaserPtcl, travel_distance) == 0x4C);
LAYOUT_ASSERT(Laser_yaw_offset, offsetof(TBoss7LaserPtcl, yaw) == 0x54);
LAYOUT_ASSERT(LaserHit_body_offset, offsetof(TUnk_804F1C88, hit_body) == 0x34);

// An x/y/z angle triple.
struct Boss7LaserAngles { s32 x, y, z; };

// Defined without a shared declaration in their owners' headers.

const char *TBoss7LaserPtcl__class_name = "TBoss7LaserPtcl";

#pragma defer_codegen on

TUnk_804F1C88::~TUnk_804F1C88() {

}

void TUnk_804F1C88::run_task() {
    s32 i;
    hit_body.radius += 2e+01f;
    reset_global_table();
    TObjPlayer::apply_status_effect((saddr)&hit_set);
    for (i = 0; i != TObjOnlineEnding::get_instance(); i++) {
        ActorBodyHit *hit = (ActorBodyHit *)TObjOnlineEnding::get_attack_entry(i);
        static_cast<TBoss7DeRolLeC *>(m_up)->emit_hit_effect(&hit->target->position);
    }
    reset_global_table();
    if (6e+01f < hit_body.radius) {
        queue_destruction();
    }
}

void TUnk_804F1C88::render() {  }

TBoss7LaserPtcl::TBoss7LaserPtcl(TObject *parent, TBoss7LaserPtclVector *origin, TBoss7LaserPtclVector *target) : TObject(parent) {
    m_name = TBoss7LaserPtcl__class_name;
    travel_distance = (f32) 8e+01f;
    yaw = 0;
    state = 0;
    VecCopy(&position, (const Vec *)origin);
    VecCopy(&direction, (const Vec *)target);
    update_position();
    particles[0] = spawn_continuous_particle_effect_with_flags(origin, 0x204, 0x40);
    particles[1] = spawn_continuous_particle_effect_with_flags(origin, 0x205, 0x40);
}

TBoss7LaserPtcl::~TBoss7LaserPtcl() {
    this->destroy_particles();
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void TBoss7LaserPtcl::run_task() {
    Vec step;
    Vec point;
    Boss7LaserAngles angles;
    TParticleCtrl **particle;
    s32 i;
    s32 n;

    particle = particles;
    for (i = 2; i != 0; i--) {
        if (*particle != NULL) {
            (*particle++)->set_position(&position);
        }
    }
    if (state == 1) {
        travel_distance += 3e+01f;
        update_position();
        VecCopy(&step, &displacement);
        VecCopy(&point, &position);
        normalize_vector(&step);
        step.x *= 8.0f;
        step.y *= 8.0f;
        step.z *= 8.0f;
        angles.y = (s32)(10430.38043493439 * atan2_float(step.x, step.z));
        direction_to_rotation_xz((u8 *)&step, &angles.x, &angles.z);
        for (n = (s32)travel_distance / 8; n != 0; n--) {
            create_oneshot_particle_emitter(&point, &angles, 0x206, 0x40);
            create_oneshot_particle_emitter(&point, &angles, 0x207, 0x40);
            vec3_add_to(&point, &step);
        }
        if (5e+02f <= travel_distance) {
            state = 2;
            destroy_particles();
        }
    }
}
#pragma pop

void TBoss7LaserPtcl::render() {  }

void TBoss7LaserPtcl::destroy_particles() {
    TParticleCtrl **particle = particles;
    s32 n = 2;
    do {
        TParticleCtrl *emitter = *particle;
        if (emitter != NULL) {
            emitter->queue_destruction();
            *particle = NULL;
        }
        n -= 1;
        particle++;
    } while (n != 0);
}

#pragma push
#pragma fp_contract on
void TBoss7LaserPtcl::calc_position(u8 *origin, u8 *direction) {
    const Vec *from = (const Vec *)origin;
    const Vec *dir = (const Vec *)direction;
    position.x = (2.0f * (5.0f * dir->x)) + from->x;
    position.y = (5.0f * dir->y) + from->y;
    position.z = (5.0f * dir->z) + from->z;
}
#pragma pop

void TBoss7LaserPtcl::init_laser() {
    destroy_particles();
    subtract_vector(&direction, &position);
    normalize_vector_xz(&direction);
    direction.y = 0.0f;
    yaw = (s32)(10430.38043493439 * atan2_float(direction.x, direction.z));
    spawn_particle_effect_with_flags(&position, 0x20A, 0x40);
    particles[0] = spawn_continuous_particle_effect_with_flags(&position, 0x177, 0x40);
    state = 1;
}

s32 TBoss7LaserPtcl::is_state_2() {
    return (u8)((u8) (this->state == 2));
}

void TBoss7LaserPtcl::update_position() {
    displacement.x = direction.x * travel_distance;
    displacement.y = lbl_805DE9F0 - position.y;
    displacement.z = direction.z * travel_distance;
}

void TBoss7LaserPtcl::calc_world_position(void *out) {
    if (out != NULL) {
        Vec *dst = (Vec *)out;
        dst->x = position.x + displacement.x;
        dst->y = position.y + displacement.y;
        dst->z = position.z + displacement.z;
    }
}

#pragma push
#pragma fp_contract on
// Where the ray from the laser's origin along its displacement crosses y = 10.
void calc_laser_ray_hit_point(u8 *laser, u8 *out) {
    const TBoss7LaserPtcl *ray = (const TBoss7LaserPtcl *)laser;
    Vec *dst = (Vec *)out;
    f32 y;
    f32 t;
    if (dst != NULL) {
        y = ray->position.y;
        t = (10.0f - y) / (lbl_805DE9F0 - y);
        dst->x = (ray->displacement.x * t) + ray->position.x;
        dst->y = (ray->displacement.y * t) + ray->position.y;
        dst->z = (ray->displacement.z * t) + ray->position.z;
    }
}
#pragma pop
