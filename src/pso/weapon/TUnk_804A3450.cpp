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
    saddr owner;
    saddr source;
    saddr temp_r4;
    saddr temp_r4_2;

    if (get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effects((TItem *)this, 2, 1);
    }
    if (is_mode_two_and_ready() != 0) {
        if (((TItemWeapon *)this)->get_tp() == 0) {
            owner = (saddr)this->owner;
            temp_r4 = owner + 0x38;
            TTecJelin::create(owner, temp_r4, temp_r4, 4);
        } else {
            source = (saddr)this->owner;
            temp_r4_2 = source + 0x38;
            TTecZarua::create_instance(source, (Vec *)temp_r4_2, (Vec *)temp_r4_2, 4);
        }
        roll_technique();
        return;
    }
    ((TItemWeapon *)this)->update_active_game_effect();
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
