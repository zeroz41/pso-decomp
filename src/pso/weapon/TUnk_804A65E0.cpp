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

extern "C" {

u8 *get_captured_target_entry(s32, s32);
s32 get_captured_target_count();
s32 get_extended_state__10TObjPlayerFv(int);

void TUnk_804A65E0::emit_marker_effects() {
    s32 state;
    TargetCursorRecord *record;
    s32 i;
    u8 *entry;

    if (is_mode_two_and_ready() != 0) {
        get_joint_position(0, &cast_point);
        state = get_extended_state__10TObjPlayerFv((int)owner);
        if (state != 0) {
            targets.count = get_captured_target_count();
            record = targets.records;
            i = 0;
            do {
                entry = get_captured_target_entry(state, i);
                if (entry != NULL) {
                    record->id = *(u16 *)(entry + 0);
                    record->flag = *(s16 *)(entry + 2);
                    record++;
                }
                i += 1;
            } while (i != 0xA);
            if (targets.count != 0) {
                ((TTecGiZonde *)owner)->create(&cast_point, &targets, (void *)((TObjPlayer *)this)->get_tp());
            }
            roll_technique();
        }
    } else {
        ((TObjPlayer *)this)->update_active_game_effect();
    }
}

}

void TUnk_804A65E0::vfunc_57() {
    roll_technique();
    roll_technique();
}

TUnk_804A65E0::~TUnk_804A65E0() {}

TUnk_804A65E0::TUnk_804A65E0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    ((TObjPlayer *)&targets)->construct_target_cursor_records();
    effect_flags.set(32);
    set_weapon_flags(34);
    ((TObjPlayer *)this)->set_effect_state(5);
}

u8 *TObjPlayer::create_effect_object(s32 item) {
    if (item != 0) {
        return (u8 *)new TUnk_804A65E0(tl_05, (u8 *)item);
    }
    return NULL;
}
