#ifndef PSO_MAP_CURRENTAREA_H
#define PSO_MAP_CURRENTAREA_H

#include "types.h"

// The area id of the current floor (current_floor_area_type; 15 is the lobby).
s32 get_current_area();

// Whether items work in the current area (is_item_area_enabled of the current area).
s32 are_items_enabled_here();

#endif
