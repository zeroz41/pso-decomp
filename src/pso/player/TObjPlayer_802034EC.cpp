#include "types.h"
#include "pso/map/CurrentArea.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/unk/text_802034B0.h"

s32 are_items_enabled_here() { return is_item_area_enabled(TOKeyMachine01::get_global_state()); }
