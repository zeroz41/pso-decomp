#ifndef PSO_UNK_TLOBBY_801F3A24_H
#define PSO_UNK_TLOBBY_801F3A24_H

#include "types.h"

// One entry per quest object (ObjectSetData::set_index): the state flags the
// 6x0B update carries; drop_id_base seeds the ids of the items the object
// drops (TLobby::init_id_tables).
struct QuestObjectEntry {
    s16 flags;
    u16 drop_id_base;

    void copy_from(QuestObjectEntry *src);
    void bswap();
};
extern QuestObjectEntry *quest_object_entries;

// Stores entry as quest object index's state; 0 when index is past the table.
s32 set_quest_object_entry(s16 index, QuestObjectEntry *entry);

void clear_quest_floor_designations(void);
bool load_quest_encounter_section(s32 floor);
void populate_quest_floor_sets(void);
void set_quest_floor_designation(s16 mode, s32 floor, s32 terrain, s32 unused);
void set_quest_floor_designation_ex(s16 mode, s32 floor, s32 area, s32 layout, s32 entities);

struct ConvertQuestObjectRowsQuestObjRow {
    u8 pad0[2];
    s16 flags;
    u8 pad1[0x40];
};

struct BswapEnemySetRowsEntry {
    u16 a;
    s16 b;
    u8 rest[0x44];
};

// One record of the loaded quest dat: type, bytes to the next record, floor and the size of the data that follows.
struct QuestDatRecord {
    s32 type;
    s32 next_offset;
    s32 floor;
    s32 size;
};

#endif
