#include "pso/enemy/EnemyFactoryTables.h"
#include "pso/misc/TLobby_8020CCD0.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/map/FloorArea.h"
typedef struct SpawnRecord_8020CC48 {
    s16 type;
    u16 flags;
    u16 index;
    s16 children;
    u16 reserved;
    u16 actor_id;
    s16 room;
    s16 wave;
    u32 secondary_wave;
    f32 position[3];
    u32 angles[3];
    f32 parameters[5];
    s16 integers[4];
} SpawnRecord_8020CC48;

typedef EnemyFactoryEntry SpawnFactory_8020CC48;

extern "C" {
s32 find_enemy_factory_entry(SpawnRecord_8020CC48 *row, SpawnFactory_8020CC48 *out);
s32 find_enemy_factory_entry(SpawnRecord_8020CC48 *row, SpawnFactory_8020CC48 *out) {
    s32 index = 0;
    SpawnFactory_8020CC48 *table = enemy_factory_area_table[get_current_floor_area()];
    SpawnFactory_8020CC48 *entry = table;
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
