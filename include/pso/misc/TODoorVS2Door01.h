#ifndef PSO_MISC_TODOORVS2DOOR01_H
#define PSO_MISC_TODOORVS2DOOR01_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct BmlResource;

// The VS-mode sliding door: its six panels slide apart along x by
// slide_offset instead of playing a motion.
struct TODoorVS2Door01 : public TODoorBase {
    enum { SLIDE_DISTANCE = 19 };  // slide_offset when fully open

    TODoorVS2Door01(TObject *parent, void *set_data);
    virtual ~TODoorVS2Door01();
    virtual void update_demo();
    virtual void update_closing();
    virtual void update_open();
    virtual void update_opening();
    virtual void update_closed();
    // Also in view while it is not closed.
    s32 is_in_view_depth(f32 min_radius);
    virtual void render();
    static void *create(void *set_data);
    static void destroy();
    static void load_resources();

    f32 slide_offset;  // 0 closed .. SLIDE_DISTANCE open, m_b8 per update

    static BmlResource *bml_resource;
    static s32 *texture_lists;  // [0] the locked texture list, [1] the bml's own
};

typedef char TODoorVS2Door01_size[sizeof(TODoorVS2Door01) == 0xD8 ? 1 : -1];

#endif
