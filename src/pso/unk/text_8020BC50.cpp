#include "types.h"
#include "pso/map/FloorPopulation.h"
#include "pso/network/TLobby.h"
#include "pso/object/base/TObjBase.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/network/protocol/SubcommandHandlers.h"
extern "C" {
s32 get_current_floor();
extern TObject *tl_02;
extern TObject *tl_05;
extern TObject *tl_06;
extern TObject *tl_07;

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
}
void handle_6x76_set_entity_set_flags(G_SetEntitySetFlags_6x76 *command) {
    FloorSavedSetRow *e;
    LobbyFloorRows *a;
    FloorSavedSetRow *e2;
    LobbyFloorRows *a2;
    s32 i;
    u16 id;
    ((TLobby *)command)->bswap_player_fields();
    id = command->header.entity_id;
    if (id >= 0x1000 && id < 0x4000) {
        a = &floor_enemy_group_table[command->floor];
        if (a->enemy_rows != NULL) {
            e = a->enemy_rows;
            for (i = 0; i < a->enemy_count; i++, e++) {
                if (e->id == id) {
                    e->flags |= command->flags;
                    break;
                }
            }
        }
        if (command->floor == get_current_floor()) {
            for (i = 0; i < current_floor_enemy_set_count; i++) {
                if (command->header.entity_id == current_floor_enemy_set_rows[i].placement.id) {
                    current_floor_enemy_set_rows[i].flags |= command->flags;
                    break;
                }
            }
        }
    }
    id = command->header.entity_id;
    if (id >= 0x4000 && id < 0xFFFF) {
        a2 = &floor_enemy_group_table[command->floor];
        if (a2->object_rows != NULL) {
            e2 = a2->object_rows;
            for (i = 0; i < a2->object_count; i++, e2++) {
                if (e2->id == id) {
                    e2->flags |= command->flags;
                    break;
                }
            }
        }
        if (command->floor == get_current_floor()) {
            for (i = 0; i < current_floor_object_set_count; i++) {
                if (command->header.entity_id == current_floor_object_set_rows[i].placement.entity_id) {
                    current_floor_object_set_rows[i].flags |= command->flags;
                    break;
                }
            }
        }
    }
}

struct Send6x76SetEntitySetFlagsPacket { u8 hdr[2]; s16 a; s16 b; s16 c; };

void build_6x76_set_entity_set_flags(void *);

void send_6x76_set_entity_set_flags(void *object, s16 flags) {
    Send6x76SetEntitySetFlagsPacket pkt;
    build_6x76_set_entity_set_flags(&pkt);
    pkt.a = ((TObjBase *)(object))->get_entity_id();
    pkt.b = ((s16 (*)())get_current_floor)();
    pkt.c = flags;
    ((TLobby *)(&pkt))->send_player_update();
}
