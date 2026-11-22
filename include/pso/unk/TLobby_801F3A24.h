#ifndef PSO_UNK_TLOBBY_801F3A24_H
#define PSO_UNK_TLOBBY_801F3A24_H

#include "types.h"

// One entry per quest object; drop_id_base seeds the ids of the items the
// object drops (TLobby::init_id_tables).
struct QuestObjectEntry {
    s16 id;
    u16 drop_id_base;
};
extern QuestObjectEntry *quest_object_entries;

void clear_quest_floor_designations(void);
bool load_quest_encounter_section(s32 arg0);
void populate_quest_floor_sets(void);
void set_quest_floor_designation(s16 mode, s32 floor, s32 terrain, s32 unused);
void set_quest_floor_designation_ex(s16 mode, s32 floor, s32 area, s32 layout, s32 entities);

#endif
