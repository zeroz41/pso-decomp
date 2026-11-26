#include "pso/system/memory.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/map/MapSetArchive.h"
#include "pso/map/FloorPopulation.h"
#include "pso/system/ResourceFile.h"
#include "pso/map/TSetManager.h"
#include "pso/enemy/TObjEnemy.h"
#include "types.h"
#include <string.h>

#pragma readonly_strings on
#include "pso/network/TLobby.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/unk/TLobby_801F3A24.h"
#include "pso/system/THeap.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include <dolphin/ar.h>
#include "pso/system/scene/TScene.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/render/NinjaUtil.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/ObjectFactoryTables.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D8F74.h"

s32 active_set_floor_area;
s32 active_set_floor;
s32 lbl_805D6100;
AramPool *floor_set_archive_pool;
THeap *floor_saved_row_heap;
FloorObjectSetRow *current_floor_object_set_rows;
s32 current_floor_object_set_count;
EnemySetRecord *current_floor_enemy_set_rows;
s32 current_floor_enemy_set_count;
FloorObjectSetRow *floor_decoration_rows;
s32 floor_decoration_row_count;
void *floor_decoration_rows_b;
s32 floor_decoration_row_count_b;
s32 item_drop_memory_pool_ar_addr;
s32 item_drop_memory_pool_size;
s16 floor_set_flags;
FloorObjectSetRow *object_set_row_buffer;
EnemySetRecord *enemy_set_row_buffer;
QuestObjectEntry *quest_object_entries;
EnemyStateRecord *enemy_state_records;
s32 object_condition_count;
s32 enemy_condition_count;


struct RecoveredGlobal_8020D2B4_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
LAYOUT_ASSERT(RecoveredGlobal_8020D2B4_lbl_8058D490_size, sizeof(RecoveredGlobal_8020D2B4_lbl_8058D490) == 0x30);

typedef struct SpawnAngles_8020D36C { u32 x, y, z; } SpawnAngles_8020D36C;

typedef struct ApplyRoomTransformToEnemyRowsSpawnRecord {
    s16 type;
    u16 flags;
    u16 index;
    s16 children;
    u16 reserved;
    u16 actor_id;
    s16 room;
    s16 wave;
    u32 secondary_wave;
    Vec position;
    SpawnAngles_8020D36C angles;
    f32 parameters[5];
    s16 integers[4];
} ApplyRoomTransformToEnemyRowsSpawnRecord;

struct ResolveSetRowFactoryIndicesOut { u8 data[0x18]; };

typedef ObjectFactoryEntry Ent_8020D5AC;

extern "C" {
s32 matrix_mult_vec(int, void *, void *);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);
}
void apply_room_transform_to_enemy_rows(ApplyRoomTransformToEnemyRowsSpawnRecord *rows, s32 count);
void apply_room_transform_to_object_rows(FloorObjectSetRow *arr, s32 n);
extern "C" {
s32 find_set_factory_index(void *, void *);
s32 is_battle_mode_running();
}
extern RecoveredGlobal_8020D2B4_lbl_8058D490 identity_matrix;
void apply_room_transform(saddr matrix, u8 *rotation, u8 *room);
void resolve_set_row_factory_indices(void *unused, FloorObjectSetRow *rows, int count);
s32 is_within_camera_distance(void *unused, void *pos, f32 max_dist_sq);
void spawn_decorations_in_range(TSetManager *manager);
void apply_room_transform(saddr matrix, u8 *rotation, u8 *room) {
    push_matrix_from(&identity_matrix.value);
    translate_matrix(0, (f32) (*(f32 *)((s8 *)room + 4)), (f32) (*(f32 *)((s8 *)room + 8)), (f32) (*(f32 *)((s8 *)room + 0xC)));
    rotate_matrix_z(0, (int) (*(s32 *)((s8 *)room + 0x18)));
    rotate_matrix_x(0, (int) (*(s32 *)((s8 *)room + 0x10)));
    rotate_matrix_y(0, (int) (*(s32 *)((s8 *)room + 0x14)));
    matrix_mult_vec(0, (void *)matrix, (void *)matrix);
    pop_matrix();
    *(s32 *)((s8 *)rotation + 0) = (s32) (*(s32 *)((s8 *)rotation + 0) + *(s32 *)((s8 *)room + 0x10));
    *(s32 *)((s8 *)rotation + 4) = (s32) (*(s32 *)((s8 *)rotation + 4) + *(s32 *)((s8 *)room + 0x14));
    *(s32 *)((s8 *)rotation + 8) = (s32) (*(s32 *)((s8 *)rotation + 8) + *(s32 *)((s8 *)room + 0x18));
}

void apply_room_transform_to_enemy_rows(ApplyRoomTransformToEnemyRowsSpawnRecord *rows, s32 count) {
    ApplyRoomTransformToEnemyRowsSpawnRecord *row;
    void *cached_room;
    s16 cached_id = -1;
    s32 i;
    for (i = 0; i < count; i++) {
        row = &rows[i];
        if (cached_id != row->room) {
            cached_room = find_scene_room_by_id(row->room);
            cached_id = row->room;
        }
        if (cached_room) {
            apply_room_transform((saddr)&row->position, (u8 *)&row->angles, (u8 *)cached_room);
        }
    }
}

void apply_room_transform_to_object_rows(FloorObjectSetRow *arr, s32 n) {
    FloorObjectSetRow *p;
    void *sec;
    s16 key;
    s32 i;
    key = -1;
    i = 0;
    for (; i < n; i++) {
        p = &arr[i];
        if (key != p->placement.room) {
            sec = find_scene_room_by_id(p->placement.room);
            key = p->placement.room;
        }
        if (sec != NULL) {
            apply_room_transform((saddr)&p->placement.position, (u8 *)p->placement.rotation, (u8 *)sec);
        }
    }
}

void resolve_set_row_factory_indices(void *unused, FloorObjectSetRow *rows, int count) {
    ResolveSetRowFactoryIndicesOut o;
    FloorObjectSetRow *p;
    s32 i;
    s32 r;
    p = rows;
    for (i = 0; i < count; i++, p++) {
        if (p->type != -1) {
            r = find_set_factory_index(p, &o);
            if (r >= 0) {
                p->type = r;
            } else {
                p->type = -1;
            }
        }
    }
}

s32 is_within_camera_distance(void *unused, void *pos, f32 max_dist_sq) {
    s32 n;
    s32 i;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        if (camera_ctrl_instance != NULL) {
            n = TCameraCtrl::get_view_count();
            for (i = 0; i < n; i++) {
                if (xyz_distance_squared(static_cast<const Vec *>(pos), &camera_ctrl_instance->split_pos[i]) < max_dist_sq) {
                    return 1;
                }
            }
        }
    } else if (camera_ctrl_instance != NULL && xyz_distance_squared(static_cast<const Vec *>(pos), &camera_ctrl_instance->pos) < max_dist_sq) {
        return 1;
    }
    return 0;
}

void spawn_decorations_in_range(TSetManager *manager) {
    Ent_8020D5AC *tbl;
    FloorObjectSetRow *p;
    s32 i;
    TObjBase *obj;
    tbl = floor_object_factory_tables[get_current_floor_area()];
    if (tbl == NULL) {
        return;
    }
    if (TObjPlayer::get_player_count() != 0 && is_quest_active() != 0 && is_battle_mode_running() == 0) {
        return;
    }
    p = floor_decoration_rows;
    for (i = 0; i < floor_decoration_row_count; i++, p++) {
        if (p->type != -1 && !(p->flags & 2) && !(p->flags & 8)
            && is_within_camera_distance(manager, &p->placement.position, tbl[p->type].creation_distance_squared) == 1) {
            p->placement.entity_id = 0xFFFF;
            p->placement.set_index = -1;
            obj = call_area_set_factory(manager, p);
            if (obj != NULL) {
                p->object = obj;
                obj->room = p->placement.room;
                obj->set_entry = p;
                p->flags |= 2;
            } else {
                p->object = NULL;
                p->flags |= 8;
            }
        }
    }
}

void TSetManager::update_decoration_spawning() { spawn_decorations_in_range(this); }
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TSetManager::apply_floor_set_rows() {
    u8 *self = (u8 *)this;
    s32 current_floor;
    LobbyFloorRows *floor;
    current_floor = get_current_floor();
    active_set_floor = current_floor;
    floor = &floor_enemy_group_table[current_floor];
    if (!(floor->object_placement & 2)) {
        apply_room_transform_to_object_rows(current_floor_object_set_rows, floor->object_count);
        floor->object_placement |= 2U;
    }
    if (!(floor->enemy_placement & 4)) {
        apply_room_transform_to_enemy_rows((ApplyRoomTransformToEnemyRowsSpawnRecord *)(current_floor_enemy_set_rows), floor->enemy_count);
        floor->enemy_placement |= 4U;
    }
    if (floor->object_placement & 2) {
        TLobby::assign_objects_to_slots((u8 *)current_floor_object_set_rows, floor->object_count);
    }
    if (floor->enemy_placement & 4) {
        TLobby::assign_display_objects(current_floor_enemy_set_rows, floor->enemy_count);
    }
    if (floor_decoration_row_count > 0) {
        apply_room_transform_to_object_rows(floor_decoration_rows, floor_decoration_row_count);
        resolve_set_row_factory_indices(self, floor_decoration_rows, floor_decoration_row_count);
    }
    this->step = 1;
}
#pragma pop

void TSetManager::post_step() {  }

void TSetManager::run_task() {
    static void (TSetManager::*steps[])() = {
        &TSetManager::apply_floor_set_rows,
        &TSetManager::update_decoration_spawning,
    };
    (this->*steps[step])();
    post_step();
}

TSetManager::~TSetManager() {}

const char *TSetManager::class_name = "TSetManager";

TSetManager::TSetManager(TObject *parent) : TObject(parent) {
    m_name = class_name;
    step = 0;
}

LobbyPoolEntry floor_set_archives[18];
LobbyFloorRows floor_enemy_group_table[18];
s32 floor_object_set_counts[18];
s32 floor_enemy_set_counts[18];
u32 TLobby__data_80513D10[9];
#pragma push
#pragma force_active on
u8 lbl_80513D34[0x24];
#pragma pop
extern const char decoration_file_suffix_online[7] = "ad.dat";
extern const char decoration_file_suffix_offline[6] = "d.dat";

void TSetManager::create() {
    new TSetManager((TObject *)tl_02);
}

void free_floor_decorations() {
    if (floor_decoration_rows != NULL) {
        mem_free(floor_decoration_rows);
        floor_decoration_rows = NULL;
        floor_decoration_row_count = 0;
    }
    if (floor_decoration_rows_b != NULL) {
        mem_free(floor_decoration_rows_b);
        floor_decoration_rows_b = NULL;
        floor_decoration_row_count_b = 0;
    }
}

s32 load_map_decoration_rows(s32 map, s32 grp, s32 room) {
    MapSetEntry *r;
    s32 i;
    s32 size;
    char path[0x20];
    if (map_set_areas[map].variants == NULL || map_set_areas[map].count - 1 < grp) {
        return 0;
    }
    r = map_set_areas[map].variants[grp].entries;
    if (r == NULL || map_set_areas[map].variants[grp].count - 1 < room) {
        return 0;
    }
    if (TLobby::is_online_ready() != 0) {
        TLobby::replace_file_extension(path, (char *)r->decoration_set_name, (char *)decoration_file_suffix_online);
    } else {
        TLobby::replace_file_extension(path, (char *)r->decoration_set_name, (char *)decoration_file_suffix_offline);
    }
    size = get_resource_file_size(path);
    if (size < 0) {
        return 0;
    }
    floor_decoration_row_count = (u32)size / sizeof(FloorObjectSetRow);
    if ((floor_decoration_rows = static_cast<FloorObjectSetRow *>(mem_alloc(floor_decoration_row_count * sizeof(FloorObjectSetRow)))) == 0) {
        return 0;
    }
    read_disc_file(path, floor_decoration_rows);
    for (i = 0; i < floor_decoration_row_count; i++) {
        swap_object_row_endian(&floor_decoration_rows[i]);
        floor_decoration_rows[i].flags = 0;
        floor_decoration_rows[i].placement.entity_id = 0xFFFF;
        floor_decoration_rows[i].placement.set_index = -1;
    }
    return 1;
}

void clear_floor_flags_and_depart() {
    free_floor_decorations();
    floor_set_flags &= ~8;
    floor_set_flags &= ~16;
    depart_floor_population();
}

void setup_floor_decorations() {
    FloorMapSelection v;
    saddr r;
    arrive_floor_population();
    floor_decoration_rows = NULL;
    floor_set_flags &= ~8;
    floor_decoration_rows_b = NULL;
    floor_decoration_row_count = 0;
    floor_decoration_row_count_b = 0;
    floor_set_flags &= ~16;
    active_set_floor_area = get_current_floor_area();
    r = get_current_floor();
    active_set_floor = r;
    if (lookup_floor_map_selection(r, &v) != 0) {
        load_map_decoration_rows(v.area, v.terrain, v.entities);
        return;
    }
    active_set_floor_area = -1;
}

void reset_id_tables() {
    s32 i;
    s32 n = 0;
    if (quest_object_entries != 0) {
        memset(quest_object_entries, 0, 0x2E80);
        for (i = 0; i < 0xBA0; i++) {
            s16 t = n + 0x100;
            n++;
            quest_object_entries[i].drop_id_base = t;
        }
    }
    if (enemy_state_records != 0) {
        memset(enemy_state_records, 0, 0x87C0);
        for (i = 0; i < 0xB50; i++) {
            s16 t = n + 0x100;
            n++;
            enemy_state_records[i].drop_id = t;
        }
    }
}

// inferred: clears the set object and enemy rows and frees every floor's enemy and object arrays; a lobby area reload callback
void clear_floor_population(void) {
    s32 n;
    s32 i;
    floor_set_flags = 0;
    if (object_set_row_buffer != NULL) {
        memset(object_set_row_buffer, 0, 0xBA0 * sizeof(FloorObjectSetRow));
        for (i = 0; i < 0xBA0; i++) {
            object_set_row_buffer[i].type = -1;
        }
    }
    if (enemy_set_row_buffer != NULL) {
        memset(enemy_set_row_buffer, 0, 0x5A8 * sizeof(EnemySetRecord));
        for (i = 0; i < 0x5A8; i++) {
            enemy_set_row_buffer[i].type = -1;
        }
    }
    memset(floor_object_set_counts, 0, sizeof(floor_object_set_counts));
    memset(floor_enemy_set_counts, 0, sizeof(floor_enemy_set_counts));
    memset(TLobby__data_80513D10, 0, sizeof(TLobby__data_80513D10));
    n = 0;
    if (quest_object_entries != 0) {
        memset(quest_object_entries, 0, 0x2E80);
        for (i = 0; i < 0xBA0; i++) {
            quest_object_entries[i].drop_id_base = n++ + 0x100;
        }
    }
    if (enemy_state_records != 0) {
        memset(enemy_state_records, 0, 0x87C0);
        for (i = 0; i < 0xB50; i++) {
            enemy_state_records[i].drop_id = n++ + 0x100;
        }
    }
    object_condition_count = 0;
    enemy_condition_count = 0;
    floor_decoration_rows = 0;
    floor_decoration_rows_b = NULL;
    floor_decoration_row_count = 0;
    floor_decoration_row_count_b = 0;
    lbl_805D6100 = 0;
    for (s32 i = 17; i >= 0; i--) {
        if (floor_set_archives[i].enemies != NULL) {
            floor_set_archive_pool->free(floor_set_archives[i].enemies);
            floor_set_archives[i].enemies = NULL;
        }
    }
    for (s32 i = 17; i >= 0; i--) {
        if (floor_set_archives[i].objects != NULL) {
            floor_set_archive_pool->free(floor_set_archives[i].objects);
            floor_set_archives[i].objects = NULL;
        }
    }
    for (s32 i = 17; i >= 0; i--) {
        if (floor_enemy_group_table[i].enemy_rows != NULL) {
            floor_saved_row_heap->heap_free(floor_enemy_group_table[i].enemy_rows);
            floor_enemy_group_table[i].enemy_rows = NULL;
        }
    }
    for (s32 i = 17; i >= 0; i--) {
        if (floor_enemy_group_table[i].object_rows != NULL) {
            floor_saved_row_heap->heap_free(floor_enemy_group_table[i].object_rows);
            floor_enemy_group_table[i].object_rows = NULL;
        }
    }
    memset(floor_enemy_group_table, 0, sizeof(floor_enemy_group_table));
}

void depart_floor_population() {
    LobbyFloorRows *area = &floor_enemy_group_table[get_current_floor()];
    if (current_floor_object_set_rows != 0) {
        FloorObjectSetRow *s = current_floor_object_set_rows;
        FloorSavedSetRow *d = area->object_rows;
        s32 i;
        for (i = 0; i < area->object_count; i++, s++, d++) {
            if (s->placement.entity_id == d->id) {
                d->flags = s->flags;
            }
        }
    }
    if (current_floor_enemy_set_rows != 0) {
        EnemySetRecord *s = current_floor_enemy_set_rows;
        FloorSavedSetRow *d = area->enemy_rows;
        s32 i;
        for (i = 0; i < area->enemy_count; i++, s++, d++) {
            if (s->placement.id == d->id) {
                d->flags = s->flags;
            }
        }
    }
    if (current_floor_enemy_set_rows != 0) {
        safe_free(current_floor_enemy_set_rows);
        current_floor_enemy_set_rows = 0;
    }
    if (current_floor_object_set_rows != 0) {
        safe_free(current_floor_object_set_rows);
        current_floor_object_set_rows = 0;
    }
}

void free_item_drop_tables() {
    if (enemy_state_records != NULL) {
        safe_free(enemy_state_records);
        enemy_state_records = NULL;
    }
    if (quest_object_entries != NULL) {
        safe_free(quest_object_entries);
        quest_object_entries = NULL;
    }
    if (floor_saved_row_heap != NULL) {
        delete floor_saved_row_heap;
        floor_saved_row_heap = NULL;
    }
    if (floor_set_archive_pool != NULL) {
        delete floor_set_archive_pool;
        floor_set_archive_pool = NULL;
    }
    if (enemy_set_row_buffer != NULL) {
        safe_free(enemy_set_row_buffer);
        enemy_set_row_buffer = NULL;
    }
    if (object_set_row_buffer != NULL) {
        safe_free(object_set_row_buffer);
        object_set_row_buffer = NULL;
    }
}

void arrive_floor_population() {
    s32 index;
    LobbyFloorRows *floor;
    saddr bytes;
    FloorObjectSetRow *o;
    FloorSavedSetRow *r;
    s32 i;
    EnemySetRecord *e;
    FloorSavedSetRow *r2;
    s32 j;
    current_floor_object_set_rows = 0;
    current_floor_enemy_set_rows = 0;
    current_floor_object_set_count = 0;
    current_floor_enemy_set_count = 0;
    index = get_current_floor();
    floor = &floor_enemy_group_table[index];
    bytes = floor->object_count * 0x44;
    if (bytes > 0) {
        bytes = (bytes + 0x1F) & ~0x1F;
        current_floor_object_set_rows = (FloorObjectSetRow *)TQuestVmDownLoadServer::alloc(bytes);
    }
    if (current_floor_object_set_rows != NULL) {
        floor_set_archive_pool->transfer(floor_set_archives[index].objects, current_floor_object_set_rows, bytes, 1);
        o = current_floor_object_set_rows;
        r = floor->object_rows;
        for (i = 0; i < floor->object_count; i++, o++, r++) {
            if (o->placement.entity_id == r->id) {
                o->flags = r->flags;
            }
        }
        floor->object_placement &= ~2U;
        current_floor_object_set_count = floor->object_count;
    }
    bytes = floor->enemy_count * 0x48;
    if (bytes > 0) {
        bytes = (bytes + 0x1F) & ~0x1F;
        current_floor_enemy_set_rows = (EnemySetRecord *)TQuestVmDownLoadServer::alloc(bytes);
    }
    if (current_floor_enemy_set_rows != NULL) {
        floor_set_archive_pool->transfer(floor_set_archives[index].enemies, current_floor_enemy_set_rows, bytes, 1);
        e = current_floor_enemy_set_rows;
        r2 = floor->enemy_rows;
        for (j = 0; j < floor->enemy_count; j++, e++, r2++) {
            if (e->placement.id == r2->id) {
                e->flags = r2->flags;
            }
        }
        floor->enemy_placement &= ~4U;
        current_floor_enemy_set_count = floor->enemy_count;
    }
}

void init_item_drop_tables(void) {
    s32 i;
    s32 k;

    floor_set_flags = 0;
    object_set_row_buffer = 0;
    enemy_set_row_buffer = 0;
    floor_set_archive_pool = 0;
    floor_saved_row_heap = 0;
    floor_set_archive_pool = new AramPool(item_drop_memory_pool_ar_addr, item_drop_memory_pool_size, 0x40);
    for (i = 0; i < 18; i++) {
        floor_set_archives[i].objects = NULL;
        floor_set_archives[i].enemies = NULL;
    }
    floor_saved_row_heap = new THeap(0xA000, 0x20);
    memset(floor_enemy_group_table, 0, 0x1B0);
    memset(floor_object_set_counts, 0, 0x48);
    memset(floor_enemy_set_counts, 0, 0x48);
    memset(TLobby__data_80513D10, 0, 0x24);
    quest_object_entries = (QuestObjectEntry *)TQuestVmDownLoadServer__sub_8007EBDC(0xBA0, 4);
    enemy_state_records = (EnemyStateRecord *)TQuestVmDownLoadServer__sub_8007EBDC(0xB50, 0xC);
    k = 0;
    for (i = 0; i < 0xBA0; i++) {
        quest_object_entries[i].drop_id_base = k++ + 0x100;
    }
    for (i = 0; i < 0xB50; i++) {
        enemy_state_records[i].drop_id = k++ + 0x100;
    }
    object_condition_count = 0;
    enemy_condition_count = 0;
    floor_decoration_rows = 0;
    floor_decoration_rows_b = NULL;
    floor_decoration_row_count = 0;
    floor_decoration_row_count_b = 0;
    lbl_805D6100 = 0;
}

void free_item_drop_memory_pool() {  }

void alloc_item_drop_memory_pool() {
    item_drop_memory_pool_size = 0x100000;
    item_drop_memory_pool_ar_addr = ARAlloc(0x100000);
}

extern "C" {

EnemySetRecord *get_loaded_enemy_set_rows() { return current_floor_enemy_set_rows; }

FloorObjectSetRow *get_loaded_object_set_rows() { return current_floor_object_set_rows; }

}
