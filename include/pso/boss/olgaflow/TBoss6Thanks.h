#ifndef PSO_BOSS_OLGAFLOW_TBOSS6THANKS_H
#define PSO_BOSS_OLGAFLOW_TBOSS6THANKS_H
#include "types.h"
#include "pso/system/task/TObject.h"
struct TBoss6Thanks : public TObject {
    TBoss6Thanks(TObject *parent);
    virtual ~TBoss6Thanks();
    s32 m_1c;
    s32 current_motion;
    s32 m_24;
    f32 frame0;
    f32 frame1;
    f32 opacity;
    s32 fade_frame;  // update_fade_out counts it to 120
    void *model0;
    void *model1;
    s32 texture0;
    s32 texture1;
    void *motions[2];
    void *motion1;
    virtual void run_task();
    virtual void render();
    // int: the body widens a bool (clrlwi) and its callers test r3 with a plain cmpwi.
    static s32 check_ship_door();
    static void dispatch_darkfalz_phase();
    void update_particle_emitters();
    void destroy_effects();
    static int is_player_near(void *arg0);
    void update_fade_out();
    void advance_thanks_state();
    void mark_done();
    static void *create();
    static s32 is_ship_door_ready();
    static s32 try_dispatch_darkfalz_phase();
    u8 unk_54[0x10];
};
LAYOUT_ASSERT(TBoss6Thanks_size, sizeof(TBoss6Thanks) == 0x64);

// Story flag 0x9A test next to check_ship_door(); int return for the same reason.
extern "C" s32 fn_8035CAE0(void);
#endif
