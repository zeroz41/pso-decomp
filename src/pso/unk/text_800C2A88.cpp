#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
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
                    TObjPlayer::apply_effect_variant_a(&effect_pos, 0x32);
                    fn_800D911C(&effect_pos);
                    appear_fade.init_death_params();
                } else {
                    TObjPlayer__sub_800D9290(&effect_pos, 0x32);
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
