#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TOKeyMachine01.h"

#include "pso/unk/text_802034B0.h"

// Whether items are active in the current game state.
s32 TObjPlayer::reset_key_machine_state() { return is_item_area_enabled(TOKeyMachine01::get_global_state()); }
