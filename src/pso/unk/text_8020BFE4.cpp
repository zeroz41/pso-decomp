#include "pso/enemy/EnemyFactoryTables.h"
#include "pso/map/FloorPopulation.h"
#include "pso/unk/text_8020BFE4.h"
#include "pso/object/base/ObjectFactoryTables.h"

#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer_80011014.h"

typedef EnemyFactoryEntry Ent_8020BFE4;

typedef ObjectFactoryEntry Ent_8020C030;


s32 get_enemy_factory_child_count(s32 arg0, s16 *arg1) {
    Ent_8020BFE4 *base = enemy_factory_area_table[arg0];
    Ent_8020BFE4 *p = base;
    for (; base != 0 && p->type != -1; p++) {
        if (p->type == *arg1) {
            return p->child_count;
        }
    }
    return 0;
}

s32 TLobby::find_floor_object_factory(s32 arg0, s16 *arg1) {
    Ent_8020C030 *base = floor_object_factory_tables[arg0];
    Ent_8020C030 *p = base;
    for (; base != 0 && p->type != -1; p++) {
        if (p->type == *arg1) {
            return p->extra_object_ids;
        }
    }
    return 0;
}

void TLobby__sub_8020C07C(s32 pl, s16 b, s16 a, s32 mask, s32 set) {
    if (pl == get_current_floor()) {
        FloorObjectSetRow *p = current_floor_object_set_rows;
        s32 i;
        for (i = 0; i < current_floor_object_set_count; i++, p++) {
            if (p->placement.room == b && p->placement.wave == a) {
                p->flags &= mask;
                p->flags |= set;
            }
        }
    }
}

s32 TLobby::count_quest_enemies_flag8() {
    s32 n = 0;
    s32 i;
    s32 j;
    if (current_floor_enemy_set_rows != NULL) {
        for (j = 0; j < current_floor_enemy_set_count; j++) {
            EnemySetRecord *a = &current_floor_enemy_set_rows[j];
            if (a->type != -1 && (a->flags & 8)) {
                n++;
            }
        }
    }
    for (i = 0; i < 0x12; i++) {
        if (i != get_current_floor()) {
            LobbyFloorRows *t = &floor_enemy_group_table[i];
            FloorSavedSetRow *b = t->enemy_rows;
            if (b != NULL) {
                for (j = 0; j < t->enemy_count; j++) {
                    if (b->flags & 8) {
                        n++;
                    }
                    b++;
                }
            }
        }
    }
    return n;
}

s32 is_room_enemy_set_cleared(s32 floor, s16 room) {
    s32 i;
    if (floor == get_current_floor()) {
        if (current_floor_enemy_set_rows != NULL) {
            for (i = 0; i < current_floor_enemy_set_count; i++) {
                EnemySetRecord *row = &current_floor_enemy_set_rows[i];
                if (room == row->placement.room && !(row->flags & 8)) {
                    return 0;
                }
            }
        }
        return 1;
    } else {
        LobbyFloorRows *saved = &floor_enemy_group_table[floor];
        FloorSavedSetRow *row = saved->enemy_rows;
        if (row != NULL) {
            for (i = 0; i < saved->enemy_count; i++, row++) {
                if (row->room == room && !(row->flags & 8)) {
                    return 0;
                }
            }
        }
        return 1;
    }
}
