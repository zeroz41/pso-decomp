#ifndef PSO_ENEMY_TUNK_80493450_H
#define PSO_ENEMY_TUNK_80493450_H
#include "types.h"
#include "pso/enemy/TObjEnemy.h"

// What TObjEnemy::movementParameters points at for a beast (one row per
// subtype): the detection radius find_nearest_visible_player takes and the
// turn step approach_angle_limited takes.
struct BeastMovementParams {
    f32 detectionRadius;
    f32 pad_04;
    s32 turnSpeed;
    s32 pad_0C[4];
};

class TUnk_80493450 : public TObjEnemy {
public:
    virtual void run_task();
    virtual ~TUnk_80493450();
    TUnk_80493450(TObject *parent);
    virtual void refresh_target();
    virtual void run_idle_action();
    virtual void run_death_reaction();
    void update_target_near_flag();
    void sub_800C4E08();
    virtual void run_hit_reaction();
    s32 test_elt_flag(s32, s32);
    s32 countChildren();
    void link_into_group_chain();
    void unlink_enemy_group_relations();
    virtual void beast_update_appear();
    virtual void beast_idle_update();
    virtual void update_turn_toward_target();
    virtual void beast_update_approach();
    virtual void beast_update_group_chase();
    virtual void beast_update_attack();
    virtual void vfunc_89();
    virtual void beast_update_hurt();
    virtual void beast_update_dead();
    virtual void beast_retire_corpse();
    virtual void update_attack_trail();
    virtual void spawn_death_effect();
    virtual void play_alert_sound();
    virtual void play_attack_sound();
    virtual void play_hurt_sound();
    virtual void play_death_sound();
    virtual void play_group_chase_sound();
    virtual void select_post_attack_mode();
    virtual void run_demo_task();
    virtual void request_stand_action();
    virtual void run_miss_reaction();
    virtual void run_move_action();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual void run_attack_action();
    virtual int test_flag_256();
    s16 m_374;
    u16 m_376;
    s32 m_378;
    u32 m_37c;
    f32 unk_380;
    f32 m_384;
    f32 unk_388;
    u32 m_38c;
    s32 m_390;
    f32 unk_394;
    float m_398;
    f32 unk_39C;
    float m_3a0;
    f32 unk_3A4;
};

#endif
