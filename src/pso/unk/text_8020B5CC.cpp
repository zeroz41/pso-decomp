#include "types.h"
#include "pso/unk/text_8020B5CC.h"
#include "pso/THeap.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
struct Ent_8020BB18 { u8 pad0[2]; s16 a; u8 pad1[0x3C]; u32 f40; };

struct Src_8020B970 { s16 f0; u8 pad2[6]; u16 f8; s16 fA; s16 fC; u8 padE[0x44 - 0xE]; };

struct Dst_8020B970 { u16 f0; u8 pad2[2]; s16 f4; s16 f6; };

struct Src_8020B7C4 { s16 f0; u8 pad2[8]; u16 fA; s16 fC; s16 fE; u8 pad10[0x48 - 0x10]; };

struct Tbl_8020B970 { s32 count; s32 count2; u8 pad8[8]; Dst_8020B970 *list; Dst_8020B970 *list2; };

struct Slot_8020B970 { void *entry; void *entry2; };

extern "C" {
void destroy_child_recursive__6TLobbyFPvPv(int, int);
extern Ent_8020BB18 *TLobby__data_805D611C;
extern s32 TLobby__data_805D6120;
extern s32 tl_02;
extern s32 tl_05;
extern s32 tl_06;
extern s32 tl_07;
void archive_pool_free(u32, void *);
void *archive_pool_alloc(u32, u32);
void *memcpy(void *, const void *, unsigned long);
void *memset(void *, int, unsigned long);
extern Slot_8020B970 TLobby__data_80513A40[];
extern Tbl_8020B970 TLobby__floor_enemy_group_table[];
extern u32 TLobby__data_805D6104;
extern u32 TLobby__data_805D6108;
s32 load_floor_enemy_group_entries__6TLobbyFiPvUi(s32 idx, Src_8020B970 *src, u32 size);
s32 init_quest_floor_enemies(s32 idx, Src_8020B7C4 *src, u32 size);

#pragma push
#pragma opt_propagation off
s32 init_quest_floor_enemies(s32 idx, Src_8020B7C4 *src, u32 size) {
    if (TLobby__data_805D6108 != 0 && TLobby__data_805D6104 != 0) {
    u32 sz = size;
    s32 n = (0, sz / 72);
    Tbl_8020B970 *t = &TLobby__floor_enemy_group_table[idx];
    Src_8020B7C4 *s;
    Dst_8020B970 *d;
    s32 i;
    void *buf;
    t->count2 = 0;
    s = src;
    for (i = 0; i < n; i++) {
        if (s->f0 != -1) {
            t->count2++;
        }
        s++;
    }
    t->list2 = (Dst_8020B970 *)((THeap *)TLobby__data_805D6108)->heap_alloc(t->count2 * 8);
    memset(t->list2, 0, t->count2 * 8);
    s = src;
    d = t->list2;
    for (i = 0; i < n; i++) {
        if (s->f0 != -1) {
            d->f0 = s->fA;
            d->f4 = s->fC;
            d->f6 = s->fE;
            d++;
        }
        s++;
    }
    if (TLobby__data_80513A40[idx].entry2 != NULL) {
        archive_pool_free(TLobby__data_805D6104, TLobby__data_80513A40[idx].entry2);
    }
    TLobby__data_80513A40[idx].entry2 = archive_pool_alloc(TLobby__data_805D6104, sz);
    if ((u32)src & 0x1F) {
        buf = TQuestVmDownLoadServer::alloc(sz);
        memcpy(buf, src, sz);
        if (TLobby__data_80513A40[idx].entry2 != NULL) {
            TLobby::send_or_handle_packet((void *)TLobby__data_805D6104, (void *)buf, TLobby__data_80513A40[idx].entry2, (void *)sz, (u32)0);
        }
        TAdSinglePlyChrSelectGC::safe_free((u32)buf);
    } else if (TLobby__data_80513A40[idx].entry2 != NULL) {
        TLobby::send_or_handle_packet((void *)TLobby__data_805D6104, (void *)src, TLobby__data_80513A40[idx].entry2, (void *)sz, (u32)0);
    }
    return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 load_floor_enemy_group_entries__6TLobbyFiPvUi(s32 idx, Src_8020B970 *src, u32 size) {
    if (TLobby__data_805D6108 != 0 && TLobby__data_805D6104 != 0) {
    u32 sz = size;
    s32 n = sz / 68;
    Tbl_8020B970 *t = &TLobby__floor_enemy_group_table[idx];
    Src_8020B970 *s;
    Dst_8020B970 *d;
    s32 i;
    void *buf;
    t->count = 0;
    s = src;
    for (i = 0; i < n; i++) {
        if (s->f0 != -1) {
            t->count++;
        }
        s++;
    }
    t->list = (Dst_8020B970 *)((THeap *)TLobby__data_805D6108)->heap_alloc(t->count * 8);
    memset(t->list, 0, t->count * 8);
    s = src;
    d = t->list;
    for (i = 0; i < n; i++) {
        if (s->f0 != -1) {
            d->f0 = s->f8;
            d->f4 = s->fC;
            d->f6 = s->fA;
            d++;
        }
        s++;
    }
    if (TLobby__data_80513A40[idx].entry != NULL) {
        archive_pool_free(TLobby__data_805D6104, TLobby__data_80513A40[idx].entry);
    }
    TLobby__data_80513A40[idx].entry = archive_pool_alloc(TLobby__data_805D6104, sz);
    if ((u32)src & 0x1F) {
        buf = TQuestVmDownLoadServer::alloc(sz);
        memcpy(buf, src, sz);
        if (TLobby__data_80513A40[idx].entry != NULL) {
            TLobby::send_or_handle_packet((void *)TLobby__data_805D6104, (void *)buf, TLobby__data_80513A40[idx].entry, (void *)sz, (u32)0);
        }
        TAdSinglePlyChrSelectGC::safe_free((u32)buf);
    } else if (TLobby__data_80513A40[idx].entry != NULL) {
        TLobby::send_or_handle_packet((void *)TLobby__data_805D6104, (void *)src, TLobby__data_80513A40[idx].entry, (void *)sz, (u32)0);
    }
    return 1;
    }
    return 0;
}
#pragma pop

void TLobby__sub_8020BB18(void) {
    Ent_8020BB18 *p = TLobby__data_805D611C;
    s32 i;
    for (i = 0; i < TLobby__data_805D6120; i++, p++) {
        if (p->f40 != 0) {
            destroy_child_recursive__6TLobbyFPvPv(tl_02, p->f40);
            destroy_child_recursive__6TLobbyFPvPv(tl_05, p->f40);
            destroy_child_recursive__6TLobbyFPvPv(tl_06, p->f40);
            destroy_child_recursive__6TLobbyFPvPv(tl_07, p->f40);
            p->a = 0;
            p->f40 = 0;
        }
    }
}

}
