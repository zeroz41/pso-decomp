#ifndef PSO_NPC_TOBJNPCBASE_H
#define PSO_NPC_TOBJNPCBASE_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

class TQuestThread;

// The stats block TObjChara::set_motion_params reads.
struct NpcBattleStats {
    s16 unk_00[8];
    f32 unk_10;
    u32 unk_14[4];
};

// What TObjEnemy::movementParameters points at for the town NPCs.
struct NpcMovementParameters {
    f32 unk_00;
    f32 speed;       // walking speed (enemy_set_heading_velocity)
    s32 turn_speed;  // largest turn per frame (approach_angle_limited)
    u32 unk_0C[4];
};

struct TObjNpcBase : public TObjEnemy {
    TObjNpcBase(TObject *parent);
    virtual ~TObjNpcBase();
    virtual void run_task();
    virtual void render();
    virtual void interact(u16 client);
    virtual void vfunc_83();
    virtual void update_standing();
    virtual void update_wandering();
    virtual void update_conversation();
    virtual void apply_set_params(s32, s32);
    virtual void request_action(s32 action);
    virtual void debug_draw_talk();
    virtual void play_voice();
    virtual void vfunc_91();
    virtual void vfunc_92();
    virtual void draw_debug_info();
    void sub_80149360(s32);
    void sub_80149358(s32);
    virtual void run_move_action();
    virtual void run_idle_action();
    virtual s32 is_target_in_attack_range();
    virtual void refresh_target();
    u8 unk_374[0x10];
    s32 m_384;
    s32 m_388;
    s32 m_38c;
    s32 m_390;
    s32 m_394;
    f32 m_398;
    f32 m_39c;
    s32 m_3a0;
    s32 m_3a4;
    s32 m_3a8;
    s32 m_3ac;
    TQuestThread *m_3b0;
    TObject *m_3b4;
    static void free_static();
    void setup_common();
};

extern "C" {
extern NpcBattleStats npc_default_battle_stats;
extern NpcMovementParameters npc_movement_parameters;
extern CollisionBody npc_base_collision_body_desc;
}

LAYOUT_ASSERT(NpcBaseSize, sizeof(TObjNpcBase) == 0x3B8);

#endif
