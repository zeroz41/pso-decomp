#include "pso/unk/TLobby_80207644.h"
#include "pso/map/MapSetArchive.h"
// Area event sets: the per-floor event records (".evt" files from gsl_set_event.gsl), their
// byte swapping, sync records and the destroy-event spawn. One TU: its .rodata opens 8-aligned at
// 0x8044BAC8 after TLobby_80207DA8's padded strings, its .sbss after that unit's 4-byte pad.
#include "pso/system/ResourceFile.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/map/FloorLifecycleTables.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/system/THeap.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/scene/TScene.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/task/TMainTask.h"
#include "pso/map/TSetEvtDestroy.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby_803DE778.h"

#pragma readonly_strings on

extern "C" {
s32 is_area_transfer_pending();
}

int set_event_destroy_id;
u8 *area_event_set_heap;
s32 lbl_805D6098;


struct Ent_80208A04 { u8 pad[8]; s32 n; };

struct Rec_80208B7C { s32 id; s16 f4; u8 pad[0xE]; };

struct Grp_80208B7C { u8 pad[8]; s32 count; s32 pad3; Rec_80208B7C recs[1]; };

struct Rec_80208904 { s32 id; s16 f4; s16 f6; s16 f8; s16 fa; s32 fc; s32 f10; };

struct Grp_80208904 { s32 a; s32 b; s32 count; s32 pad; Rec_80208904 recs[1]; };

struct Rec_80208A40 { s32 id; s16 f4; u8 pad[0xE]; };

struct Grp_80208A40 { u8 pad[8]; s32 count; s32 pad3; Rec_80208A40 recs[1]; };

struct Rec_80208AD8 { s32 id; s16 f4; u8 pad[0xE]; };

struct Grp_80208AD8 { u8 pad[8]; s32 count; s32 pad3; Rec_80208AD8 recs[1]; };

struct Grp_80208BD8 { u8 pad[8]; s32 count; s32 pad3; SetDestroyEventRecord recs[1]; };
// Indexed by a floor event record's create_type: 0 creates nothing, 1 a TSetEvtDestroy.
typedef void (*FloorEventCreateFunc)(SetDestroyEventRecord *event);

struct Rec_802089B0 { u8 pad[4]; s16 f4; u8 pad2[0xE]; };

struct Grp_802089B0 { u8 pad[8]; s32 count; s32 pad3; Rec_802089B0 recs[1]; };

extern "C" {
void activate_triggered_floor_events(void);
u8 * heap_alloc__5THeapFUl(void *, s32);
}
s32 activate_first_floor_event(s32 idx, s32 id);
LobbySlotPtrTable lobby_slot_ptr_table;
s32 set_floor_event_flags(s32 arg0, s32 arg1, s32 arg2);
void bswap_floor_event_set(s32 idx);

void clear_floor_event_flags(void);
void set_destroy_event__6TLobbyFi(int a0) { set_event_destroy_id = a0; }
void show_partner_chatter_for_key(s16 key);
void spawn_destroy_event(SetDestroyEventRecord *event) {
    if (TLobby::get_destroy_event_obj() != -1) {
        show_partner_chatter_for_key(event->spawn_arg0);
    }
    new TSetEvtDestroy(tl_01, event);
    set_destroy_event__6TLobbyFi(-1);
}

void create_empty_floor_event(SetDestroyEventRecord *event) {}

__declspec(section ".data") FloorEventCreateFunc floor_event_create_table[] = {
    create_empty_floor_event,
    spawn_destroy_event,
};

void bswap_floor_event_set(s32 idx) {
    Rec_80208904 *r = ((Rec_80208904 **)&lobby_slot_ptr_table)[idx];
    s32 n;
    s32 i;
    if (r != NULL) {
        bswap_32((u32 *)r);
        bswap_32((u32 *)r + 1);
        bswap_32((u32 *)r + 2);
        n = ((Grp_80208904 *)r)->count;
        r = ((Grp_80208904 *)r)->recs;
        i = 0;
        for (; i < n; i++, r++) {
            bswap_32((u32 *)&r->id);
            bswap_16((u16 *)&r->f4);
            bswap_16((u16 *)&r->f6);
            bswap_16((u16 *)&r->f8);
            bswap_16((u16 *)&r->fa);
            bswap_32((u32 *)&r->fc);
            bswap_32((u32 *)&r->f10);
        }
    }
}

void clear_floor_event_flags(void) {
    Grp_802089B0 **t;
    Grp_802089B0 *g;
    s32 i;
    s32 n;
    Rec_802089B0 *r;
    s32 j;
    i = 0;
    t = (Grp_802089B0 **)&lobby_slot_ptr_table;
    do {
        g = t[i];
        if (g != NULL) {
            n = g->count;
            r = g->recs;
            for (j = 0; j < n; j++, r++) {
                r->f4 = 0;
            }
        }
        i++;
    } while (i < 0x12);
}

s32 TLobby::count_sync_record_bytes() {
    s32 sum = 0;
    s32 i;
    for (i = 0; i < 18; i++) {
        if (((Ent_80208A04 * *)&lobby_slot_ptr_table)[i] != 0) sum += ((Ent_80208A04 * *)&lobby_slot_ptr_table)[i]->n;
    }
    return sum * 2;
}

void TLobby::import_sync_records(s16 *arg0) {
    Grp_80208A40 **t;
    s16 *src;
    s32 i;
    s32 n;
    Rec_80208A40 *r;
    s32 j;
    s16 tmp;
    TLobby::count_sync_record_bytes();
    src = arg0;
    t = (Grp_80208A40 **)&lobby_slot_ptr_table;
    i = 0;
    do {
        Grp_80208A40 *g = t[i];
        if (g != NULL) {
            n = g->count;
            r = g->recs;
            for (j = 0; j < n; j++, src++, r++) {
                tmp = *src;
                bswap_16((u16 *)&tmp);
                r->f4 = tmp;
            }
        }
        i++;
    } while (i < 0x12);
}

s32 TLobby::export_sync_records(s16 *arg0) {
    s32 ret;
    Grp_80208AD8 **t;
    s16 *src;
    s32 i;
    s32 n;
    Rec_80208AD8 *r;
    s32 j;
    s16 tmp;
    ret = TLobby::count_sync_record_bytes();
    src = arg0;
    t = (Grp_80208AD8 **)&lobby_slot_ptr_table;
    i = 0;
    do {
        Grp_80208AD8 *g = t[i];
        if (g != NULL) {
            n = g->count;
            r = g->recs;
            for (j = 0; j < n; j++, src++, r++) {
                tmp = r->f4 & ~2;
                bswap_16((u16 *)&tmp);
                *src = tmp;
            }
        }
        i++;
    } while (i < 0x12);
    return ret;
}

s32 set_floor_event_flags(s32 arg0, s32 arg1, s32 arg2) {
    Grp_80208B7C *g = ((Grp_80208B7C * *)&lobby_slot_ptr_table)[arg0];
    Rec_80208B7C *r;
    s32 n;
    if (g == 0) {
        return 0;
    }
    n = g->count;
    r = g->recs;
    s32 i;
    for (i = 0; i < n; i++) {
        if (r->id == arg1) {
            r->f4 |= arg2;
        }
        r++;
    }
    return 1;
}

void activate_triggered_floor_events(void) {
    FloorEventCreateFunc *tbl;
    s32 n;
    SetDestroyEventRecord *r;
    s32 i;
    Grp_80208BD8 *g = ((Grp_80208BD8 **)&lobby_slot_ptr_table)[get_current_floor()];
    if (g != NULL) {
        n = g->count;
        r = g->recs;
        i = 0;
        tbl = floor_event_create_table;
        for (; i < n; i++, r++) {
            if (!(r->flags & 2) && (r->flags & 4)) {
                tbl[r->create_type](r);
                r->flags |= 6;
            }
        }
    }
}

s32 activate_first_floor_event(s32 idx, s32 id) {
    Grp_80208BD8 *g = ((Grp_80208BD8 **)&lobby_slot_ptr_table)[idx];
    SetDestroyEventRecord *r;
    s32 i;
    if (g == NULL) {
        return 0;
    }
    r = g->recs;
    for (i = g->count; i > 0; i--, r++) {
        if (r->id == id && !(r->flags & 2)) {
            floor_event_create_table[r->create_type](r);
            r->flags |= 6;
            return 1;
        }
    }
    return 0;
}

u8 *TLobby::alloc_heap_slot(s32 arg0, s32 arg1) {
    s32 temp_r30;
    u8 *temp_r3;
    if (arg0 > 0x11) {
        return NULL;
    }
    temp_r30 = arg0 * 4;
    if ((u32) *(s32 *)((s8 *)&lobby_slot_ptr_table.value + temp_r30) != 0U) {
        return NULL;
    }
    temp_r3 = (u8 *)(((THeap *)area_event_set_heap)->heap_alloc(arg1));
    if (temp_r3 != NULL) {
        *(s32 *)((s8 *)&lobby_slot_ptr_table.value + temp_r30) = (long) (temp_r3);
        return temp_r3;
    }
    return NULL;
}

#undef wave_event_stream_base
#undef wave_event_stream_cursor

#pragma fp_contract on

struct Buf_80208E8C { u8 data[0x20]; };

#define area_event_set_heap (*(s32 *)&area_event_set_heap)
#define lobby_slot_ptr_table (*(s32 (*)[1])&lobby_slot_ptr_table)
extern "C" {
s32 replace_file_extension__6TLobbyFPvPvPv(char *arg0, char *arg1, char *arg2);

#define HA2 ((s32 (*)(s32, s32))heap_alloc__5THeapFUl)
}

s32 load_area_event_set(s32 floor, s32 area, s32 terrain, s32 entities);
#define lobby_slot_ptr_table (*(s32 (*)[1])&lobby_slot_ptr_table)
#define area_event_set_heap (*(s32 *)&area_event_set_heap)

#define lobby_slot_ptr_table (*(s32 (*)[1])&lobby_slot_ptr_table)
#define area_event_set_heap (*(s32 *)&area_event_set_heap)

s32 TLobby::add_player(s32 arg0, saddr arg1, s32 arg2) {
    s32 temp_r29;
    saddr temp_r3;

    if (arg0 > 0x11) {
        return 0;
    }
    temp_r29 = arg0 * 4;
    if ((u32) *((s32 *)((s8 *)lobby_slot_ptr_table + temp_r29)) != 0U) {
        return 0;
    }
    temp_r3 = HA2(area_event_set_heap, arg2);
    if (temp_r3 != 0) {
        move_data((void *)(temp_r3), (const void *)((const void *)arg1), (u32)arg2);
        *((s32 *)((s8 *)lobby_slot_ptr_table + temp_r29)) = temp_r3;
        bswap_floor_event_set(arg0);
        return 1;
    }
    return 0;
}

void TLobby::free_team_buffers() {
    s32 i;
    for (i = 17; i >= 0; i--) {
        if ((u32)((s32 *)&lobby_slot_ptr_table)[i] != 0) {
            ((THeap *)area_event_set_heap)->heap_free((void *)((s32 *)&lobby_slot_ptr_table)[i]);
            ((s32 *)&lobby_slot_ptr_table)[i] = 0;
        }
    }
}

s32 load_area_event_set(s32 floor, s32 area, s32 terrain, s32 entities) {
    Buf_80208E8C buf;
    s32 n;
    void *p;
    if (TLobby__data_805D6068[area].variants == 0 || TLobby__data_805D6068[area].count - 1 < terrain) {
        return 0;
    }
    if (TLobby__data_805D6068[area].variants[terrain].entries == 0 || TLobby__data_805D6068[area].variants[terrain].count - 1 < entities) {
        return 0;
    }
    replace_file_extension__6TLobbyFPvPvPv((char *)&buf, (char *)TLobby__data_805D6068[area].variants[terrain].entries[entities].enemy_set_name, ".evt");
    n = get_resource_file_size((const char *)buf.data);
    if (n > 0) {
        p = ((void *)HA2((saddr)((*(void * *)&area_event_set_heap)), n));
        if (p != 0) {
            read_disc_file((const char *)buf.data, p);
            ((void * *)&lobby_slot_ptr_table)[floor] = p;
            bswap_floor_event_set(floor);
            return 1;
        }
    }
    return 0;
}

#undef area_event_set_heap
#undef lobby_slot_ptr_table

extern "C" {

s32 TLobby::load_all_floor_event_sets() {
    FloorMapSelection stack;
    s32 var_r31;
    var_r31 = 0;
loop_1:
    if ((get_floor_map_selection(var_r31, &stack) == 1) && (stack.area >= 0)) {
        if (is_area_transfer_pending() != 0) {
            return 0;
        }
        ((s32 (*)(int, int, int, int))load_area_event_set)(var_r31, stack.area, stack.terrain, stack.entities);
        goto block_6;
    }
block_6:
    var_r31 += 1;
    if (var_r31 >= 0x12) {
        return 1;
    }
    goto loop_1;
}

u8 * __ct__5THeapFUli(void *, s32, s32);
#define area_event_set_heap (*(int *)&area_event_set_heap)
void close_gsl_archive();
void open_gsl_archive(char *name);
#define lobby_slot_ptr_table (*(s32 (*)[1])&lobby_slot_ptr_table)
int __dt__5THeapFv(void*, void*);

void TLobby::get_team_state() { TLobby::free_team_buffers(); }

#define area_event_set_heap (*(int *)&area_event_set_heap)

void TLobby::load_set_event_gsl() {
    s32 i;
    for (i = 0; i < 0x12; i++) {
        lobby_slot_ptr_table[i] = 0;
    }
    (*(s32 *)&set_event_destroy_id) = -1;
    lbl_805D6098 = 0;
    open_gsl_archive("gsl_set_event.gsl");
    if (TLobby::load_all_floor_event_sets() == 0) {
        close_gsl_archive();
        return;
    }
    close_gsl_archive();
}

void TLobby::free_heap() { __dt__5THeapFv((void*)area_event_set_heap, (void*)1); area_event_set_heap = 0; }

void TLobby::create_heap_8000() {
    u8 *heap;
    u8 *var_r0;
    heap = (u8 *)(THeap::operator new(0x14));
    var_r0 = heap;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(__ct__5THeapFUli(heap, 0x8000, 0x20));
    }
    (*(u8 * *)&area_event_set_heap) = var_r0;
}

int TLobby::get_destroy_event_obj() {  return set_event_destroy_id; }

}

#undef area_event_set_heap
#undef lobby_slot_ptr_table
