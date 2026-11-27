#ifndef PSO_MAP_MAPSETDATA_H
#define PSO_MAP_MAPSETDATA_H

#include "types.h"

struct EventShuffleTableIndexEntry;
struct AppendRecord;
struct ItemDataTableHeader;
struct EventShuffleTable;
struct FloorObjectSetRow;

struct ChallengeRandomEvent;

// Header of each chunk of a challenge quest file (big-endian on disc); the
// chunk list ends at a chunk of type 0.
struct QuestChunkHeader {
    s32 type;
    s32 size;  // whole chunk, header included
    s32 id;
    s32 data_size;
    void bswap();
};

// Find the chunk of quest `id` of each type; they return the data after the
// header, or NULL. find_header_by_id also stores the chunk's data_size in
// challenge_event_source_size (-1 when missing).
QuestChunkHeader *find_header_by_id(QuestChunkHeader *chunks, s32 id);
QuestChunkHeader *find_chunk_by_id(QuestChunkHeader *chunks, s32 id);
QuestChunkHeader *find_type5_header(QuestChunkHeader *chunks, s32 id);

// Gives each of the count object rows just read for a floor of `area` its
// entity id and set index, and reserves the extra ids its object type spawns.
void assign_object_ids(FloorObjectSetRow *rows, s32 count, s32 area);

// --- C functions defined in MapSetData.cpp ---
EventShuffleTable *construct_event_shuffle_table(EventShuffleTable *table, s32 capacity);
void select_event_shuffle_table(s16 id);
void init_item_drop_rng(void);
void bswap_event_table_entry(EventShuffleTableIndexEntry *entry);
void copy_event_table_entry(void *dst, void *src);
void bswap_item_data_record(AppendRecord *record);
void bswap_table_header(ItemDataTableHeader *header);
void copy_challenge_random_event(ChallengeRandomEvent *dst, ChallengeRandomEvent *src);
void load_floor_object_set(s32 player);
s32 get_total_object_set_count(void);
// --- end of C functions

// Id counters of the map set loaders; setup_quest_list resets them.
extern s32 map_set_object_id_counter;
extern s32 next_enemy_set_actor_id;
extern s32 map_object_id_counter;
extern s32 map_set_enemy_id_counter;
extern saddr item_drop_server_seed;

struct DestroyEventShuffleTableEntry {
    f32 a, b, c;
    u32 d, e, f;
    u16 g, h;
    void bswap();
};

struct PickRandomEntryOut { u8 pad[0x14]; f32 a, b, c; u32 d, e, f; };
void pick_random_entry(PickRandomEntryOut *out);

// The head of item_data_table_buffer: where its AppendRecord table (sorted by h[2], searched by
// lookup_item_data_record) and its PickWeightedEntryEntry table (pick_weighted_entry) start, and their counts.
struct ItemDataTableHeader {
    s32 record_offset;
    s32 weighted_offset;
    s32 record_count;
    s32 weighted_count;
};

struct AppendRecord { f32 f[5]; s16 h[6]; };

struct AppendOut {
    u8 pad0[6];
    s16 f6;
    u8 pad8[0x2C - 8];
    f32 f[5];
    s16 f40;
    s16 f42;
};

// slot_index indexes lobby_random_slot_id_table, record_key is the lookup_item_data_record key.
struct PickWeightedEntryEntry { u8 slot_index; u8 record_key; u8 weight; u8 pad; };

struct TLobbyHdr2 { s32 table; s32 data; s32 count; };

struct EventShuffleTableIndexEntry { s16 id; s16 count; s32 offset; };

struct DestroyEventShuffleTableSpawnRecord {
    s16 type;
    u16 flags;
    s16 index;
    s16 children;
    u16 reserved;
    s16 actor_id;
    s16 room;
    s16 wave;
    u8 placement[0x48 - 0x10];
};

void reserve_enemy_set_actor_ids(DestroyEventShuffleTableSpawnRecord *slots, s32 count, s32 floor);

struct LoadEnemySetFileEntry { s16 a; s16 b; u8 pad[0x48 - 4]; };

struct LoadEnemySetFileName { char s[0x20]; };

struct LoadObjectSetFileEntry { s16 a; s16 b; u8 pad[0x44 - 4]; };

struct LoadObjectSetFileName { char s[0x20]; };

struct LoadAreaObjectSetRecord { u8 pad0[2]; s16 f2; u8 pad4[0x40]; };

s32 load_enemy_set_file(s32 idx, const char *filename);
void load_map_set_data(s32 idx, const char *filename);
s32 load_object_set_file(s32 idx, const char *filename);

s32 load_area_enemy_set(s32 floor, s32 area, s32 terrain, s32 entities);

s32 load_area_object_set(s32 floor, saddr lobby, s32 terrain, s32 entities);

void clear_map_set_data(void);
void append_swapped_u32(s32 *value);
void *bsearch_record(void *records, int n, int key);
s32 pick_random_slot(s16 *slot);
void init_sub_objects();
s32 set_flags_on_matching_entries(s32 floor, s16 room, s16 wave, s32 flags);
s32 set_room_group_flags(s32 floor, s16 room, s16 group, s32 bits);
int get_obj_table_entry(int a0);
void pick_weighted_entry(s32 *key, s32 *slot);
int get_object_type(int a0);
void load_set_gsl_files();
s32 load_all_floor_enemy_sets();
s32 load_all_floor_object_sets();
void free_data_60F0();
s32 init_handle(s32 size);
s32 sum_floor_enemy_counts();

#endif
