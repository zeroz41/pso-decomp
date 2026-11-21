#include "pso/enemy/EnemyFactoryTables.h"
#include "pso/unk/text_8020CCF4.h"

#include "types.h"

typedef EnemyFactoryEntry Out_8020CCF4;
extern "C" {
s32 find_enemy_factory_entry(void *, void *);
}
saddr construct_enemy_from_set_row(u8 *row) {
    Out_8020CCF4 o;
    if (find_enemy_factory_entry(row, &o) >= 0) {
        return (saddr) o.create(row + 4);
    }
    return 0;
}
