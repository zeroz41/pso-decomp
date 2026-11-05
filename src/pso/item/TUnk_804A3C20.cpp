#include "types.h"
#include "pso/player/TObjPlayer_801284F0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804A3C20.h"
#include "pso/item/TItemEquipVariant_801285D8.h"
#include "pso/item/TItemEquipVariant_8012A82C.h"
#include "pso/item/TItem.h"

extern "C" {

void draw_weapon_at_joint(s32 arg0, s8 arg1);
void construct_srank_weapon(void *);

void TUnk_804A3C20::reserved_53() { draw_weapon_at_joint((s32)this, (s8)((void*)49)); ((TItemWeapon *)this)->update_trail_slot(0); ((TItemWeapon *)this)->update_trail_slot(1); }

extern s32 lbl_804A3C20[];

void *TObjPlayer__sub_80128538(void *player, s32 parent, void *item) {
    construct_srank_weapon(player);
    *(s32 **)((s8 *)player + 0x18) = lbl_804A3C20;
    ((TItemWeapon *)player)->set_weapon_flags(1);
    return player;
}

}

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_obj_80128580(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TObjPlayer__sub_80128538(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

extern s32 lbl_804A3C20[];

void *__dt__13TUnk_804A3C20Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A3C20;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
