#include "types.h"
#include "pso/weapon/TUnk_804A62F8.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A62F8::vfunc_60() {
    if (glows != 0 && TObjPlayer::get_player_list() == 1) {
        begin_particle_tev();
        load_projection_tex(0);
    }
}

void TUnk_804A62F8::update_weapon() {
    if (get_item_index() == 5) {
        refresh_owner_stats();
    }
}

TUnk_804A62F8::~TUnk_804A62F8() {}

TUnk_804A62F8::TUnk_804A62F8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    if (item[2] == 5 || item[1] == 0x8F) {
        glows = 1;
    } else {
        glows = 0;
    }
    if (glows != 0) {
        set_weapon_flags(0x800);
    }
    if (item[2] > 5U) {
        ((TObjPlayer *)this)->set_atp(-1);
    }
}

u8 *create_sword_weapon(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A62F8(tl_05, item);
    }
    return NULL;
}
