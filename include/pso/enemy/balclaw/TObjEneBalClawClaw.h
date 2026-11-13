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
    f32 m_3c0;             // xz distance squared to where it is moving (the body while following it)
    u8 unk_3C4[0x2];
    u16 m_3c6;             // entity id of the body it follows
    s16 m_3c8;             // frames left to chase
    u8 unk_3CA[0x5E];
    void set_claw_flags();
    void clear_flag();
    void enter_hit_state(s16 arg1);
    s32 check_active();
    void update_chase_state();
    void run_active_state();
    static void update_chase(void *claw);
    static void action(void *claw);
    static void update_follow_parent(void *claw);
    static void update_move_to_target(void *claw);
    static int reset_active_state(void *claw);
    static void update_drop(void *claw);
};

typedef char TObjEneBalClawClaw_size[sizeof(TObjEneBalClawClaw) == 0x428 ? 1 : -1];

extern "C" {
void TObjEneBalClawClaw__ct(TObjEneBalClawClaw *claw);
void TObjEneBalClawClaw__sub_80090A10(TObjEneBalClawClaw *claw, Vec *pos, s32 rot_y, s16 hp);
void spawn_lobby_npc_enemy(void);
}

#endif
