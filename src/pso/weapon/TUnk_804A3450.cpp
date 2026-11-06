#include "types.h"
#include "pso/weapon/TUnk_804A3450.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecJelin.h"
#include "pso/technique/TTecZarua.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A3450::vfunc_57() {
    roll_technique();
    roll_technique();
}

void TUnk_804A3450::emit_marker_effects() {
    s32 owner;
    s32 temp_r3_2;
    s32 temp_r4;
    s32 temp_r4_2;

    if (get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effects((TItem *)this, 2, 1);
    }
    if (is_mode_two_and_ready() != 0) {
        if (((TObjPlayer *)this)->get_tp() == 0) {
            owner = (s32)this->owner;
            temp_r4 = owner + 0x38;
            TTecJelin::create(owner, temp_r4, temp_r4, 4);
        } else {
            temp_r3_2 = (s32)this->owner;
            temp_r4_2 = temp_r3_2 + 0x38;
            TTecZarua::create_instance(temp_r3_2, temp_r4_2, temp_r4_2, 4);
        }
        roll_technique();
        return;
    }
    ((TObjPlayer *)this)->update_active_game_effect();
}

TUnk_804A3450::~TUnk_804A3450() {}

TUnk_804A3450::TUnk_804A3450(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    ((TObjPlayer *)this)->set_effect_state(2);
}

u8 *TObjPlayer::create_substate_b(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A3450(tl_05, arg0);
    }
    return NULL;
}
