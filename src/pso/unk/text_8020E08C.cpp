#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
struct ObjRow_8020E08C { s16 type; s16 flags; u8 pad04[4]; u16 id; u8 tail[0x44 - 0xA]; };

struct EneRow_8020E08C { s16 type; s16 flags; u8 pad04[6]; u16 id; u8 tail[0x48 - 0xC]; };

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

struct Rec4_8020E228 { u16 a; u16 id; };
struct Rec12_8020E228 { u32 a; u16 id; u16 b; u32 c; };
extern "C" {
s32 get_current_floor(void);
Archive_8020E08C TLobby__data_80513A40[18];
Floor_8020E08C TLobby__floor_enemy_group_table[18];
u32 TLobby__data_80513C80[18];
u32 TLobby__data_80513CC8[18];
u32 TLobby__data_80513D10[9];
void *alloc__23TAdSinglePlyChrSelectGCFv(s32);
void *TQuestVmDownLoadServer__sub_8007EBDC(s32, s32);
void *__ct__5THeapFUli(void *, u32, s32);
void *__nw__5THeapFUl(u32);
void *memset(void *, int, u32);
}
extern void *TLobby__data_805D6104;
extern ObjRow_8020E08C *TLobby__data_805D610C;
extern EneRow_8020E08C *TLobby__data_805D6114;
extern s32 TLobby__current_floor_object_set_count;
extern s32 TLobby__current_floor_enemy_set_count;
void arrive_floor_population(void);
void arrive_floor_population(void) {
    s32 index;
    Floor_8020E08C *floor;
    s32 bytes;
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
        TLobby__data_805D610C = (ObjRow_8020E08C *)((TQuestVmDownLoadServer *)bytes)->alloc();
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
        TLobby__data_805D6114 = (EneRow_8020E08C *)((TQuestVmDownLoadServer *)bytes)->alloc();
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

extern s32 lbl_805D6100;
extern void *TLobby__data_805D6108;
extern s32 TLobby__data_805D611C;
extern s32 TLobby__data_805D6120;
extern s32 TLobby__data_805D6124;
extern s32 TLobby__data_805D6128;
extern s32 item_drop_memory_pool_ar_addr;
extern s32 item_drop_memory_pool_size;
extern s16 TLobby__data_805D6134;
extern s32 TLobby__data_805D6138;
extern s32 TLobby__data_805D613C;
extern Rec4_8020E228 *quest_object_entries;
extern Rec12_8020E228 *TLobby__data_805D6144;
extern s32 TLobby__data_805D6148;
extern s32 TLobby__data_805D614C;

void init_item_drop_tables(void) {
    s32 i;
    s32 k;
    void *p;

    TLobby__data_805D6134 = 0;
    TLobby__data_805D6138 = 0;
    TLobby__data_805D613C = 0;
    TLobby__data_805D6104 = 0;
    TLobby__data_805D6108 = 0;
    p = alloc__23TAdSinglePlyChrSelectGCFv(0x30);
    if (p != NULL) {
        p = ((TLobby *)p)->init_memory_pool(item_drop_memory_pool_ar_addr, item_drop_memory_pool_size, 0x40);
    }
    TLobby__data_805D6104 = p;
    for (i = 0; i < 18; i++) {
        TLobby__data_80513A40[i].objects = NULL;
        TLobby__data_80513A40[i].enemies = NULL;
    }
    p = __nw__5THeapFUl(0x14);
    if (p != NULL) {
        p = __ct__5THeapFUli(p, 0xA000, 0x20);
    }
    TLobby__data_805D6108 = p;
    memset(TLobby__floor_enemy_group_table, 0, 0x1B0);
    memset(TLobby__data_80513C80, 0, 0x48);
    memset(TLobby__data_80513CC8, 0, 0x48);
    memset(TLobby__data_80513D10, 0, 0x24);
    quest_object_entries = (Rec4_8020E228 *)TQuestVmDownLoadServer__sub_8007EBDC(0xBA0, 4);
    TLobby__data_805D6144 = (Rec12_8020E228 *)TQuestVmDownLoadServer__sub_8007EBDC(0xB50, 0xC);
    k = 0;
    for (i = 0; i < 0xBA0; i++) {
        quest_object_entries[i].id = k++ + 0x100;
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
