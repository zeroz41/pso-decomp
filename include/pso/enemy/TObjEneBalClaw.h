#ifndef PSO_ENEMY_TOBJENEBALCLAW_H
#define PSO_ENEMY_TOBJENEBALCLAW_H

#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/player/TUnk_80490470.h"

struct TObjEneBalClaw : public TObjEnemyCustom {
    TObjEneBalClaw(TObject *parent);
    virtual ~TObjEneBalClaw();
    void set_attack_distance_flag();
    void clear_attack_flag();
    virtual void vfunc_62();
    virtual void vfunc_61();
    virtual void vfunc_59();
    virtual s32 update_movement_status();
    virtual s32 update_action_hold_status();
    virtual s32 is_target_in_attack_range();
    u8 _pad38C[0x4];
    TUnk_80490470 fade;
    f32 m_3ac;
    f32 m_3b0;
    f32 m_3b4;
    u32 m_3b8;
    void render_scaled(s32 arg1);
    void update_wobble();
    void update_claw_angle();
    static void release_global_805D4F20();
    void clear_flag_in_state7();
    f32 m_3bc;
};

typedef char TObjEneBalClaw_size[sizeof(TObjEneBalClaw) == 0x3C0 ? 1 : -1];

extern "C" {
void TObjEneBalClawClaw__sub_8008DC14(void);
void TObjEneBalClaw__sub_8008D68C(void);
void *__dt__14TObjEneBalClawFv(void *arg0, s16 arg1);
}

#endif
