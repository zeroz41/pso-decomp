#ifndef PSO_BOSS_BARBARAY_TOBJBOSS7DUSTCTRL_H
#define PSO_BOSS_BARBARAY_TOBJBOSS7DUSTCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>

class TObjBoss7DustCtrl : public TObject {
public:
    TObjBoss7DustCtrl(TObject *parent);
    virtual ~TObjBoss7DustCtrl();
    virtual void run_task();
public:
    static void create();
    // Twins of TObjBoss2DustCtrl's. Names inferred from the bodies and callers.
    // Hands each new TObjBoss7Dust the next of the 10 strips, wrapping to 0.
    static s32 next_strip_slot();
    // Empty; called by free_boss7_tunnel.
    static void free_strips();
    // Builds the strip shape, rotation and phase tables and resets the slot counter;
    // called by init_scene_boss2_tunnel.
    static void init_strips();
};

void boss7_dust_draw_at(const Vec *position, s32 slot);

#endif
