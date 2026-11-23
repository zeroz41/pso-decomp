#ifndef PSO_MAP_TSETMANAGER_H
#define PSO_MAP_TSETMANAGER_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TSetManager : public TObject {
public:
    TSetManager(TObject *parent);
    virtual ~TSetManager();
    virtual void run_task();
public:
    static void create();
    static const char *class_name;
    void update_decoration_spawning();
    void apply_floor_set_rows();
    void post_step();  // empty; run_task calls it after every step

    s32 step;  // which of run_task's steps (apply_floor_set_rows, update_decoration_spawning) runs
};
LAYOUT_ASSERT(TSetManagerSize, sizeof(TSetManager) == 0x20);


// Floor set state: allocated by init_item_drop_tables and released by free_item_drop_tables (a scene callback
// pair); arrive/depart_floor_population restore and save a floor's set rows around a floor change.
void init_item_drop_tables(void);
void free_item_drop_tables();
void alloc_item_drop_memory_pool();
void free_item_drop_memory_pool();
void reset_id_tables();
void clear_floor_population(void);
void arrive_floor_population();
void depart_floor_population();
void setup_floor_decorations();
void clear_floor_flags_and_depart();
void free_floor_decorations();
// Entry counts of quest_object_entries and the enemy state records, sent and received as the object and enemy
// condition packets.
extern s32 object_condition_count;
extern s32 enemy_condition_count;

#endif
