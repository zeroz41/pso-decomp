#ifndef PSO_MISC_TODOORANCIENT06_H
#define PSO_MISC_TODOORANCIENT06_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct BmlResource;
struct NJS_OBJECT;

// The ancient-area door with the red/green switch lights: shares
// TODoorAncient07's bml and draws its first three nodes detached while it is
// not moving.
struct TODoorAncient06 : public TODoorBase {
    TODoorAncient06(TObject *parent, void *set_data);
    virtual ~TODoorAncient06();
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

typedef char TODoorAncient06_size[sizeof(TODoorAncient06) == 0xD4 ? 1 : -1];
#endif
