#ifndef PSO_MAP_FLOORPOPULATION_H
#define PSO_MAP_FLOORPOPULATION_H

#include "types.h"
#include "pso/enemy/EnemyPlacement.h"
#include "pso/object/base/ObjectSetData.h"
#include <stddef.h>

struct TObjEnemy;
class TObject;
class TObjBase;
class TSetManager;
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
    void *objects;
    void *enemies;
};

LAYOUT_ASSERT(FloorObjectSetRow_size, sizeof(FloorObjectSetRow) == 0x44);
LAYOUT_ASSERT(FloorObjectSetRowPlacementOffset, offsetof(FloorObjectSetRow, placement) == 4);
LAYOUT_ASSERT(FloorObjectSetRowPositionOffset, offsetof(FloorObjectSetRow, placement) + offsetof(ObjectSetData, position) == 0x10);
LAYOUT_ASSERT(FloorObjectSetRowObjectOffset, offsetof(FloorObjectSetRow, object) == 0x40);
LAYOUT_ASSERT(EnemySetRecordSize, sizeof(EnemySetRecord) == 0x48);
LAYOUT_ASSERT(EnemySetRecordFlags, offsetof(EnemySetRecord, flags) == 2);
LAYOUT_ASSERT(EnemySetRecordPlacement, offsetof(EnemySetRecord, placement) == 4);
LAYOUT_ASSERT(EnemySetRecordId, offsetof(EnemySetRecord, placement) + offsetof(EnemyPlacement, id) == 0xA);
LAYOUT_ASSERT(EnemySetRecordIndex, offsetof(EnemySetRecord, placement) + offsetof(EnemyPlacement, enemy_index) == 4);
LAYOUT_ASSERT(EnemySetRecordRoom, offsetof(EnemySetRecord, placement) + offsetof(EnemyPlacement, room) == 0xC);
LAYOUT_ASSERT(EnemySetRecordWave, offsetof(EnemySetRecord, placement) + offsetof(EnemyPlacement, wave) == 0xE);
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
extern void *floor_set_archive_pool;
extern THeap *floor_saved_row_heap;
extern LobbyPoolEntry floor_set_archives[18];
extern LobbyFloorRows floor_enemy_group_table[18];
// Object and enemy set row counts of each floor, -1 when its set file failed to load.
extern s32 floor_object_set_counts[18];
extern s32 floor_enemy_set_counts[18];
extern FloorObjectSetRow *object_set_row_buffer;
extern EnemySetRecord *enemy_set_row_buffer;

extern "C" {
// The original callers pass the floor; these return the currently loaded rows.
FloorObjectSetRow *get_active_floor_object_rows(s32 floor);
EnemySetRecord *get_active_floor_enemy_rows(s32 floor);
TObjBase *call_area_set_factory(TSetManager *manager, FloorObjectSetRow *row);
void destroy_child_recursive__6TLobbyFPvPv(TObject *root, TObject *object);

s32 init_quest_floor_enemies(s32 floor, EnemySetRecord *source, u32 size);
s32 load_floor_enemy_group_entries__6TLobbyFiPvUi(s32 floor, FloorObjectSetRow *source, u32 size);
}

#endif
