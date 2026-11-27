#ifndef PSO_QUEST_QUESTFLOORDESIGNATION_H
#define PSO_QUEST_QUESTFLOORDESIGNATION_H

#include "types.h"

struct FloorObjectSetRow;

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

// One record of the loaded quest dat: type, bytes to the next record, floor and the size of the data that follows.
struct QuestDatRecord {
    s32 type;
    s32 next_offset;
    s32 floor;
    s32 size;
};

void setup_quest_list();
void refresh_quest_list(const char *path);
void open_session(const char *path);
void convert_quest_object_rows(FloorObjectSetRow *rows, u32 byte_size);

#endif
