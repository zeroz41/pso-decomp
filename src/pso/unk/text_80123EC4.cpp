#include "types.h"
#include "pso/unk/text_80123EC4.h"
#include "pso/item/TUnk_804A1E28.h"

struct RecoveredGlobal_80123EC4_lbl_804A1E28 {
    s32 value;
    u8 remaining[0xF4];
};

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * __ct__11TItemWeaponFP7TObjectPUc(void *, void *);
}
extern RecoveredGlobal_80123EC4_lbl_804A1E28 lbl_804A1E28;

typedef char RecoveredGlobal_80123EC4_lbl_804A1E28_size[sizeof(RecoveredGlobal_80123EC4_lbl_804A1E28) == 0xF8 ? 1 : -1];
u8 *sorcerers_cane_ct(u8 *arg0, u8 *arg1, s32 _w2) {
    __ct__11TItemWeaponFP7TObjectPUc(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804A1E28.value;
    *(s16 *)((s8 *)arg0 + 0x1FE) = 3;
    *(s32 *)((s8 *)arg0 + 0x1F8) = 0;
    ((TUnk_804A1E28 *)arg0)->m_1fc = -1;
    return arg0;
}

u8 *create_sorcerers_cane(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x200));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(sorcerers_cane_ct((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}
