#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNGENEMY_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNGENEMY_H

#include "types.h"
#include "pso/object/container/TObjContainerBase.h"

struct QuestObjectEntry;

struct NJS_OBJECT;

struct TObjContainerJungEnemy : public TObjContainerBase {
    TObjContainerJungEnemy(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjContainerJungEnemy();
    virtual void spawn_break_effects() const;
    virtual void draw_model();
    virtual void debug_print_item_box_info();
    virtual void apply_saved_state(QuestObjectEntry *, s32);
    virtual void update_state();
    virtual f32 receive_physical_attack(TObjChara *, f32);
    NJS_OBJECT *body_model;
    NJS_OBJECT *large_fragment_model;
    NJS_OBJECT *small_fragment_model;
    NJS_OBJECT *light_model;
    void load_models();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TObjContainerJungEnemy_size, sizeof(TObjContainerJungEnemy) == 0x378);

#endif
