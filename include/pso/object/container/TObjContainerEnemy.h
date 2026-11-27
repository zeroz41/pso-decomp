#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERENEMY_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERENEMY_H

#include "types.h"
#include "pso/object/container/TObjContainerBase.h"

struct QuestObjectEntry;

struct TObjContainerEnemy : public TObjContainerBase {
    TObjContainerEnemy(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjContainerEnemy();
    virtual void debug_print_item_box_info();
    virtual void draw_model();
    virtual void update_state();
    virtual void spawn_break_effects() const;
    virtual void apply_saved_state(QuestObjectEntry *, s32);
    virtual f32 receive_physical_attack(TObjChara *, f32);
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TObjContainerEnemy_size, sizeof(TObjContainerEnemy) == 0x368);


#endif
