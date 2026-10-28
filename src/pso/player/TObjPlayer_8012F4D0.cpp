#include "types.h"
#include "pso/player/TUnk_804A63F0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecBarta.h"

extern "C" {


extern s32 tl_05;

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
