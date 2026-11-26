#ifndef PSO_ENEMY_BALCLAW_TOBJENEBALCLAW_H
#define PSO_ENEMY_BALCLAW_TOBJENEBALCLAW_H

#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/render/MaterialShadeFade.h"

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
    MaterialShadeFade fade;
    f32 hover_height_min;     // hover_height sinks to this (25 body, 15 claw)
    f32 hover_height_max;     // and rises to this while behavior_flags bit 0x10000 is set (40)
    f32 hover_height;         // height of the model and collision body above the floor
    s32 wobble_angle;         // advanced 0x200 a frame while behavior_flags bit 0x20000 is set
    void set_model(s32 index);  // models[index] of the Bal Claw BML: 0 bal_body, 1 bcbody, 2 claw_body
    void render_scaled(s32 shadow);
    void update_wobble();
    void update_claw_angle();
    static void free_resources();
    static void load_resources();
    static void scroll_part_uvs();  // once a frame: scrolls the UVs of the 7 balclaw_parts
    void clear_flag_in_state7();
    f32 wobble_offset;        // 5 * sin(wobble_angle), added to hover_height
};

LAYOUT_ASSERT(TObjEneBalClaw_size, sizeof(TObjEneBalClaw) == 0x3C0);

struct BmlResource;
struct NJS_OBJECT;

// The record dispatch_shared_handler_a(31 body, 32 claw) returns (DarkGunner's layout).
struct BalClawBehaviorParams {
    f32 float_params[6];
    s32 int_params[4];  // body: 0 hp percent at which it turns on its target
};

// The Bal Claw BML archive, loaded by TObjEneBalClaw::load_resources.
extern BmlResource *balclaw_bml_resource;
// Per claw slot, the visible model nodes of that claw (NULL-terminated).
extern NJS_OBJECT *balclaw_arm_part_models[4][11];
// The body's combat-stat tables from TLobby, filled by TObjEneBalClaw::load_resources.
extern player_stats *balclaw_body_base_params[];
extern AttackParams *balclaw_body_attack_params[];
extern ActorParamBlock *balclaw_body_resistance_params[];
extern BalClawBehaviorParams *balclaw_body_behavior_params[];
// The same for the claws (TObjEneBalClawClaw::init binds them).
extern player_stats *balclaw_claw_base_params[];
extern AttackParams *balclaw_claw_attack_params[];
extern ActorParamBlock *balclaw_claw_resistance_params[];
extern BalClawBehaviorParams *balclaw_claw_behavior_params[];

struct BalClawPartEntry {
    s16 *plist;
    s16 model_index;
    s16 part_index;
    s16 uv_scroll_u;  // added to the u of the texture_id strips once a frame
    s16 uv_scroll_v;
    s16 texture_id;
    s16 pad_e;
};

#endif
