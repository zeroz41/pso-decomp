#include "pso/enemy/EnemyFactoryTables.h"
#include "pso/unk/TLobby_8020CCD0.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorPopulation.h"

#include "types.h"
#include "pso/player/TObjPlayer_80011014.h"

extern "C" {
s32 find_enemy_factory_entry(const volatile EnemySetRecord *row, EnemyFactoryEntry *out) {
    s32 index = 0;
    EnemyFactoryEntry *table = enemy_factory_area_table[get_current_floor_area()];
    EnemyFactoryEntry *entry = table;
    while (table != NULL && entry->type != -1) {
        if (entry->type == row->type) {
            copy_enemy_factory_entry(out, entry);
            return index;
        }
        entry++;
        index++;
    }
    return -1;
}

}
