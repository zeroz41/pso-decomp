#ifndef PSO_MAP_FLOORPOPULATION_H
#define PSO_MAP_FLOORPOPULATION_H

#include "types.h"
#include "pso/enemy/EnemyPlacement.h"
#include "pso/object/base/ObjectSetData.h"
#include "pso/system/AramPool.h"
#include <stddef.h>

struct TObjEnemy;
class TObject;
class TObjBase;
class TSetManager;
struct ObjectFactoryEntry;
struct EnemyFactoryEntry;
class THeap;

// Live object and enemy rows in the floor set buffers.
struct FloorObjectSetRow {
    s16 type;
    s16 flags;
    ObjectSetData placement;
    TObject *object;
};

struct EnemySetRecord {
    s16 type;
    s16 flags;
    EnemyPlacement placement;
    TObjEnemy *enemy;
};

// Flags and identifiers retained for a floor after its live rows are released.
struct FloorSavedSetRow {
    u16 id;
    s16 flags;
    s16 room;
    s16 wave;
};

struct LobbyFloorRows {
    s32 object_count;
    s32 enemy_count;
    u32 object_placement;
    u32 enemy_placement;
    FloorSavedSetRow *object_rows;
    FloorSavedSetRow *enemy_rows;
};

// Raw object and enemy set archive blocks for each floor.
struct LobbyPoolEntry {
    AramBlock *objects;
    AramBlock *enemies;
};

LAYOUT_ASSERT(FloorObjectSetRow_size, sizeof(FloorObjectSetRow) == 0x44);
LAYOUT_ASSERT(FloorObjectSetRowPlacementOffset, offsetof(FloorObjectSetRow, placement) == 4);
LAYOUT_ASSERT(FloorObjectSetRowPositionOffset, offsetof(FloorObjectSetRow, placement.position) == 0x10);
LAYOUT_ASSERT(FloorObjectSetRowObjectOffset, offsetof(FloorObjectSetRow, object) == 0x40);
LAYOUT_ASSERT(EnemySetRecordSize, sizeof(EnemySetRecord) == 0x48);
LAYOUT_ASSERT(EnemySetRecordFlags, offsetof(EnemySetRecord, flags) == 2);
LAYOUT_ASSERT(EnemySetRecordPlacement, offsetof(EnemySetRecord, placement) == 4);
LAYOUT_ASSERT(EnemySetRecordId, offsetof(EnemySetRecord, placement.id) == 0xA);
LAYOUT_ASSERT(EnemySetRecordIndex, offsetof(EnemySetRecord, placement.enemy_index) == 4);
LAYOUT_ASSERT(EnemySetRecordRoom, offsetof(EnemySetRecord, placement.room) == 0xC);
LAYOUT_ASSERT(EnemySetRecordWave, offsetof(EnemySetRecord, placement.wave) == 0xE);
LAYOUT_ASSERT(EnemySetRecordEnemy, offsetof(EnemySetRecord,enemy)==0x44);
LAYOUT_ASSERT(FloorSavedSetRow_size, sizeof(FloorSavedSetRow) == 8);
LAYOUT_ASSERT(LobbyFloorRows_size, sizeof(LobbyFloorRows) == 0x18);
LAYOUT_ASSERT(LobbyFloorRows_object_rows_offset, offsetof(LobbyFloorRows, object_rows) == 0x10);
LAYOUT_ASSERT(LobbyFloorRows_enemy_rows_offset, offsetof(LobbyFloorRows, enemy_rows) == 0x14);
LAYOUT_ASSERT(LobbyPoolEntry_size, sizeof(LobbyPoolEntry) == 8);

// Set rows of the floor being played and their counts.
extern FloorObjectSetRow *current_floor_object_set_rows;
extern s32 current_floor_object_set_count;
extern EnemySetRecord *current_floor_enemy_set_rows;
extern s32 current_floor_enemy_set_count;
// Decoration rows of the floor's map set (the ad.dat / d.dat file).
extern FloorObjectSetRow *floor_decoration_rows;
extern s32 floor_decoration_row_count;
// Floor (and its area, -1 without a map selection) whose set rows were last set up.
extern s32 active_set_floor;
extern s32 active_set_floor_area;
// Bit 0: the floor sets are loaded.
extern s16 floor_set_flags;
// Every floor's set rows, kept in the ARAM pool, and the flags saved in the row heap while a floor is left.
extern AramPool *floor_set_archive_pool;
extern THeap *floor_saved_row_heap;
extern LobbyPoolEntry floor_set_archives[18];
extern LobbyFloorRows floor_enemy_group_table[18];
// Object and enemy set row counts of each floor, -1 when its set file failed to load.
extern s32 floor_object_set_counts[18];
extern s32 floor_enemy_set_counts[18];
extern FloorObjectSetRow *object_set_row_buffer;
extern EnemySetRecord *enemy_set_row_buffer;

// Spawns the hidden enemies of one room wave on the current floor, or flags them on another floor.
s32 unhide_enemies_at(s32 floor, s16 room, s16 wave);

// The original callers pass the floor; these return the currently loaded rows.
FloorObjectSetRow *get_active_floor_object_rows(s32 floor);
EnemySetRecord *get_active_floor_enemy_rows(s32 floor);
TObjBase *call_area_set_factory(TSetManager *manager, FloorObjectSetRow *row);
s32 init_quest_floor_enemies(s32 floor, EnemySetRecord *source, u32 size);
// Looks the row's type up in the current area's object factory table: copies the entry to out and returns its
// index, or -1.
s32 find_set_factory_index(FloorObjectSetRow *row, ObjectFactoryEntry *out);
// Builds the object of a set row through its factory; NULL for an empty row or an unknown type.
TObjBase *create_set_object_from_row(FloorObjectSetRow *row);
void copy_object_factory_entry(ObjectFactoryEntry *out, ObjectFactoryEntry *entry);
void copy_enemy_factory_entry(EnemyFactoryEntry *out, EnemyFactoryEntry *entry);
TObjEnemy *construct_enemy_from_set_row(EnemySetRecord *row);
// Number of child enemies the area's factory entry for that enemy type spawns with it.
s32 get_enemy_factory_child_count(s32 area, s16 *enemy_type);

// Followed by the object flag stream and then the enemy flag stream in game-state packet 6x6E.
struct FloorSetFlagsHeader {
    u32 object_offset;
    s32 object_count;
    u32 enemy_offset;
    s32 enemy_count;
};

// The decompressed sync scratch has 0x4000 payload bytes after its length words.
struct FloorSetFlagsPayload : FloorSetFlagsHeader {
    s16 flags[(0x4000 - sizeof(FloorSetFlagsHeader)) / sizeof(s16)];
};

LAYOUT_ASSERT(FloorSetFlagsPayloadSize, sizeof(FloorSetFlagsPayload) == 0x4000);
LAYOUT_ASSERT(FloorSetFlagsHeaderSize, sizeof(FloorSetFlagsHeader) == 0x10);
LAYOUT_ASSERT(FloorSetFlagsEnemyOffset, offsetof(FloorSetFlagsHeader, enemy_offset) == 8);

// Game-state packet 6x6E after decompression: the sizes of its three streams, then the streams.
struct GameStateSyncScratch {
    u16 total_size;
    u16 floor_flags_size;
    u16 sync_records_size;
    u16 switch_table_size;
    u8 payload[sizeof(FloorSetFlagsPayload)];

    void bswap();
};
LAYOUT_ASSERT(GameStateSyncScratchSize, sizeof(GameStateSyncScratch) == 0x4008);
LAYOUT_ASSERT(GameStateSyncPayloadOffset, offsetof(GameStateSyncScratch, payload) == 8);

void swap_floor_set_flags_header(FloorSetFlagsHeader *header);
void unpack_floor_set_flags(FloorSetFlagsHeader *buffer);
void apply_floor_set_flags_packet(FloorSetFlagsHeader *buffer, u16 length);
int pack_floor_set_flags(FloorSetFlagsPayload *buffer);
int serialize_area_set_flags(FloorSetFlagsPayload *buffer);
int get_floor_set_flags_size(void);

void init_scene_objects();
void destroy_current_floor_objects(void);
void destroy_floor_decoration_objects(void);
void mark_floor_enemies_dead(void);
void send_6x76_set_entity_set_flags(TObjBase *object, s16 flags);
void set_wave_object_flags(s32 pl, s16 b, s16 a, s32 mask, s32 set);
s32 is_room_free_of_active_enemies(s32 floor, s16 room);
// 1 when every enemy set row of the room on that floor has flag 8 (the quest zone-clear check).
s32 is_room_enemy_set_cleared(s32 floor, s16 room);
// Creates the hidden objects of one room group on the current floor, or flags them on another floor.
s32 unhide_room_set_objects(s32 floor, s16 room, s16 group);
s32 spawn_objects_at_pos(s16 room, s16 wave);
void assign_display_objects(EnemySetRecord *rows, s32 enemy_count);
void assign_objects_to_slots(FloorObjectSetRow *rows, s32 object_count);
void create_objects(s32 floor);
void attach_objects_by_id(s32 floor);
EnemySetRecord *get_loaded_enemy_set_rows();
FloorObjectSetRow *get_loaded_object_set_rows();
#endif
