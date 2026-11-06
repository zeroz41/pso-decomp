#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/enemy/TUnk_804EF130.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/morfos/TObjEneMorfos.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_80086B64.h"

#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TMainTask.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
s32 *csnVecterUnder(s32 origin, s32 mask);
f32 xz_distance_squared(void *, void *);
void subtract_vector(void *, void *);
extern const f32 morfos_projectile_speed;
extern const f32 morfos_param_table_speed_copy;
s16 get_entity_id(void *);
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
f32 fabs_float(f32);
u32 csnVector(void *, void *, int);
void vec3_add_to(void *, void *);
}

void TUnk_804EF130::hit_target_in_range(TObjChara *target, TObjCollidable *owner) {
    Vec v = pos;
    subtract_vector(&v, &vel);
    if (target != 0 && target != owner && !(target->actorFlags & 0x04000A00)) {
        if (!(xz_distance_squared(&v, (u8 *)target + 0x2FC) > (1.5f * morfos_projectile_speed) * (1.5f * morfos_projectile_speed))) {
            DirectAttackPayload hit = {0, morfos_param_table_speed_copy};
            target->receive_direct_attack(owner, hit, 0, -1, -1);
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
            TObjEneMorfos::snap_to_ground((s32)this, (s32)&ground_pos);
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
            if (TObjPlayer::is_valid_and_active((u32)p) != 0 && fabs_float(pos.y - *(f32 *)((u8 *)p + 0x300)) < 20.0f) {
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

TUnk_804EF130::TUnk_804EF130(Vec *start, s32 angle, TObjEneMorfos *owner) : TObjCollidable(tl_06) {
    ParticleAngles a;
    VecCopy(&pos, start);
    distance = 0.0f;
    owner_id = get_entity_id(owner);
    a.x = 0;
    a.y = angle - 0x4000;
    a.z = 0x4000;
    vel.x = morfos_projectile_speed * sin_table_lookup(angle);
    vel.y = 0.0f;
    vel.z = morfos_projectile_speed * cos_table_lookup(angle);
    effect = (TParticleCtrl *)spawn_particle_effect_with_rotation(start, &a, 0x213, 2);
    VecCopy(&ground_pos, &pos);
    TObjEneMorfos::snap_to_ground((s32)this, (s32)&ground_pos);
    ground_timer = 0;
}
