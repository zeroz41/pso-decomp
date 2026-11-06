#include "types.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
#include "pso/unk/text_80278E48.h"

extern "C" {
u8 *__nw__7TObjectFUl(s32);
s32 TShopJudgmentItemWindow__sub_80267F9C(void *, int);
u8 *create_equip_kind_window(s32 arg0, s32 arg1, s16 arg2) {
    u8 *window_sub_equip_kind;
    u8 *var_r0;
    TShopJudgmentItemWindow__sub_80267F9C((void *)arg1, 0x1F);
    window_sub_equip_kind = (u8 *)(__nw__7TObjectFUl(0x8C));
    var_r0 = window_sub_equip_kind;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TWindowSubEquipKind__ct(window_sub_equip_kind, arg0, arg2));
    }
    return var_r0;
}

}
