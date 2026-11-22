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
void archive_pool_free(u32, void *);
void *archive_pool_alloc(u32, u32);
extern uaddr TLobby__data_805D6104;
extern uaddr TLobby__data_805D6108;

// The header is followed by the s16 flags of every object set, then of every enemy set.
int TLobby__sub_8020B5CC(FloorSetFlagsPayload *buf) {
    s32 enemies;
    FloorSetFlagsHeader *out = buf;
    s32 objects = 0;
    s16 *p = buf->flags;
    out->object_offset = sizeof(FloorSetFlagsHeader);
    for (s32 i = 0; i < 18; i++) {
        if (TLobby__floor_enemy_group_table[i].object_count > 0) {
            FloorSavedSetRow *e = TLobby__floor_enemy_group_table[i].object_rows;
            s32 n = TLobby__floor_enemy_group_table[i].object_count;
            if (get_current_floor() == i) {
                FloorObjectSetRow *s = TLobby__data_805D610C;
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
        if (TLobby__floor_enemy_group_table[i].enemy_count > 0) {
            FloorSavedSetRow *e = TLobby__floor_enemy_group_table[i].enemy_rows;
            s32 n = TLobby__floor_enemy_group_table[i].enemy_count;
            if (get_current_floor() == i) {
                EnemySetRecord *s = TLobby__data_805D6114;
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
    if (TLobby__data_805D6108 != 0 && TLobby__data_805D6104 != 0) {
    uaddr sz = size;
    s32 n = (0, sz / 72);
    LobbyFloorRows *t = &TLobby__floor_enemy_group_table[idx];
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
    t->enemy_rows = (FloorSavedSetRow *)((THeap *)TLobby__data_805D6108)->heap_alloc(t->enemy_count * 8);
    memset(t->enemy_rows, 0, t->enemy_count * 8);
    s = src;
    d = t->enemy_rows;
    for (i = 0; i < n; i++) {
        if (s->type != -1) {
            d->id = s->id;
            d->room = s->room;
            d->wave = s->wave;
            d++;
        }
        s++;
    }
    if (TLobby__data_80513A40[idx].enemies != NULL) {
        archive_pool_free(TLobby__data_805D6104, TLobby__data_80513A40[idx].enemies);
    }
    TLobby__data_80513A40[idx].enemies = archive_pool_alloc(TLobby__data_805D6104, sz);
    if ((uaddr)src & 0x1F) {
        buf = TQuestVmDownLoadServer::alloc(sz);
        memcpy(buf, src, sz);
        if (TLobby__data_80513A40[idx].enemies != NULL) {
            TLobby::send_or_handle_packet((void *)TLobby__data_805D6104, (void *)buf, TLobby__data_80513A40[idx].enemies, (void *)sz, (u32)0);
        }
        TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
    } else if (TLobby__data_80513A40[idx].enemies != NULL) {
        TLobby::send_or_handle_packet((void *)TLobby__data_805D6104, (void *)src, TLobby__data_80513A40[idx].enemies, (void *)sz, (u32)0);
    }
    return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 load_floor_enemy_group_entries__6TLobbyFiPvUi(s32 idx, FloorObjectSetRow *src, u32 size) {
    if (TLobby__data_805D6108 != 0 && TLobby__data_805D6104 != 0) {
    uaddr sz = size;
    s32 n = sz / 68;
    LobbyFloorRows *t = &TLobby__floor_enemy_group_table[idx];
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
    t->object_rows = (FloorSavedSetRow *)((THeap *)TLobby__data_805D6108)->heap_alloc(t->object_count * 8);
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
    if (TLobby__data_80513A40[idx].objects != NULL) {
        archive_pool_free(TLobby__data_805D6104, TLobby__data_80513A40[idx].objects);
    }
    TLobby__data_80513A40[idx].objects = archive_pool_alloc(TLobby__data_805D6104, sz);
    if ((uaddr)src & 0x1F) {
        buf = TQuestVmDownLoadServer::alloc(sz);
        memcpy(buf, src, sz);
        if (TLobby__data_80513A40[idx].objects != NULL) {
            TLobby::send_or_handle_packet((void *)TLobby__data_805D6104, (void *)buf, TLobby__data_80513A40[idx].objects, (void *)sz, (u32)0);
        }
        TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
    } else if (TLobby__data_80513A40[idx].objects != NULL) {
        TLobby::send_or_handle_packet((void *)TLobby__data_805D6104, (void *)src, TLobby__data_80513A40[idx].objects, (void *)sz, (u32)0);
    }
    return 1;
    }
    return 0;
}
#pragma pop

void TLobby__sub_8020BB18(void) {
    FloorObjectSetRow *p = floor_decoration_rows;
    s32 i;
    for (i = 0; i < TLobby__data_805D6120; i++, p++) {
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
