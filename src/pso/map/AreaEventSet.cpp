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
#include "pso/npc/NpcPartnerControl.h"
#include "pso/system/GslArchive.h"
#include "pso/unk/TLobby_800F8AA8.h"

#pragma readonly_strings on

extern "C" {
}

int set_event_destroy_id;
THeap *area_event_set_heap;
s32 lbl_805D6098;


// Indexed by a floor event record's create_type: 0 creates nothing, 1 a TSetEvtDestroy.
typedef void (*FloorEventCreateFunc)(SetDestroyEventRecord *event);

FloorEventSet *floor_event_sets[18];

void TLobby::set_destroy_event(int destroy_event) { set_event_destroy_id = destroy_event; }
void spawn_destroy_event(SetDestroyEventRecord *event) {
    if (TLobby::get_destroy_event_obj() != -1) {
        show_partner_chatter_for_key(event->spawn_arg0);
    }
    new TSetEvtDestroy(tl_01, event);
    TLobby::set_destroy_event(-1);
}

void create_empty_floor_event(SetDestroyEventRecord *event) {}

__declspec(section ".data") FloorEventCreateFunc floor_event_create_table[] = {
    create_empty_floor_event,
    spawn_destroy_event,
};

void bswap_floor_event_set(s32 floor) {
    FloorEventSet *set = floor_event_sets[floor];
    SetDestroyEventRecord *r;
    s32 n;
    s32 i;
    if (set != NULL) {
        bswap_32((u32 *)&set->action_stream_offset);
        bswap_32((u32 *)&set->pad_4);
        bswap_32((u32 *)&set->count);
        n = set->count;
        r = set->records;
        i = 0;
        for (; i < n; i++, r++) {
            bswap_32((u32 *)&r->id);
            bswap_16((u16 *)&r->flags);
            bswap_16((u16 *)&r->create_type);
            bswap_16((u16 *)&r->spawn_arg0);
            bswap_16((u16 *)&r->spawn_arg1);
            bswap_32((u32 *)&r->delay_ticks);
            bswap_32((u32 *)&r->action_offset);
        }
    }
}

void clear_floor_event_flags(void) {
    FloorEventSet **t;
    FloorEventSet *set;
    s32 i;
    s32 n;
    SetDestroyEventRecord *r;
    s32 j;
    i = 0;
    t = floor_event_sets;
    do {
        set = t[i];
        if (set != NULL) {
            n = set->count;
            r = set->records;
            for (j = 0; j < n; j++, r++) {
                r->flags = 0;
            }
        }
        i++;
    } while (i < 0x12);
}

s32 TLobby::count_sync_record_bytes() {
    s32 sum = 0;
    s32 i;
    for (i = 0; i < 18; i++) {
        if (floor_event_sets[i] != NULL) sum += floor_event_sets[i]->count;
    }
    return sum * 2;
}

void TLobby::import_sync_records(s16 *arg0) {
    FloorEventSet **t;
    s16 *src;
    s32 i;
    s32 n;
    SetDestroyEventRecord *r;
    s32 j;
    s16 tmp;
    TLobby::count_sync_record_bytes();
    src = arg0;
    t = floor_event_sets;
    i = 0;
    do {
        FloorEventSet *set = t[i];
        if (set != NULL) {
            n = set->count;
            r = set->records;
            for (j = 0; j < n; j++, src++, r++) {
                tmp = *src;
                bswap_16((u16 *)&tmp);
                r->flags = tmp;
            }
        }
        i++;
    } while (i < 0x12);
}

s32 TLobby::export_sync_records(s16 *arg0) {
    s32 ret;
    FloorEventSet **t;
    s16 *src;
    s32 i;
    s32 n;
    SetDestroyEventRecord *r;
    s32 j;
    s16 tmp;
    ret = TLobby::count_sync_record_bytes();
    src = arg0;
    t = floor_event_sets;
    i = 0;
    do {
        FloorEventSet *set = t[i];
        if (set != NULL) {
            n = set->count;
            r = set->records;
            for (j = 0; j < n; j++, src++, r++) {
                tmp = r->flags & ~2;
                bswap_16((u16 *)&tmp);
                *src = tmp;
            }
        }
        i++;
    } while (i < 0x12);
    return ret;
}

s32 set_floor_event_flags(s32 floor, s32 id, s32 flags) {
    FloorEventSet *set = floor_event_sets[floor];
    SetDestroyEventRecord *r;
    s32 n;
    if (set == 0) {
        return 0;
    }
    n = set->count;
    r = set->records;
    s32 i;
    for (i = 0; i < n; i++) {
        if (r->id == id) {
            r->flags |= flags;
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
    FloorEventSet *set = floor_event_sets[get_current_floor()];
    if (set != NULL) {
        n = set->count;
        r = set->records;
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

s32 activate_first_floor_event(s32 floor, s32 id) {
    FloorEventSet *set = floor_event_sets[floor];
    SetDestroyEventRecord *r;
    s32 i;
    if (set == NULL) {
        return 0;
    }
    r = set->records;
    for (i = set->count; i > 0; i--, r++) {
        if (r->id == id && !(r->flags & 2)) {
            floor_event_create_table[r->create_type](r);
            r->flags |= 6;
            return 1;
        }
    }
    return 0;
}

u8 *TLobby::alloc_heap_slot(s32 floor, s32 size) {
    u8 *set;
    if (floor > 0x11) {
        return NULL;
    }
    if (floor_event_sets[floor] != NULL) {
        return NULL;
    }
    set = (u8 *)area_event_set_heap->heap_alloc(size);
    if (set != NULL) {
        floor_event_sets[floor] = (FloorEventSet *)set;
        return set;
    }
    return NULL;
}

#pragma fp_contract on

s32 TLobby::add_player(s32 floor, saddr data, s32 size) {
    u8 *set;

    if (floor > 0x11) {
        return 0;
    }
    if (floor_event_sets[floor] != NULL) {
        return 0;
    }
    set = (u8 *)area_event_set_heap->heap_alloc(size);
    if (set != NULL) {
        move_data(set, (const void *)data, size);
        floor_event_sets[floor] = (FloorEventSet *)set;
        bswap_floor_event_set(floor);
        return 1;
    }
    return 0;
}

void TLobby::free_team_buffers() {
    s32 i;
    for (i = 17; i >= 0; i--) {
        if (floor_event_sets[i] != NULL) {
            area_event_set_heap->heap_free(floor_event_sets[i]);
            floor_event_sets[i] = NULL;
        }
    }
}

s32 load_area_event_set(s32 floor, s32 area, s32 terrain, s32 entities) {
    char path[0x20];
    s32 n;
    FloorEventSet *set;
    if (map_set_areas[area].variants == 0 || map_set_areas[area].count - 1 < terrain) {
        return 0;
    }
    if (map_set_areas[area].variants[terrain].entries == 0 || map_set_areas[area].variants[terrain].count - 1 < entities) {
        return 0;
    }
    TLobby::replace_file_extension(path, (char *)map_set_areas[area].variants[terrain].entries[entities].enemy_set_name, (char *)".evt");
    n = get_resource_file_size(path);
    if (n > 0) {
        set = (FloorEventSet *)area_event_set_heap->heap_alloc(n);
        if (set != NULL) {
            read_disc_file(path, set);
            floor_event_sets[floor] = set;
            bswap_floor_event_set(floor);
            return 1;
        }
    }
    return 0;
}

s32 TLobby::load_all_floor_event_sets() {
    FloorMapSelection selection;
    s32 floor;
    for (floor = 0; floor < 0x12; floor++) {
        if (get_floor_map_selection(floor, &selection) == 1 && selection.area >= 0) {
            if (is_area_transfer_pending() != 0) {
                return 0;
            }
            load_area_event_set(floor, selection.area, selection.terrain, selection.entities);
        }
    }
    return 1;
}

void TLobby::get_team_state() { TLobby::free_team_buffers(); }

void TLobby::load_set_event_gsl() {
    s32 i;
    for (i = 0; i < 0x12; i++) {
        floor_event_sets[i] = NULL;
    }
    set_event_destroy_id = -1;
    lbl_805D6098 = 0;
    open_gsl_archive("gsl_set_event.gsl");
    if (TLobby::load_all_floor_event_sets() == 0) {
        close_gsl_archive();
        return;
    }
    close_gsl_archive();
}

void TLobby::free_heap() {
    delete area_event_set_heap;
    area_event_set_heap = NULL;
}

void TLobby::create_heap_8000() { area_event_set_heap = new THeap(0x8000, 0x20); }

int TLobby::get_destroy_event_obj() {  return set_event_destroy_id; }
