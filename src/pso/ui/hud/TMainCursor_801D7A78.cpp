#include "types.h"
#include "pso/player/TPlyDispConfig.h"
#include "pso/player/TObjPlayer_801D84A8.h"

s32 TPlyDispConfigSmth::find_action_slot_for_target(TObjPlayer *player, s16 type, s32 enabled) {
    return find_action_slot(player, type, enabled, TObjPlayer__sub_801D84A8(this));
}
