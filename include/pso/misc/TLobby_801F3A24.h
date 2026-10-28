#ifndef PSO_MISC_TLOBBY_801F3A24_H
#define PSO_MISC_TLOBBY_801F3A24_H

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
extern "C" {
void open_session__6TLobbyFi(s32 arg0);
}
void populate_quest_floor_sets(void);
extern "C" {
void rebuild_all__6TLobbyFi(int a0);
void refresh_quest_list__6TLobbyFi(s32 arg0);
}
void set_quest_floor_designation(s16 mode, s32 floor, s32 terrain, s32 unused);
void set_quest_floor_designation_ex(s16 mode, s32 floor, s32 area, s32 layout, s32 entities);
extern "C" {
void update_and_reset__6TLobbyFi(int a0);
}

// --- C functions defined in TLobby_801F3A24.cpp ---
extern "C" {
void rebuild_all__6TLobbyFi(int a0);
void refresh_quest_list__6TLobbyFi(s32 arg0);
void update_and_reset__6TLobbyFi(int a0);
}
// --- end of C functions

#endif
