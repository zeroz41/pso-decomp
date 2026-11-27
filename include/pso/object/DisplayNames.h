#ifndef PSO_OBJECT_DISPLAYNAMES_H
#define PSO_OBJECT_DISPLAYNAMES_H

#include "types.h"

const char *enemy_name_for_rt_index(s32 rt_index);
// The name of a character's section id (luker_stat_entry_ptr_table).
const char *get_section_id_name(int section_id);
// The localized destination name of a floor area (text group 9).
const char *get_floor_destination_name(u32 area);

#endif
