#ifndef PSO_ENEMY_GIGUE_TOBJENEME1GIGUE_H
#define PSO_ENEMY_GIGUE_TOBJENEME1GIGUE_H

#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/render/RenderFadeState.h"
#include "pso/system/BmlResource.h"

// The tuning block TLobby::dispatch_shared_handler_a hands out for the Gi Gue
// (read by get_gigue_float_parameter and get_gigue_int_parameter).
struct GiGueParameters {
    f32 floats[6];
    s32 ints[5];
};

class TObjChara;

struct TObjEneMe1GiGue : public TObjEnemyCustom {
    TObjEneMe1GiGue(TObject *parent, void *set_data);
    virtual ~TObjEneMe1GiGue();
    void move_around_center(const Vec *center, f32 radius);
    void clear_state7_flag(); // update_action_hold_status's hook, as TObjEneNanoDrago's
    virtual void run_task();
    virtual void render();
    void update_idle_state();
    void update_proximity_state();
    void init_move();
    void update_direction();
    void load_params();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    virtual s32 update_action_hold_status();
    virtual f32 receive_physical_attack(void *, f32);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual void run_miss_reaction();
    virtual void run_move_action();
    virtual void run_attack_action();
    virtual void run_idle_action();
    u16 m_38c;
    Vec moveDestination;
    Vec missileOrigin;
    Vec shotOrigin;
    Vec rootPosition;
    s32 targetCount;
    u16 targetIds[12];
    s32 circlingAngle;
    f32 wanderDistance;
    f32 moveSpeed;
    f32 sinkingOffset;
    f32 flightHeight;
    u8 pad_3f0[0x4];
    s32 cameraShakeCooldown;
    s32 approachCount;
    TUnk_80494938 appearFade;
    RenderFadeState cameraFade;
    s32 attackAngle;
    f32 attackRange;
    f32 entryHeight;
    f32 barrierChance;
    f32 techniqueChance;
    s32 volleyCount;
    s32 barrierDuration;
    s32 attackDuration;
    s32 rushDelay;
    void dispatch_state();
    void clear_barrier_active();
    void set_barrier_active();
    s32 is_active_state();
    s32 get_barrier_duration();
    s32 get_rotation_y();
    Vec *update_and_get_pos();
    static void *create(void *set_data);
    static void delete_barrier();
    static void load_resources();
    void load_params_from_table(s32 i);
    static BmlResource *get_resource();
    void apply_hit_shake(TObjChara *player);
    s32 check_vector_bit(Vec *pos);
    s32 remap_sound_id(s32 id);
    void break_apart();
    void update_hit_reaction();
    void update_rush_attack();
    void add_target_in_cone(TObjChara *target);
    void find_open_direction(Vec *dir);
    void capture_shot_origins();
    s32 collect_shot_targets();
    void init();
    void update_landing_state();
    void spawn_targeted_shot(s32 index);
    void action();
    void update_technique_state();
    void update_multi_shot_state();
    void update_missile_state();
    void update_circling_state();
    void run_demo_task();
    void update_attack();     // mode 2 (run_attack_action's); empty, the attacks are modes 9-11
};

LAYOUT_ASSERT(TObjEneMe1GiGue_size, sizeof(TObjEneMe1GiGue) == 0x458);

// Shot parameters load_params copies from the GiGue parameter table for TUnk_804E14E8.
extern f32 gigue_shot_speed;
extern f32 gigue_shot_homing;
extern f32 gigue_shot_homing_step;
extern s32 gigue_shot_power;
#endif
