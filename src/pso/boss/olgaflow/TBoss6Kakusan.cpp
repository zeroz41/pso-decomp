#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/olgaflow/TBoss6Kakusan.h"
#include "pso/system/vector.h"

#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdLdQuestPrtGC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TObject.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/render_util.h"
#include "pso/player/PlayerSlots.h"


#pragma readonly_strings on

extern "C" {
const char *TBoss6Kakusan__name = "TBoss6Kakusan";
s32 TBoss6Kakusan__homing_start_frame;
u8 boss6_kakusan_homing_start_initialized;
s32 boss6_kakusan_homing_end_frame;
u8 TBoss6Kakusan__homing_end_frame_initialized;
}

void TBoss6Kakusan::check_beam_player_hits() {
    s32 count = TLobby::get_game_mode();
    for (s32 i = 0; i < count; i++) {
        TObjPlayer *player = TObjPlayer::get_player_data(i);
        if (player == NULL) {
            continue;
        }
        f32 step = radius;
        s32 found = 0;
        Vec dir;
        Vec p;
        VecCopy(&p, &position);
        VecCopy(&dir, &prev_position);
        subtract_vector(&dir, &p);
        f32 len = vector_length(&dir);
        f32 t = 0.0f;
        if (len > 1e-05f) {
            f32 s = step / len;
            dir.x *= s;
            dir.y *= s;
            dir.z *= s;
        }
        while (t <= len) {
            f32 y = player->position.y;
            f32 hi = radius + (15.0f + y);
            f32 py = p.y;
            if (!(py < y - radius) && !(py > hi)) {
                Vec q;
                VecCopy(&q, &p);
                subtract_vector(&q, &player->position);
                q.y = 0.0f;
                if (vector_length(&q) <= 5.0f) {
                    found = 1;
                    break;
                }
            }
            t += step;
            vec3_add_to(&p, &dir);
        }
        if (found != 0) {
            DirectAttackPayload attack;
            s32 power = TBoss6PlotFalz::rand_vary_count(damage, 0.1f);
            attack.kind = 0;
            attack.power = power;
            player->receive_direct_attack(m_up, attack, NULL, -1, -1);
        }
    }
}

s32 TBoss6Kakusan::sub_8032263C() { return 0; }

s32 TBoss6Kakusan::is_out_of_range() {
    if (position.y < -200.0f || position.y > 200.0f) {
        return 1;
    }
    Vec v = position;
    v.y = 0.0f;
    return vector_length(&v) > 400.0f;
}

void TBoss6Kakusan::render() {  }

void TBoss6Kakusan::run_task() {
    Vec v;
    Vec w;
    s32 rot[3];
    Vec step;
    f32 speed;
    TObjPlayer *player;
    if (TObjPlayer::check_demo_mode() != 0) return;
    if (TObjEneDD::query_teammate_state() != 0) return;
    VecCopy(&prev_position, &position);
    if ((s8)boss6_kakusan_homing_start_initialized == 0) {
        TBoss6Kakusan__homing_start_frame = 7;
        boss6_kakusan_homing_start_initialized = 1;
    }
    if ((s8)TBoss6Kakusan__homing_end_frame_initialized == 0) {
        boss6_kakusan_homing_end_frame = 0x25;
        TBoss6Kakusan__homing_end_frame_initialized = 1;
    }
    if (frame >= TBoss6Kakusan__homing_start_frame && frame <= boss6_kakusan_homing_end_frame) {
        speed = vector_length(&velocity);
        if (!(speed <= 1e-05f)) {
            player = get_player_by_client_id(target_client);
            if (TBoss6PlotFalz::is_active(player) != 0) {
                VecCopy(&v, &player->position);
                v.y += 10.0f;
                subtract_vector(&v, &position);
                if (!(vector_length(&v) <= 1e-05f)) {
                    normalize_vector(&v);
                    v.x *= homing_weight;
                    v.y *= homing_weight;
                    v.z *= homing_weight;
                    VecCopy(&w, &velocity);
                    normalize_vector(&w);
                    vec3_add_to(&v, &w);
                    if (!(vector_length(&v) <= 1e-05f)) {
                        normalize_vector(&v);
                        v.x *= speed;
                        v.y *= speed;
                        v.z *= speed;
                        VecCopy(&velocity, &v);
                    }
                }
            }
        }
    }
    vec3_add_to(&position, &velocity);
    if (particle != NULL) {
        particle->set_position(&position);
        VecCopy(&step, &position);
        subtract_vector(&step, &prev_position);
        direction_to_rotation_xz((u8 *)&step, &rot[0], &rot[2]);
        rot[1] = 0;
        particle->set_direction(rot);
    }
    if (is_out_of_range() != 0 || sub_8032263C() != 0) {
        queue_destruction();
        return;
    }
    check_beam_player_hits();
    frame += 1;
}

TBoss6Kakusan::~TBoss6Kakusan() {
    if (particle != NULL) {
        TParticleCtrl::release(particle);
        particle = NULL;
    }
}

#pragma push
#pragma opt_common_subs off
TBoss6Kakusan::TBoss6Kakusan(TObject *parent, Vec *pos, Vec *dir, u16 target_client, f32 radius) : TObject(parent) {
    m_name = TBoss6Kakusan__name;
    this->target_client = target_client;
    this->radius = radius;
    if (this->radius <= 0.0f) {
        this->radius = 1.0f;
    }
    VecCopy(&velocity, dir);
    if (vector_length(&velocity) <= 1e-05f) {
        velocity.y = 1.0f;
    }
    VecCopy(&position, pos);
    VecCopy(&prev_position, &position);
    f32 param = ((f32 *)TLobby::dispatch_shared_handler_a(0x2B))[1];
    damage = (s32)param;
    if (0.0f == param) {
        damage = 0x14;
    }
    homing_weight = ((f32 *)TLobby::dispatch_shared_handler_a(0x2F))[4];
    if (homing_weight < 0.0f) {
        homing_weight = 0.0f;
    }
    particle = create_particle_emitter(&position, 0x214);
    if (particle != NULL) {
        particle->set_flags(0x40);
    }
    frame = 0;
}
#pragma pop

u8 *TBoss6Type1::create_kakusan(TObject *parent, Vec *pos, Vec *dir, u16 target_client, f32 speed) {
    return (u8 *)new TBoss6Kakusan(parent, pos, dir, target_client, speed);
}
