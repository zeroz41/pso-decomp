#include "types.h"
#include "pso/player/TUnk_804A63F0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecBarta.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012F5F8.h"
#include "pso/item/TItem.h"
#include "pso/TMainTask.h"

extern "C" {

void TUnk_804A63F0::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    u8 *temp_r3;

    if (get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effects((TItem*)arg0, 3, 2);
    }
    ((TItemWeapon *)arg0)->get_joint_position(0, &sp8);
    if (((TItemWeapon *)arg0)->is_mode_two_and_ready() != 0) {
        temp_r3 = (unsigned char *) (this->owner);
        ((TTecBarta *)temp_r3)->create_ex(temp_r3 + 0x38, (void *)(*(s32 *)((s8 *)temp_r3 + 0x60)), (void *)3);
        return;
    }
    ((TObjPlayer *)arg0)->update_active_game_effect();
}

}

TUnk_804A63F0::TUnk_804A63F0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
}

extern "C" {
u8 *TObjPlayer::create_vtable_804A63F0(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A63F0(tl_05, arg0);
    }
    return NULL;
}

}


TUnk_804A63F0::~TUnk_804A63F0() {}
