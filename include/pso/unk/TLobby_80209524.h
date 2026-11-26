#ifndef PSO_UNK_TLOBBY_80209524_H
#define PSO_UNK_TLOBBY_80209524_H

#include "types.h"

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

// --- C functions defined in TLobby_80209524.cpp ---
EventShuffleTable *construct_event_shuffle_table(EventShuffleTable *table, s32 capacity);
void select_event_shuffle_table(s16 id);
void init_item_drop_rng(void);
void bswap_event_table_entry(void *p);
void copy_event_table_entry(void *dst, void *src);
void bswap_item_data_record(void *p);
void bswap_table_header(void *p);
void copy_challenge_random_event(ChallengeRandomEvent *dst, ChallengeRandomEvent *src);
void load_floor_object_set(s32 player);
s32 get_total_object_set_count(void);
// --- end of C functions

// Id counters of the map set loaders; TLobby::setup_quest_list resets them.
extern s32 map_set_object_id_counter;
extern s32 next_enemy_set_actor_id;
extern s32 map_object_id_counter;
extern s32 map_set_enemy_id_counter;
extern saddr item_drop_server_seed;

struct DestroyEventShuffleTableEntry { f32 a, b, c; u32 d, e, f, g; };

struct PickRandomEntryOut { u8 pad[0x14]; f32 a, b, c; u32 d, e, f; };

struct TLobbyHdr { s32 table; s32 b; s32 count; s32 d; };

struct AppendRecord { f32 f[5]; s16 h[6]; };

struct AppendOut {
    u8 pad0[6];
    s16 f6;
    u8 pad8[0x2C - 8];
    f32 f[5];
    s16 f40;
    s16 f42;
};

struct PickWeightedEntryHdr { s32 a; s32 table; s32 c; s32 count; };

struct PickWeightedEntryEntry { u8 b0; u8 b1; u8 weight; u8 pad; };

struct BsearchRecordTmp { u8 pad[0x18]; s16 v; u8 pad2[2]; };

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

#endif
