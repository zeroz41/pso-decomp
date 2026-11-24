#include "pso/enemy/EnemyFactoryTables.h"
#include "pso/unk/text_8020CCF4.h"
#include "pso/map/FloorPopulation.h"

#include "types.h"

TObjEnemy *construct_enemy_from_set_row(EnemySetRecord *row) {
    EnemyFactoryEntry entry;
    if (find_enemy_factory_entry(row, &entry) >= 0) {
        return static_cast<TObjEnemy *>(entry.create(&row->placement));
    }
    return NULL;
}
