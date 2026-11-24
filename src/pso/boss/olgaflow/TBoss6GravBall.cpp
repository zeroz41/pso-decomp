#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/boss/olgaflow/TBoss6GravBall.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/task/TObject.h"

#include "pso/player/TObjPlayer.h"

#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/ui/frontend/TAdLdQuestPrtGC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixOps.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"


const char TBoss6GravBall__class_name_string[] = "TBoss6GravBall";
const s32 TBoss6GravBall__emitter_id_table[9] = {535, 536, 537, 538, 539, 534, 534, 534, 534};
// The emitters the constructor creates.
const s32 boss6_grav_ball_start_emitters[2] = {0, 1};
// drift_to_center snaps the ball here once it is within 2/3 of a unit.
const Vec boss6_grav_ball_origin = {0.0f, 0.0f, 0.0f};
const char *TBoss6GravBall__name = TBoss6GravBall__class_name_string;

void TBoss6GravBall::update_emitter_positions() {
    s32 i;
    Vec position;
    for (i = 0; i < 9; i++) {
        if (emitters[i] != NULL) {
            switch (i) {
            case 5: case 6: case 7: case 8: {
                TObjPlayer *player = get_player_by_client_id((u16)(i - 5));
                if (player != NULL) {
                    VecCopy(&position, &player->position);
                    emitters[i]->set_position(&position);
                }
                break;
            }
            default:
                emitters[i]->set_position(&ball_position);
                break;
            }
        }
    }
}

void TBoss6GravBall::destroy_part(s32 index) {
    if (emitters[index] != NULL) {
        TParticleCtrl::release(emitters[index]);
        emitters[index] = NULL;
    }
}

void TBoss6GravBall::create_charge_emitter(s32 index) {
    if (emitters[index] == NULL) {
        emitters[index] = create_particle_emitter(&ball_position, TBoss6GravBall__emitter_id_table[index]);
        if (emitters[index] != NULL) {
            emitters[index]->set_flags(0x2040);
        }
    }
}

void TBoss6GravBall::create_emitter(s32 index) {
    if (emitters[index] == NULL) {
        emitters[index] = create_particle_emitter(&ball_position, TBoss6GravBall__emitter_id_table[index]);
        if (emitters[index] != NULL) {
            emitters[index]->set_flags(0x40);
        }
    }
}

void TBoss6GravBall::init_parts() {
    s32 i;
    i = 0;
    do {
        destroy_part(i);
        i += 1;
    } while (i < 9);
}

void TBoss6GravBall::clear_emitters() {
    for (s32 i = 0; i < 9; i++) {
        emitters[i] = NULL;
    }
}

void TBoss6GravBall::render() {  }

void TBoss6GravBall::clear_player_grav_flags() {
    s32 n = TLobby::get_game_mode();
    s32 i;
    for (i = 0; i < n; i++) {
        TObjPlayer *p = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_state_1f(p) != 0) {
            p->actorFlags &= 0xFFFDFFFF;
        }
    }
}

void TBoss6GravBall::push_players() {
    Vec v;
    s32 n;
    s32 i;
    TObjPlayer *pl;
    saddr id;
    s32 flag;
    f32 d;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        pl = TObjPlayer::get_player_data(i);
        id = pl->get_entity_id() + 5;
        if (TBoss6PlotFalz::is_active(pl) == 0) {
            destroy_part(id);
            continue;
        }
        flag = 0;
        VecCopy(&v, &ball_position);
        subtract_vector(&v, &pl->position);
        v.y = 0.0f;
        d = vector_length(&v);
        if (d > 32.5f) {
            destroy_part(id);
            continue;
        }
        if (d <= 1e+01f) {
            s32 a = pl->get_entity_id() << 14;
            v.x = 2.5f * sin_table_lookup(a) + v.x;
            v.z = 2.5f * cos_table_lookup(a) + v.z;
            flag = 1;
        } else {
            f32 s = (-33.5f) + d;
            normalize_vector(&v);
            v.x *= s;
            v.z *= s;
        }
        vec3_add_to(&v, &pl->position);
        project_actor_to_ground(this, &v, NULL);
        TBoss6PlotFalz::move_player_to(pl, &v);
        if (flag != 0) {
            pl->actorFlags |= 0x20000;
            create_emitter(id);
        }
    }
}

void TBoss6GravBall::pull_players() {
    Vec v;
    s32 n;
    s32 i;
    TObjPlayer *pl;
    saddr id;
    s32 flag;
    f32 d;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        pl = TObjPlayer::get_player_data(i);
        id = pl->get_entity_id() + 5;
        if (TBoss6PlotFalz::is_active(pl) == 0) {
            destroy_part(id);
            continue;
        }
        flag = 1;
        VecCopy(&v, &ball_position);
        {
            s32 a = pl->get_entity_id() << 14;
            v.x = 2.5f * sin_table_lookup(a) + v.x;
            v.z = 2.5f * cos_table_lookup(a) + v.z;
        }
        subtract_vector(&v, &pl->position);
        v.y = 0.0f;
        d = vector_length(&v);
        if (d > 1e+01f) {
            f32 s;
            if (pull_flags & 1) {
                destroy_part(id);
                continue;
            }
            s = 3.0f * (pull_strength * (1.0f - d / 225.0f));
            if (s < 1.0f) {
                s = 1.0f;
            }
            normalize_vector(&v);
            flag = 0;
            v.x *= s;
            v.z *= s;
        }
        vec3_add_to(&v, &pl->position);
        project_actor_to_ground(this, &v, NULL);
        TBoss6PlotFalz::move_player_to(pl, &v);
        if (flag != 0) {
            pl->actorFlags |= 0x20000;
            create_emitter(id);
        }
    }
}

void TBoss6GravBall::drift_to_center() {
    Vec v = ball_position;
    v.y = 0.0f;
    if (vector_length(&v) > 0.6666667f) {
        normalize_vector(&v);
        v.x *= 0.6666667f;
        v.z *= 0.6666667f;
        subtract_vector(&ball_position, &v);
    } else {
        VecCopy(&ball_position, &boss6_grav_ball_origin);
    }
    clamp_to_ground();
}

s32 TBoss6GravBall::clamp_to_ground() {
    Vec v = ball_position;
    if (project_actor_to_ground(this, &v, NULL) == 0) {
        queue_destruction();
        return 1;
    }
    v.y += 1e+01f;
    ball_position.y += -2.0f;
    if (ball_position.y < v.y) {
        ball_position.y = v.y;
        return 1;
    }
    return 0;
}

void TBoss6GravBall::update_lifetime() {
    s32 next_age;

    next_age = age + 1;
    age = next_age;
    if (next_age > 0x1E) {
        queue_destruction();
    }
}

void TBoss6GravBall::update_charge_effects() {
    s32 charge;
    s32 pulse;
    s32 slow_pulse;

    push_players();
    play_persistent_sound(0x4003C418, this, &ball_position, 0, 0);
    charge = charge_age;
    if (charge >= 0x96) {
        if (charge == 0x96) {
            create_emitter(3);
        }
    } else if (charge > 0x4B) {
        pulse = charge & 0xF;
        if (pulse == 0) {
            create_emitter(3);
        } else if (pulse == 0xE) {
            destroy_part(3);
        }
    } else {
        slow_pulse = charge & 0xF;
        if (slow_pulse == 0) {
            create_emitter(3);
        } else if (slow_pulse == 0xA) {
            destroy_part(3);
        }
    }
    charge_age = (s32) (charge_age + 1);
    age = (s32) (age + 1);
    switch (owner->get_gravity_attack_state()) {
    case 29:
    case 30:
    case 39:
        return;
    case 31:
        if ((s32) burst_played == 0) {
            spawn_particle_effect((&ball_position), 0x21C);
            spawn_particle_effect((&ball_position), 0x21D);
            burst_played = 1;
        }
        destroy_part(5);
        destroy_part(6);
        destroy_part(7);
        destroy_part(8);
        return;
    case 32:
        destroy_part(4);
        destroy_part(3);
        destroy_part(5);
        destroy_part(6);
        destroy_part(7);
        destroy_part(8);
        age = 0;
        clear_player_grav_flags();
        state = 2;
        play_sound_effect(0x4003C417, &ball_position, 0, 0);
        return;
    default:
        queue_destruction();
        return;
    }
}

void TBoss6GravBall::update_state() {
    s32 grounded;
    grounded = clamp_to_ground();
    if (grounded != 0) {
        drift_to_center();
    }
    update_emitter_positions();
    if (grounded != 0) {
        create_emitter(2);
        if ((pull_strength) < 1.0f) {
            pull_strength += 0.033333335f;
            if (pull_strength > 1.0f) {
                pull_strength = 1.0f;
            }
        }
        pull_players();
        play_persistent_sound(0x4003B51A, this, &ball_position, 0, 0);
        switch (owner->get_gravity_attack_state()) {
        case 0x27:
            return;
        case 0x1D:
            break;
        case 0x1E:
        case 0x1F:
            destroy_part(0);
            destroy_part(1);
            destroy_part(2);
            create_charge_emitter(4);
            charge_age = 0;
            age = 0;
            state = 1;
            play_sound_effect(0x4003B516, &ball_position, 0, 0);
            break;
        case 0x20:
        default:
            queue_destruction();
            break;
        }
    }
}

void TBoss6GravBall::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        return;
    }
    if (TObjEneDD::query_teammate_state() != 0) {
        return;
    }
    typedef void (TBoss6GravBall::*Handler)();
    static Handler handlers[3] = {
        &TBoss6GravBall::update_state, &TBoss6GravBall::update_charge_effects, &TBoss6GravBall::update_lifetime,
    };
    Handler action = handlers[state];
    if (action) {
        (this->*action)();
    }
    pull_flags++;
}

TBoss6GravBall::~TBoss6GravBall() {
    init_parts();
    clear_player_grav_flags();
}
TBoss6GravBall::TBoss6GravBall(TBoss6Type1 *owner, const Vec *position)
    : TObjCollidable(owner) {
    s32 i;
    m_name = TBoss6GravBall__name;
    this->owner = owner;
    VecCopy(&ball_position, position);
    age = 0;
    state = 0;
    pull_strength = 0.0f;
    pull_flags = 0;
    burst_played = 0;
    clear_emitters();
    for (i = 0; i < 2; i++) {
        create_emitter(boss6_grav_ball_start_emitters[i]);
    }
}
