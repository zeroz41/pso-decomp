#include "types.h"
#include "pso/weapon/TItemWeaponTheSighOfAGod.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/technique/TTecGiZonde.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/data/FlagWord.h"
#include "pso/weapon/SpecialProjectileWeapons.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/unk/text_8011B328.h"
#include "pso/unk/text_8011B620.h"
#include "pso/weapon/TItemWeaponTwinPsychogun.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/CapturedTargetList.h"

extern "C" {


void TItemWeaponTheSighOfAGod::emit_marker_effects() {
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

void TItemWeaponTheSighOfAGod::on_equipped() {
    roll_technique();
    roll_technique();
}

TItemWeaponTheSighOfAGod::~TItemWeaponTheSighOfAGod() {}

TItemWeaponTheSighOfAGod::TItemWeaponTheSighOfAGod(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    effect_flags.set(32);
    set_weapon_flags(34);
    set_technique_roll_range(5);
}

TItem *TItemWeaponTheSighOfAGod::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponTheSighOfAGod(tl_05, item);
    }
    return NULL;
}
