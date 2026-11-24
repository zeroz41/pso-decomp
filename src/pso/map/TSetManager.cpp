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
#include "pso/unk/TLobby.h"
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
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"

s32 active_set_floor_area;
s32 active_set_floor;
s32 lbl_805D6100;
void *floor_set_archive_pool;
THeap *floor_saved_row_heap;
FloorObjectSetRow *current_floor_object_set_rows;
s32 current_floor_object_set_count;
EnemySetRecord *current_floor_enemy_set_rows;
s32 current_floor_enemy_set_count;
FloorObjectSetRow *floor_decoration_rows;
s32 floor_decoration_row_count;
void *TLobby__data_805D6124;
s32 TLobby__data_805D6128;
s32 item_drop_memory_pool_ar_addr;
s32 item_drop_memory_pool_size;
s16 floor_set_flags;
FloorObjectSetRow *object_set_row_buffer;
EnemySetRecord *enemy_set_row_buffer;
QuestObjectEntry *quest_object_entries;
EnemyStateRecord *TLobby__data_805D6144;
s32 object_condition_count;
s32 enemy_condition_count;

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
extern "C" {
void archive_pool_free(void *pool, void *node);
}
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
    if (TLobby__data_805D6124 != NULL) {
        mem_free(TLobby__data_805D6124);
        TLobby__data_805D6124 = NULL;
        TLobby__data_805D6128 = 0;
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
        TLobby::replace_file_extension((char *)path, (char *)r->decoration_set_name, (char *)decoration_file_suffix_online);
    } else {
        TLobby::replace_file_extension((char *)path, (char *)r->decoration_set_name, (char *)decoration_file_suffix_offline);
    }
    size = get_resource_file_size((const char *)path);
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
        floor_decoration_rows[i].placement.object_type = -1;
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
    TLobby__data_805D6124 = NULL;
    floor_decoration_row_count = 0;
    TLobby__data_805D6128 = 0;
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
    if (TLobby__data_805D6144 != 0) {
        memset(TLobby__data_805D6144, 0, 0x87C0);
        for (i = 0; i < 0xB50; i++) {
            s16 t = n + 0x100;
            n++;
            TLobby__data_805D6144[i].drop_id = t;
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
    if (TLobby__data_805D6144 != 0) {
        memset(TLobby__data_805D6144, 0, 0x87C0);
        for (i = 0; i < 0xB50; i++) {
            TLobby__data_805D6144[i].drop_id = n++ + 0x100;
        }
    }
    object_condition_count = 0;
    enemy_condition_count = 0;
    floor_decoration_rows = 0;
    TLobby__data_805D6124 = NULL;
    floor_decoration_row_count = 0;
    TLobby__data_805D6128 = 0;
    lbl_805D6100 = 0;
    for (s32 i = 17; i >= 0; i--) {
        if (floor_set_archives[i].enemies != NULL) {
            archive_pool_free(floor_set_archive_pool, floor_set_archives[i].enemies);
            floor_set_archives[i].enemies = NULL;
        }
    }
    for (s32 i = 17; i >= 0; i--) {
        if (floor_set_archives[i].objects != NULL) {
            archive_pool_free(floor_set_archive_pool, floor_set_archives[i].objects);
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
    if (TLobby__data_805D6144 != NULL) {
        safe_free(TLobby__data_805D6144);
        TLobby__data_805D6144 = NULL;
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
        TLobby::free_and_delete((u32 *)floor_set_archive_pool, 1);
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
        TLobby::send_or_handle_packet((void *)floor_set_archive_pool, floor_set_archives[index].objects, (void *)current_floor_object_set_rows, (void *)bytes, (u32)1);
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
        TLobby::send_or_handle_packet((void *)floor_set_archive_pool, floor_set_archives[index].enemies, (void *)current_floor_enemy_set_rows, (void *)bytes, (u32)1);
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
    void *p;

    floor_set_flags = 0;
    object_set_row_buffer = 0;
    enemy_set_row_buffer = 0;
    floor_set_archive_pool = 0;
    floor_saved_row_heap = 0;
    p = ::operator new(0x30);
    if (p != NULL) {
        p = ((TLobby *)p)->init_memory_pool(item_drop_memory_pool_ar_addr, item_drop_memory_pool_size, 0x40);
    }
    floor_set_archive_pool = p;
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
    TLobby__data_805D6144 = (EnemyStateRecord *)TQuestVmDownLoadServer__sub_8007EBDC(0xB50, 0xC);
    k = 0;
    for (i = 0; i < 0xBA0; i++) {
        quest_object_entries[i].drop_id_base = k++ + 0x100;
    }
    for (i = 0; i < 0xB50; i++) {
        TLobby__data_805D6144[i].drop_id = k++ + 0x100;
    }
    object_condition_count = 0;
    enemy_condition_count = 0;
    floor_decoration_rows = 0;
    TLobby__data_805D6124 = NULL;
    floor_decoration_row_count = 0;
    TLobby__data_805D6128 = 0;
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
