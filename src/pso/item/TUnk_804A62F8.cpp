#include "types.h"
#include "pso/item/TUnk_804A62F8.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012F384.h"
#include "pso/items/TItemWeapon.h"
#include "pso/unk/text_8012F478.h"

extern "C" {

u8 get_item_index__5TItemFv();

void TUnk_804A62F8::vfunc_60() {
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

extern s32 __vt__13TUnk_804A62F8[];

TUnk_804A62F8::~TUnk_804A62F8() {}

extern "C" {

s32 __ct__11TItemWeaponFP7TObjectPUc();

extern s32 __vt__13TUnk_804A62F8[];

void *TObjPlayer::init_from_item(void *arg1, void *arg2) {
    __ct__11TItemWeaponFP7TObjectPUc();
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A62F8;
    if (((u8) *(u8 *)((s8 *)arg2 + 2) == 5) || ((u8) *(u8 *)((s8 *)arg2 + 1) == 0x8F)) {
        *(s32 *)&this->unk_1F8 = 1;
    } else {
        *(s32 *)&this->unk_1F8 = 0;
    }
    if ((s32) *(s32 *)&this->unk_1F8 != 0) {
        ((TItemWeapon *)this)->set_weapon_flags(0x800);
    }
    if ((u8) *(u8 *)((s8 *)arg2 + 2) > 5U) {
        set_atp(-1);
    }
    return this;
}

}

extern "C" {
u8 *__nw__5TItemFUl(s32);
}
extern s32 tl_05;
u8 *create_sword_weapon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((TObjPlayer *)temp_r3)->init_from_item((void *)tl_05, (void *)arg0));
        }
        return var_r0;
    }
    return NULL;
}
