#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TUnk_804A62F8.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

u8 get_item_index__5TItemFv();

void TObjPlayer::update_boss2tunnel() {
    if (((s32) *(s32 *)&this->unk_1F8 != 0) && (TObjPlayer::get_player_list() == 1)) {
        ((TItem *)this)->begin_particle_tev();
        ((TItem *)this)->load_projection_tex(0);
    }
}

void TUnk_804A62F8::update_weapon() {
    s32 arg0 = (s32)this;
    if (get_item_index__5TItemFv() == 5) {
        ((TItemEquipBase *)arg0)->refresh_owner_stats();
    }
}

}
