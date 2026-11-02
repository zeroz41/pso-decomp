#include "types.h"
#include "pso/item/TUnk_804A5058.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_803D853C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012BE68.h"

void TUnk_804A5058::vfunc_60() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    get_current_matrix((void *)(*(s32 *)((s8 *)(*(void * *)&(*(NJS_MOTION_LINK *)((u8 *)this + 0xE4)).frame[1]) + 0xDB4) + (player_list * 0x30)));
    if (player_list == 9) {
        TItem::begin_effect_render();
    }
}

extern s32 __vt__13TUnk_804A5058[];

TUnk_804A5058::~TUnk_804A5058() {}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 __vt__13TUnk_804A5058[];

void *TUnk_804A5058::ct_variant() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A5058;
    return this;
}

}

extern "C" {
u8 * ct_variant__13TUnk_804A5058Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_variant_ct(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(ct_variant__13TUnk_804A5058Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
