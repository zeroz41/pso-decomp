#ifndef PSO_ENEMY_LAPPY_TOBJENELAPPY_H
#define PSO_ENEMY_LAPPY_TOBJENELAPPY_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct BmlResource;

// TObjEneLappy::lappy_flags.
enum {
    LAPPY_NODE_VISIBLE = 0x1,   // set each frame by run_task, cleared while dying; shows model node 0x12
    LAPPY_FLEEING = 0x2,        // start_fleeing
    LAPPY_FLEE_KILLED = 0x4,    // killed while fleeing: item drop requested, tumble played
    LAPPY_NO_EXPERIENCE = 0x10, // run_death_reaction awards no experience
    LAPPY_DROP_IN = 0x20,       // spawned in the air: run_idle_action lifts it 300 above the ground
    LAPPY_FALLING = 0x40,       // spawned in the air: falls until it lands
    LAPPY_NOTIFIED = 0x80,      // set_flag_and_notify sent the entity flags
    LAPPY_GIANT = 0x400,        // drawn at 2 x 1.5 x 2 scale (v2 mode, 1 in 30)
};

// What TObjEnemy::movementParameters points at, one per variant (lappy_movement_params).
struct LappyMovementParameters {
    f32 target_range;  // find_nearest_visible_player's radius; a farther target is dropped
    f32 move_speed;    // walk speed; a target nearer than this is dropped too
    s32 turn_speed;    // turn_toward_direction's max step
    u32 unknown_0c[4];
};

// The enemy set entry create hands the constructor (TBoss4DarkFalzSetEntry's layout; field
// names from TObjEnemy::apply_set_data, which reads the same entry). A Rappy of a later wave
// drops in; a non-zero variant makes it the rare one.
struct LappySetData {
    s16 set_index;
    s16 kind;
    u8 pad_04[0x2];
    u16 entity_id;
    s16 room;
    s16 wave;
    u8 pad_0c[0x4];
    Vec position;
    s32 rotation[3];
    f32 parameters[5];
    s16 variant;
    s16 state;
};

struct TObjEneLappy : public TObjEnemy {
    TObjEneLappy(TObject *parent, void *set_data);
    virtual ~TObjEneLappy();
    virtual void run_task();
    virtual void render();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual void refresh_target();
    virtual int test_flag_256();
    virtual void run_idle_action();
    virtual void run_move_action();
    virtual void run_attack_action();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    void set_flag_1();
    void clear_flag_1();
    void set_speed_params(s32);
    void update_invuln_timer();
    void update_dying();
    void start_fleeing();
    void apply_variant_speeds();
    void clear_flags_60();
    s32 advance_flee_step();
    void set_flag_and_notify();
    s16 lappy_flags;          // LAPPY_* bits
    u8 pad_376[0x2];
    u8 idle_mode;             // update_idle_state: 0 wander, 1 stand, 2 walk back home
    u8 home_idle_mode;        // idle_mode from the set data (parameters[0]); restored near home
    s16 move_phase;           // update_moving: 0 chase, 1 close chase, 3 turn to flee_heading, 4 flee
    u8 pad_37c[0x2];
    s16 idle_timer;           // frames until the next idle cry (sound 0x3B20B) or wander
    s16 down_timer;           // frames spent with object flag 0x800 set; at 900 the rappy gets up and flees (inferred)
    s16 last_attack_target;   // targetId of the last attack
    s16 attack_streak;        // attacks in a row on last_attack_target; above 3 refresh_target picks another player
    u8 pad_386[0x2];
    s32 pad_388;
    f32 wander_distance;  // set to 30 when a wander starts, reduced by the walk speed each frame (inferred)
    s32 flee_heading;         // random angle start_fleeing picks; move_phase 3 turns toward it
    s16 flee_turn_timer;  // frames since the fleeing rappy last turned away from a player (inferred)
    s16 dust_timer;           // frames until the next dust particle (0xF3) while fleeing
    void play_walk_sound();
    void update_hurt();
    void update_attacking();
    void update_moving();
    void update_idle_state();
    void sub_800BFF54();
    static void *create(void *set);
    static void load_resources();
    static void free_resources();
    s32 pad_398;
    f32 pad_39c;
    u8 pad_3a0[0x4];
};

LAYOUT_ASSERT(TObjEneLappy_size, sizeof(TObjEneLappy) == 0x3A4);

// The Rappy model archive load_resources picks, shared with the town NPC TObjNpcLappy.
extern BmlResource *rappy_bml_resource;

// The rare and the normal Rappy texture archives TObjEneLappy::load_resources picks from. The unit
// defines them after that function, which reaches each with its own lis/addi.
extern const char re3_b_lappy_base_niji_gvm[];
extern const char re3_b_lappy_base_ao_gvm[];
#endif
