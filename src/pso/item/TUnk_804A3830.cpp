#include "types.h"
#include "pso/unk/text_80127EE8.h"
#include "pso/item/TUnk_804A3830.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/item/TUnk_804A3928.h"
#include "pso/player/TObjPlayer_80128158.h"
#include "pso/item/TItemEquipVariant_801281C4.h"

extern "C" {
s32 draw_weapon_at_joint(void *, int);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
}


void TUnk_804A3830::reserved_53() {
    s32 temp_r31;
    draw_weapon_at_joint(this, 0x31);
    update_trail_slot(0);
    update_trail_slot(1);
    temp_r31 = *(s32 *)((s8 *)((u8 *)this) + 0xF4);
    *(s32 *)((s8 *)((u8 *)this) + 0xF4) = (s32) this->second_model;
    draw_weapon_at_joint(this, 0x24);
    *(s32 *)((s8 *)((u8 *)this) + 0xF4) = temp_r31;
    update_trail_slot(2);
    update_trail_slot(3);
}

extern s32 __vt__13TUnk_804A3830[];

TUnk_804A3830::~TUnk_804A3830() {}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);


void *TUnk_804A3830::construct_state_variant() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A3830;
    set_weapon_trail_joints((s32)this, 2, 1, 2);
    set_weapon_trail_joints((s32)this, 3, 3, 4);
    set_weapon_flags(513);
    return this;
}

}


extern "C" {
u8 * construct_state_variant__13TUnk_804A3830Fv(void *, s32, void *);

u8 *TObjPlayer::create_state_variant(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_state_variant__13TUnk_804A3830Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

