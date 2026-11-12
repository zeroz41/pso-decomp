#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TObjResultWin.h"
#include "pso/unk/text_8024450C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowRoom.h"

extern "C" {
s32 __nw__7TObjectFUl(int);
s32 TWindowArea__ct();
u8 *get_title_entry__11TWindowRoomFv(s32);
extern const f32 lbl_805DCABC;
extern const f32 lbl_805DCAC0;
void fn_8024450C(s32 arg0) {
    s32 var_r30;
    s32 var_r31;
    s32 var_r3;
    s32 var_r5;
    var_r30 = arg0;
    var_r31 = TObjNewFloorWin__sub_8007410C();
    var_r3 = var_r30;
    var_r5 = TWindowSubComCard__sub_80244774();
    ((TWindowSubStatusDisp *)var_r3)->set_count_ratio_text(var_r31, var_r5);
}
#pragma push
#pragma fp_contract on
s32 create_area_window(s32 arg0) {
    s32 object;
    u8 *temp_r31;
    object = __nw__7TObjectFUl(0x64);
    if (object != 0) {
        object = TWindowArea__ct();
    }
    ((TWindowSubStatusDisp *)object)->set_entry_display_value(arg0);
    fn_802449E0((u8 *)object);
    temp_r31 = (u8 *)(((TWindowRoom *)object)->get_title_entry());
    *(f32 *)((s8 *)temp_r31 + 8) = (f32) -((lbl_805DCAC0 * (f32) calc_text_width((char *)(arg0))) - lbl_805DCABC);
    return object;
}
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 create_window_area(void) {
    s32 object;
    u8 *temp_r31;
    object = __nw__7TObjectFUl(0x64);
    if (object != 0) {
        object = TWindowArea__ct();
    }
    fn_802449E0((u8 *)object);
    fn_8024450C(object);
    temp_r31 = get_title_entry__11TWindowRoomFv(object);
    *(f32 *)((s8 *)temp_r31 + 8) = (f32) -((lbl_805DCAC0 * (f32) calc_text_width((char *)(((TWindowSubComCard *)temp_r31)->get_field_20()))) - lbl_805DCABC);
    return object;
}
#pragma pop
