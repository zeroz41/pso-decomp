#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2DUSTCTRL_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2DUSTCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>

class TObjBoss2DustCtrl : public TObject {
public:
    TObjBoss2DustCtrl(TObject *parent);
    virtual ~TObjBoss2DustCtrl();
    virtual void run_task();
public:
    static void create();
    // Hands each new TObjBoss2Dust the next of the 10 strips of
    // boss2_dust_output_table, wrapping to 0.
    static s32 next_strip_slot();
    // Empty; called by free_boss2_tunnel.
    static void free_strips();
    // Builds the strip shape, rotation and phase tables and resets the slot counter;
    // called by init_boss2_tunnel after the common resource loads.
    static void init_strips();
};

void boss2_dust_draw_at(const Vec *position, s32 slot);

#endif
