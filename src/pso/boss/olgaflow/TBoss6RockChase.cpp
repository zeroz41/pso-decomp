#include "pso/enemy/BattleParameters.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/boss/olgaflow/TBoss6RockChase.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/boss/olgaflow/TBoss6Rock.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"

#include <stddef.h>

#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"

extern "C" {
__declspec(section ".rodata") char TBoss6RockChase__class_name_string[] = "TBoss6RockChase";
}
extern const TBoss6RockChaseKind boss6_rock_chase_model_radius_table[2];
const TBoss6RockChaseKind boss6_rock_chase_model_radius_table[2] = {
    {4, 20.0f},
    {0, 30.0f},
};
const char *TBoss6RockChase__name = TBoss6RockChase__class_name_string;

void TBoss6RockChase::damage_players_in_range() {
    Vec d;
    s32 count;
    s32 damage;
    s32 i;
    TObjPlayer *player;
    f32 range;
    count = TLobby::get_game_mode();
    range = boss6_rock_chase_model_radius_table[size_kind].radius;
    damage = TLobby::dispatch_shared_handler_a(0x2C)->values.floats[3];
    if (damage < 1) {
        damage = 20;
    }
    for (i = 0; i < count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active(player) != 0) {
            VecCopy(&d, &player->position);
            subtract_vector(&d, &position);
            d.y = 0.0f;
            if (!(vector_length(&d) > range)) {
                DirectAttackPayload h;
                s32 power = TBoss6PlotFalz::rand_vary_count(damage, 0.1f);
                h.kind = 0;
                h.power = power;
                player->receive_direct_attack(owner, h, 0, -1, -1);
            }
        }
    }
}

void TBoss6RockChase::render() {
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, rotation_y);
    rotate_matrix_x(NULL, rotation_x);
    rotate_matrix_z(NULL, rotation_z);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(textures));
    draw_ginja_object(model);
    pop_matrix();
}

#pragma push
#pragma opt_common_subs off
void TBoss6RockChase::run_task() {
    s32 delay;
    if (TObjEneDD::query_teammate_state() == 0) {
        delay = this->delay;
        if (delay > 0) {
            this->delay = delay - 1;
            return;
        }
        rotation_y = rotation_y + spin_speed;
        fall_speed += -0.9375f;
        if (fall_speed < -11.25f) {
            fall_speed = -11.25f;
        }
        position.y = position.y + fall_speed;
        if (position.y <= 0.0f) {
            position.y = 0.0f;
            fall_speed = 0.0f;
            damage_players_in_range();
            play_sound_effect(0x4006B51E, &position, 0, 0);
            spawn_particle_effect(&position, 0x220);
            spawn_particle_effect(&position, 0x222);
            TBoss6PlotFalz::apply_radial_effect_to_players((u8 *)&position, 0xC0, 0xF, 100.0f);
            TBoss6Rock::spawn_crush_rocks(&position, size_kind);
            play_sound_effect(0x4006AB1F, &position, 0, 0);
            queue_destruction();
        }
    }
}
#pragma pop

TBoss6RockChase::~TBoss6RockChase() {

}


#pragma push
#pragma fp_contract on
TBoss6RockChase::TBoss6RockChase(TObject *parent, const Vec *position, s32 size_kind) : TObjCollidable(parent) {
    m_name = TBoss6RockChase__name;
    owner = parent;
    this->size_kind = size_kind;
    delay = (s32)(15.0f * (3.0517578e-05f * (f32)rand()));
    rotation_x = (s32)(2048.0f * ((3.0517578e-05f * (f32)rand()) - 0.5f));
    rotation_y = (s32)(65535.0f * (3.0517578e-05f * (f32)rand()));
    rotation_z = (s32)(2048.0f * ((3.0517578e-05f * (f32)rand()) - 0.5f));
    spin_speed = (s32)(8192.0f * ((3.0517578e-05f * (f32)rand()) - 0.5f));
    fall_speed = 0.0f;
    VecCopy(&this->position, position);
    model = get_bml_model(TBoss6Rock::get_resource(), boss6_rock_chase_model_radius_table[size_kind].model);
    textures = TBoss6Rock::get_texture_list();
}
#pragma pop

TBoss6RockChase *TBoss6RockChase::spawn(TObject *parent, const Vec *position) {
    Vec point;
    s32 var_r31;
    VecCopy(&point, position);
    var_r31 = 0;
    point.y = 450.0f;
    if ((3.0517578e-05f * (f32) rand()) < 0.5f) {
        var_r31 = 1;
    }
    return new TBoss6RockChase(parent, &point, var_r31);
}

