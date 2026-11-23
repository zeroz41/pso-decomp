#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804A3450.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecJelin.h"
#include "pso/technique/TTecZarua.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A3450::on_equipped() {
    roll_technique();
    roll_technique();
}

void TUnk_804A3450::emit_marker_effects() {
    if (get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effects(this, 2, 1);
    }
    if (is_mode_two_and_ready() != 0) {
        if (get_tp() == 0) {
            TTecJelin::create((saddr)owner, (saddr)&owner->position, (saddr)&owner->position, 4);
        } else {
            TTecZarua::create_instance((saddr)owner, &owner->position, &owner->position, 4);
        }
        roll_technique();
        return;
    }
    update_active_game_effect();
}

TUnk_804A3450::~TUnk_804A3450() {}

TUnk_804A3450::TUnk_804A3450(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    set_technique_roll_range(2);
}

TItem *TObjPlayer::create_substate_b(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A3450(tl_05, item);
    }
    return NULL;
}
