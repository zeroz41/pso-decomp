// ---- pso/player/TObjPlayer_8012C180
#include "types.h"
#include "pso/unk/TUnk_804A5248.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEffOrgaFlowShot.h"

extern "C" {

u8 get_item_index__5TItemFv();
s32 scale_matrix(s32, f32, f32, f32);



void TObjPlayer::check_shield_combo() {
    if ((get_item_index__5TItemFv() == 5) && (TObjPlayer::get_player_list() == 3)) {
        scale_matrix(0, 1.0f, *(f32 *)((s8 *)this + 0x1F8), 1.0f);
    }
}




void TUnk_804A5248::update_idle() {
    s32 arg0 = (s32)this;
    if (get_item_index__5TItemFv() == 5) {
        TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)0.1f, (f32)0.6f);
    }
}



void TUnk_804A5248::update_attack() {
    s32 arg0 = (s32)this;
    if (get_item_index__5TItemFv() == 5) {
        TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)0.2f, (f32)1.0f);
    }
}

}

// ---- pso/unk/text_8012C268
#include "types.h"
#include "pso/unk/text_80120D50.h"
#include "pso/unk/text_8012C268.h"
#include "pso/items/TItemWeaponRifle.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
void spawn_weapon_impact_effect();
extern u32 lbl_804A5248[];

}

TItemWeaponRifle* TItemWeaponRifle::initialize(s32 parent,u8* item) {
    TItemWeaponRifle* self=this;
    __ct__11TItemWeaponFP7TObjectPUc((TItemWeapon *)((u8 *)self), (void *)parent, item);
    self->dispatch=lbl_804A5248;
    self->impactFactory=spawn_weapon_impact_effect;
    self->phase=1.0f;
    if(item[2]>=5U)((TObjPlayer *)self)->set_atp(-1);
    return self;
}

extern "C" {

u8 *__nw__5TItemFUl(s32);
}
extern s32 tl_05;
u8 *create_rifle_weapon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((TItemWeaponRifle*)temp_r3)->initialize(tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}
