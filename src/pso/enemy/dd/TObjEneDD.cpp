#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/EnemyBmlResource.h"
#pragma fp_contract on
#include "pso/map/CsnGroundQuery.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/boss/DragonAttackParams.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/render_util.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/math/AngleLookup.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/camera/TCameraCtrl.h"

#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjBase.h"
const char *TObjEneDD__name = "TObjEneDD";
const char *TObjEneDD_ST__name = "TObjEneDD_ST";
#include "pso/map/CsnQuery.h"

#include "pso/enemy/epsilon/TObjEneEpsilon_800B92AC.h"

#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/unk/TLobby.h"
extern "C" {
f32 atan2_float(f32 y, f32 x);
}
extern "C" {
f32 normalize_vector_xz__FP3Vec(void *, f32, f32);
}
extern const f32 lbl_805D9E80 = -0.1f;
extern const f32 view_detail_far_depth = 310.0f;
extern const f32 view_detail_near_depth = 155.0f;
#include "pso/enemy/dd/TObjEneDD_800B9AF8.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/ambient/TObjLight.h"

#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"


#include "pso/ui/TLevelSelect.h"
extern "C" {
int is_local_client_floor_leader(void*);
int TObjPlayer__sub_801BA42C(void*);
int freeze_all_players__10TObjPlayerFv(void*);
}


#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/render/BlobShadow.h"
#include "pso/unk/text_803D96A8.h"


#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/model_render_state.h"




#include "pso/player/TUnk_804928CC.h"


#include <stddef.h>
extern "C" {
TUnk_804928CC *obj_ene_dd_instance;
}




#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"

#include "pso/math/MatrixVector.h"


#include "pso/unk/text_803D853C.h"


extern "C" {
f32 newton_sqrtf(f32);
}
#include <dolphin/mtx.h>


extern "C" {
f32 fabs_float(f32);
s32 VecCopy__FP3VecPC3Vec(void *, void *, s32);
}



extern "C" {
TargetCandidate enemy_target_candidate_table[4];
u16 enemy_nearest_visible_enemy_sq(TObjChara *self, f32 range);
}


#include "pso/enemy/fly/TObjEneBm3Fly.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"


extern "C" {
int submit_cursor_candidate(void*, int);
}


#include "pso/unk/text_800BC4C8.h"

#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/TProtocol.h"
#include "pso/player/TPlyDispData.h"

extern "C" {
int fn_800FD8A0(void*);
extern s32 area_random_seed;
}

s32 tick_period_counter(s32 self, s32 *counter, s32 limit) {
    s32 count;
    count = *counter;
    if (count >= limit) {
        *counter = 0;
        return 1;
    }
    *counter = count + 1;
    return 0;
}


int TObjEneDD::get_enemy_count() {  return registered_enemy_count; }

void TObjEneDD::create_instance() {
    obj_ene_dd_instance = new TUnk_804928CC(NULL, NULL);
}

void TObjEneDD::release_resource() {
    if (obj_ene_dd_instance != NULL) {
        delete obj_ene_dd_instance;
        obj_ene_dd_instance = NULL;
    }
}

TObjEneDD::TObjEneDD(TObject *parent) : TObjEnemy(parent) {
    m_name = TObjEneDD__name;
    previous_mode = 0;
    next_mode = 0;
    wall_reach = 5.0f;
    wall_probe_failures = 0;
    ground_probe_failures = 0;
    active_flags = 0;
}

TObjEneDD::~TObjEneDD() {}

void TObjEneDD::init_position_vectors() {
    u8 *self = (u8 *)this;
    VecCopy(&this->prev_position, (const Vec *)&this->position);
    VecCopy(&this->home_position, (const Vec *)&this->position);
    VecCopy(&this->center, (const Vec *)&this->position);
    register_by_id();
    VecCopy(&this->body_center, (const Vec *)&this->position);
    *(f32 *)((s8 *)self + 0x308) = 0.0f;
    this->velocity.y = 0.0f;
    this->velocity.z = 0.0f;
    this->ground_normal.x = 0.0f;
    ground_normal.y = 0.0f;
    this->ground_normal.z = 0.0f;
    this->target = 0;
    this->clear_lobby_object_state();
}

s32 TObjEneDD::update_status_effects() {
    if (this->has_flag_0x800() != 0) {
        this->run_death_reaction();
        return 1;
    }
    this->update_attack_stat_status();
    this->update_defense_stat_status();
    this->update_flag30_timer();
    if (this->update_immobilizing_statuses() != 0) {
        return 4;
    }
    if (this->test_flag30_512() != 0) {
        this->run_hit_reaction();
        return 2;
    }
    return 0;
}

s32 TObjEneDD::update_immobilizing_statuses() {
    s32 r = update_action_hold_status();
    r |= update_shock_clock();
    r |= update_movement_status();
    return r;
}

void TObjEneDD::update_action_state() {
    if (has_action_state_changed() == 0) {
        dispatch_action(mode, 3);
    }
    dispatch_action(mode, 0);
    sub_800BBA0C();
}

s32 TObjEneDD::has_action_state_changed() {
    return previous_mode != this->mode;
}

void TObjEneDD::transition_enemy_state(s32 state) {
    dispatch_action(mode, 5);
    dispatch_action(state, 4);
    mode = state;
}

void TObjEneDD::sub_800BBA0C() {
    previous_mode = this->mode;
}

void TObjEneDD::set_field_378(s32 v) { next_mode = v; }

BmlResource *load_enemy_bml_resource(BmlResourceDescriptor *descriptor) {
    return new BmlResource(1, descriptor, 0, 0, NULL);
}

#pragma push
#pragma scheduling off
void BmlResourceDescriptor::copy_from(const BmlResourceDescriptor &other) {
    archive_filename = other.archive_filename;
    model_filenames = other.model_filenames;
    motion_filenames = other.motion_filenames;
    model_count = other.model_count;
    motion_count = other.motion_count;
}
#pragma pop

BmlResource *load_enemy_bml_resource_named(BmlResourceDescriptor *descriptor, const char *archive_filename) {
    BmlResourceDescriptor copy;
    copy.copy_from(*descriptor);
    copy.archive_filename = archive_filename;
    return load_enemy_bml_resource(&copy);
}

void TObjEneDD::apply_enemy_state(s32 *state) {
    s16 mode;

    mode = this->mode;
    TObjEnemy::apply_enemy_state(state);
    this->mode = mode;
}

void TObjEneDD::invoke_initialization_hook(void *set_data) {
    apply_set_data(set_data);
}

void TObjEneDD::reset_state_fields() {
    s32 i;
    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 0.0f;
    rotation_x = 0;
    rotation_y = 0;
    rotation_z = 0;
    for (i = 0; i < 5; i++) {
        parameters[i] = 0.0f;
    }
    variant = 0;
    state36C = 0;
    room = -1;
    set_group = -1;
}

s32 pack_debug_text_position(s32 x, s32 y) {
    return ((x + 0x13) << 0x10) | (y + 0x1A);
}

int TObjEneDD::get_target_info() { return fn_800FD8A0(this); }

void TObjEneDD::init_common_from(TObjBase *source) {
    reset_state_fields();
    room = source->room;
    set_group = source->set_group;
    subtractive_rng_seed(&rng, (int) (this->entity_id + area_random_seed));
}


int TObjEnemy::submit_default_cursor_candidate() { return submit_cursor_candidate(this, -1); }

void TBoss8Dragon__sub_800BB7DC(void *self) {  }

void TBoss8Dragon__sub_800BB7D8(void *self, s32 id, f32 scale) {  }

void TBoss8Dragon__sub_800BB7D4(void *self, int id) {  }

void TBoss8Dragon::noop() {  }

void TObjEneDD::clear_attack_receipts() {
    s32 i;
    referenceHp = hp;
    actorFlags &= ~0x200;
    hit_flags = 0;
    for (i = 0; i < body_count; i++) {
        bodies[i].flags &= ~0x04000000;
    }
}

int TObjEneBm3Fly::was_hit_by_ranged() { return (this->hit_flags >> 1) & 0x1; }

void TObjEnemy::refresh_and_send_entity_flags() { refresh_lobby_state(); send_entity_set_flags(); }

u16 enemy_nearest_visible_player_sq(TObjChara *self, f32 range) {
    f32 d;
    f32 best;
    s32 n;
    TObjChara *p;
    u16 result;
    s32 i;
    best = range;
    result = 0xFFFF;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = (TObjChara *)TObjPlayer::get_player_data(i);
        if (p->is_alive() != 0) {
            d = horizontal_distance_squared(&self->body_center, &p->position);
            if (d < best && csnLookAt(&self->body_center, &p->body_center) == 0) {
                result = p->get_entity_id();
                best = d;
            }
        }
    }
    return result;
}


u16 enemy_find_nearest_player_in_range(TObjChara *self, f32 range) {
    return enemy_nearest_visible_player_sq(self, range * range);
}

void TBoss8Dragon__sub_800BB650(TargetCandidate *dst, TargetCandidate *src) {
    dst->id = src->id;
    dst->dist = src->dist;
}

s32 collect_enemy_target_candidates(TObjEneDD *self, TargetCandidate *out, f32 range) {
    s32 n;
    s32 cnt;
    TargetCandidate tmp;
    TObjPlayer *p;
    s32 mi;
    s32 j;
    f32 mx;
    f32 d;
    s32 k;
    n = 0;
    cnt = TLobby::get_game_mode();
    if (range > 0.0f) {
        for (s32 i = 0; i < cnt; i++) {
            p = TObjPlayer::get_player_data(i);
            if (p->is_alive() != 0) {
                d = horizontal_distance_squared(&self->position, &p->position);
                if (d < range) {
                    out[n].id = p->get_entity_id();
                    out[n].dist = d;
                    n++;
                }
            }
        }
    } else {
        for (s32 i = 0; i < cnt; i++) {
            p = TObjPlayer::get_player_data(i);
            if (p->is_alive() != 0) {
                d = horizontal_distance_squared(&self->position, &p->position);
                out[n].id = p->get_entity_id();
                out[n].dist = d;
                n++;
            }
        }
    }
    if (n > 1) {
        for (k = n - 1; k >= 1; k--) {
            mx = out[0].dist;
            mi = 0;
            for (j = 1; j <= k; j++) {
                f32 v = out[j].dist;
                if (v > mx) {
                    mx = v;
                    mi = j;
                }
            }
            if (mi != k) {
                TBoss8Dragon__sub_800BB650(&tmp, &out[mi]);
                TBoss8Dragon__sub_800BB650(&out[mi], &out[k]);
                TBoss8Dragon__sub_800BB650(&out[k], &tmp);
            }
        }
    }
    return n;
}

s32 TObjEneDD::collect_target_candidates(TObjEneDD *actor, f32 range) {
    return collect_enemy_target_candidates(actor, enemy_target_candidate_table, range);
}

u16 enemy_nearest_visible_enemy_sq(TObjChara *self, f32 range) {
    s32 count;
    s32 base;
    TObjChara *p;
    u16 best;
    s32 i;
    f32 d;

    best = 0xFFFF;
    base = TLobby::get_game_mode();
    count = TObjEneDD::get_enemy_count();
    for (i = 0; i < count; i++) {
        p = (TObjChara *)TObjPlayer::get_player_data(base + i);
        if (p != self && !(p->actorFlags & 0x01000000) && p->is_alive() != 0) {
            d = horizontal_distance_squared(&self->body_center, &p->position);
            if (d < range && csnLookAt(&self->body_center, &p->body_center) == 0) {
                best = p->get_entity_id();
                range = d;
            }
        }
    }
    return best;
}

u16 enemy_nearest_visible_enemy(void *self, f32 range) {
    return enemy_nearest_visible_enemy_sq((TObjChara *)self, range * range);
}

CsnHit *TObjEneDD::snap_to_ground_at(u8 *dest) {
    const Vec *target = reinterpret_cast<const Vec *>(dest);
    Vec probe;
    CsnHit *hit;
    probe.x = target->x;
    probe.y = target->y + this->stat_block->proportions;
    probe.z = target->z;
    if (csnVectorUnder(&probe, this->ground_candidates.groups, 0xE0) != NULL) {
        return NULL;
    }
    hit = csnVectorUnder(&probe, ground_candidates.groups, 0x15);
    if (hit == NULL) {
        return NULL;
    }
    this->position.y = hit->contact->point.y;
    return hit;
}

CsnHit *TObjEneDD::enemy_probe_wall_ahead(f32 dx, f32 dz, f32 dist) {
    f32 step_z;
    Vec ahead;
    f32 step_x;
    step_x = dx * dist;
    step_z = dz * dist;
    if ((fabs_float(step_x) < 0.01f) && (fabs_float(step_z) < 0.01f)) {
        return NULL;
    }
    ahead.x = position.x + step_x;
    ahead.y = body_center.y;
    ahead.z = position.z + step_z;
    return csnVector(&body_center, &ahead, 0x88E0);
}

void TObjEneDD::calc_shot_position(Vec *shot, f32 dx, f32 dz, f32 dist) {
    Vec *out = shot;
    s32 failures;

    f32 reach = dist + wall_reach;
    if (enemy_probe_wall_ahead(dx, dz, reach) == NULL) {
        out->x = dx * dist + position.x;
        out->y = position.y;
        out->z = dz * dist + position.z;
        wall_probe_failures = 0;
        return;
    }
    failures = wall_probe_failures;
    wall_probe_failures = failures + 1;
    VecCopy__FP3VecPC3Vec(shot, (u8 *)&position, failures);
}


#pragma push
#pragma fp_contract on
void calc_wall_slide_destination(TObjEneDD *e, Vec *out, f32 dx, f32 dz, f32 dist) {
    CsnHit *n;
    Vec v;
    n = e->enemy_probe_wall_ahead(dx, dz, dist + e->wall_reach);
    if (n == NULL) {
        out->x = dx * dist + e->position.x;
        out->y = e->position.y;
        out->z = dz * dist + e->position.z;
        e->wall_probe_failures = 0;
        return;
    }
    e->wall_probe_failures++;
    v.x = n->contact->normal.z;
    v.z = -n->contact->normal.x;
    normalize_vector_xz((Vec *)(&v));
    if (dx * v.x + dz * v.z >= 0.0f) {
        dx = v.x;
        dz = v.z;
    } else {
        dx = -v.x;
        dz = -v.z;
    }
    if (e->enemy_probe_wall_ahead(dx, dz, dist + e->wall_reach) == NULL) {
        out->x = dx * dist + e->position.x;
        out->y = e->position.y;
        out->z = dz * dist + e->position.z;
        return;
    }
    VecCopy(out, &e->position);
}
#pragma pop

#pragma push
#pragma fp_contract on
void calc_wall_clamped_destination(TObjEneDD *e, Vec *out, f32 dx, f32 dz, f32 dist) {
    CsnHit *n = e->enemy_probe_wall_ahead(dx, dz, dist + e->wall_reach);
    if (n == NULL) {
        e->wall_probe_failures = 0;
    } else {
        Vec *p;
        f32 ddx;
        f32 px;
        f32 ddz;
        e->wall_probe_failures++;
        p = &n->contact->point;
        px = p->x;
        ddz = p->z - e->position.z;
        ddx = px - e->position.x;
        dist = ((f32 (*)(f32, f32, f32))newton_sqrtf)(ddx * ddx + ddz * ddz, px, ddz) - e->wall_reach;
    }
    out->x = dx * dist + e->position.x;
    out->y = e->position.y;
    out->z = dz * dist + e->position.z;
}
#pragma pop

// Keep coordinate reads and writes in order if the target aliases position.
CsnHit *TObjEneDD::try_move_actor_xz_on_ground(const Vec *shot) {
    volatile Vec &current = position;
    volatile Vec &previous = prev_position;
    const volatile Vec &target = *shot;
    f32 y;
    CsnHit *hit;
    y = position.y;
    hit = snap_to_ground_at(reinterpret_cast<u8 *>(const_cast<Vec *>(shot)));
    if (hit != NULL) {
        previous.x = current.x;
        previous.y = y;
        previous.z = current.z;
        current.x = target.x;
        current.z = target.z;
        VecCopy(&ground_normal, &hit->contact->normal);
        ground_probe_failures = 0;
    } else {
        ground_probe_failures = ground_probe_failures + 1;
    }
    return hit;
}

CsnHit *TObjEneDD::move_xz_on_ground(const Vec *dest) {
    volatile Vec &current = position;
    volatile Vec &previous = prev_position;
    const volatile Vec &target = *dest;
    f32 y;
    CsnHit *hit;
    y = position.y;
    hit = snap_to_ground_at(reinterpret_cast<u8 *>(const_cast<Vec *>(dest)));
    if (hit != NULL) {
        VecCopy(&ground_normal, &hit->contact->normal);
    }
    previous.x = current.x;
    previous.y = y;
    previous.z = current.z;
    current.x = target.x;
    current.z = target.z;
    ground_probe_failures = 0;
    return hit;
}

CsnHit *TObjEneDD::update_ground_contact() {
    f32 y;
    CsnHit *hit;
    y = position.y;
    hit = update_actor_ground_y();
    if (hit != NULL) {
        VecCopy(&ground_normal, &hit->contact->normal);
    }
    prev_position.x = position.x;
    prev_position.y = y;
    prev_position.z = position.z;
    ground_probe_failures = 0;
    return hit;
}

void TObjEneDD::move_to_shot_position(f32 dx, f32 dz, f32 dist) {
    Vec dest;
    calc_shot_position(&dest, dx, dz, dist);
    try_move_actor_xz_on_ground(&dest);
}

void TObjEneDD::move_with_wall_slide_on_ground(f32 dx, f32 dz, f32 dist) {
    Vec dest;
    calc_wall_slide_destination(this, &dest, dx, dz, dist);
    try_move_actor_xz_on_ground(&dest);
}

void TObjEneDD::move_clamped_on_ground(f32 dx, f32 dz, f32 dist) {
    Vec dest;
    calc_wall_clamped_destination(this, &dest, dx, dz, dist);
    try_move_actor_xz_on_ground(&dest);
}

void TObjEneDD::move_with_wall_stop(f32 dx, f32 dz, f32 dist) {
    Vec dest;
    calc_shot_position(&dest, dx, dz, dist);
    move_xz_on_ground(&dest);
}

CsnHit *TObjEneDD::move_with_wall_slide_commit(f32 dx, f32 dz, f32 dist) {
    Vec dest;
    calc_wall_slide_destination(this, &dest, dx, dz, dist);
    return move_xz_on_ground(&dest);
}

void TObjEneDD::move_to_wall_clamped_destination(f32 dx, f32 dz, f32 dist) {
    Vec dest;
    calc_wall_clamped_destination(this, &dest, dx, dz, dist);
    move_xz_on_ground(&dest);
}

int TObjEneDD::has_move_failures(s32 limit) {
    u8 failed;
    failed = 0;
    if ((wall_probe_failures >= limit) || (ground_probe_failures >= limit)) {
        failed = 1;
    }
    return failed;
}


void TObjEneDD_ST::set_active() { active_flags = 1; }

void TObjEneDD::clear_field_388() { active_flags = 0; }

void TObjEneDD::init_model(CollisionBody *bodies, s32 count) {
    init_collision_body_parts(this, bodies, count);
    transform_part_positions();
}

void TObjEneDD::set_part_local_pos(void *v, s32 i) {
    Vec *p;
    VecCopy(&bodies[i].center, (const Vec *)v);
    p = &bodies[i].offset;
    VecCopy(p, (const Vec *)v);
    subtract_vector(p, &position);
    rotate_xz_pair_by_angle(&p->x, &p->z, -rotation_y);
}

void update_local_colliders_from_world(TObjEneDD *self, Vec *world_points) {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    rotate_matrix_y(NULL, -self->rotation_y);
    translate_matrix(0, -self->position.x, -self->position.y, -self->position.z);
    for (i = 0; i < self->body_count; i++) {
        VecCopy(&self->bodies[i].center, world_points);
        matrix_mult_vec(NULL, world_points, &self->bodies[i].offset);
        world_points++;
    }
    pop_matrix();
}

void TObjEneDD::set_part_position(void *actor, void *v, int i) {
    Vec *p;
    VecCopy(&((TObjCollidable *)actor)->bodies[i].offset, (const Vec *)v);
    p = &((TObjCollidable *)actor)->bodies[i].center;
    VecCopy(p, (const Vec *)v);
    rotate_xz_pair_by_angle(&p->x, &p->z, ((TObjCollidable *)actor)->rotation_y);
    vec3_add_to(p, &((TObjCollidable *)actor)->position);
}

void TObjEneDD::transform_part_positions() {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, rotation_y);
    set_motion_packed_rotation();
    for (i = 0; i < this->body_count; i++) {
        matrix_mult_vec(NULL, &bodies[i].offset, &bodies[i].center);
    }
    clear_motion_packed_rotation();
    pop_matrix();
}


void TObjEneDD::update_body_colliders() {  }

void TObjEneDD::check_collisions() {
    this->update_body_colliders();
    this->check_object_collisions();
    check_enemy_body_collisions(this);
}

s32 TObjEneDD::vfunc_90() {
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        if (bodies[i].flags & 0x380000) {
            return 1;
        }
    }
    return 0;
}

void set_collider_contact_high(CollisionBody *body) {
    body->flags |= 4;
    body->flags &= ~2U;
}

void set_collider_contact_low(CollisionBody *body) {
    body->flags &= ~4U;
    body->flags |= 2;
}

void update_collider_contact_by_height(CollisionBody *body, f32 height) {
    if (body->offset.y >= height) {
        set_collider_contact_high(body);
        return;
    }
    set_collider_contact_low(body);
}


s32 is_player_entity_id(u16 id) {
    return (u32)(id - 0x1000) >> 0x1FU;
}

int is_enemy_entity_id(u16 id) {
    u8 is_enemy;
    is_enemy = 0;
    if ((id >= 0x1000U) && (id < 0x4000U)) {
        is_enemy = 1;
    }
    return is_enemy;
}

s32 TObjEneDD::is_valid_target() {
    int valid;

    valid = 0;
    if ((this != NULL) && (all_parents_unqueued_for_destruction() != 0) && !(this->actorFlags & 0x06040800)) {
        valid = 1;
    }
    return (u8)valid;
}

s32 TObjChara::is_target_unobstructed(const Vec *from) {
    if ((is_alive() != 0) && (csnLookAt(from, &body_center) == NULL)) {
        return 1;
    }
    return 0;
}

s32 is_target_unobstructed_from(TObjEneDD *self, TObjChara *target) { return target->is_target_unobstructed(&self->body_center); }

s32 TObjBase::is_alive() {
    int alive;

    alive = 0;
    if ((this != NULL) && (all_parents_unqueued_for_destruction() != 0) && !(this->actorFlags & 0x02040800)) {
        alive = 1;
    }
    return (u8)alive;
}

int is_target_ranger(void* p) { return (((TObjPlayer *)p)->class_flags & CLASS_FLAG_RANGER) != 0; }

int is_target_android(void* p) { return (((TObjPlayer *)p)->class_flags & CLASS_FLAG_ANDROID) != 0; }

void TObjEneDD::setup_instance(TObjBase *owner, Vec *pos, DragonAttackParams *params, AreaAttackHistory *attack_history) {
    obj_ene_dd_instance->set_owner(owner);
    obj_ene_dd_instance->set_position_from(pos);
    obj_ene_dd_instance->bodies->radius = params->radius;
    obj_ene_dd_instance->bodies->flags = 0x9D03;
    if (params->radius > 100.0f) {
        obj_ene_dd_instance->area_attack_deliver_direct(&params->contact, (saddr)params, attack_history, params->radius);
        return;
    }
    obj_ene_dd_instance->call_vt13_with_default(&params->contact, params, (saddr)attack_history);
}

void TObjEneDD::setup(TObjBase *owner, Vec *pos, DragonAttackParams *params) { TObjEneDD::setup_instance(owner, pos, params, NULL); }

void TObjEneDD__sub_800BA5A4(TObjBase *owner, DragonAttackParams *params) {
    TObjEneDD::setup_instance(owner, &owner->position, params, NULL);
}

void TObjEneDD::emit_enemy_effect(TObjBase *owner, const Vec *pos, const DragonAttackParams *params,
                                   AreaAttackHistory *attack_history) {
    obj_ene_dd_instance->set_owner(owner);
    obj_ene_dd_instance->set_position_from(pos);
    obj_ene_dd_instance->bodies->radius = params->radius;
    // Store the hitbox flags before rereading the radius for dispatch.
    static_cast<volatile CollisionBody *>(obj_ene_dd_instance->bodies)->flags = 0x9D03;
    f32 radius = static_cast<const volatile DragonAttackParams *>(params)->radius;
    if (radius > 100.0f) {
        obj_ene_dd_instance->area_attack_deliver_physical(const_cast<AreaAttackContact *>(&params->contact),
                                                          attack_history, radius);
        return;
    }
    obj_ene_dd_instance->call_vt16_with_default(const_cast<AreaAttackContact *>(&params->contact), attack_history);
}

void TObjEneDD::emit_effect(TObjBase *owner, const Vec *pos, const DragonAttackParams *params) {
    TObjEneDD::emit_enemy_effect(owner, pos, params, NULL);
}

void TObjEneDD::emit_effect_at_position(const DragonAttackParams *params) {
    TObjEneDD::emit_enemy_effect(this, &position, params, NULL);
}

void TObjEneDD__sub_800BA438(TObjChara *attacker, TObjChara *target) {
    DirectAttackPayload attack = {0x12, 1.0f};
    target->receive_direct_attack(attacker, attack, NULL, -1, -1);
}

void TObjEneDD::inflict_poison(TObjChara *attacker, TObjChara *target) {
    DirectAttackPayload attack = {0xF, 1.0f};
    target->receive_direct_attack(attacker, attack, NULL, -1, -1);
}

void TObjEneDD__sub_800BA378(TObjChara *attacker, TObjChara *target) {
    DirectAttackPayload attack = {0x10, 1.0f};
    target->receive_direct_attack(attacker, attack, NULL, -1, -1);
}

void TObjEneDD::send_damage_message(TObjChara *attacker, TObjChara *target) {
    DirectAttackPayload attack = {0x11, 1.0f};
    target->receive_direct_attack(attacker, attack, NULL, -1, -1);
}

void TObjEneDD::set_state_flag_1() { add_flags_2e4(1); }

void TObjEneDD::set_state_flag_2() { add_flags_2e4(2); }

void TObjEneDD::set_state_flag_4() { add_flags_2e4(4); }

void TObjEneDD::set_state_8() { add_flags_2e4(8); }

void TObjEneDD::set_invulnerable() {
    s32 i;
    this->actorFlags |= 0x04000000;
    for (i = 0; i < this->body_count; i++) {
        bodies[i].flags |= 0x02000000;
    }
}

void TObjEneDD::clear_invulnerable() {
    s32 i;
    this->actorFlags &= ~0x04000000;
    for (i = 0; i < this->body_count; i++) {
        bodies[i].flags &= ~0x02000000;
    }
}

void TObjEneDD::enable_body_collision() {
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        bodies[i].flags |= 1;
    }
}

void TObjEneDD::disable_body_collision() {
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        bodies[i].flags &= ~1;
    }
}

void TObjEneDD::set_intangible() {
    this->set_invulnerable();
    this->disable_body_collision();
    this->actorFlags = (s32) (this->actorFlags | 0x04040000);
}

void TObjEneDD::clear_intangible() {
    this->clear_invulnerable();
    this->enable_body_collision();
    this->actorFlags = (s32) (this->actorFlags & 0xFBFBFFFF);
}

void TObjEneDD::set_colliders_contact_high() {
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        set_collider_contact_high(&bodies[i]);
    }
}

void TObjEneDD::set_colliders_contact_low() {
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        set_collider_contact_low(&bodies[i]);
    }
}

s32 TObjEneDD::is_confused() {
    return (u8)(((this->actorFlags & 0x10) - 0x10) == 0);
}

f32 TObjEneDD::calc_elapsed_scaled() {
    return 2.0f * (random_ratio() - 0.5f);
}

f32 TObjEneDD::rand_range(f32 low, f32 high) {
    return ((high - low) * this->random_ratio()) + low;
}

s32 TObjEneDD::get_random_scaled() {
    return (s32) (65535.0f * random_ratio());
}

void TObjEneDD::initialize_enemy_state(s32 parameter) {
    set_param(parameter);
}

void forward_split_screen_view_matrix() { TCameraCtrl::apply_split_screen_view_matrix(); }

void forward_transform_to_view(const Vec *in, Vec *out) { TCameraCtrl::transform_to_view(in, out); }

void TObjEneDD::reset_hp(player_stats *base_stats, AttackParams *attack_stats, ActorParamBlock *resistance_stats) {
    bind_enemy_combat_stats(base_stats, attack_stats, resistance_stats);
    referenceHp = hp;
}

void TObjEneDD::reload_stats_keep_hp_tp(player_stats *base_stats, AttackParams *attack_stats, ActorParamBlock *resistance_stats) {
    s16 a = this->hpmax;
    s16 c = this->hp;
    s16 b = this->tpmax;
    s16 d = this->tp;
    bind_enemy_combat_stats(base_stats, attack_stats, resistance_stats);
    this->hpmax = a;
    this->hp = c;
    this->tpmax = b;
    this->tp = d;
}

void TObjEneDD::update_secondary_light() { select_actor_lighting(this); }

void TObjEneDD::update_primary_light() { restore_scene_lighting(); }

void TObjEneDD::draw_oriented_shadow(const Vec *position, const Vec *normal, saddr angle, const Vec *scale) {
    s32 rot[3];
    direction_to_rotation_xz((u8 *)normal, &rot[0], &rot[2]);
    push_matrix();
    post_translate_matrix(&position->x);
    translate_matrix(0, 0.0f, 0.3f, 0.0f);
    rotate_matrix_z(0, rot[2]);
    rotate_matrix_x(0, rot[0]);
    rotate_matrix_y(NULL, angle);
    if (scale != NULL) {
        scale_current_matrix(&scale->x);
    }
    rotate_matrix_x(0, -0x4000);
    draw_blob_shadow(0);
    pop_matrix();
}

void TObjEneDD::draw_ground_shadow(const Vec *scale, s32 forceDraw) {
    TObjEnemy::draw_ground_shadow(scale, forceDraw);
}

void TObjEneDD::clear_global_flag_400() { model_render_flags = (model_render_flags & 0xfffffbff); }

void TObjEneDD::render_minimap_dot() {
    if (!(this->actorFlags & 0x40800)) {
        minimap_render_dot(&this->position, -0x5DB4, 1, 0);
    }
}

s32 TObjEneDD::is_main_phase_15() {
    return get_main_phase() == 0xF;
}

s32 TObjEneDD::is_phase_e() {
    return (u8) (get_main_phase() == 0xE);
}

int TObjEneDD::update_lobby_state() { return is_local_client_floor_leader(this); }

int TObjEneDD::query_teammate_state() { return TObjPlayer::is_any_teammate_in_state(); }

void project_sound_origin_from_camera(const Vec *source, Vec *out, f32 distance) {
    f32 scale;
    VecCopy(out, source);
    subtract_vector(out, &camera_ctrl_instance->pos);
    { f32 s = normalize_vector_safe(out); scale = s * distance; }
    out->x *= scale;
    out->y *= scale;
    out->z *= scale;
    vec3_add_to(out, &camera_ctrl_instance->pos);
}

int TObjEneDD::get_target_state_b() { return freeze_all_players__10TObjPlayerFv(this); }

int TObjEneDD::get_target_state_a() { return TObjPlayer__sub_801BA42C(this); }

s32 TObjEneDD::check_v2_mode() {
    if (((s32) enable_v2_features != 0) && ((s32) game_difficulty_selection == 3)) {
        return 1;
    }
    return 0;
}

s32 TObjEneDD::clamp_frame_index(s32 frame) {
    s32 limit;
    s32 idx;

    idx = frame;
    limit = 0xE;
    if (TObjEneDD::check_v2_mode() != 0) {
        limit = 0x1D;
    }
    if (idx < 0) {
        idx = 0;
    } else if (idx >= limit) {
        idx = limit - 1;
    }
    return idx;
}

void TObjEneDD__sub_800B9B24(f32) {}

void TObjEneDD::init_lights() { current_scene_light->sub_801337F8(); TObjLight__sub_801337FC(lbl_805D555C); }


TObjEneDD_ST::TObjEneDD_ST(TObject *parent) : TObjEneDD(parent) {
    m_name = TObjEneDD_ST__name;
    this->enemy_clear_target();
    init_float_params();
    enemy_init_acquire_period(30);
    enemy_init_validate_period(30);
}

TObjEneDD_ST::~TObjEneDD_ST() {}


void TObjEneDD_ST::update_velocity() {
    f32 dest_z;
    f32 dest_x;

    dest_x = destination.x;
    destination_direction.x = dest_x - position.x;
    destination_direction.y = 0.0f;
    dest_z = destination.z;
    destination_direction.z = dest_z - position.z;
    destination_distance = normalize_vector_xz__FP3Vec(&destination_direction, dest_z, dest_x);
}


void TObjEneDD_ST::init_float_params() {
    destination.x = 0.0f;
    destination.y = 0.0f;
    destination.z = 0.0f;
    destination_direction.x = 0.0f;
    destination_direction.y = 0.0f;
    destination_direction.z = 0.0f;
    destination_distance = 0.0f;
}


void enemy_set_target_id(TObjEneDD_ST *self, u16 id) {
    self->target_id = id;
    if (id != 0xFFFF) {
        self->current_target = (TObjChara *)find_active_entity_by_id(self->target_id);
    } else {
        self->target_id = 0xFFFF;
        self->current_target = 0;
    }
}

void TObjEneDD_ST::set_target_player(void *player) {
    s32 n;
    s32 i;
    target_id = 0xFFFF;
    current_target = 0;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        if (player == TObjPlayer::get_player_data(i)) {
            target_id = ((TObjBase *)(player))->get_entity_id();
            current_target = (TObjChara *)player;
            return;
        }
    }
}

void TObjEneDD_ST::enemy_clear_target() {
    current_target = 0;
    target_id = 0xFFFF;
}

void TObjEneDD_ST::enemy_init_acquire_period(s32 period) {
    acquire_counter = this->entity_id % period;
    acquire_period = period;
}

s32 TObjEneDD_ST::acquire_target(f32 distance) { return select_nearest_target(distance); }

s32 enemy_bind_or_clear_target(TObjEneDD_ST *self, u16 id) {
    if (id != 0xFFFF) {
        enemy_set_target_id(self, id);
        return 1;
    }
    self->enemy_clear_target();
    return 0;
}

s32 TObjEneDD_ST::select_and_apply_target(f32 range) {
    u16 enemy;
    u16 target;

    if (this->is_confused() != 0) {
        enemy = enemy_nearest_visible_enemy(this, range);
        target = enemy;
        if (enemy == 0xFFFF) {
            target = enemy_find_nearest_player_in_range(this, range);
        }
    } else {
        target = enemy_find_nearest_player_in_range(this, range);
    }
    return enemy_bind_or_clear_target(this, target);
}


s32 TObjEneDD_ST::select_nearest_target(f32 distance) {
    u16 target = enemy_find_nearest_player_in_range(this, distance);
    return enemy_bind_or_clear_target(this, target);
}

s32 TObjEneDD_ST::enemy_tick_target_acquisition(s32 *counter, s32 limit, f32 scale) {
    s32 has_target;
    if (tick_period_counter((saddr)this, counter, limit) != 0) {
        has_target = this->acquire_target(scale);
    } else {
        has_target = enemy_has_live_target();
        if (has_target == 0) {
            this->enemy_clear_target();
        }
    }
    return has_target;
}

s32 TObjEneDD_ST::update_linked_position(f32 scale) {
    return this->enemy_tick_target_acquisition(&acquire_counter, acquire_period, scale);
}

void TObjEneDD_ST::enemy_copy_target_destination() {
    TObjChara *target = current_target;
    if (target != NULL) {
        set_target_destination(&target->position);
    }
}

void TObjEneDD_ST::set_target_destination(const Vec *position) { VecCopy(&this->destination, position); }

void TObjEneDD_ST::enemy_init_validate_period(s32 period) {
    validate_period = period;
    validate_counter = (this->entity_id + 3) % validate_period;
}

s32 enemy_validate_retained_target(TObjEneDD_ST *self) {
    if (tick_period_counter((saddr)self, &self->validate_counter, self->validate_period) != 0) {
        if (is_target_unobstructed_from(self, self->current_target) != 0) {
            return 1;
        }
        goto block_5;
    }
    if (self->enemy_has_live_target() != 0) {
        return 1;
    }
block_5:
    self->enemy_clear_target();
    return 0;
}

s32 TObjEneEpsilon::update_death_check() {
    if ((this->is_confused() == 0) && (is_player_entity_id(this->target_id) == 0)) {
        this->enemy_clear_target();
        return 0;
    }
    return enemy_validate_retained_target(this);
}

void TObjEneDD_ST::turn_toward_target_direction(s32 max_step) {
    this->rotation_y = (s16) approach_angle_limited(this->rotation_y, (s32) (10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z)), max_step);
}

void TObjEneDD_ST::fire_attack_c(Vec *shot_pos, s32 iscale, f32 scale) {
    f32 dist;

    dist = scale;
    turn_toward_target_direction(iscale);
    this->calc_shot_position(shot_pos, (f32)(sin_table_lookup(this->rotation_y)), (f32)(cos_table_lookup(this->rotation_y)), (f32)dist);
}

void TObjEneDD_ST::fire_attack_b(Vec *out, s32 max_step, f32 distance) {
    f32 dz;
    f32 dist;

    dist = distance;
    turn_toward_target_direction(max_step);
    dz = cos_table_lookup(this->rotation_y);
    calc_wall_slide_destination(this, out, (f32)(sin_table_lookup(this->rotation_y)), (f32)((f32)dz), (f32)((f32)dist));
}

void TObjEneDD_ST::fire_attack_a(Vec *out, s32 max_step, f32 distance) {
    f32 dist;

    dist = distance;
    turn_toward_target_direction(max_step);
    calc_wall_clamped_destination(this, out, (f32)(sin_table_lookup(this->rotation_y)), (f32)((f32)cos_table_lookup(this->rotation_y)), (f32)((f32)dist));
}

CsnHit *TObjEneEpsilon__sub_800B9384(TObjEneDD_ST *self, s32 iscale, f32 scale) {
    Vec dest;
    self->fire_attack_c(&dest, iscale, scale);
    return self->try_move_actor_xz_on_ground(&dest);
}

CsnHit *enemy_turn_and_move_on_ground(TObjEneDD_ST *self, s32 max_step, f32 currentSpeed) {
    Vec dest;
    self->fire_attack_b(&dest, max_step, currentSpeed);
    return self->try_move_actor_xz_on_ground(&dest);
}


CsnHit *TObjEneEpsilon__sub_800B92F8(TObjEneDD_ST *self, s32 max_step, f32 distance) {
    Vec dest;
    self->fire_attack_b(&dest, max_step, distance);
    return self->move_xz_on_ground(&dest);
}

CsnHit *TObjEneEpsilon__sub_800B92AC(TObjEneDD_ST *self, s32 max_step, f32 distance) {
    Vec dest;
    self->fire_attack_a(&dest, max_step, distance);
    return self->move_xz_on_ground(&dest);
}

s32 TObjEneDD_ST::update_status_effects() {
    if ((is_player_entity_id(target_id) != 0) && (get_player_by_client_id(target_id) == 0U)) {
        this->enemy_clear_target();
    }
    return TObjEneDD::update_status_effects();
}

s32 TObjEneDD_ST::enemy_check_target_valid() {
    u16 id = target_id;
    if (id == 0xFFFF) {
        return 0;
    }
    if (find_entity_by_id(id) == 0U) {
        this->enemy_clear_target();
        return 0;
    }
    return ((TObjEneDD *)current_target)->is_valid_target();
}

#pragma push
#pragma fp_contract on
s32 TObjEneDD_ST::enemy_has_live_target() {
    u32 id = target_id;
    if (id == 0xFFFF) {
        return 0;
    }
    if (find_entity_by_id(id) == 0U) {
        this->enemy_clear_target();
        return 0;
    }
    return current_target->is_alive();
}
#pragma pop

