#ifndef PSO_OBJECT_TOBJDOAEX01_H
#define PSO_OBJECT_TOBJDOAEX01_H

#include "types.h"
#include "pso/object/door/TODoorBase.h"

struct TObjDoaEx01 : public TODoorBase {
    TObjDoaEx01(TObject *parent, ObjectSetData *placement);
    virtual ~TObjDoaEx01();
    virtual void update_closing();
    virtual void update_open();
    virtual void update_opening();
    virtual void update_closed();
    virtual void render();
    void draw_object_tree(NJS_OBJECT *obj);
    static void free_resource();
    static void load_resources();
    // Constant material colour of the door's two alpha parts; r pulses 0-1 while the door is closed
    // and unlocked (door_flags 0x100000 = rising).
    NJS_ARGB glow_color;
    void try_open();
    void draw_model();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TObjDoaEx01_size, sizeof(TObjDoaEx01) == 0xE4);
#endif
