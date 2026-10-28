#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80126334.h"
#include "pso/item/TUnk_804A2960.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemProShield.h"

struct RecoveredGlobal_80126334_lbl_804A2960 {
    s32 value;
    u8 remaining[0xF4];
};

struct RecoveredGlobal_80126414_lbl_804A05E8 {
    s32 value;
    u8 remaining[0x1C];
};

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * TItemWeapon__ct(void *, void *);
extern RecoveredGlobal_80126334_lbl_804A2960 lbl_804A2960;
u8 * TItemTimerEvent__ct(void *, s16, s32);
}
extern RecoveredGlobal_80126414_lbl_804A05E8 lbl_804A05E8;

typedef char RecoveredGlobal_80126334_lbl_804A2960_size[sizeof(RecoveredGlobal_80126334_lbl_804A2960) == 0xF8 ? 1 : -1];
u8 *frozen_shooter_ct(u8 *arg0, u8 *arg1, s32 _w2) {
    TItemWeapon__ct(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804A2960.value;
    ((TObjPlayer *)arg0)->set_status_flags(0x22);
    if (((TItem *)arg0)->get_item_index() == 1) {
        *(s32 *)((s8 *)arg0 + 0x1F8) = 0xA;
        *(s32 *)((s8 *)arg0 + 0x200) = 0x1F5;
    } else {
        *(s32 *)((s8 *)arg0 + 0x1F8) = 1;
        *(s32 *)((s8 *)arg0 + 0x200) = 0x95;
    }
    ((TUnk_804A2960 *)arg0)->m_1fc = 0;
    return arg0;
}

u8 *frozen_shooter_create(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x204));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(frozen_shooter_ct((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}
typedef char RecoveredGlobal_80126414_lbl_804A05E8_size[sizeof(RecoveredGlobal_80126414_lbl_804A05E8) == 0x20 ? 1 : -1];

u8 *freeze_curse_timer_ct(u8 *arg0, s16 arg1, s32 arg2, f32 farg0) {
    TItemTimerEvent__ct(arg0, arg1, arg2);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804A05E8.value;
    *(f32 *)((s8 *)arg0 + 0x2C) = farg0;
    return arg0;
}
