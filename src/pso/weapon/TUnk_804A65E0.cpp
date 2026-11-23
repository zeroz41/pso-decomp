#include "types.h"
#include "pso/weapon/TUnk_804A65E0.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/technique/TTecGiZonde.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/data/FlagWord.h"
#include "pso/weapon/SpecialProjectileWeapons.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/unk/text_8011B328.h"
#include "pso/unk/text_8011B620.h"
#include "pso/weapon/TUnk_804A66D8.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/CapturedTargetList.h"

extern "C" {


void TUnk_804A65E0::emit_marker_effects() {
    CapturedTargetList *state;
    TargetCursorRecord *record;
    s32 i;
    CapturedTarget *entry;

    if (is_mode_two_and_ready() != 0) {
        get_joint_position(0, &cast_point);
        state = ((TObjPlayer *)owner)->get_extended_state();
        if (state != 0) {
            targets.count = state->get_captured_target_count();
            record = targets.records;
            i = 0;
            do {
                entry = state->get_captured_target_entry(i);
                if (entry != NULL) {
                    record->id = entry->uid;
                    record->flag = entry->collider_index;
                    record++;
                }
                i += 1;
            } while (i != 0xA);
            if (targets.count != 0) {
                TTecGiZonde::create(owner, (Vec *)&cast_point, &targets, ((TItemWeapon *)this)->get_tp());
            }
            roll_technique();
        }
    } else {
        ((TItemWeapon *)this)->update_active_game_effect();
    }
}

}

void TUnk_804A65E0::on_equipped() {
    roll_technique();
    roll_technique();
}

TUnk_804A65E0::~TUnk_804A65E0() {}

TUnk_804A65E0::TUnk_804A65E0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    effect_flags.set(32);
    set_weapon_flags(34);
    set_technique_roll_range(5);
}

TItem *TObjPlayer::create_effect_object(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A65E0(tl_05, item);
    }
    return NULL;
}
