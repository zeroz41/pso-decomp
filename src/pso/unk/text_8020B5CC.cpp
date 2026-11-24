#include "pso/system/memory.h"
#include "pso/map/FloorPopulation.h"
#include "types.h"
#include <string.h>
#include "pso/unk/text_8020B5CC.h"
#include "pso/system/THeap.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/network/protocol/protocol.h"
#include "pso/unk/pso_carve_8020bf88.h"
#include "pso/player/TObjPlayer_80011014.h"
extern "C" {
extern TObject *tl_02;
extern TObject *tl_05;
extern TObject *tl_06;
extern TObject *tl_07;
void archive_pool_free(void *pool, void *node);
void *archive_pool_alloc(void *pool, u32 size);

// The header is followed by the s16 flags of every object set, then of every enemy set.
int TLobby__sub_8020B5CC(FloorSetFlagsPayload *buf) {
    s32 enemies;
    FloorSetFlagsHeader *out = buf;
    s32 objects = 0;
    s16 *p = buf->flags;
    out->object_offset = sizeof(FloorSetFlagsHeader);
    for (s32 i = 0; i < 18; i++) {
        if (floor_enemy_group_table[i].object_count > 0) {
            FloorSavedSetRow *e = floor_enemy_group_table[i].object_rows;
            s32 n = floor_enemy_group_table[i].object_count;
            if (get_current_floor() == i) {
                FloorObjectSetRow *s = current_floor_object_set_rows;
                if (s != NULL) {
                    for (s32 j = 0; j < n; j++) {
                        s16 flags = s->flags & ~2;
                        bswap_16((u16 *)&flags);
                        *p++ = flags;
                        s++;
                        objects++;
                    }
                }
            } else {
                for (s32 j = 0; j < n; j++) {
                    s16 flags = e->flags & ~2;
                    bswap_16((u16 *)&flags);
                    *p++ = flags;
                    e++;
                    objects++;
                }
            }
        }
    }
    enemies = 0;
    out->object_count = objects;
    out->enemy_offset = out->object_count * 2 + 0x10;
    for (s32 i = 0; i < 18; i++) {
        if (floor_enemy_group_table[i].enemy_count > 0) {
            FloorSavedSetRow *e = floor_enemy_group_table[i].enemy_rows;
            s32 n = floor_enemy_group_table[i].enemy_count;
            if (get_current_floor() == i) {
                EnemySetRecord *s = current_floor_enemy_set_rows;
                if (s != NULL) {
                    for (s32 j = 0; j < n; j++) {
                        s16 flags = s->flags & ~2;
                        bswap_16((u16 *)&flags);
                        *p++ = flags;
                        s++;
                        enemies++;
                    }
                }
            } else {
                for (s32 j = 0; j < n; j++) {
                    s16 flags = e->flags & ~2;
                    bswap_16((u16 *)&flags);
                    *p++ = flags;
                    e++;
                    enemies++;
                }
            }
        }
    }
    out->enemy_count = enemies;
    swap_floor_set_flags_header(out);
    return TLobby__sub_8020BF88();
}

#pragma push
#pragma opt_propagation off
s32 init_quest_floor_enemies(s32 idx, EnemySetRecord *src, u32 size) {
    if (floor_saved_row_heap != 0 && floor_set_archive_pool != 0) {
    uaddr sz = size;
    s32 n = (0, sz / 72);
    LobbyFloorRows *t = &floor_enemy_group_table[idx];
    EnemySetRecord *s;
    FloorSavedSetRow *d;
    s32 i;
    void *buf;
    t->enemy_count = 0;
    s = src;
    for (i = 0; i < n; i++) {
        if (s->type != -1) {
            t->enemy_count++;
        }
        s++;
    }
    t->enemy_rows = (FloorSavedSetRow *)floor_saved_row_heap->heap_alloc(t->enemy_count * 8);
    memset(t->enemy_rows, 0, t->enemy_count * 8);
    s = src;
    d = t->enemy_rows;
    for (i = 0; i < n; i++) {
        if (s->type != -1) {
            d->id = s->placement.id;
            d->room = s->placement.room;
            d->wave = s->placement.wave;
            d++;
        }
        s++;
    }
    if (floor_set_archives[idx].enemies != NULL) {
        archive_pool_free(floor_set_archive_pool, floor_set_archives[idx].enemies);
    }
    floor_set_archives[idx].enemies = archive_pool_alloc(floor_set_archive_pool, sz);
    if ((uaddr)src & 0x1F) {
        buf = TQuestVmDownLoadServer::alloc(sz);
        memcpy(buf, src, sz);
        if (floor_set_archives[idx].enemies != NULL) {
            TLobby::send_or_handle_packet(floor_set_archive_pool, (void *)buf, floor_set_archives[idx].enemies, (void *)sz, (u32)0);
        }
        safe_free(buf);
    } else if (floor_set_archives[idx].enemies != NULL) {
        TLobby::send_or_handle_packet(floor_set_archive_pool, (void *)src, floor_set_archives[idx].enemies, (void *)sz, (u32)0);
    }
    return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 load_floor_enemy_group_entries__6TLobbyFiPvUi(s32 idx, FloorObjectSetRow *src, u32 size) {
    if (floor_saved_row_heap != 0 && floor_set_archive_pool != 0) {
    uaddr sz = size;
    s32 n = sz / 68;
    LobbyFloorRows *t = &floor_enemy_group_table[idx];
    FloorObjectSetRow *s;
    FloorSavedSetRow *d;
    s32 i;
    void *buf;
    t->object_count = 0;
    s = src;
    for (i = 0; i < n; i++) {
        if (s->type != -1) {
            t->object_count++;
        }
        s++;
    }
    t->object_rows = (FloorSavedSetRow *)floor_saved_row_heap->heap_alloc(t->object_count * 8);
    memset(t->object_rows, 0, t->object_count * 8);
    s = src;
    d = t->object_rows;
    for (i = 0; i < n; i++) {
        if (s->type != -1) {
            d->id = s->placement.entity_id;
            d->room = s->placement.room;
            d->wave = s->placement.wave;
            d++;
        }
        s++;
    }
    if (floor_set_archives[idx].objects != NULL) {
        archive_pool_free(floor_set_archive_pool, floor_set_archives[idx].objects);
    }
    floor_set_archives[idx].objects = archive_pool_alloc(floor_set_archive_pool, sz);
    if ((uaddr)src & 0x1F) {
        buf = TQuestVmDownLoadServer::alloc(sz);
        memcpy(buf, src, sz);
        if (floor_set_archives[idx].objects != NULL) {
            TLobby::send_or_handle_packet(floor_set_archive_pool, (void *)buf, floor_set_archives[idx].objects, (void *)sz, (u32)0);
        }
        safe_free(buf);
    } else if (floor_set_archives[idx].objects != NULL) {
        TLobby::send_or_handle_packet(floor_set_archive_pool, (void *)src, floor_set_archives[idx].objects, (void *)sz, (u32)0);
    }
    return 1;
    }
    return 0;
}
#pragma pop

void TLobby__sub_8020BB18(void) {
    FloorObjectSetRow *p = floor_decoration_rows;
    s32 i;
    for (i = 0; i < floor_decoration_row_count; i++, p++) {
        if (p->object != 0) {
            TLobby::destroy_child_recursive(tl_02, p->object);
            TLobby::destroy_child_recursive(tl_05, p->object);
            TLobby::destroy_child_recursive(tl_06, p->object);
            TLobby::destroy_child_recursive(tl_07, p->object);
            p->flags = 0;
            p->object = 0;
        }
    }
}

}
