#include "pso/object/base/ObjectSetData.h"
#ifndef PSO_MAP_FLOORPOPULATION_H
#define PSO_MAP_FLOORPOPULATION_H

#include "types.h"
#include <stddef.h>

struct TObjEnemy;
class TObject;
class TObjBase;
class TSetManager;

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
    s16 enemy_index;
    u8 pad_06[4];
    u16 id;
    s16 room;
    s16 wave;
    u8 unknown10[0x34];
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
LAYOUT_ASSERT(EnemySetRecordId, offsetof(EnemySetRecord, id) == 0xA);
LAYOUT_ASSERT(EnemySetRecordFlags, offsetof(EnemySetRecord,flags)==2);
LAYOUT_ASSERT(EnemySetRecordIndex, offsetof(EnemySetRecord,enemy_index)==4);
LAYOUT_ASSERT(EnemySetRecordRoom, offsetof(EnemySetRecord,room)==0xC);
LAYOUT_ASSERT(EnemySetRecordWave, offsetof(EnemySetRecord,wave)==0xE);
LAYOUT_ASSERT(EnemySetRecordEnemy, offsetof(EnemySetRecord,enemy)==0x44);
LAYOUT_ASSERT(FloorSavedSetRow_size, sizeof(FloorSavedSetRow) == 8);
LAYOUT_ASSERT(LobbyFloorRows_size, sizeof(LobbyFloorRows) == 0x18);
LAYOUT_ASSERT(LobbyFloorRows_object_rows_offset, offsetof(LobbyFloorRows, object_rows) == 0x10);
LAYOUT_ASSERT(LobbyFloorRows_enemy_rows_offset, offsetof(LobbyFloorRows, enemy_rows) == 0x14);
LAYOUT_ASSERT(LobbyPoolEntry_size, sizeof(LobbyPoolEntry) == 8);

extern "C" {
// The original callers pass the floor; these return the currently loaded rows.
FloorObjectSetRow *get_active_floor_object_rows(s32 floor);
EnemySetRecord *get_active_floor_enemy_rows(s32 floor);
extern FloorObjectSetRow *TLobby__data_805D610C;
extern FloorObjectSetRow *floor_decoration_rows;
extern s32 TLobby__data_805D6120;
TObjBase *call_area_set_factory(TSetManager *manager, FloorObjectSetRow *row);
void destroy_child_recursive__6TLobbyFPvPv(TObject *root, TObject *object);
extern EnemySetRecord *TLobby__data_805D6114;
extern s32 current_floor_object_set_count;
extern s32 current_floor_enemy_set_count;
extern LobbyPoolEntry TLobby__data_80513A40[18];
extern LobbyFloorRows floor_enemy_group_table[18];
extern s32 TLobby__data_80513C80[18];
extern s32 TLobby__data_80513CC8[18];

s32 init_quest_floor_enemies(s32 floor, EnemySetRecord *source, u32 size);
s32 load_floor_enemy_group_entries__6TLobbyFiPvUi(s32 floor, FloorObjectSetRow *source, u32 size);
}

#endif
