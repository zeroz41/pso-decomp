#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/text_8020CCF4.h"
#include "pso/map/FloorPopulation.h"
#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/object/base/TObjCharaHelpers.h"
extern "C" {
s32 set_flags_on_matching_entries__6TLobbyFlssl(s32, s32, s32, s32);
}

s32 unhide_enemies_at(s32 floor, s32 room, s32 wave) {
    s32 n;
    s32 count;
    s32 local;
    EnemySetRecord *set;
    s32 i;
    TObjEnemy *obj;
    count = 0;
    local = 0;
    if (floor == get_current_floor()) {
        local = 1;
    }
    if (local == 0) {
        return set_flags_on_matching_entries__6TLobbyFlssl(floor, room, wave, 1);
    }
    set = get_active_floor_enemy_rows(floor);
    n = TLobby::get_object_type(floor);
    for (i = 0; i < n; i++, set++) {
        if (set->flags & 8) continue;
        if (set->flags & 2) continue;
        if (set->flags & 1) continue;
        if (set->placement.room != (s16)room) continue;
        if (set->placement.wave != (s16)wave) continue;
        if (local != 0) {
            obj = construct_enemy_from_set_row(set);
            if (obj != NULL) {
                set->enemy = obj;
                set->flags |= 2;
                obj->room = set->placement.room;
                obj->set_group = set->placement.wave;
                obj->set_index = set->placement.enemy_index;
                obj->set_entry = set;
                if (obj->set_index != -1) {
                    obj->apply_enemy_state(&enemy_state_records[obj->set_index].flags);
                }
                count++;
            } else {
                set->enemy = NULL;
            }
        } else {
            set->flags |= 1;
            count++;
        }
    }
    return count;
}
