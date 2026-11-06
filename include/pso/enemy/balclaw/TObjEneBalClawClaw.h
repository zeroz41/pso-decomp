#ifndef PSO_ENEMY_BALCLAW_TOBJENEBALCLAWCLAW_H
#define PSO_ENEMY_BALCLAW_TOBJENEBALCLAWCLAW_H

#include "types.h"
#include "pso/enemy/balclaw/TObjEneBalClaw.h"

struct TObjEneBalClawClaw : public TObjEneBalClaw {
    TObjEneBalClawClaw(TObject *parent, TObjEneBalClaw *body, s32 id, s32 index, Vec *pos, s32 rot_y, s32);
    TObjEneBalClawClaw(TObject *parent, void *set_data);
    virtual ~TObjEneBalClawClaw();
    virtual void run_task();
    virtual void render();
    void update_attack_distance_state();
    void sub_80090D3C();
    void sub_80090798();
    virtual void vfunc_58();
    void sub_80090824();
    void sub_800914A4();
    void sub_80090418(s32);
    void update_state();
    void *create(void *arg1, void *arg2, void *arg3, void *arg4, void *arg5);
    void *create();
    static void spawn_child_enemy();
    u8 unk_3C0[0x6];
    s16 m_3c6;
    u8 unk_3C8[0x60];
    void set_claw_flags();
    void clear_flag();
    void enter_hit_state(s16 arg1);
    s32 check_active();
    void update_chase_state();
    void run_active_state();
};

typedef char TObjEneBalClawClaw_size[sizeof(TObjEneBalClawClaw) == 0x428 ? 1 : -1];

extern "C" {
s32 TObjEneBalClawClaw__ct(void *arg0);
void TObjEneBalClawClaw__sub_80090A10(u8 *arg0, u8 *arg1, s32 arg2, s16 arg3);
void action__18TObjEneBalClawClawFPv(u8 *arg0);
int reset_active_state__18TObjEneBalClawClawFPv(void *p);
void run_active_state__18TObjEneBalClawClawFv(u8 *arg0);
void spawn_lobby_npc_enemy(void);
void update_chase_state__18TObjEneBalClawClawFv(u8 *arg0);
}

#endif
