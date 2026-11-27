#ifndef PSO_ENEMY_ENEMY_FACTORY_TABLES_H
#define PSO_ENEMY_ENEMY_FACTORY_TABLES_H
#include "types.h"

struct EnemySetRecord;
struct EnemyPlacement;

typedef void *(*EnemyFactoryFunction)(EnemyPlacement *placement);
struct EnemyFactoryEntry {
    s16 type;
    EnemyFactoryFunction create;
    f32 creation_distance_squared;
    s32 child_count;
};

extern EnemyFactoryEntry* enemy_factory_area_table[36];
s32 find_enemy_factory_entry(const volatile EnemySetRecord *row, EnemyFactoryEntry *out);
void copy_enemy_factory_entry(EnemyFactoryEntry* out, EnemyFactoryEntry* entry);
#endif
