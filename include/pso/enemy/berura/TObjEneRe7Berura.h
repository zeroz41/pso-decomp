#ifndef PSO_ENEMY_BERURA_TOBJENERE7BERURA_H
#define PSO_ENEMY_BERURA_TOBJENERE7BERURA_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80490470.h"
#include "pso/system/NinjaTypes.h"

class TParticleCtrl;
class TAttackTraceStrip;
struct TObjEneRe7BeruraPunch;

// What TObjEnemy::movementParameters points at for the Berura.
struct TObjEneRe7BeruraMovementParameters {
    f32 unknown_00;
    f32 unknown_04;
    s32 unknown_08;
    u32 unknown_0C[4];
};

// One of the Berura's two arms (TObjEneRe7Berura__detached_part_states): the node matrices sampled
// at the launch frame draw the arm while it flies as a TObjEneRe7BeruraPunch.
struct TObjEneRe7BeruraPart {
    void show();
    void hide();

    GC_Mtx *node_matrices;
    s32 first_node;
    s32 last_node;
    s32 action;            // the punch's action (lattack / rattack)
    f32 emit_end_frame;    // hand emitters follow the hands before this frame
    f32 launch_frame;      // the punch leaves at this frame of the action
    NJS_OBJECT *first_object;
    NJS_OBJECT *last_object;
    NJS_OBJECT object;     // stands in for first_object while the arm is drawn alone
    Vec launch_offset;     // hand position at launch_frame, from the body
};

LAYOUT_ASSERT(TObjEneRe7BeruraPart_size, sizeof(TObjEneRe7BeruraPart) == 0x64);

// TObjEneRe7Berura::status_flags.
enum {
    BERURA_HIDDEN = 0x1,      // render draws nothing
    BERURA_BODY_FADE = 0x2,   // render draws through body_fade
    BERURA_NO_FLINCH = 0x4    // hits only clear the attack receipts
};

// TObjEneRe7Berura::arm_flags.
enum {
    BERURA_ARM_DETACHED = 0x1,  // hidden on the body
    BERURA_ARM_FLYING = 0x2,    // the punch has not come back
    BERURA_ARM_REGROWING = 0x4  // drawn through arm_fade
};

struct TObjEneRe7Berura : public TObjEneDD_ST {
    TObjEneRe7Berura(TObject *parent, void *set_data);
    virtual ~TObjEneRe7Berura();
    virtual void update_body_colliders();
    virtual void run_demo_task();
    virtual void render_demo();
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    void sub_80095328();
    void render();
    void run_task();
    virtual void dispatch_action(u32 state, s32 reason);
    void handle_message_transition(s32 msg);
    void state_attack(s32 reason);
    void update_hidden_state(s32 reason);
    void update_emerge_state(s32 reason);
    void update_walk_state(s32 reason);
    void update_punch_state(s32 reason);
    void update_melee_state(s32 reason);
    void run_flash_warning_state(s32 reason);
    void handle_state(s32 reason);
    void state_patrol(s32 reason);
    void update_damage_state(s32 reason);
    void update_death_state(s32 reason);
    s32 check_death_trigger();
    void play_band_sound();
    void reload_stats_from_tables();
    void reload_base_stats();
    void destroy_parts();
    void clear_arm_flying();
    s32 get_dizzy_duration();
    s32 is_over_limit();
    s32 step_toward_target(s32 angle, s32 max_step);
    void reset_turn_total();
    s32 get_turn_limit();
    s32 is_arm_ready();
    s32 acquire_target_in_view();
    static void draw_arm(s32 arm);
    static void draw_saved_node_tree(NJS_OBJECT *obj, GC_Mtx *matrices);
    static void draw_node_tree(NJS_OBJECT *obj);
    static void capture_arm_matrices(NJS_OBJECT *root, TObjEneRe7BeruraPart *arm);
    static s32 collect_node_matrices(NJS_OBJECT *obj, s32 idx);
    void update_collision_center();
    void init_enemy();
    static void destroy_children();
    void *create();
    static void load_static_resources();
    static void advance_state(NJS_OBJECT *);
    static void demo_frame_callback(NJS_OBJECT *);
    TObjEneRe7BeruraPunch *spawn_punch();

    u32 status_flags;            // BERURA_*
    u32 node2_color;             // material colour of model node 2 (alpha rises while emerging)
    u32 node1_color;             // material colour of model node 1 (flashes while dizzy)
    s32 texture_scroll_speed;
    s32 texture_scroll;          // render scrolls the body strips by it
    s32 dizzy_level;             // +1 after every dizzy spell; scales turn_limit and the next spell
    TUnk_80490470 body_fade;
    s32 current_arm;             // the arm the next punch throws (0 / 1)
    TObjEneRe7BeruraPunch *punch;
    TUnk_80490470 arm_fade;      // fades the thrown arm back in
    u32 arm_flags[2];            // BERURA_ARM_*
    Vec hand_positions[2];       // the hand emitters follow these
    TParticleCtrl *hand_emitters[2];
    TAttackTraceStrip *attack_trails[2];
    RenderFadeState camera_fades[4];
    s32 turn_limit;              // turning this far in total makes it dizzy (state 7)
    s32 turn_total;
    s32 step;                    // state work variables
    s32 counter;
    s32 target_angle;
    s32 pad_4cc;
    f32 accum;
    f32 emit_end_frame;
    Vec walk_dir;                // sin, 0, cos of rotation_y when the walk starts
};

LAYOUT_ASSERT(TObjEneRe7Berura_size, sizeof(TObjEneRe7Berura) == 0x4E4);
LAYOUT_ASSERT(TObjEneRe7Berura_body_fade, offsetof(TObjEneRe7Berura, body_fade) == 0x3D8);
LAYOUT_ASSERT(TObjEneRe7Berura_camera_fades, offsetof(TObjEneRe7Berura, camera_fades) == 0x448);
#endif
