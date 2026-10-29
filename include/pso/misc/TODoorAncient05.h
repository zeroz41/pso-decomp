#ifndef PSO_MISC_TODOORANCIENT05_H
#define PSO_MISC_TODOORANCIENT05_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct BmlResource;
struct NJS_OBJECT;

// The ancient-area door on TODoorAncient07's bml with one switch light:
// locked it keeps the bml's own textures, unlocked it switches to
// fs_obj_door07_m_01_g.gvm. Like TODoorAncient06/07 it draws its first three
// model nodes detached while it is not moving.
struct TODoorAncient05 : public TODoorBase {
    TODoorAncient05(TObject *parent, void *set_data);
    virtual ~TODoorAncient05();
    virtual void update_open();
    virtual void update_closed();
    virtual void render();
    static void *create(void *set_data);
    static void free_resources();
    static void load_resources();

    static BmlResource *bml_resource;
    static s32 *texture_lists;  // [0] the bml's own (locked), [1] green (unlocked)
    static NJS_OBJECT *model_nodes;  // three nodes copied out of the bml model
};

typedef char TODoorAncient05_size[sizeof(TODoorAncient05) == 0xD4 ? 1 : -1];
#endif
