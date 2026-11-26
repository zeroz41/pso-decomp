#ifndef PSO_UNK_TEXT_8020BFE4_H
#define PSO_UNK_TEXT_8020BFE4_H

#include "types.h"

void set_wave_object_flags(s32 pl, s16 b, s16 a, s32 mask, s32 set);
extern "C" {
s32 get_enemy_factory_child_count(s32 area, s16 *enemy_type);
s32 is_room_enemy_set_cleared(s32 floor, s16 room);
}

#endif
