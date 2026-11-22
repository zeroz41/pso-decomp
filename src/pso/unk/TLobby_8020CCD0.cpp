#include "pso/enemy/EnemyFactoryTables.h"
#include "pso/unk/TLobby_8020CCD0.h"
#include "types.h"

void copy_enemy_factory_entry(EnemyFactoryEntry *arg0, EnemyFactoryEntry *entry) {
    arg0->type = entry->type;
    arg0->create = entry->create;
    arg0->field_08 = entry->field_08;
    arg0->child_count = entry->child_count;
}
