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
struct ObjRow_8020E08C { s16 type; s16 flags; u8 pad04[4]; u16 id; u8 tail[0x44 - 0xA]; };

struct EneRow_8020E08C { s16 type; s16 flags; u8 pad04[6]; u16 id; u8 tail[0x48 - 0xC]; };

struct Rec12_8020E228 { u32 a; u16 id; u16 b; u32 c; };

s32 lbl_805D60F8;
s32 TLobby__data_805D60FC;
s32 lbl_805D6100;
void *TLobby__data_805D6104;
THeap *TLobby__data_805D6108;
ObjRow_8020E08C *TLobby__data_805D610C;
s32 TLobby__current_floor_object_set_count;
EneRow_8020E08C *TLobby__data_805D6114;
s32 TLobby__current_floor_enemy_set_count;
uaddr TLobby__data_805D611C;
s32 TLobby__data_805D6120;
uaddr TLobby__data_805D6124;
s32 TLobby__data_805D6128;
s32 item_drop_memory_pool_ar_addr;
s32 item_drop_memory_pool_size;
s16 TLobby__data_805D6134;
ObjRow_8020E08C *TLobby__data_805D6138;
EneRow_8020E08C *TLobby__data_805D613C;
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

struct Saved_8020E08C { u16 id; s16 flags; s16 room; s16 wave; };

struct Floor_8020E08C {
    s32 objects;
    s32 enemies;
    u32 objectPlacement;
    u32 enemyPlacement;
    Saved_8020E08C *objectRows;
    Saved_8020E08C *enemyRows;
};

struct Archive_8020E08C { void *objects; void *enemies; };

struct Vec3_8020DB44 { s32 a, b, c; };

struct Room_8020D9A0 { u8 pad0[8]; s32 name; };

struct Grp_8020D9A0 { Room_8020D9A0 *room; s32 count; };

struct Map_8020D9A0 { Grp_8020D9A0 *grp; s32 count; };

struct Rec_8020D9A0 { u8 pad0[2]; s16 f2; s16 f4; u8 pad6[2]; u16 f8; u8 padA[0x3A]; };

extern "C" {
s32 get_current_floor(void);
Archive_8020E08C TLobby__data_80513A40[18];
Floor_8020E08C TLobby__floor_enemy_group_table[18];
u32 TLobby__data_80513C80[18];
u32 TLobby__data_80513CC8[18];
u32 TLobby__data_80513D10[9];
#pragma push
#pragma force_active on
u8 lbl_80513D34[0x24];
#pragma pop
void archive_pool_free(void *pool, void *node);
s32 lookup_scene_object__6TLobbyFPv(s32, void *);
void *mem_alloc(u32);
}
void arrive_floor_population(void);
void swap_object_row_endian(void *);
extern const char lbl_8044BC24[7] = "ad.dat";
extern const char lbl_8044BC2C[6] = "d.dat";
extern Map_8020D9A0 *TLobby__data_805D6068;
s32 load_map_decoration_rows(s32 map, s32 grp, s32 room);
extern "C" {
void* __nw__7TObjectFUl(u32);
void mem_free(void*);

extern void *tl_02;

void TSetManager::create() {
    void* obj = TObject::operator new(0x20);
    if (obj != 0) {
        TSetManager__ct(obj, tl_02);
    }
}

void TLobby__sub_8020D94C(void) {
    if ((u32) TLobby__data_805D611C != 0U) {
        mem_free((void*)TLobby__data_805D611C);
        TLobby__data_805D611C = 0U;
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
    Room_8020D9A0 *r;
    s32 i;
    s32 size;
    char path[0x20];
    if (TLobby__data_805D6068[map].grp == NULL || TLobby__data_805D6068[map].count - 1 < grp) {
        return 0;
    }
    r = TLobby__data_805D6068[map].grp[grp].room;
    if (r == NULL || TLobby__data_805D6068[map].grp[grp].count - 1 < room) {
        return 0;
    }
    if (TLobby::is_online_ready() != 0) {
        TLobby::replace_file_extension((char *)path, (char *)r->name, (char *)lbl_8044BC24);
    } else {
        TLobby::replace_file_extension((char *)path, (char *)r->name, (char *)lbl_8044BC2C);
    }
    size = get_resource_file_size((const char *)path);
    if (size < 0) {
        return 0;
    }
    TLobby__data_805D6120 = (u32)size / 0x44;
    if ((TLobby__data_805D611C = (uaddr)mem_alloc(TLobby__data_805D6120 * 0x44)) == 0) {
        return 0;
    }
    read_disc_file(path, (void *)TLobby__data_805D611C);
    for (i = 0; i < TLobby__data_805D6120; i++) {
        swap_object_row_endian(&((Rec_8020D9A0 *)TLobby__data_805D611C)[i]);
        ((Rec_8020D9A0 *)TLobby__data_805D611C)[i].f2 = 0;
        ((Rec_8020D9A0 *)TLobby__data_805D611C)[i].f8 = 0xFFFF;
        ((Rec_8020D9A0 *)TLobby__data_805D611C)[i].f4 = -1;
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
    Vec3_8020DB44 v;
    saddr r;
    arrive_floor_population();
    (*(s32 *)&TLobby__data_805D611C) = 0;
    TLobby__data_805D6134 &= ~8;
    (*(saddr *)&TLobby__data_805D6124) = 0;
    TLobby__data_805D6120 = 0;
    TLobby__data_805D6128 = 0;
    TLobby__data_805D6134 &= ~16;
    lbl_805D60F8 = get_current_floor_area();
    r = get_current_floor();
    TLobby__data_805D60FC = r;
    if (lookup_scene_object__6TLobbyFPv(r, &v) != 0) {
        load_map_decoration_rows(v.a, v.b, v.c);
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
        memset(TLobby__data_805D6138, 0, 0xBA0 * sizeof(ObjRow_8020E08C));
        for (i = 0; i < 0xBA0; i++) {
            TLobby__data_805D6138[i].type = -1;
        }
    }
    if (TLobby__data_805D613C != NULL) {
        memset(TLobby__data_805D613C, 0, 0x5A8 * sizeof(EneRow_8020E08C));
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
    TLobby__data_805D611C = 0;
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
        if (TLobby__floor_enemy_group_table[i].enemyRows != NULL) {
            TLobby__data_805D6108->heap_free(TLobby__floor_enemy_group_table[i].enemyRows);
            TLobby__floor_enemy_group_table[i].enemyRows = NULL;
        }
    }
    for (s32 i = 17; i >= 0; i--) {
        if (TLobby__floor_enemy_group_table[i].objectRows != NULL) {
            TLobby__data_805D6108->heap_free(TLobby__floor_enemy_group_table[i].objectRows);
            TLobby__floor_enemy_group_table[i].objectRows = NULL;
        }
    }
    memset(TLobby__floor_enemy_group_table, 0, sizeof(TLobby__floor_enemy_group_table));
}

void depart_floor_population(int unused) {
    Floor_8020E08C *area = &TLobby__floor_enemy_group_table[get_current_floor()];
    if (TLobby__data_805D610C != 0) {
        ObjRow_8020E08C *s = TLobby__data_805D610C;
        Saved_8020E08C *d = area->objectRows;
        s32 i;
        for (i = 0; i < area->objects; i++, s++, d++) {
            if (s->id == d->id) {
                d->flags = s->flags;
            }
        }
    }
    if (TLobby__data_805D6114 != 0) {
        EneRow_8020E08C *s = TLobby__data_805D6114;
        Saved_8020E08C *d = area->enemyRows;
        s32 i;
        for (i = 0; i < area->enemies; i++, s++, d++) {
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
    Floor_8020E08C *floor;
    saddr bytes;
    ObjRow_8020E08C *o;
    Saved_8020E08C *r;
    s32 i;
    EneRow_8020E08C *e;
    Saved_8020E08C *r2;
    s32 j;
    TLobby__data_805D610C = 0;
    TLobby__data_805D6114 = 0;
    TLobby__current_floor_object_set_count = 0;
    TLobby__current_floor_enemy_set_count = 0;
    index = get_current_floor();
    floor = &TLobby__floor_enemy_group_table[index];
    bytes = floor->objects * 0x44;
    if (bytes > 0) {
        bytes = (bytes + 0x1F) & ~0x1F;
        TLobby__data_805D610C = (ObjRow_8020E08C *)TQuestVmDownLoadServer::alloc(bytes);
    }
    if (TLobby__data_805D610C != NULL) {
        TLobby::send_or_handle_packet((void *)TLobby__data_805D6104, TLobby__data_80513A40[index].objects, (void *)TLobby__data_805D610C, (void *)bytes, (u32)1);
        o = TLobby__data_805D610C;
        r = floor->objectRows;
        for (i = 0; i < floor->objects; i++, o++, r++) {
            if (o->id == r->id) {
                o->flags = r->flags;
            }
        }
        floor->objectPlacement &= ~2U;
        TLobby__current_floor_object_set_count = floor->objects;
    }
    bytes = floor->enemies * 0x48;
    if (bytes > 0) {
        bytes = (bytes + 0x1F) & ~0x1F;
        TLobby__data_805D6114 = (EneRow_8020E08C *)TQuestVmDownLoadServer::alloc(bytes);
    }
    if (TLobby__data_805D6114 != NULL) {
        TLobby::send_or_handle_packet((void *)TLobby__data_805D6104, TLobby__data_80513A40[index].enemies, (void *)TLobby__data_805D6114, (void *)bytes, (u32)1);
        e = TLobby__data_805D6114;
        r2 = floor->enemyRows;
        for (j = 0; j < floor->enemies; j++, e++, r2++) {
            if (e->id == r2->id) {
                e->flags = r2->flags;
            }
        }
        floor->enemyPlacement &= ~4U;
        TLobby__current_floor_enemy_set_count = floor->enemies;
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
    TLobby__data_805D611C = 0;
    TLobby__data_805D6124 = 0;
    TLobby__data_805D6120 = 0;
    TLobby__data_805D6128 = 0;
    lbl_805D6100 = 0;
}

extern "C" {

s32 Dolphin_ARAlloc(s32);

void TLobby__sub_8020E3BC(void) {  }

void TLobby__sub_8020E3C0(void) {
    item_drop_memory_pool_size = 0x100000;
    item_drop_memory_pool_ar_addr = Dolphin_ARAlloc(0x100000);
}

saddr TLobby::get_matching_object() {  return (saddr)TLobby__data_805D6114; }

saddr TLobby::get_object_count() {  return (saddr)TLobby__data_805D610C; }

}
