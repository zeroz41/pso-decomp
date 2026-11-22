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
    // boss2_dust_output_table, wrapping to 0 (name inferred).
    static s32 next_strip_slot();
    // Empty; called by TLobby::init_boss2_stage, which is the twin of free_boss7_tunnel
    // (name inferred).
    static void free_strips();
    // Builds the strip shape, rotation and phase tables and resets the slot counter;
    // called by TLobby__sub_8003A9AC after the common resource loads (name inferred).
    static void init_strips();
};

void boss2_dust_draw_at(const Vec *position, s32 slot);

#endif
