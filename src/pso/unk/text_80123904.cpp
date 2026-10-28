#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/unk/text_80123904.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80123904_lbl_804A1B40 {
    s32 value;
    u8 remaining[0xF4];
};

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * __ct__11TItemWeaponFP7TObjectPUc(void *, void *);
extern RecoveredGlobal_80123904_lbl_804A1B40 lbl_804A1B40;

typedef char RecoveredGlobal_80123904_lbl_804A1B40_size[sizeof(RecoveredGlobal_80123904_lbl_804A1B40) == 0xF8 ? 1 : -1];
u8 *TObjPlayer__sub_80123904(u8 *player, u8 *arg1, s32 _w2) {
    __ct__11TItemWeaponFP7TObjectPUc(player, arg1);
    *(s32 **)((s8 *)player + 0x18) = &lbl_804A1B40.value;
    ((TItemWeapon *)player)->set_weapon_flags(0x800201);
    return player;
}

u8 *TObjPlayer__sub_80123950(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TObjPlayer__sub_80123904((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
