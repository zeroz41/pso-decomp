#include "pso/unk/TLobby_80207644.h"
#include "pso/map/MapSetArchive.h"
#include "pso/map/FloorPopulation.h"
#include "pso/system/ResourceFile.h"
#include "pso/map/TSetManager.h"
#include "types.h"
#include <string.h>

#pragma readonly_strings on
#include "pso/map/TSetManager_8020D918.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/unk/TLobby_801F3A24.h"
#include "pso/unk/TLobby_8020E3BC.h"
#include "pso/system/THeap.h"
#include "pso/system/scene/TScene.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TMainTask.h"

extern "C" {
extern "C" void apply_floor_set_rows__11TSetManagerFv();
extern "C" void update_decoration_spawning__11TSetManagerFv();
void *set_manager_task_pmf_table[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&apply_floor_set_rows__11TSetManagerFv,
};
void *lbl_804C9454[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_decoration_spawning__11TSetManagerFv,
};
void *lbl_804C9460[6] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
}
struct Rec12_8020E228 { u32 a; u16 id; u16 b; u32 c; };

s32 lbl_805D60F8;
s32 TLobby__data_805D60FC;
s32 lbl_805D6100;
void *TLobby__data_805D6104;
THeap *TLobby__data_805D6108;
FloorObjectSetRow *TLobby__data_805D610C;
s32 TLobby__current_floor_object_set_count;
EnemySetRecord *TLobby__data_805D6114;
s32 TLobby__current_floor_enemy_set_count;
FloorObjectSetRow *floor_decoration_rows;
s32 TLobby__data_805D6120;
uaddr TLobby__data_805D6124;
s32 TLobby__data_805D6128;
s32 item_drop_memory_pool_ar_addr;
s32 item_drop_memory_pool_size;
s16 TLobby__data_805D6134;
FloorObjectSetRow *TLobby__data_805D6138;
EnemySetRecord *TLobby__data_805D613C;
QuestObjectEntry *quest_object_entries;
Rec12_8020E228 *TLobby__data_805D6144;
s32 TLobby__data_805D6148;
s32 TLobby__data_805D614C;

void TSetManager__sub_8020D7D4(void) {  }
typedef void (TSetManager::*Pmf_8020D7D8)();

void TSetManager::run_task() {
    static s8 init;
    if (!init) {
        ((Pmf_8020D7D8 *)lbl_804C9460)[0] = *(Pmf_8020D7D8 *)set_manager_task_pmf_table;
        ((Pmf_8020D7D8 *)lbl_804C9460)[1] = *(Pmf_8020D7D8 *)lbl_804C9454;
        init = 1;
    }
    (this->*((Pmf_8020D7D8 *)lbl_804C9460)[*(s32 *)((u8 *)this + 0x1C)])();
    ((void (*)(void *))TSetManager__sub_8020D7D4)(this);
}

TSetManager::~TSetManager() {}

extern "C" {

void __ct__7TObjectFP7TObject(void *, void *);

extern s32 __vt__11TSetManager[];
const char *lbl_805D3638 = "TSetManager";

void *TSetManager__ct(void *set_manager, void *parent) {
    __ct__7TObjectFP7TObject(set_manager, parent);
    *(s32 **)((s8 *)set_manager + 0x18) = __vt__11TSetManager;
    ((TSetManager *)set_manager)->m_name = lbl_805D3638;
    *(u32 *)((s8 *)set_manager + 0x1C) = 0;
    return set_manager;
}

}

extern "C" {
s32 get_current_floor(void);
LobbyPoolEntry TLobby__data_80513A40[18];
LobbyFloorRows TLobby__floor_enemy_group_table[18];
s32 TLobby__data_80513C80[18];
s32 TLobby__data_80513CC8[18];
u32 TLobby__data_80513D10[9];
#pragma push
#pragma force_active on
u8 lbl_80513D34[0x24];
#pragma pop
void archive_pool_free(void *pool, void *node);
s32 replace_file_extension__6TLobbyFPvPvPv(char *arg0, char *arg1, char *arg2);
void *mem_alloc(u32);
}
void arrive_floor_population(void);
void swap_object_row_endian(void *);
extern const char lbl_8044BC24[7] = "ad.dat";
extern const char lbl_8044BC2C[6] = "d.dat";
s32 load_map_decoration_rows(s32 map, s32 grp, s32 room);
extern "C" {
void* __nw__7TObjectFUl(u32);
void mem_free(void*);


void TSetManager::create() {
    void* obj = TObject::operator new(0x20);
    if (obj != 0) {
        TSetManager__ct(obj, tl_02);
    }
}

void TLobby__sub_8020D94C(void) {
    if (floor_decoration_rows != NULL) {
        mem_free(floor_decoration_rows);
        floor_decoration_rows = NULL;
        TLobby__data_805D6120 = 0;
    }
    if ((u32) TLobby__data_805D6124 != 0U) {
        mem_free((void*)TLobby__data_805D6124);
        TLobby__data_805D6124 = 0U;
        TLobby__data_805D6128 = 0;
    }
}
}

s32 load_map_decoration_rows(s32 map, s32 grp, s32 room) {
    MapSetEntry *r;
    s32 i;
    s32 size;
    char path[0x20];
    if (TLobby__data_805D6068[map].variants == NULL || TLobby__data_805D6068[map].count - 1 < grp) {
        return 0;
    }
    r = TLobby__data_805D6068[map].variants[grp].entries;
    if (r == NULL || TLobby__data_805D6068[map].variants[grp].count - 1 < room) {
        return 0;
    }
    if (TLobby::is_online_ready() != 0) {
        replace_file_extension__6TLobbyFPvPvPv((char *)path, (char *)r->decoration_set_name, (char *)lbl_8044BC24);
    } else {
        replace_file_extension__6TLobbyFPvPvPv((char *)path, (char *)r->decoration_set_name, (char *)lbl_8044BC2C);
    }
    size = get_resource_file_size((const char *)path);
    if (size < 0) {
        return 0;
    }
    TLobby__data_805D6120 = (u32)size / sizeof(FloorObjectSetRow);
    if ((floor_decoration_rows = static_cast<FloorObjectSetRow *>(mem_alloc(TLobby__data_805D6120 * sizeof(FloorObjectSetRow)))) == 0) {
        return 0;
    }
    read_disc_file(path, floor_decoration_rows);
    for (i = 0; i < TLobby__data_805D6120; i++) {
        swap_object_row_endian(&floor_decoration_rows[i]);
        floor_decoration_rows[i].flags = 0;
        floor_decoration_rows[i].placement.entity_id = 0xFFFF;
        floor_decoration_rows[i].placement.object_type = -1;
    }
    return 1;
}

#pragma push
#pragma scheduling off

void TLobby::clear_floor_flags_and_depart() {
    s32 unused;
    TLobby__sub_8020D94C();
    unused = TLobby__data_805D6134 & ~8;
    TLobby__data_805D6134 = unused;
    TLobby__data_805D6134 &= ~16;
    depart_floor_population(unused);
}
#pragma pop

void TLobby::setup_floor_decorations() {
    FloorMapSelection v;
    saddr r;
    arrive_floor_population();
    floor_decoration_rows = NULL;
    TLobby__data_805D6134 &= ~8;
    (*(saddr *)&TLobby__data_805D6124) = 0;
    TLobby__data_805D6120 = 0;
    TLobby__data_805D6128 = 0;
    TLobby__data_805D6134 &= ~16;
    lbl_805D60F8 = get_current_floor_area();
    r = get_current_floor();
    TLobby__data_805D60FC = r;
    if (lookup_floor_map_selection(r, &v) != 0) {
        load_map_decoration_rows(v.area, v.terrain, v.entities);
        return;
    }
    lbl_805D60F8 = -1;
}

void TLobby::reset_id_tables() {
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
            TLobby__data_805D6144[i].id = t;
        }
    }
}

// inferred: clears the set object and enemy rows and frees every floor's enemy and object arrays; a lobby area reload callback
void clear_floor_population(void) {
    s32 n;
    s32 i;
    TLobby__data_805D6134 = 0;
    if (TLobby__data_805D6138 != NULL) {
        memset(TLobby__data_805D6138, 0, 0xBA0 * sizeof(FloorObjectSetRow));
        for (i = 0; i < 0xBA0; i++) {
            TLobby__data_805D6138[i].type = -1;
        }
    }
    if (TLobby__data_805D613C != NULL) {
        memset(TLobby__data_805D613C, 0, 0x5A8 * sizeof(EnemySetRecord));
        for (i = 0; i < 0x5A8; i++) {
            TLobby__data_805D613C[i].type = -1;
        }
    }
    memset(TLobby__data_80513C80, 0, sizeof(TLobby__data_80513C80));
    memset(TLobby__data_80513CC8, 0, sizeof(TLobby__data_80513CC8));
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
            TLobby__data_805D6144[i].id = n++ + 0x100;
        }
    }
    TLobby__data_805D6148 = 0;
    TLobby__data_805D614C = 0;
    floor_decoration_rows = 0;
    TLobby__data_805D6124 = 0;
    TLobby__data_805D6120 = 0;
    TLobby__data_805D6128 = 0;
    lbl_805D6100 = 0;
    for (s32 i = 17; i >= 0; i--) {
        if (TLobby__data_80513A40[i].enemies != NULL) {
            archive_pool_free(TLobby__data_805D6104, TLobby__data_80513A40[i].enemies);
            TLobby__data_80513A40[i].enemies = NULL;
        }
    }
    for (s32 i = 17; i >= 0; i--) {
        if (TLobby__data_80513A40[i].objects != NULL) {
            archive_pool_free(TLobby__data_805D6104, TLobby__data_80513A40[i].objects);
            TLobby__data_80513A40[i].objects = NULL;
        }
    }
    for (s32 i = 17; i >= 0; i--) {
        if (TLobby__floor_enemy_group_table[i].enemy_rows != NULL) {
            TLobby__data_805D6108->heap_free(TLobby__floor_enemy_group_table[i].enemy_rows);
            TLobby__floor_enemy_group_table[i].enemy_rows = NULL;
        }
    }
    for (s32 i = 17; i >= 0; i--) {
        if (TLobby__floor_enemy_group_table[i].object_rows != NULL) {
            TLobby__data_805D6108->heap_free(TLobby__floor_enemy_group_table[i].object_rows);
            TLobby__floor_enemy_group_table[i].object_rows = NULL;
        }
    }
    memset(TLobby__floor_enemy_group_table, 0, sizeof(TLobby__floor_enemy_group_table));
}

void depart_floor_population(int unused) {
    LobbyFloorRows *area = &TLobby__floor_enemy_group_table[get_current_floor()];
    if (TLobby__data_805D610C != 0) {
        FloorObjectSetRow *s = TLobby__data_805D610C;
        FloorSavedSetRow *d = area->object_rows;
        s32 i;
        for (i = 0; i < area->object_count; i++, s++, d++) {
            if (s->placement.entity_id == d->id) {
                d->flags = s->flags;
            }
        }
    }
    if (TLobby__data_805D6114 != 0) {
        EnemySetRecord *s = TLobby__data_805D6114;
        FloorSavedSetRow *d = area->enemy_rows;
        s32 i;
        for (i = 0; i < area->enemy_count; i++, s++, d++) {
            if (s->id == d->id) {
                d->flags = s->flags;
            }
        }
    }
    if (TLobby__data_805D6114 != 0) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)TLobby__data_805D6114);
        TLobby__data_805D6114 = 0;
    }
    if (TLobby__data_805D610C != 0) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)TLobby__data_805D610C);
        TLobby__data_805D610C = 0;
    }
}

void TLobby::free_resources() {
    if (TLobby__data_805D6144 != NULL) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)TLobby__data_805D6144);
        TLobby__data_805D6144 = NULL;
    }
    if (quest_object_entries != NULL) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)quest_object_entries);
        quest_object_entries = NULL;
    }
    if (TLobby__data_805D6108 != NULL) {
        delete TLobby__data_805D6108;
        TLobby__data_805D6108 = NULL;
    }
    if (TLobby__data_805D6104 != NULL) {
        TLobby::free_and_delete((u32 *)TLobby__data_805D6104, 1);
        TLobby__data_805D6104 = NULL;
    }
    if (TLobby__data_805D613C != NULL) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)TLobby__data_805D613C);
        TLobby__data_805D613C = NULL;
    }
    if (TLobby__data_805D6138 != NULL) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)TLobby__data_805D6138);
        TLobby__data_805D6138 = NULL;
    }
}

extern "C" {
void *TQuestVmDownLoadServer__sub_8007EBDC(s32, s32);
}
void arrive_floor_population(void) {
    s32 index;
    LobbyFloorRows *floor;
    saddr bytes;
    FloorObjectSetRow *o;
    FloorSavedSetRow *r;
    s32 i;
    EnemySetRecord *e;
    FloorSavedSetRow *r2;
    s32 j;
    TLobby__data_805D610C = 0;
    TLobby__data_805D6114 = 0;
    TLobby__current_floor_object_set_count = 0;
    TLobby__current_floor_enemy_set_count = 0;
    index = get_current_floor();
    floor = &TLobby__floor_enemy_group_table[index];
    bytes = floor->object_count * 0x44;
    if (bytes > 0) {
        bytes = (bytes + 0x1F) & ~0x1F;
        TLobby__data_805D610C = (FloorObjectSetRow *)TQuestVmDownLoadServer::alloc(bytes);
    }
    if (TLobby__data_805D610C != NULL) {
        TLobby::send_or_handle_packet((void *)TLobby__data_805D6104, TLobby__data_80513A40[index].objects, (void *)TLobby__data_805D610C, (void *)bytes, (u32)1);
        o = TLobby__data_805D610C;
        r = floor->object_rows;
        for (i = 0; i < floor->object_count; i++, o++, r++) {
            if (o->placement.entity_id == r->id) {
                o->flags = r->flags;
            }
        }
        floor->object_placement &= ~2U;
        TLobby__current_floor_object_set_count = floor->object_count;
    }
    bytes = floor->enemy_count * 0x48;
    if (bytes > 0) {
        bytes = (bytes + 0x1F) & ~0x1F;
        TLobby__data_805D6114 = (EnemySetRecord *)TQuestVmDownLoadServer::alloc(bytes);
    }
    if (TLobby__data_805D6114 != NULL) {
        TLobby::send_or_handle_packet((void *)TLobby__data_805D6104, TLobby__data_80513A40[index].enemies, (void *)TLobby__data_805D6114, (void *)bytes, (u32)1);
        e = TLobby__data_805D6114;
        r2 = floor->enemy_rows;
        for (j = 0; j < floor->enemy_count; j++, e++, r2++) {
            if (e->id == r2->id) {
                e->flags = r2->flags;
            }
        }
        floor->enemy_placement &= ~4U;
        TLobby__current_floor_enemy_set_count = floor->enemy_count;
    }
}

void init_item_drop_tables(void) {
    s32 i;
    s32 k;
    void *p;

    TLobby__data_805D6134 = 0;
    TLobby__data_805D6138 = 0;
    TLobby__data_805D613C = 0;
    TLobby__data_805D6104 = 0;
    TLobby__data_805D6108 = 0;
    p = ::operator new(0x30);
    if (p != NULL) {
        p = ((TLobby *)p)->init_memory_pool(item_drop_memory_pool_ar_addr, item_drop_memory_pool_size, 0x40);
    }
    TLobby__data_805D6104 = p;
    for (i = 0; i < 18; i++) {
        TLobby__data_80513A40[i].objects = NULL;
        TLobby__data_80513A40[i].enemies = NULL;
    }
    TLobby__data_805D6108 = new THeap(0xA000, 0x20);
    memset(TLobby__floor_enemy_group_table, 0, 0x1B0);
    memset(TLobby__data_80513C80, 0, 0x48);
    memset(TLobby__data_80513CC8, 0, 0x48);
    memset(TLobby__data_80513D10, 0, 0x24);
    quest_object_entries = (QuestObjectEntry *)TQuestVmDownLoadServer__sub_8007EBDC(0xBA0, 4);
    TLobby__data_805D6144 = (Rec12_8020E228 *)TQuestVmDownLoadServer__sub_8007EBDC(0xB50, 0xC);
    k = 0;
    for (i = 0; i < 0xBA0; i++) {
        quest_object_entries[i].drop_id_base = k++ + 0x100;
    }
    for (i = 0; i < 0xB50; i++) {
        TLobby__data_805D6144[i].id = k++ + 0x100;
    }
    TLobby__data_805D6148 = 0;
    TLobby__data_805D614C = 0;
    floor_decoration_rows = 0;
    TLobby__data_805D6124 = 0;
    TLobby__data_805D6120 = 0;
    TLobby__data_805D6128 = 0;
    lbl_805D6100 = 0;
}

extern "C" {

s32 ARAlloc(s32);

void TLobby__sub_8020E3BC(void) {  }

void TLobby__sub_8020E3C0(void) {
    item_drop_memory_pool_size = 0x100000;
    item_drop_memory_pool_ar_addr = ARAlloc(0x100000);
}

EnemySetRecord *get_loaded_enemy_set_rows() { return TLobby__data_805D6114; }

FloorObjectSetRow *get_loaded_object_set_rows() { return TLobby__data_805D610C; }

}
