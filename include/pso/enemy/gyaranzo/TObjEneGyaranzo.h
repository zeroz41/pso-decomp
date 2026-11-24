#ifndef PSO_ENEMY_GYARANZO_TOBJENEGYARANZO_H
#define PSO_ENEMY_GYARANZO_TOBJENEGYARANZO_H

#include "types.h"
#include "dolphin/mtx.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80494938.h"

struct BmlResource;

// Modes (TObjChara::mode): 0 idle, 1 chase, 2 aim and fire, 4 damaged, 5 death,
// 7 fade in, 8 walk home, 9 chase dropping mines.
struct EnemyPlacement;

struct TObjEneGyaranzo : public TObjEnemyCustom {
    TObjEneGyaranzo(TObject *parent, EnemyPlacement *set_data);
    virtual ~TObjEneGyaranzo();
    // Throws three chips of the hahen01-03 fragment models from above the body.
    void spawn_hit_fragments();
    void select_targets();
    virtual void run_task();
    virtual void render();
    void sub_800D37F4();
    // Advances break_stage and throws the parts that break off as chips.
    void break_off_parts();
    void init_params_from_table();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    virtual void run_idle_action();
    virtual s32 is_target_in_attack_range();
    virtual void run_move_action();
    virtual void run_miss_reaction();
    virtual s32 update_movement_status();
    virtual s32 update_shock_clock();
    void clear_flag_and_update();
    void spawn_missile();
    void spawn_missile_volley();
    void update_walk_to_target();
    void dispatch_state_update();
    void update_death_breakup();
    void update_aim_and_fire();
    // Modes 1 and 9: walk after the target (mode 9 drops a mine every 20 units).
    void update_chase_target();
    // Mode 4: the damage02 action while the knockback velocity dies down.
    void update_damaged();
    // Mode 7: fade the body in (appear_fade).
    void update_fade_in();
    // Hides the first broken_part_count parts and, from break stage 1, two more nodes.
    void hide_broken_parts();
    void run_demo_task();
    s32 broken_part_count;
    Vec chase_destination;
    f32 chase_distance;        // walked since the chase began
    f32 chase_distance_limit;  // the chase ends here
    f32 mine_drop_distance;    // walked since the last mine
    s32 break_stage;           // 0-2, see break_off_parts
    u32 pad_3AC;
    s32 low_hp_threshold;      // a third of the starting hp
    u32 mine_chase_count;
    s32 fragment_cooldown;     // frames until the next spawn_hit_fragments
    u32 target_ids[4];         // select_targets, nearest first
    s32 target_count;
    TUnk_80494938 appear_fade;
    RenderFadeState camera_fades[4];  // one per camera (render indexes it by camera mode)
    static void *create(void *set_data);
    static void free_static_instances();
};

LAYOUT_ASSERT(TObjEneGyaranzo_size, sizeof(TObjEneGyaranzo) == 0x45C);
LAYOUT_ASSERT(TObjEneGyaranzo_target_ids, offsetof(TObjEneGyaranzo, target_ids) == 0x3BC);

extern BmlResource *gyaranzo_bml_resource;
// The frame count after which spawn_missile_volley's missiles go off.
extern s32 gyaranzo_missile_volley_end_time;

// The Gyaranzo parameter table (TLobby::dispatch_shared_handler_a(0x1D)).
struct GyaranzoParameters {
    f32 floats[6];
    s32 ints[4];
};
extern GyaranzoParameters *gyaranzo_missile_param_table;
// Entries of gyaranzo_missile_param_table.
f32 get_gyaranzo_missile_float_parameter(s32 i);
s32 get_gyaranzo_missile_int_parameter(s32 i);

#endif
