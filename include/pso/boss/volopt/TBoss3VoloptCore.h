#ifndef PSO_BOSS_VOLOPT_TBOSS3VOLOPTCORE_H
#define PSO_BOSS_VOLOPT_TBOSS3VOLOPTCORE_H

#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include <dolphin/mtx.h>

struct BmlResource;

struct TBoss3VoloptCoreMovement {
    f32 target_range;
    f32 base_speed;
    s32 turn_speed;
    s32 params[4];
};

struct TBoss3VoloptCoreBodyPart {
    u8 pad_0[0xC];
    f32 radius;
    u8 pad_10[0x8];
    u32 flags;
    u8 pad_1C[0x10];
};

class TBoss3VoloptCore : public TObjEnemyCustom {
public:
    TBoss3VoloptCore(TObject *parent, u16 id, s32 param);
    TBoss3VoloptCore(TObject *parent, void *set_data);
    virtual ~TBoss3VoloptCore();
    virtual void run_task();
    virtual void render();
    virtual s32 is_target_in_attack_range();

    static void *create(void *set_data);
    static void load_resources();
    static void release();
    static void set_grabbed_state(s32 delay);
    static void link_photon(u16 id, s32);

    void init_params();
    void load_entry_params_volopt(s32 index);
    void dispatch_reaction_state();
    void sub_80040558();
    s32 calc_hit_zone_index();
    s32 alloc_boss_target_slot();
    void set_boss_target_pos(s32 slot, s32 moves, s32 delay);
    void update_orbit_position();
    s32 calc_spin_value();
    s32 check_target_collision();
    static s32 get_orbit_speed(s32 index);
    BOOL is_mode_0();

    void run_freeze_state();
    void update_orbit_state();
    void update_charge_state();
    void update_grabbed_state();
    void update_reaction_animation();
    void update_state_spin();
    void sub_8003F81C();
    void update_topple_state();

    f32 orbit_radius;
    s32 orbit_angle;
    s32 sweep_angle;
    s32 facing_angle;
    Vec home_pos;
    s32 slot_index;
    u8 pad_3AC[0x8];
    s32 charge_step;
    s32 charge_timer;
    s32 target_slot;
    s32 moves_left;
    s32 delay;
    s32 hit_cooldown;
    TObject *effect;
    s32 drop_angle;
};

typedef char TBoss3VoloptCore_size[sizeof(TBoss3VoloptCore) == 0x3D4 ? 1 : -1];

extern s32 boss3_volopt_core_active_flag;

#endif
