#ifndef PSO_MISC_TODOORANCIENT07_H
#define PSO_MISC_TODOORANCIENT07_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct BmlResource;
struct NJS_OBJECT;
struct BmlResourceDescriptor;

// The door07 bml TODoorAncient05, 06 and 07 all load.
extern BmlResourceDescriptor door_ancient_567_resource_descriptor;

// The ancient-area door with the red/green switch lights, drawing its first
// three model nodes detached while it is not moving.
struct TODoorAncient07 : public TODoorBase {
    TODoorAncient07(TObject *parent, void *set_data);
    virtual ~TODoorAncient07();
    virtual void update_open();
    virtual void update_closed();
    virtual void render();
    static void *create(void *set_data);
    static void destroy();
    static void load_resources();

    static BmlResource *bml_resource;
    static s32 *texture_lists;  // [0] red (locked), [1] green (open)
    static NJS_OBJECT *model_nodes;  // three nodes copied out of the bml model
};

typedef char TODoorAncient07_size[sizeof(TODoorAncient07) == 0xD4 ? 1 : -1];
#endif
