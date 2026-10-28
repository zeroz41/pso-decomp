#include "types.h"
#include "pso/unk/text_80120D50.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/unk/text_80126B6C.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * init_with_update_handler__13TUnk_804A2D88Fv(void *, s32, void *);
}
extern s32 lbl_804A2C90[];

u8 *create_suppressed_gun_weapon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_with_update_handler__13TUnk_804A2D88Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

u8 *construct_handgun_weapon(u8 *player, s32 parent, u8 *item) {
    TItemWeapon__ct((TItemWeapon *)player, (void *)parent, item);
    *(s32 **)((s8 *)player + 0x18) = lbl_804A2C90;
    ((TObjPlayer *)player)->m_1ec = (s32*)&spawn_weapon_impact_effect;
    if ((u8) *(u8 *)((s8 *)item + 2) >= 5U) {
        ((TObjPlayer *)player)->set_atp(-1);
    }
    return player;
}

u8 *create_handgun_weapon(u8 *item) {
    u8 *temp_r3;
    u8 *var_r0;
    if (item != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_handgun_weapon(temp_r3, tl_05, item));
        }
        return var_r0;
    }
    return NULL;
}
