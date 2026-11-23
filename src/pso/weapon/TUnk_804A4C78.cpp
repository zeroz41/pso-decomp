#include "types.h"
#include "pso/weapon/TUnk_804A4C78.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/data/FlagWord.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/unk/text_80120908.h"
#include "pso/system/task/TMainTask.h"
#include <stdlib.h>


s32 TObjPlayer::is_rand_below_threshold() {
    return (u32)__cntlzw(((3.0517578e-05f * (f32) rand()) < 0.3f)) >> 5;
}


void TUnk_804A4C78::reserved_53() {
    s32 saved;
    NJS_OBJECT *saved_model;
    saved = sub_8012B1F8();
    saved_model = item_model;
    if (((TObjPlayer *)this)->is_rand_below_threshold() == 0) {
        sub_8012B1F0(8);
        item_render_state.set(4);
    }
    draw_weapon_model();
    if (sub_8012B1F8() != 8) {
        update_trail_slot(0);
    }
    item_model = second_model;
    if (((TObjPlayer *)this)->is_rand_below_threshold() == 0) {
        sub_8012B1F0(8);
        item_render_state.set(4);
    } else {
        sub_8012B1F0(saved);
    }
    draw_weapon_at_joint((saddr)this, 0x23);
    if (sub_8012B1F8() != 8) {
        update_trail_slot(1);
    }
    item_model = saved_model;
    sub_8012B1F0(saved);
}


TUnk_804A4C78::TUnk_804A4C78(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(513);
}

TItem *TObjPlayer::create_obj_8012B140(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A4C78(tl_05, item);
    }
    return NULL;
}

TUnk_804A4C78::~TUnk_804A4C78() {}

void TUnk_804A4C78::sub_8012B1F0(s16 v) { this->photon_color_id = v; }
s16 TUnk_804A4C78::sub_8012B1F8() { return this->photon_color_id; }
