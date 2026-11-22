#ifndef PSO_BOSS_OLGAFLOW_TBOSS6TUBE_H
#define PSO_BOSS_OLGAFLOW_TBOSS6TUBE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TBoss6PlotFalz;

struct TBoss6Tube : public TObject {
    TBoss6Tube(TObject *parent);
    virtual ~TBoss6Tube();
    // Turns the scroll_phase change since the last call into TBoss6Tube__scroll_delta.
    void update_scroll_delta();
    u32 state;  // run_task: 0 update_timer, 1 spawn_trap, 2 update_wobble
    u32 timer;  // update_timer's frame count; at 270 it switches to state 1
    s32 scroll_speed;  // added to scroll_phase each frame
    s32 scroll_phase;  // copied into TBoss6Tube__previous_scroll_phase
    TBoss6PlotFalz *plot_falz;  // the parent; render reads its scene state
    virtual void run_task();
    virtual void render();
    static f32 scale_by_const(f32 value);
    static f32 calc_tube_progress(s32 phase);
    static void reset_state();
    void update_wobble();
    void accelerate_scroll();
    void spawn_trap();
    void update_timer();
    static TBoss6Tube *create(void *parent);
    void activate_warp();
    // Puts run_task in state 2 (update_wobble); TBoss6PlotFalz::free_child calls it.
    void start_wobble();
    static s32 sub_802B1018();
    static void free_resources();
    static void load_resources();
};

LAYOUT_ASSERT(TBoss6Tube_size, sizeof(TBoss6Tube) == 0x30);
#endif
