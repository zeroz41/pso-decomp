#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/enemy/TUnk_804EF130.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/morfos/TObjEneMorfos.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/map/CsnQuery.h"
#include "pso/render/NinjaUtil.h"
#include "pso/object/base/TObjBase.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
extern const f32 morfos_projectile_speed;
extern const f32 morfos_param_table_speed_copy;
}

void TUnk_804EF130::hit_target_in_range(TObjChara *target, TObjCollidable *owner) {
    Vec v = pos;
    subtract_vector(&v, &vel);
    if (target != 0 && target != owner && !(target->actorFlags & 0x04000A00)) {
        if (!(xz_distance_squared(&v, &target->body_center) > (1.5f * morfos_projectile_speed) * (1.5f * morfos_projectile_speed))) {
            DirectAttackPayload hit = {0, morfos_param_table_speed_copy};
            target->receive_direct_attack(owner, hit, 0, -1, -1);
        }
    }
}

s32 TUnk_804EF130::snap_to_ground(Vec *position) {
    CsnHit *hit = csnVecterUnder(position, 0x16EF);
    if (hit == NULL) {
        return 0;
    }
    VecCopy(position, &hit->contact->point);
    return 1;
}

struct O_80337500;
struct V_80337500;
void TUnk_804EF130::run_task() {
    TObjCollidable *owner;
    s32 i;
    TObjPlayer *p;
    Vec v = pos;
    vec3_add_to(&pos, &vel);
    if (effect != 0) {
        effect->set_position(&pos);
    }
    distance += morfos_projectile_speed;
    if (follow_ground != 0) {
        VecCopy(&ground_pos, &pos);
        ground_timer++;
        if (ground_timer > 4) {
            ground_timer = 0;
            snap_to_ground(&ground_pos);
        }
    }
    if (distance >= 500.0f) {
        queue_destruction();
        return;
    }
    if (csnVector(&v, &pos, -1) != 0) {
        queue_destruction();
        return;
    }
    owner = find_entity_by_id(owner_id);
    if (owner != 0) {
        for (i = 0; i < registered_player_count; i++) {
            p = TObjPlayer::get_player_data(i);
            if (TObjPlayer::is_valid_and_active((uaddr)p) != 0 && fabs_float(pos.y - p->body_center.y) < 20.0f) {
                hit_target_in_range((TObjChara *)p, owner);
            }
        }
    }
}

TUnk_804EF130::~TUnk_804EF130() {
    if (effect != NULL) {
        effect->queue_destruction();
    }
}

TUnk_804EF130::TUnk_804EF130(const Vec *start, s32 angle, TObjChara *owner) : TObjCollidable(tl_06) {
    ParticleAngles a;
    VecCopy(&pos, start);
    distance = 0.0f;
    owner_id = owner->get_entity_id();
    a.x = 0;
    a.y = angle - 0x4000;
    a.z = 0x4000;
    vel.x = morfos_projectile_speed * sin_table_lookup(angle);
    vel.y = 0.0f;
    vel.z = morfos_projectile_speed * cos_table_lookup(angle);
    effect = (TParticleCtrl *)spawn_particle_effect_with_rotation(const_cast<Vec *>(start), &a, 0x213, 2);
    VecCopy(&ground_pos, &pos);
    snap_to_ground(&ground_pos);
    ground_timer = 0;
}
