#ifndef PSO_BOSS_OLGAFLOW_TBOSS6MINE_H
#define PSO_BOSS_OLGAFLOW_TBOSS6MINE_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/enemy/TObjEnemy.h"

struct TBoss6Mine : public TObjEnemy {
    virtual ~TBoss6Mine();
    virtual void run_task();
    virtual void vfunc_63();
    virtual void vfunc_62();
    virtual void render_shadows();
    virtual void render();
    u32 m_374;
    u32 m_378;
    s32 heading;
    s32 state;
    u32 m_384;
    u32 m_388;
    s32 state_frames;
    u32 m_390;
    u32 m_394;
    u32 m_398;
    f32 anim_frame;
    u32 rise_delay;
    u32 spread_frames;
    u32 arm_delay;
    f32 travel_distance;
    Vec start_pos;
    Vec target_pos;
    f32 fade_amount;
    void *emitter;
    void copy_pos();
    void draw();
    void update_facing_angles();
    s32 is_far_from_origin();
    static s32 create(s32 arg0);
    static f32 next_random_float(s32 *arg0);
    void explode_damage_players();
    void state_0();
    void state_1();
    void state_2();
    void state_3();
    void state_4();
    void state_5();
    void state_6();
    void state_7();
};

typedef char TBoss6Mine_size[sizeof(TBoss6Mine) == 0x3D0 ? 1 : -1];

extern "C" {
s32 TBoss6Mine__ct(s32 arg0, s32 parent, s32 arg2);
void *__dt__10TBoss6MineFv(void *arg0, s16 arg1);
void explode_damage_players__10TBoss6MineFv(u8 *arg0);
}

#endif
