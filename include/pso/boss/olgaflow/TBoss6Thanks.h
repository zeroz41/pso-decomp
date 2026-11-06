#ifndef PSO_BOSS_OLGAFLOW_TBOSS6THANKS_H
#define PSO_BOSS_OLGAFLOW_TBOSS6THANKS_H
#include "types.h"
#include "pso/system/task/TObject.h"
struct TBoss6Thanks : public TObject {
    virtual ~TBoss6Thanks();
    s32 m_1c;
    s32 current_motion;
    s32 m_24;
    f32 frame0;
    f32 frame1;
    f32 opacity;
    u32 m_34;
    void *model0;
    void *model1;
    s32 texture0;
    s32 texture1;
    void *motions[2];
    void *motion1;
    virtual void run_task();
    virtual void render();
    static u8 check_ship_door();
    static int dispatch_darkfalz_phase();
    void update_particle_emitters();
    void destroy_effects();
    static int is_player_near(void *arg0);
    void update_fade_out();
    void advance_thanks_state();
    void mark_done();
    static void *create();
    s32 is_ship_door_ready();
    static s32 try_dispatch_darkfalz_phase();
    u8 unk_54[0x10];
};
typedef char TBoss6Thanks_size[sizeof(TBoss6Thanks) == 0x64 ? 1 : -1];
#endif
