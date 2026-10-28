#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_801258A0.h"
#include "pso/player/TUnk_804A2564.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemProShield.h"

struct RecoveredGlobal_801258A0_lbl_804A2564 {
    s32 value;
    u8 remaining[0xF8];
};

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * TItemWeapon__ct(void *, void *);
}
extern RecoveredGlobal_801258A0_lbl_804A2564 lbl_804A2564;
extern const f32 lbl_805DAD50;
extern const f32 lbl_805DAD58;
extern const f32 lbl_805DAD60;

typedef char RecoveredGlobal_801258A0_lbl_804A2564_size[sizeof(RecoveredGlobal_801258A0_lbl_804A2564) == 0xFC ? 1 : -1];
u8 *construct_panzer_faust(u8 *arg0, u8 *arg1, s32 _w2) {
    TItemWeapon__ct(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804A2564.value;
    *(f32 *)((s8 *)arg0 + 0x200) = (f32) lbl_805DAD58;
    ((TUnk_804A2564 *)arg0)->m_1fc = (f32) lbl_805DAD58;
    *(f32 *)((s8 *)arg0 + 0x1F8) = (f32) lbl_805DAD58;
    ((TUnk_804A2564 *)arg0)->m_234 = 0;
    *(f32 *)((s8 *)arg0 + 0x1E4) = (f32) lbl_805DAD50;
    ((TObjPlayer *)arg0)->set_status_flags(0x8000);
    if (((TItem *)arg0)->get_item_index() == 1) {
        *(f32 *)((s8 *)arg0 + 0x238) = (f32) lbl_805DAD50;
        ((TUnk_804A2564 *)arg0)->m_23c = 0x80;
    } else {
        *(f32 *)((s8 *)arg0 + 0x238) = (f32) lbl_805DAD60;
        ((TUnk_804A2564 *)arg0)->m_23c = 0;
    }
    return arg0;
}

u8 *create_panzer_faust(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x240));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_panzer_faust((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}
