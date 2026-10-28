#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_8012D354.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemProShield.h"

struct RecoveredGlobal_8012D354_lbl_804A5838 {
    s32 value;
    u8 remaining[0xF4];
};

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * __ct__11TItemWeaponFP7TObjectPUc(void *, void *);
}
extern RecoveredGlobal_8012D354_lbl_804A5838 lbl_804A5838;

typedef char RecoveredGlobal_8012D354_lbl_804A5838_size[sizeof(RecoveredGlobal_8012D354_lbl_804A5838) == 0xF8 ? 1 : -1];
u8 *construct_soul_eater_weapon(u8 *arg0, u8 *arg1, s32 _w2) {
    __ct__11TItemWeaponFP7TObjectPUc(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804A5838.value;
    *(s32 *)((s8 *)arg0 + 0x1F8) = 0;
    if (((TItem *)arg0)->get_item_index() == 1) {
        ((TItemWeapon *)arg0)->set_weapon_flags(0x22);
    }
    return arg0;
}

u8 *create_soul_eater_weapon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_soul_eater_weapon((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}
