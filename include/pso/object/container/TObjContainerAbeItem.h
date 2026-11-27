#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERABEITEM_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERABEITEM_H

#include "types.h"
#include "pso/object/container/TObjContainerBase.h"

// Object 0x92: the item-dropping container drawn with the same models as TObjContainerAbeEnemy (0x93)
// (obj_seabed_con_rare on the seabed floors, fe_obj_con_hahen1/obj_abecon elsewhere); it breaks and drops
// its set item as TObjContainerItem (0x88) does. Its constructor stores its base's name string
// ("TObjContainerBase") in m_name, so the game gives it no name of its own.
struct TObjContainerAbeItem : public TObjContainerBase {
    TObjContainerAbeItem(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjContainerAbeItem();
    virtual void spawn_break_effects() const;
    virtual void draw_model();
    virtual void update_state();
    virtual void apply_saved_state(s16 *, s32);
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TObjContainerAbeItem_size, sizeof(TObjContainerAbeItem) == 0x368);
#endif
