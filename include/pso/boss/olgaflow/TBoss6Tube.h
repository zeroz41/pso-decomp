#ifndef PSO_BOSS_OLGAFLOW_TBOSS6TUBE_H
#define PSO_BOSS_OLGAFLOW_TBOSS6TUBE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TBoss6Tube : public TObject {
    TBoss6Tube(TObject *parent);
    virtual ~TBoss6Tube();
    void sub_802B1218();
    u32 m_1c;
    u32 m_20;
    s32 scroll_speed;  // added to scroll_phase each frame
    s32 scroll_phase;  // copied into TBoss6Tube__previous_scroll_phase
    u32 m_2c;
    virtual void run_task();
    virtual void render();
    static f32 scale_by_const(f32 farg0);
    static f32 calc_tube_progress(s32 arg0);
    static void reset_state();
    void update_wobble();
    void accelerate_scroll();
    void spawn_trap();
    void update_timer();
    static TBoss6Tube *create(void *parent);
    void activate_warp();
    void sub_802B1004();
    static s32 sub_802B1018();
    static void free_resources();
    static void load_resources();
};

LAYOUT_ASSERT(TBoss6Tube_size, sizeof(TBoss6Tube) == 0x30);
#endif
