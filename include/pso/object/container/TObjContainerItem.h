#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERITEM_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERITEM_H

#include "types.h"
#include "pso/object/container/TObjContainerBase.h"

struct TObjContainerItem : public TObjContainerBase {
    TObjContainerItem(TObject *parent, void *set_data);
    virtual ~TObjContainerItem();
    virtual void draw_model();
    virtual void update_state();
    virtual void spawn_break_effects() const;
    virtual void apply_saved_state(s16 *, s32);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjContainerItem_size, sizeof(TObjContainerItem) == 0x368);

// Object 0x92's container. Its constructor stores its base's name string ("TObjContainerBase") in m_name,
// so the game gives it no name of its own.
struct TUnk_804B66F4 : public TObjContainerBase {
    TUnk_804B66F4(TObject *parent, void *set_data);
    virtual ~TUnk_804B66F4();
    virtual void spawn_break_effects() const;
    virtual void draw_model();
    virtual void update_state();
    virtual void apply_saved_state(s16 *, s32);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TUnk_804B66F4_size, sizeof(TUnk_804B66F4) == 0x368);

void load_forest_box_resources(void);
#endif
