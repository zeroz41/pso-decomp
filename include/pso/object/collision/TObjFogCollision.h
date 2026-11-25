#ifndef PSO_OBJECT_COLLISION_TOBJFOGCOLLISION_H
#define PSO_OBJECT_COLLISION_TOBJFOGCOLLISION_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjFogCollision : public TObjBase {
    TObjFogCollision(TObject *parent, void *set);
    virtual ~TObjFogCollision();
    virtual void init_params(s32);
    virtual void draw_debug_text();
    virtual void draw_volume();
    virtual void render();
    u32 debug_state;
    u32 far_timer;
    virtual void run_task();
    s32 check_collision(u16 client);
    // Debug switches, 0 in the retail game: render prints the debug text and draws the
    // volume when they are set, and the collision checks are skipped.
    int debug_text_enabled();
    int debug_draw_enabled();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjFogCollision_size, sizeof(TObjFogCollision) == 0x98);
#endif
