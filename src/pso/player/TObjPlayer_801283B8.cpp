#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer_801283B8.h"
#include "pso/player/TUnk_804A3B20.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void construct_srank_weapon(void *);

void srank_marker_noop(void) {  }

extern s32 tl_05;

void TObjPlayer::spawn_cane_effects_if_ready(s32 arg0) {
    if (((TItemWeapon *)arg0)->get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effects((TItem*)arg0, 1, 2);
    }
}

extern s32 lbl_804A3B20[];

void *TUnk_804A3B20::init_state_vtable() {
    construct_srank_weapon(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A3B20;
    return this;
}

}
