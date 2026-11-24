#include "types.h"
#include "pso/map/FloorPopulation.h"
#include "pso/unk/TLobby.h"
#include "pso/object/base/TObjBase.h"
struct Pkt_8020BD50 { u8 hdr[2]; u16 id; s16 area; s16 flags; };

extern "C" {
s32 get_current_floor();
void *find_entity_by_id(u16 id);
void TLobby__sub_8020BCE4(void);
extern TObject *tl_02;
extern TObject *tl_05;
extern TObject *tl_06;
extern TObject *tl_07;
void TLobby__sub_8020BC50(void);
void handle_6x76_set_entity_set_flags(Pkt_8020BD50 *pkt);

void TLobby__sub_8020BC50(void) {
    s32 n;
    FloorObjectSetRow *p;
    s32 i;
    p = get_active_floor_object_rows(get_current_floor());
    n = TLobby::get_obj_table_entry(get_current_floor());
    for (i = 0; i < n; i++, p++) {
        if (p->object != 0) {
            TLobby::destroy_child_recursive(tl_02, p->object);
            TLobby::destroy_child_recursive(tl_05, p->object);
            TLobby::destroy_child_recursive(tl_06, p->object);
            TLobby::destroy_child_recursive(tl_07, p->object);
            p->object = 0;
        }
    }
}

void TLobby__sub_8020BCE4(void) {
    EnemySetRecord *p;
    s32 n;
    s32 i;
    p = get_active_floor_enemy_rows(get_current_floor());
    n = TLobby::get_object_type(get_current_floor());
    for (i = 0; i < n; i++, p++) {
        u32 r = (uaddr)find_entity_by_id(p->placement.id);
        if (r != 0) {
            ((TObjBase *)(saddr)r)->set_actor_flags(0x800);
        }
    }
}
void handle_6x76_set_entity_set_flags(Pkt_8020BD50 *pkt) {
    FloorSavedSetRow *e;
    LobbyFloorRows *a;
    FloorSavedSetRow *e2;
    LobbyFloorRows *a2;
    s32 i;
    u16 id;
    ((TLobby *)pkt)->bswap_player_fields();
    id = pkt->id;
    if (id >= 0x1000 && id < 0x4000) {
        a = &floor_enemy_group_table[pkt->area];
        if (a->enemy_rows != NULL) {
            e = a->enemy_rows;
            for (i = 0; i < a->enemy_count; i++, e++) {
                if (e->id == id) {
                    e->flags |= pkt->flags;
                    break;
                }
            }
        }
        if (pkt->area == get_current_floor()) {
            for (i = 0; i < current_floor_enemy_set_count; i++) {
                if (pkt->id == current_floor_enemy_set_rows[i].placement.id) {
                    current_floor_enemy_set_rows[i].flags |= pkt->flags;
                    break;
                }
            }
        }
    }
    id = pkt->id;
    if (id >= 0x4000 && id < 0xFFFF) {
        a2 = &floor_enemy_group_table[pkt->area];
        if (a2->object_rows != NULL) {
            e2 = a2->object_rows;
            for (i = 0; i < a2->object_count; i++, e2++) {
                if (e2->id == id) {
                    e2->flags |= pkt->flags;
                    break;
                }
            }
        }
        if (pkt->area == get_current_floor()) {
            for (i = 0; i < current_floor_object_set_count; i++) {
                if (pkt->id == current_floor_object_set_rows[i].placement.entity_id) {
                    current_floor_object_set_rows[i].flags |= pkt->flags;
                    break;
                }
            }
        }
    }
}

}

struct Pkt_8020BF14 { u8 hdr[2]; s16 a; s16 b; s16 c; };

extern "C" {
}
void build_6x76_set_entity_set_flags(void *);
void send_6x76_set_entity_set_flags(void *arg0, s16 arg1);

void send_6x76_set_entity_set_flags(void *arg0, s16 arg1) {
    Pkt_8020BF14 pkt;
    build_6x76_set_entity_set_flags(&pkt);
    pkt.a = ((TObjBase *)(arg0))->get_entity_id();
    pkt.b = ((s16 (*)())get_current_floor)();
    pkt.c = arg1;
    ((TLobby *)(&pkt))->send_player_update();
}
