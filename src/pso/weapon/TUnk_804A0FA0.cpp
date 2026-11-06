#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TUnk_804A0FA0.h"
#include "pso/effect/item/TItemEffOrgaFlowShot.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/system/task/TMainTask.h"

extern "C" {
void scale_matrix(s32, f32, f32, f32);
}

void TUnk_804A0FA0::vfunc_60() {
    if (get_item_index() == 5) {
        s32 n = TObjPlayer::get_player_list();
        switch (n) {
        case 3:
        case 4:
            scale_matrix(0, 1.0f, blade_scale, blade_scale);
            break;
        }
    }
}

void TUnk_804A0FA0::update_idle() {
    if (get_item_index() == 5) {
        TItemEffOrgaFlowShot::approach_value(&blade_scale, 0.2f, 0.0f);
    }
}

void TUnk_804A0FA0::update_attack() {
    if (get_item_index() == 5) {
        TItemEffOrgaFlowShot::approach_value(&blade_scale, 0.5f, 1.0f);
    }
}

TUnk_804A0FA0::TUnk_804A0FA0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    u8 kind;
    set_weapon_flags(0x600);
    blade_scale = 1.0f;
    kind = item[2];
    if ((kind >= 5U) && (kind != 7)) {
        ((TObjPlayer *)this)->set_atp(-1);
    }
}

u8 *create_dagger_weapon(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A0FA0(tl_05, arg0);
    }
    return NULL;
}

TUnk_804A0FA0::~TUnk_804A0FA0() {}

void TObjPlayer::set_atp(s16 v) { *(s16 *)&this->unk_1CC = v; }
