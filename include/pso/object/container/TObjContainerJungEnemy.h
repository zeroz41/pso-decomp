#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNGENEMY_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNGENEMY_H

#include "types.h"
#include "pso/player/TObjContainerCommon.h"

struct NJS_OBJECT;

struct TObjContainerJungEnemy : public TObjContainerCommon {
    TObjContainerJungEnemy(TObject *parent, void *set_data);
    virtual ~TObjContainerJungEnemy();
    virtual void spawn_break_effects() const;
    virtual void draw_model();
    virtual void debug_print_item_box_info();
    virtual void vfunc_6(s16 *, s32);
    virtual void update_state();
    virtual f32 receive_physical_attack(void *, f32);
    NJS_OBJECT *body_model;
    NJS_OBJECT *large_fragment_model;
    NJS_OBJECT *small_fragment_model;
    NJS_OBJECT *light_model;
    void load_models();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjContainerJungEnemy_size, sizeof(TObjContainerJungEnemy) == 0x378);

#endif
