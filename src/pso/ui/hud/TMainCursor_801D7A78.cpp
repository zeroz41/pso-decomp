#include "types.h"
#include "pso/ui/hud/TMainCursor.h"

extern "C" {

s32 TObjPlayer__sub_801D84A8();

}

s32 TMainCursor::find_action_slot_for_target(void *slots, void *player, s16 type, s32 enabled) {
    return find_action_slot((saddr)slots, player, type, enabled, TObjPlayer__sub_801D84A8());
}
