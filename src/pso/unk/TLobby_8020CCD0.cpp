#include "pso/enemy/EnemyFactoryTables.h"
#include "pso/unk/TLobby_8020CCD0.h"
#include "types.h"

void copy_enemy_factory_entry(EnemyFactoryEntry *arg0, EnemyFactoryEntry *arg1) {
    arg0->type = arg1->type;
    arg0->create = arg1->create;
    arg0->field_08 = arg1->field_08;
    arg0->child_count = arg1->child_count;
}
