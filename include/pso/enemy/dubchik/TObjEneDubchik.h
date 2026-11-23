#ifndef PSO_ENEMY_DUBCHIK_TOBJENEDUBCHIK_H
#define PSO_ENEMY_DUBCHIK_TOBJENEDUBCHIK_H
#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/render/TUnk_80494938.h"

class TParticleCtrl;
class TAttackTraceStrip;

class TUnk_80491478;

struct BmlResource;

// The dubchik's loaded BML resource (TObjEneDubchik::load_resources loads it).
extern "C" {
extern BmlResource *dubchik_resource;
extern NJS_TEXLIST *dubchik_texlist;
}

// The record TLobby::dispatch_shared_handler_a(0x1B + variant) returns (DarkGunner's layout).
struct TObjEneDubchikBehaviorParams {
    f32 float_params[6]; // 0/4 scratch01/02 motion speed, 1/5 attack range (whole/collapsed), 2 collapsed chase
                         // speed, 3 walk02 motion speed
    s32 int_params[4];   // 0 state_timer on collapsing, 1 shoot delay, 2 knockback timer, 3 shot power
};

class TObjEneDubchik : public TObjEnemyCustom {
public:
    TObjEneDubchik(TObject *parent, void *set_data);
    virtual s32 update_shock_clock();
    virtual ~TObjEneDubchik();
    static void *create(void *set_data);
    static void load_resources();
    static void free_resources();
    void target_nearest_player(f32);
    void init_level_stats(s32);
    void update_proximity_state();       // picks the next mode from the target's range
    void load_params();                  // behavior params -> motion speeds and attack range
    void apply_broken_part_visibility(); // hides the node lists of detached parts
    // The state handlers run_synced_state_handler picks by mode (names from the motions they play).
    void run_synced_state_handler();
    void update_timed_state();  // mode 0: wait
    void update_chase();        // mode 1: walk toward the target
    void update_scratch();      // mode 2: scratch01/scratch02 swing at the target
    void update_knockback();    // mode 4: damage motion, pushed back
    void update_return_home();  // mode 8: walks back to home_position
    void update_fall_apart();  // state 5 (TObjEnemyCustom::run_death_reaction): falls apart into parts, reassembles
    void update_appear();       // mode 7: starting motion while it fades in
    void update_shoot();        // mode 9: kamae then shoot01/shoot02 volleys
    void run_demo_task();
    void start_dying();
    void update_dying();
    void set_flag_start_effect();
    void clear_state7_flag();
    void set_invuln_flags();
    void clear_flag_04000000();
    s32 undo_large_move(); // back to prev_position after an xz step over 50
    f32 get_float_parameter(s32);
    s32 get_int_parameter(s32);
    virtual void run_move_action();
    virtual void run_idle_action();
    virtual void render();
    void render_model_and_set_attach_points();
    virtual void run_task();
    virtual s32 update_movement_status();
    s16 reassemble_count;  // 0x38C: bumped each time it falls apart; at 5 it stays dead (inferred)
    s16 shot_count;  // 0x38E: shots left in the volley update_shoot fires (parameters[0], default 2)
    s16 attack_count;  // 0x390: attacks since the last retarget; past 3 it retargets the nearest player (inferred)
    s16 collapsed;  // 0x392: set while the parts lie apart; render then draws with the base texlist (inferred)
    TUnk_80491478 *parts[3];  // the pieces it falls apart into
    s8 part_hit[3];
    u8 pad_3A3[0x1];
    f32 chase_distance;  // 0x3A4: distance walked while chasing; past a threshold it may switch target (inferred)
    TParticleCtrl *effect;  // 0x3A8: particle 0x119 while it falls apart (inferred)
    TAttackTraceStrip *saver;
    TUnk_80494938 fade;
    s32 knockback_timer;  // 0x3CC: frames update_knockback waits before set_invuln_flags
    f32 search_range;  // 0x3D0: passed to find_target_in_range (inferred)
    Vec part_offsets[3];
    u8 pad_3F8[0x18];
    Vec muzzle_position;  // 0x410: node 0x22, where update_shoot's particle and shots start
};
LAYOUT_ASSERT(TObjEneDubchik_size, sizeof(TObjEneDubchik) == 0x41C);

extern const char *TObjEneDubchik__class_name;

#endif
