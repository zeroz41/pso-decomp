#ifndef PSO_ENEMY_BALCLAW_TOBJENEBALCLAWBODY_H
#define PSO_ENEMY_BALCLAW_TOBJENEBALCLAWBODY_H

#include "types.h"
#include "pso/enemy/balclaw/TObjEneBalClaw.h"

class TParticleCtrl;

struct TObjEneBalClawBody : public TObjEneBalClaw {
    TObjEneBalClawBody(TObject *parent, void *set_data);
    virtual ~TObjEneBalClawBody();
    void sub_800C73F4();
    int get_flag_0x388_b24();
    virtual void run_task();
    virtual void render();
    virtual void run_attack_action();
    virtual void run_idle_action();
    void sub_8008DC90();
    void sub_8008DD14();
    s32 sub_8008E098();
    void sub_8008E254();
    void sub_8008E310();
    void sub_8008EC3C();
    void sub_8008EDE8();
    void sub_8008F1DC();
    void sub_8008F910();
    void sub_8008FAD0();
    void run_death_sequence();
    void update_move_to_target();
    void reset_enemy_state();
    void set_form(s32 form);
    void calc_slot_offset_position(s32 slot, Vec *out, s32 *angle_out);
    void sub_8008FC0C();
    void sub_8008FC10();
    void sub_8008FF50();
    void update_dragon_boss_state();
    static void *create(void *set_data);
    f32 m_3c0;             // xz distance squared to the target
    u32 child_ids[4];      // entity ids of the claws; the dtor destroys the first m_3d8 of them
    s32 m_3d4;             // frames since the last merge/split (not counted while idle or returning home)
    s16 m_3d8;             // how many of child_ids are in use (the ctor sets 4)
    s16 m_3da;
    TParticleCtrl *effects[4];  // queue_destruction'd by the dtor
    Vec m_3ec;
    s32 m_3f8[3];
};

LAYOUT_ASSERT(TObjEneBalClawBody_size, sizeof(TObjEneBalClawBody) == 0x404);
#endif
