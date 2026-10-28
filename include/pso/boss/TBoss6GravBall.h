#ifndef PSO_BOSS_TBOSS6GRAVBALL_H
#define PSO_BOSS_TBOSS6GRAVBALL_H

#include "types.h"
#include "pso/object/TObjMotion.h"
#include <dolphin/mtx.h>

struct TBoss6GravBall : public TObjCollidable {
    TBoss6GravBall(s32 arg1, void *arg2);
    virtual ~TBoss6GravBall();
    virtual void run_task();
    u32 m_ac;
    u32 m_b0;
    u32 m_b4;
    u8 _padB8[0x8];
    u32 m_c0;
    u32 m_c4;
    Vec ball_position;
    static void clear_player_grav_flags();
    s32 clamp_to_ground();
    void update_state(void *);
    void update_charge_effects(void *);
    void update_lifetime(void *);
    void destroy_part(s32 arg1);
    void create_emitter(s32 arg1);
    void init_parts();
    virtual void render();
    s32 get_state();
    u8 unk_D4[0x24];
};

typedef char TBoss6GravBall_size[sizeof(TBoss6GravBall) == 0xF8 ? 1 : -1];
#endif
