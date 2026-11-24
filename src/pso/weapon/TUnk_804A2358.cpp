#include "types.h"
#include "pso/weapon/TUnk_804A2358.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecFoie.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_80120908.h"

extern "C" {

void TUnk_804A2358::emit_marker_effects() {
    s32 origin;
    void *owner;

    if (is_mode_two_and_ready() != 0) {
        if (get_joint_position(0, &origin) != 0) {
            owner = this->owner;
            TTecFoie::create(owner, &origin, *(saddr *)((s8 *)owner + 0x60), ((TItemWeapon *)this)->get_tp() + 2);
            roll_technique();
        }
    } else {
        ((TItemWeapon *)this)->update_active_game_effect();
    }
}
void TUnk_804A2358::reserved_53() { draw_weapon_at_joint((saddr)this, 49); update_trail_slot(0); update_trail_slot(1); update_trail_slot(2); }
void TUnk_804A2358::on_equipped() { this->roll_technique(); this->roll_technique(); }

}

TUnk_804A2358::~TUnk_804A2358() {}

TUnk_804A2358::TUnk_804A2358(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_trail_joints(this, 2, 6, 5);
    set_weapon_flags(35);
    set_technique_roll_range(13);
}

TItem *TObjPlayer::create_configured_state(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A2358(tl_05, item);
    }
    return NULL;
}
