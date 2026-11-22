#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/boss/olgaflow/TBoss6GravBall.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/task/TObject.h"

#include "pso/player/TObjPlayer.h"

#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/unk/TLobby.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/ui/frontend/TAdLdQuestPrtGC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_803D96A8.h"


const char TBoss6GravBall__class_name_string[] = "TBoss6GravBall";
const s32 TBoss6GravBall__emitter_id_table[9] = {535, 536, 537, 538, 539, 534, 534, 534, 534};
const s32 lbl_8047667C[2] = {0, 1};
const Vec lbl_80476684 = {0.0f, 0.0f, 0.0f};
const char *TBoss6GravBall__name = TBoss6GravBall__class_name_string;

extern "C" {

void fn_80323134(TBoss6GravBall *ball) {
    s32 i;
    Vec position;
    for (i = 0; i < 9; i++) {
        if (ball->emitters[i] != NULL) {
            switch (i) {
            case 5: case 6: case 7: case 8: {
                TObjPlayer *player = get_player_by_client_id((u16)(i - 5));
                if (player != NULL) {
                    VecCopy(&position, &player->position);
                    ball->emitters[i]->set_position(&position);
                }
                break;
            }
            default:
                ball->emitters[i]->set_position(&ball->ball_position);
                break;
            }
        }
    }
}

#pragma push
#pragma opt_common_subs off

void TBoss6GravBall::destroy_part(s32 index) {
    u8 *entry_base = (u8 *)((uaddr)this + index * sizeof(TParticleCtrl *));
    TParticleCtrl *emitter = *(TParticleCtrl **)(entry_base + offsetof(TBoss6GravBall, emitters));
    if (emitter != NULL) {
        TParticleCtrl::release(emitter);
        *(TParticleCtrl **)(entry_base + offsetof(TBoss6GravBall, emitters)) = NULL;
    }
}

void TBoss6GravBall__sub_80323214(TBoss6GravBall *ball, s32 index) {
    s32 offset = index * sizeof(TParticleCtrl *);
    u8 *entry_base = (u8 *)((uaddr)ball + offset);
    if (*(TParticleCtrl **)(entry_base + offsetof(TBoss6GravBall, emitters)) == NULL) {
        *(TParticleCtrl **)(entry_base + offsetof(TBoss6GravBall, emitters)) =
            create_particle_emitter(&ball->ball_position, *(s32 *)((u8 *)TBoss6GravBall__emitter_id_table + offset));
        TParticleCtrl *emitter = *(TParticleCtrl **)(entry_base + offsetof(TBoss6GravBall, emitters));
        if (emitter != NULL) {
            emitter->set_flags(0x2040);
        }
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void TBoss6GravBall::create_emitter(s32 index) {
    s32 offset = index * sizeof(TParticleCtrl *);
    u8 *entry_base = (u8 *)((uaddr)this + offset);
    if (*(TParticleCtrl **)(entry_base + offsetof(TBoss6GravBall, emitters)) == NULL) {
        *(TParticleCtrl **)(entry_base + offsetof(TBoss6GravBall, emitters)) =
            create_particle_emitter(&ball_position, *(s32 *)((u8 *)TBoss6GravBall__emitter_id_table + offset));
        TParticleCtrl *emitter = *(TParticleCtrl **)(entry_base + offsetof(TBoss6GravBall, emitters));
        if (emitter != NULL) {
            emitter->set_flags(0x40);
        }
    }
}

#pragma pop

void TBoss6GravBall::init_parts() {
    s32 self = (saddr)this;
    s32 var_r31;
    var_r31 = 0;
    do {
        destroy_part(var_r31);
        var_r31 += 1;
    } while (var_r31 < 9);
}

void TBoss6GravBall__sub_80323320(TBoss6GravBall *ball) {
    for (s32 i = 0; i < 9; i++) {
        ball->emitters[i] = NULL;
    }
}

void TBoss6GravBall::render() {  }

}


extern "C" {
f32 vector_length(void *);
void subtract_vector(void *, void *);


void TBoss6GravBall__sub_803236F8(TBoss6GravBall *arg0);
s32 project_actor_to_ground(void *, void *, int);


u16 get_entity_id(void *);
void vec3_add_to(void *, void *);
void TBoss6PlotFalz__sub_802AC724(void *, void *);


void TBoss6GravBall__sub_803233AC(TBoss6GravBall *self);


void TBoss6GravBall__sub_80323544(TBoss6GravBall *self);

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

void TBoss6GravBall__sub_803233AC(TBoss6GravBall *self) {
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
        id = get_entity_id(pl) + 5;
        if (TBoss6PlotFalz::is_active(pl) == 0) {
            self->destroy_part(id);
            continue;
        }
        flag = 0;
        VecCopy(&v, &self->ball_position);
        subtract_vector(&v, &pl->position);
        v.y = 0.0f;
        d = vector_length(&v);
        if (d > 32.5f) {
            self->destroy_part(id);
            continue;
        }
        if (d <= 1e+01f) {
            s32 a = get_entity_id(pl) << 14;
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
        project_actor_to_ground(self, &v, 0);
        TBoss6PlotFalz__sub_802AC724(pl, &v);
        if (flag != 0) {
            pl->actorFlags |= 0x20000;
            self->create_emitter(id);
        }
    }
}

void TBoss6GravBall__sub_80323544(TBoss6GravBall *self) {
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
        id = get_entity_id(pl) + 5;
        if (TBoss6PlotFalz::is_active(pl) == 0) {
            self->destroy_part(id);
            continue;
        }
        flag = 1;
        VecCopy(&v, &self->ball_position);
        {
            s32 a = get_entity_id(pl) << 14;
            v.x = 2.5f * sin_table_lookup(a) + v.x;
            v.z = 2.5f * cos_table_lookup(a) + v.z;
        }
        subtract_vector(&v, &pl->position);
        v.y = 0.0f;
        d = vector_length(&v);
        if (d > 1e+01f) {
            f32 s;
            if (self->pull_flags & 1) {
                self->destroy_part(id);
                continue;
            }
            s = 3.0f * (self->pull_strength * (1.0f - d / 225.0f));
            if (s < 1.0f) {
                s = 1.0f;
            }
            normalize_vector(&v);
            flag = 0;
            v.x *= s;
            v.z *= s;
        }
        vec3_add_to(&v, &pl->position);
        project_actor_to_ground(self, &v, 0);
        TBoss6PlotFalz__sub_802AC724(pl, &v);
        if (flag != 0) {
            pl->actorFlags |= 0x20000;
            self->create_emitter(id);
        }
    }
}

void TBoss6GravBall__sub_803236F8(TBoss6GravBall *boss6_grav_ball) {
    Vec v = boss6_grav_ball->ball_position;
    v.y = 0.0f;
    if (vector_length(&v) > 0.6666667f) {
        normalize_vector(&v);
        v.x *= 0.6666667f;
        v.z *= 0.6666667f;
        subtract_vector(&boss6_grav_ball->ball_position, &v);
    } else {
        VecCopy(&boss6_grav_ball->ball_position, &lbl_80476684);
    }
    boss6_grav_ball->clamp_to_ground();
}

s32 TBoss6GravBall::clamp_to_ground() {
    Vec v = ball_position;
    if (project_actor_to_ground(this, &v, 0) == 0) {
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
    s32 temp_r0;

    temp_r0 = age + 1;
    age = temp_r0;
    if (temp_r0 > 0x1E) {
        queue_destruction();
    }
}

}

extern "C" {
s32 query_teammate_state__9TObjEneDDFv(void);

s32 play_persistent_sound(int, void *, void *, int, int);



void TBoss6GravBall::update_charge_effects() {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;

    TBoss6GravBall__sub_803233AC(this);
    play_persistent_sound(0x4003C418, this, &ball_position, 0, 0);
    temp_r0 = charge_age;
    if (temp_r0 >= 0x96) {
        if (temp_r0 == 0x96) {
            create_emitter(3);
        }
    } else if (temp_r0 > 0x4B) {
        temp_r0_2 = temp_r0 & 0xF;
        if (temp_r0_2 == 0) {
            create_emitter(3);
        } else if (temp_r0_2 == 0xE) {
            destroy_part(3);
        }
    } else {
        temp_r0_3 = temp_r0 & 0xF;
        if (temp_r0_3 == 0) {
            create_emitter(3);
        } else if (temp_r0_3 == 0xA) {
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
    s32 temp_r3;
    s32 temp_r3_2;
    temp_r3 = clamp_to_ground();
    if (temp_r3 != 0) {
        TBoss6GravBall__sub_803236F8(this);
    }
    fn_80323134(this);
    if (temp_r3 != 0) {
        create_emitter(2);
        if ((pull_strength) < 1.0f) {
            pull_strength += 0.033333335f;
            if (pull_strength > 1.0f) {
                pull_strength = 1.0f;
            }
        }
        TBoss6GravBall__sub_80323544(this);
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
            TBoss6GravBall__sub_80323214(this, 4);
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
    if (query_teammate_state__9TObjEneDDFv() != 0) {
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
    TBoss6GravBall__sub_80323320(this);
    for (i = 0; i < 2; i++) {
        create_emitter(lbl_8047667C[i]);
    }
}
