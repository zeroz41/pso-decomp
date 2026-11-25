#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/TObjEnemy.h"
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/flower/TObjEneRe2Flower.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/MatrixOps.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/object/TDeadSpot.h"
#include "pso/enemy/flower/TObjEneRe2Flower_EffCurse3.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjBase.h"

extern const f32 lbl_805D9FAC;
extern const f32 lbl_805D9FC4;

void TObjEneRe2Flower::state_destroy(s32 reason) {
    switch (reason) {
    case 0:
        return;
    case 3:
        queue_destruction();
        return;
    }
}

void TObjEneRe2Flower::state_die(s32 reason) {
    Vec effect_pos;
    f32 x;
    switch (reason) {
    case 4:
        requested_action = 5;
        clear_intangible();
        clear_child_flags();
        flags &= ~8;
        refresh_and_send_entity_flags();
        TBoss8Dragon__sub_800BB7D4(this, 0xF2);
        state_step = 0;
        sink_depth = lbl_805D9FAC;
        play_sound_effect(remap_sound_for_variant(0x4003A812), &position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x200);
        return;
    case 3:
        if (state_step == 2) {
            transition_enemy_state(0xB);
        }
    case 5:
        return;
    case 0:
        switch (state_step) {
        case 0:
            advance_animation();
            if (get_flag_b4() != 0) {
                state_step = 1;
                x = lbl_805D9FC4 * sin_table_lookup(rotation_y);
                effect_pos.y = lbl_805D9FAC;
                effect_pos.x = x;
                effect_pos.z = lbl_805D9FC4 * cos_table_lookup(rotation_y);
                vec3_add_to(&effect_pos, &position);
                if (is_tower_variant() != 0) {
                    TDeadSpot::spawn_kind0_scale7_5(&effect_pos, 0x32);
                    fn_800D911C(&effect_pos);
                    appear_fade.init_death_params();
                } else {
                    TDeadSpot::spawn_kind1_scale2_5(&effect_pos, 0x32);
                    spawn_ground_effect(&effect_pos, 0x46);
                }
            }
            update_ground_contact();
            return;
        case 1:
            if (is_tower_variant() != 0) {
                if (appear_fade.decay_value_toward_floor() != 0) {
                    state_step = 2;
                    return;
                }
            } else {
                position.y -= 0.1f;
                sink_depth += 0.1f;
                if (sink_depth > 20.0f) {
                    state_step = 2;
                }
            }
            break;
        }
        break;
    }
}

// The client id is passed unextended, as a u16; TObjPlayer_801AF2F0.h declares it s32.
extern "C" void send_6x2F_change_player_hp(s32 sender, u16 client, s32 hp);

// The curse's hit on a target that is not a player.
const DirectAttackPayload lbl_8043BA60[1] = {{16, 0}};

void TObjEneRe2Flower::state_damaged(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 4;
        clear_intangible();
        clear_child_flags();
        flags &= ~8;
        TBoss8Dragon__sub_800BB7D4(this, 0xF2);
        play_sound_effect(remap_sound_for_variant(0x4003AB13), &position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x200);
        break;
    case 3:
        if (get_flag_b4() != 0) {
            if (next_mode == 8) {
                transition_enemy_state(next_mode);
            } else if (hp < hpmax / 4) {
                transition_enemy_state(8);
            } else if (random_ratio() < 0.3f) {
                transition_enemy_state(6);
            } else {
                transition_enemy_state(next_mode);
            }
        }
        break;
    case 0:
        advance_animation();
        update_ground_contact();
        update_body_colliders();
        noop();
        break;
    case 5:
        actorFlags &= ~0x200;
        flags &= ~2;
        clear_attack_receipts();
        break;
    }
}

void TObjEneRe2Flower::state_curse(s32 reason) {
    TObjPlayer *t;
    switch (reason) {
    case 4:
        requested_action = 1;
        clear_intangible();
        set_invulnerable();
        clear_child_flags();
        flags &= ~8;
        state_step = 0;
        state_timer = 0;
        break;
    case 3:
        if (state_step >= 0x1E) {
            transition_enemy_state(3);
        }
        break;
    case 0:
        advance_animation();
        if (state_step == 6) {
            t = find_target_in_range();
            if (t != NULL) {
                new TObjEneRe2Flower_EffCurse3(this, (TObjBase *)t);
                current_target = (TObjChara *)t;
                state_timer = 1;
                play_sound_effect(remap_sound_for_variant(0x4003A50F), &position, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x200);
            }
        } else if (state_step == 0x19 && state_timer != 0 && current_target->is_alive() != 0) {
            if (is_tower_variant() != 0) {
                if (is_player_entity_id(current_target->get_entity_id()) != 0) {
                    send_6x2F_change_player_hp(entity_id, current_target->get_entity_id(), 1);
                }
            } else {
                DirectAttackPayload p = lbl_8043BA60[0];
                current_target->receive_direct_attack(this, p, current_target->bodies, -1, -1);
            }
        }
        state_step++;
        update_ground_contact();
        update_body_colliders();
        noop();
        break;
    case 5:
        actorFlags &= ~0x04000000;
        flags &= ~2;
        break;
    }
}

__declspec(section ".sdata2") extern const f32 lbl_805D9FD4 = 3.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9FD8 = 15.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9FDC = 12.0f;
__declspec(section ".sdata2") extern const f32 re2_flower_lose_target_distance = 300.0f;
__declspec(section ".sdata2") extern const f32 re2_flower_attack_distance = 50.0f;
__declspec(section ".sdata2") extern const f32 re2_flower_track_timeout = 100.0f;
__declspec(section ".sdata2") extern const f32 re2_flower_retarget_margin = 30.0f;
__declspec(section ".sdata2") extern const f32 re2_flower_acquire_range = 250.0f;
__declspec(section ".sdata2") extern const f32 re2_flower_player_range_sq = 10000.0f;
__declspec(section ".sdata2") extern const f32 re2_flower_body_center_height = 8.0f;
__declspec(section ".sdata2") extern const f32 re2_flower_rare_chance = 0.002f;
