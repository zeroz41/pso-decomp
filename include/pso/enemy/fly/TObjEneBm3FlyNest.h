#ifndef PSO_ENEMY_FLY_TOBJENEBM3FLYNEST_H
#define PSO_ENEMY_FLY_TOBJENEBM3FLYNEST_H

#include "types.h"

struct NJS_OBJECT;
#include <stddef.h>
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/render/RenderFadeState.h"

struct BmlResource;
struct TObjEneBm3Fly;

struct EnemyPlacement;

// The nest of the Bm3 flies: it keeps up to six TObjEneBm3Fly children alive (start_num at
// first, total_num in all, both from its set parameters) and sends TObjEneBm3FlyNest_CarryFly
// effects out when it is hit.
struct TObjEneBm3FlyNest : public TObjEneDD {
    TObjEneBm3FlyNest(TObject *parent, EnemyPlacement *set_data);
    virtual ~TObjEneBm3FlyNest();
    virtual void run_task();
    virtual void render();
    virtual void render_shadows();
    virtual void refresh_target();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void update_body_colliders();
    // Slot 104, the first one TObjEneDD leaves to its subclasses; run_task calls it in demo mode.
    virtual void init();
    virtual void render_with_state_debug();
    void init_params();
    // dispatch_action's handlers, one per state; reason is TObjEneDD's 4 enter / 3 check /
    // 0 update / 5 leave.
    void handle_appear(s32 reason);         // state 0
    void state_initial_emit(s32 reason);    // state 1
    void state_wait(s32 reason);            // state 2
    void handle_event(s32 reason);          // state 3
    void update_down_state(s32 reason);     // state 4
    void update_state(s32 reason);          // state 5
    void state_spawn(s32 reason);           // state 6
    void handle_motion_event(s32 reason);   // state 7
    void state_dying(s32 reason);           // state 8
    void handle_state(s32 reason);          // state 9
    s32 has_pending_spawns();
    Vec *get_spawn_point();
    s32 copy_target_state(s32 sound_id);
    static void capture_attachment(NJS_OBJECT *object);
    static void handle_attachment_sample(NJS_OBJECT *object);
    static BmlResource *get_bml_resource();
    void remove_child(TObjEneBm3Fly *child);
    s32 has_free_attack_slot(u16 id);
    void spawn_child();
    void update_replenish();
    void copy_pos();
    static void free_fly();
    static void *create(void *set_data);
    static void load_resources();
    static void init_vertex_table();

    s32 state;           // 0x38C "STATE : NORMAL/DEAD/FALLEN" (2/9/5) in render_with_state_debug
    s32 start_num;       // 0x390 "START NUM"
    s32 total_num;       // 0x394 "TOTAL NUM", capped by the set entry
    s32 pad_398[4];
    s32 fallen;          // set once it has gone down (state 4/5): hits and death take the fallen motions
    s32 drawn;           // render drew it this frame
    s32 child_count;     // live children in child_ids
    s32 spawned_count;   // children spawned so far (capped by total_num)
    u16 child_ids[6];
    u16 next_child_id;   // entity id the next child gets
    Vec attachment_points[2];  // model nodes 36 and 45 in view space; [1] is where children come out
    Vec carry_origins[8];      // nodes sampled while it lands: where the CarryFly effects start
    RenderFadeState fades[4];  // one per camera (render)
    f32 height_offset;   // render draws the model this far above position
    u32 replenish_state; // update_replenish's state
    s32 pending_spawns;  // flies left to send out (spawn_child decrements it)
    s32 replenish_timer;
    s32 replenish_count;    // flies per replenish (1, 2 once fallen)
    s32 replenish_interval; // frames between replenishes
    s32 counter;         // state work variables
    union {
        s32 carry_release;  // appear: CarryFly index allowed to leave (their *arrived)
        s32 emitted;        // initial emit: children sent out so far
        s32 sound_timer;    // dying
    };
    s32 step;
    s32 descent_wave;    // appear: wobble of the drop
    f32 sink_depth;      // dying: how far it has sunk into the ground
};

LAYOUT_ASSERT(TObjEneBm3FlyNest_size, sizeof(TObjEneBm3FlyNest) == 0x4DC);
LAYOUT_ASSERT(TObjEneBm3FlyNest_child_count_offset, offsetof(TObjEneBm3FlyNest, child_count) == 0x3B0);
LAYOUT_ASSERT(TObjEneBm3FlyNest_fades_offset, offsetof(TObjEneBm3FlyNest, fades) == 0x440);
LAYOUT_ASSERT(TObjEneBm3FlyNest_sink_depth_offset, offsetof(TObjEneBm3FlyNest, sink_depth) == 0x4D8);


#endif
