#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/BattleParameters.h"
#include "types.h"
#include "pso/boss/darkfalz/TBoss4Zako.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/boss/darkfalz/TBoss4Bishi.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Type1.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/TObjControl.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_803D96A8.h"

#pragma defer_codegen on

CollisionBody TBoss4Zako_collision_body_parts[1] = {
    { { 0.0f, 7.5f, 0.0f }, 5.0f, 0.0f, 0, 0x807A, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

#pragma readonly_strings on

static const char TBoss4Zako__class_name_string[] = "TBoss4Zako";
static const char TBoss4Uro__class_name_string[] = "TBoss4Uro";
static const char TBoss4Bishi__class_name_string[] = "TBoss4Bishi";
const char *TBoss4Zako__name = TBoss4Zako__class_name_string;
const char *TBoss4Uro__name = TBoss4Uro__class_name_string;
const char *TBoss4Bishi__name = TBoss4Bishi__class_name_string;

static const f32 movement_speed_step = 0.033333335f;
static const f32 one_third = 0.33333334f;

// Counts a spawned minion (get_live_minion_count returns minions_spawned - minions_lost).
void TBoss4DarkFalz::count_minion_spawned() {
    minions_spawned = minions_spawned + 1;
}

// Counts a minion that died or sank.
void TBoss4DarkFalz::count_minion_lost() {
    minions_lost = minions_lost + 1;
}

s32 TBoss4Zako::is_hunting() {
    return state == 1 || state == 2;
}

s32 TBoss4Zako::is_not_sinking() {
    return (u8)(state != 3);
}

TBoss4Zako *TBoss4Zako::create(TBoss4ZakoSetData *set_data) {
    return new TBoss4Zako(new TObjControl(tl_04), set_data);
}

#pragma push
#pragma fp_contract on
TBoss4Zako::TBoss4Zako(TObject *parent, TBoss4ZakoSetData *set_data) : TObjEnemy(parent) {
    m_name = TBoss4Zako__name;
    add_flags_2e4(8);
    owner = set_data->owner;
    owner->count_minion_spawned();
    apply_set_data(&set_data->set_index);
    clear_lobby_object_state();
    archive = TBoss4Uro::get_instance_count();
    texlist = 0;
    model = 0;
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    collision = init_collision_body_parts(this, TBoss4Zako_collision_body_parts, 1);
    VecCopy(&body_center, &position);
    TObjChara::velocity.z = 0.0f;
    TObjChara::velocity.y = 0.0f;
    TObjChara::velocity.x = 0.0f;
    target = 0;
    bind_enemy_combat_stats(TLobby::register_boss(0x35), TLobby::dispatch_shared_handler_b(0x35), TLobby::register_object(0x35));
    referenceHp = hp;
    register_by_id();
    set_param(0);
    target_id = 0;
    if ((emitter = create_particle_emitter(&position, 0x103)) != 0) {
        emitter->set_flags(0x40);
    }
    speed = 0.0f;
    velocity.z = 0.0f;
    velocity.y = 0.0f;
    velocity.x = 0.0f;
    state_timer = 10.0f * (entity_id & 3);
    rotation_x = 0;
    rotation_y = entity_id << 14;
    frame_count = 0;
    surfaced = 0;
    surface_timer = (entity_id % 6 + 1) * 450;
    spin_ratio = 0.0f;
    bob_angle = 65536.0f * random_ratio();
    bob_angle_step = 2184.0f * random_ratio() + 1092.0f;
    max_speed = TLobby::dispatch_shared_handler_a(0x35)->values.floats[0];
    if (max_speed <= one_third || max_speed > 5.833333f) {
        max_speed = 0.5833333f;
    }
    max_speed_alt = TLobby::dispatch_shared_handler_a(0x39)->values.floats[0];
    if (max_speed_alt <= one_third || max_speed_alt > 10.208332f) {
        max_speed_alt = 1.0208333f;
    }
    state = 0;
}
#pragma pop

TBoss4Zako::~TBoss4Zako() {
    free_collision_body_parts(this);
    collision = 0;
    if (emitter != 0) {
        TParticleCtrl::release(emitter);
        emitter = 0;
    }
}

void TBoss4Zako::run_death_reaction() {
    if (state != 3) {
        set_state3();
    }
}

#pragma push
#pragma fp_contract on
void TBoss4Zako::run_task() {
    void (TBoss4Zako::*fn)();

    if (is_not_sinking() != 0 && owner->get_phase() != 4) {
        set_state3();
    }
    if (is_hunting() != 0) {
        surface_timer--;
        if (surface_timer < 0) {
            surfaced = 0;
            surface_timer = 2700;
        } else if (surface_timer < 450) {
            surfaced = 1;
        }
    }
    static void (TBoss4Zako::*state_handlers[5])() = {
        &TBoss4Zako::update_rise_state,
        &TBoss4Zako::update_move_to_target_state,
        &TBoss4Zako::update_surround_player_state,
        &TBoss4Zako::update_sink_state,
    };
    fn = state_handlers[state];
    if (fn) {
        (this->*fn)();
        if (state == 1 || state == 2) {
            position.y = 0.099999994f * sin_table_lookup(bob_angle) + position.y;
            bob_angle += bob_angle_step;
        }
        if (emitter != NULL) {
            Vec p = position;
            if (surfaced != 0) {
                p.y += 10.0f;
            } else {
                p.y += -250.0f;
            }
            emitter->set_position(&p);
        }
        spin_ratio = 0.0f;
        if (surfaced != 0) {
            if (surface_timer < 30) {
                spin_ratio = (f32)surface_timer / 30.0f;
            } else {
                spin_ratio = 1.0f;
            }
        } else if (surface_timer < 480) {
            spin_ratio = (f32)(480 - surface_timer) / 30.0f;
        }
        if (is_hunting() != 0 && spin_ratio > 0.0f) {
            rotation_y = 4369.0f * spin_ratio + rotation_y;
        }
        apply_contact_damage();
        update_prev_position();
        queue_entry(&position, rotation_x, rotation_y);
        if (is_not_sinking() != 0) {
            if (surfaced != 0) {
                collision->flags |= 1;
                update_collisions();
                submit_cursor_candidate(this, -1);
                minimap_render_dot(&body_center, -0x5DB4, 1, 0);
            } else {
                collision->flags &= ~1;
                add_radar_scaled_marker(&body_center, 0xFF7F5126, 1, 1, 1.0f);
            }
        }
        frame_count++;
    }
}
#pragma pop

void TBoss4Zako::render() {}

void TBoss4Zako::update_rise_state() {
    VecCopy(&prev_position, &position);
    if (position.y < 6.0f) {
        if ((position.y += one_third) > 6.0f) {
            position.y = 6.0f;
            state = 1;
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss4Zako::update_move_to_target_state() {
    Vec d;
    f32 limit;
    f32 dist;
    s32 id;
    VecCopy(&d, &home_position);
    subtract_vector(&d, &position);
    d.y = 0.0f;
    dist = vector_length(&d);
    if (dist < 1.0f && speed < 1.0f) {
        position.x = home_position.x;
        position.z = home_position.z;
        speed = 0.0f;
        velocity.z = 0.0f;
        velocity.x = 0.0f;
        if (--state_timer < 0) {
            id = find_nearest_visible_player(this, 0, 150.0f);
            target_id = id;
            if (id == 0xFFFF) {
                state_timer = 0x3C;
                return;
            }
            state_timer = 0xB4;
            state = 2;
        }
        return;
    }
    if (dist < 25.0f) {
        if ((speed -= movement_speed_step) < one_third) {
            speed = one_third;
        }
    } else {
        if ((speed += movement_speed_step) > (limit = max_speed)) {
            speed = limit;
        }
    }
    VecCopy(&velocity, &d);
    if (0.0f != dist) {
        normalize_vector(&velocity);
    }
    velocity.x *= speed;
    velocity.z *= speed;
    vec3_add_to(&position, &velocity);
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss4Zako::update_surround_player_state() {
    TObjPlayer *pl;
    s32 ang;
    pl = get_player_by_client_id(target_id);
    if (pl == NULL) {
        state_timer = 0x3C;
        state = 1;
        return;
    }
    Vec t = pl->position;
    ang = entity_id << 0xD;
    t.x = 8.0f * sin_table_lookup(ang) + t.x;
    t.z = 8.0f * cos_table_lookup(ang) + t.z;
    if (position.x < t.x) {
        velocity.x += 0.029166667f;
    } else {
        velocity.x -= 0.029166667f;
    }
    if (position.z < t.z) {
        velocity.z += 0.029166667f;
    } else {
        velocity.z -= 0.029166667f;
    }
    speed = vector_length(&velocity);
    if (speed > max_speed) {
        normalize_vector(&velocity);
        velocity.x *= max_speed;
        velocity.z *= max_speed;
        speed = max_speed;
    }
    vec3_add_to(&position, &velocity);
    if (--state_timer < 0) {
        state_timer = 0x3C;
        state = 1;
    }
}
#pragma pop

void TBoss4Zako::update_sink_state() {
    f32 y;
    position.y += -0.33333334f;
    y = position.y;
    if ((y < 0.0f) && (y >= -0.33333334f)) {
        spawn_particle_effect(&position, 0xF3);
    }
    rotation_x = (rotation_x + 0x111);
    if (position.y < -13.0f) {
        queue_destruction();
    }
}

void TBoss4Zako::set_state3() {
    owner->count_minion_lost();
    surfaced = 0;
    state = 3;
}

#pragma push
#pragma dont_inline off
#pragma auto_inline off
#pragma inline_depth(2)
void TBoss4Zako::apply_contact_damage() {
    DirectAttackPayload hit;
    s32 lim;
    s32 n;
    s32 id;
    TObjPlayer *p;

    if (speed <= 0.5f) {
        lim = 16;
    } else {
        lim = (s32)(8.0f / speed);
    }
    for (n = 1; n < lim; n *= 2) {
    }
    if (((n - 1) & frame_count) != 0 || is_hunting() == 0) {
        return;
    }
    id = find_nearest_visible_player(this, 0, 8.0f);
    if (id == 0xFFFF || (p = get_player_by_client_id(id)) == 0) {
        return;
    }
    hit.kind = 0;
    hit.power = atp;
    p->receive_direct_attack(this, hit, 0, -1, -1);
}
#pragma pop

TBoss4Uro *TBoss4Uro::create(TBoss4ZakoSetData *set_data) {
    return new TBoss4Uro(new TObjControl(tl_04), set_data);
}

#pragma push
#pragma fp_contract on
TBoss4Uro::TBoss4Uro(TObject *parent, TBoss4ZakoSetData *set_data) : TBoss4Zako(parent, set_data) {
    m_name = TBoss4Uro__name;
    velocity.x = -position.x;
    velocity.y = 0.0f;
    velocity.z = -position.z;
    if (vector_length(&velocity) < 0.01f) {
        velocity.x = 1.0f;
        velocity.z = 0.0f;
    }
    normalize_vector(&velocity);
    speed = 0.41666666f * random_ratio() + 1.6666666f;
    velocity.x = velocity.x * speed;
    velocity.z = velocity.z * speed;
    target_id = 0xFFFF;
    orbit_center.x = 0.0f;
    orbit_center.y = 0.0f;
    orbit_center.z = 0.0f;
    state = 4;
    collision->flags |= 1;
}
#pragma pop

TBoss4Uro::~TBoss4Uro() {}

void TBoss4Uro::run_death_reaction() {
    if (state != 3) {
        distribute_experience();
        owner->count_minion_lost();
        state = 3;
    }
}

#pragma push
#pragma fp_contract on
// Keeps it at least 100 units from Dark Falz on the xz plane.
void TBoss4Uro::clamp_min_player_distance() {
    Vec target;
    Vec d;
    f32 len;
    if (owner == 0) {
        return;
    }
    TBoss4Type1 *falz = TBoss4DarkFalz::get_instance();
    if (falz == NULL) {
        return;
    }
    VecCopy(&target, reinterpret_cast<TObjPlayer *>(falz)->get_position_ptr());
    VecCopy(&d, &position);
    subtract_vector(&d, &target);
    d.y = 0.0f;
    len = vector_length(&d);
    if (len >= 100.0f) {
        return;
    }
    if (len > 0.01f) {
        normalize_vector(&d);
    } else {
        d.x = 1.0f;
        d.z = 0.0f;
    }
    position.x = 100.0f * d.x + target.x;
    position.z = 100.0f * d.z + target.z;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss4Uro::run_task() {
    if (state != 3 && owner->get_phase() != 6) {
        owner->count_minion_lost();
        state = 3;
        return;
    }
    static void (TBoss4Uro::*state_handlers[5])() = {
        0,
        0,
        &TBoss4Uro::vt4,
        &TBoss4Uro::update_sink_state,
        &TBoss4Uro::vt6,
    };
    void (TBoss4Uro::*fn)() = state_handlers[state];
    if (fn) {
        (this->*fn)();
        if (state == 2) {
            position.y = 0.099999994f * sin_table_lookup(bob_angle) + position.y;
            bob_angle += bob_angle_step;
        }
        Vec v = position;
        if (is_not_sinking() != 0) {
            v.y += 10.0f;
        } else {
            v.y += -250.0f;
        }
        emitter->set_position(&v);
        if (is_not_sinking() != 0) {
            rotation_y += 0x1111;
        }
        queue_entry(&position, rotation_x, rotation_y);
        apply_contact_damage();
        update_prev_position();
        if (is_not_sinking() != 0) {
            update_collisions();
            submit_cursor_candidate(this, -1);
            minimap_render_dot(&body_center, -0x5DB4, 1, 0);
        }
        frame_count++;
    }
}
#pragma pop

struct TBoss4BishiSpawnOffset {
    f32 x;
    f32 z;
};

// Where around its target player each TBoss4Bishi aims (entity_id & 3).
TBoss4BishiSpawnOffset TBoss4Bishi_spawn_offsets[4] = {
    { -4.0f, -4.0f }, { 4.0f, -4.0f }, { -4.0f, 4.0f }, { 4.0f, 4.0f },
};

void TBoss4Uro::vt4() {
    update_target_position();
    update_orbit_velocity();
    VecCopy(&prev_position, &position);
    vec3_add_to(&position, &velocity);
}

#pragma push
#pragma fp_contract on
void TBoss4Uro::update_target_position() {
    s32 angle;
    TBoss4Type1 *instance;
    if (!(frame_count & 0x7F)) {
        if (target_id == 0xFFFF) {
            target_id = find_nearest_visible_player(this, 0, 287.5f);
            return;
        }
        target_id = 0xFFFF;
        if (owner != 0) {
            instance = TBoss4DarkFalz::get_instance();
            if (instance != NULL) {
                angle = 65536.0f * random_ratio();
                VecCopy(&orbit_center, reinterpret_cast<TObjPlayer *>(instance)->get_position_ptr());
                orbit_center.y = 0.0f;
                orbit_center.x = 110.0f * sin_table_lookup(angle) + orbit_center.x;
                orbit_center.z = 110.0f * cos_table_lookup(angle) + orbit_center.z;
            }
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss4Uro::update_orbit_velocity() {
    f32 tx;
    f32 tz;
    s32 ang;
    TObjPlayer *pl;
    if (target_id != 0xFFFF) {
        pl = get_player_by_client_id(target_id);
        if (pl != 0) {
            VecCopy(&orbit_center, &pl->position);
        }
    }
    ang = entity_id << 0xD;
    tx = 16.0f * sin_table_lookup(ang) + orbit_center.x;
    tz = 16.0f * cos_table_lookup(ang) + orbit_center.z;
    velocity.y = 0.0f;
    if (position.x < tx) {
        velocity.x += 0.051041663f;
    } else {
        velocity.x -= 0.051041663f;
    }
    if (position.z < tz) {
        velocity.z += 0.051041663f;
    } else {
        velocity.z -= 0.051041663f;
    }
    clamp_min_player_distance();
    speed = vector_length(&velocity);
    if (speed > max_speed_alt) {
        speed += -0.051041663f;
        normalize_vector(&velocity);
        velocity.x *= speed;
        velocity.z *= speed;
    }
}
#pragma pop

void TBoss4Uro::update_sink_state() {
    f32 y;
    position.y += -0.33333334f;
    y = position.y;
    if ((y < 0.0f) && (y >= -0.33333334f)) {
        spawn_particle_effect(&position, 0xF3);
    }
    rotation_x = (rotation_x + 0x111);
    if (position.y < -13.0f) {
        queue_destruction();
    }
}

void TBoss4Uro::vt6() {
    velocity.y += -0.015000001f;
    VecCopy(&prev_position, &position);
    vec3_add_to(&position, &velocity);
    if (position.y < 6.0f) {
        velocity.y = 0.0f;
        position.y = 6.0f;
        state = 2;
    }
}

TBoss4Bishi *TBoss4Bishi::create(TBoss4ZakoSetData *set_data) {
    return new TBoss4Bishi(new TObjControl(tl_04), set_data);
}

#pragma push
#pragma opt_common_subs off
TBoss4Bishi::TBoss4Bishi(TObject *parent, TBoss4ZakoSetData *set_data) : TBoss4Zako(parent, set_data) {
    s32 id;
    TObjPlayer *pl;
    m_name = TBoss4Bishi__name;
    if ((id = find_nearest_visible_player(this, 0, 100.0f)) == 0xFFFF ||
        (pl = get_player_by_client_id(id)) == 0) {
        velocity.x = velocity.z = 0.0f;
    } else {
        VecCopy(&velocity, &pl->position);
        id = entity_id & 3;
        velocity.x += TBoss4Bishi_spawn_offsets[id].x;
        velocity.z += TBoss4Bishi_spawn_offsets[id].z;
    }
    subtract_vector(&velocity, &position);
    velocity.y = 0.0f;
    if (0.0f == vector_length(&velocity)) {
        velocity.x = 1.0f;
        velocity.z = 0.0f;
    } else {
        normalize_vector(&velocity);
    }
    speed = max_speed_alt;
    velocity.x *= speed;
    velocity.z *= speed;
    position.y = -13.0f;
    charge_timer = 0x96;
    state = 0;
    collision->flags |= 1;
}
#pragma pop

TBoss4Bishi::~TBoss4Bishi() {}

void TBoss4Bishi::run_death_reaction() {
    if (state != 3) {
        distribute_experience();
        enter_state_3();
    }
}

void TBoss4Bishi::enter_state_3() {
    if (state != 3) {
        owner->count_minion_lost();
        state = 3;
    }
}

#pragma push
#pragma fp_contract on
void TBoss4Bishi::run_task() {
    if (state != 3 && owner->get_phase() != 8) {
        enter_state_3();
        return;
    }
    static void (TBoss4Bishi::*state_handlers[5])() = {
        &TBoss4Bishi::update_rise_state,
        0,
        &TBoss4Bishi::vt1,
        &TBoss4Bishi::update_sink_state,
        0,
    };
    void (TBoss4Bishi::*fn)() = state_handlers[state];
    if (fn) {
        (this->*fn)();
        if (state == 2) {
            position.y = 0.099999994f * sin_table_lookup(bob_angle) + position.y;
            bob_angle += bob_angle_step;
        }
        Vec v = position;
        if (is_not_sinking() != 0) {
            v.y += 10.0f;
        } else {
            v.y += -250.0f;
        }
        emitter->set_position(&v);
        if (is_not_sinking() != 0) {
            rotation_y += 0x1111;
        }
        queue_entry(&position, rotation_x, rotation_y);
        apply_contact_damage();
        update_prev_position();
        if (is_not_sinking() != 0) {
            update_collisions();
            submit_cursor_candidate(this, -1);
            minimap_render_dot(&body_center, -0x5DB4, 1, 0);
        }
        frame_count++;
    }
}
#pragma pop

void TBoss4Bishi::update_rise_state() {
    VecCopy(&prev_position, &position);
    if (position.y < 6.0f) {
        if ((position.y += 1.1111112f) > 6.0f) {
            position.y = 6.0f;
            state = 2;
        }
    }
}

void TBoss4Bishi::vt1() {
    VecCopy(&prev_position, &position);
    vec3_add_to(&position, &velocity);
    Vec v = position;
    v.y = 0.0f;
    if (--charge_timer < 0 || vector_length(&v) > 260.0f) {
        enter_state_3();
    }
}

void TBoss4Bishi::update_sink_state() {
    f32 y;
    position.y += -0.33333334f;
    y = position.y;
    if ((y < 0.0f) && (y >= -0.33333334f)) {
        spawn_particle_effect(&position, 0xF3);
    }
    rotation_x = (rotation_x + 0x111);
    if (position.y < -13.0f) {
        queue_destruction();
    }
}

void TBoss4Type3::clear_harmful_statuses() {}
void TBoss4Type3::apply_shock_status() {}
void TBoss4Type3::apply_movement_ailment(s32) {}
void TBoss4Type3::apply_confusion_status() {}
void TBoss4Type3::apply_slow_status() {}
void TBoss4Type3::apply_paralysis() {}
void TBoss4Type3::apply_poison_status() {}
