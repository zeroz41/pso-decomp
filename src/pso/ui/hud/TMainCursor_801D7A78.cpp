#include "types.h"
#include "pso/ui/hud/TMainCursor.h"

extern "C" {

s32 TObjPlayer__sub_801D84A8();
s32 find_action_slot__11TMainCursorFlPvsll(s32, s32, s32, s32, s32);

void TMainCursor::find_action_slot_for_target(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    find_action_slot__11TMainCursorFlPvsll(arg0, arg1, arg2, arg3, TObjPlayer__sub_801D84A8());
}

}
