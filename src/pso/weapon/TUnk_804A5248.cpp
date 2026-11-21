#include "types.h"
#include "pso/weapon/TUnk_804A5248.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemEffOrgaFlowShot.h"
#include "pso/unk/text_80120D50.h"
#include "pso/unk/text_8012C268.h"
#include "pso/weapon/TItemWeaponRifle.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012C32C.h"
#include "pso/item/TItem.h"


extern "C" {

s32 scale_matrix(s32, f32, f32, f32);


void TUnk_804A5248::vfunc_60() {
    if ((get_item_index() == 5) && (TObjPlayer::get_player_list() == 3)) {
        scale_matrix(0, 1.0f, barrel_scale, 1.0f);
    }
}


void TUnk_804A5248::update_idle() {
    if (get_item_index() == 5) {
        TItemEffOrgaFlowShot::approach_value(&barrel_scale, 0.1f, 0.6f);
    }
}


void TUnk_804A5248::update_attack() {
    if (get_item_index() == 5) {
        TItemEffOrgaFlowShot::approach_value(&barrel_scale, 0.2f, 1.0f);
    }
}

void spawn_weapon_impact_effect();
extern u32 __vt__13TUnk_804A5248[];

}

TItemWeaponRifle* TItemWeaponRifle::initialize(saddr parent,u8* item) {
    TItemWeaponRifle* self=this;
    __ct__11TItemWeaponFP7TObjectPUc((TItemWeapon *)((u8 *)self), (void *)parent, item);
    self->dispatch=__vt__13TUnk_804A5248;
    self->impactFactory=spawn_weapon_impact_effect;
    self->phase=1.0f;
    if(item[2]>=5U)((TObjPlayer *)self)->set_atp(-1);
    return self;
}

extern s32 tl_05;
TItem *create_rifle_weapon(u8 *item) {
    u8 *item_weapon_rifle;
    u8 *var_r0;
    if (item != NULL) {
        item_weapon_rifle = (u8 *)((u8 *)TItem::operator new(0x1FC));
        var_r0 = item_weapon_rifle;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((TItemWeaponRifle*)item_weapon_rifle)->initialize(tl_05, item));
        }
        return reinterpret_cast<TItem *>(var_r0);
    }
    return NULL;
}


TUnk_804A5248::~TUnk_804A5248() {}
