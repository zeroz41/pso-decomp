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
    void update_decoration_spawning();
    void apply_floor_set_rows();

    s32 step;  // which of run_task's steps (apply_floor_set_rows, update_decoration_spawning) runs
};
LAYOUT_ASSERT(TSetManagerSize, sizeof(TSetManager) == 0x20);


extern "C" {
void TSetManager__sub_8020D7D4(void);
}

void init_item_drop_tables(void);
// Entry counts of quest_object_entries and the enemy state records, sent and received as the object and enemy
// condition packets.
extern s32 object_condition_count;
extern s32 enemy_condition_count;

#endif
