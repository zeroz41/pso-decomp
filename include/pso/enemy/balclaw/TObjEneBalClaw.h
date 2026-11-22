#ifndef PSO_ENEMY_BALCLAW_TOBJENEBALCLAW_H
#define PSO_ENEMY_BALCLAW_TOBJENEBALCLAW_H

#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/render/TUnk_80490470.h"

struct TObjEneBalClaw : public TObjEnemyCustom {
    TObjEneBalClaw(TObject *parent);
    virtual ~TObjEneBalClaw();
    void set_attack_distance_flag();
    void clear_attack_flag();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    virtual void run_move_action();
    virtual s32 update_movement_status();
    virtual s32 update_action_hold_status();
    virtual s32 is_target_in_attack_range();
    s32 range_band;           // 0 near, 1 mid, 2 far: the target's xz distance band, with hysteresis
    TUnk_80490470 fade;
    f32 hover_height_min;     // hover_height sinks to this (25 body, 15 claw)
    f32 hover_height_max;     // and rises to this while m_388 bit 0x10000 is set (40)
    f32 hover_height;         // height of the model and collision body above the floor
    s32 wobble_angle;         // advanced 0x200 a frame while m_388 bit 0x20000 is set
    void render_scaled(s32 shadow);
    void update_wobble();
    void update_claw_angle();
    static void free_resources();
    static void load_resources();
    static void sub_8008D68C();
    void clear_flag_in_state7();
    f32 wobble_offset;        // 5 * sin(wobble_angle), added to hover_height
};

LAYOUT_ASSERT(TObjEneBalClaw_size, sizeof(TObjEneBalClaw) == 0x3C0);

struct BmlResource;
struct BmlMotionEntry;
struct NJS_OBJECT;

// A movement row TObjEnemy::movementParameters points at.
struct BalClawMovement {
    EnemyMoveParams move;
    s16 m_c;
    s16 m_e;
    s32 m_10;
    s32 m_14;
    s32 m_18;
};

// The motion-binding block TLobby::spawn_npc_enemy takes (same layout as
// MojaAnimationBinding and DelDepthAnimationBinding).
struct BalClawSpawnParams {
    BmlMotionEntry *motions;
    TObjMotionAction *actions;
    u32 unknown_08;
    u16 actionCount;
    u16 unknown_0E;
};

// The Bal Claw BML archive, loaded by TObjEneBalClaw::load_resources.
extern BmlResource *balclaw_bml_resource;
// Per claw slot, the visible model nodes of that claw (NULL-terminated).
extern NJS_OBJECT *balclaw_arm_part_models[4][11];
// The body's combat-stat tables from TLobby, filled by TObjEneBalClaw::load_resources.
extern u8 *balclaw_body_base_params[];
extern u8 *balclaw_body_attack_params[];
extern u8 *balclaw_body_resistance_params[];
extern u8 *balclaw_body_behavior_params[];
// The same for the claws (TObjEneBalClawClaw::sub_80091A38 binds them).
extern u8 *balclaw_claw_base_params[];
extern u8 *balclaw_claw_attack_params[];
extern u8 *balclaw_claw_resistance_params[];
extern u8 *balclaw_claw_behavior_params[];

#endif
