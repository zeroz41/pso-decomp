#ifndef PSO_BOSS_DEROLLE_TBOSS2MINE_H
#define PSO_BOSS_DEROLLE_TBOSS2MINE_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/system/vector.h"

struct TBoss2Mine : public TObjEneDD {
    // variant picks the row of the stat tables: 0 for the floor mines
    // (TUnk_80482EC0), 1 for the launched ones (TUnk_80482D04); inferred.
    TBoss2Mine(TObject *parent, u16 entity_id, s32 set_index, s32 variant);
    virtual ~TBoss2Mine();
    virtual void dispatch_action(u32 state, s32 reason);
    void set_node_offsets();
    void init(s32 variant);
    // Starts the warning pulse: waiting interval frames between flashes, rate brighter per frame.
    void init_params(s32 interval, f32 rate);
    void update_pulse_state();
    // The handlers dispatch_action() runs for each state: 0 hidden until launched, 1 thrown at its
    // target, 2 armed and counting down, 3 exploding, 4 destroyed (names inferred).
    virtual void state_hidden(s32 reason);
    virtual void state_launch(s32 reason);
    virtual void state_armed(s32 reason);
    virtual void state_explode(s32 reason);
    virtual void state_destroyed(s32 reason);
    virtual void run_demo_task();
    virtual void render_demo();
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void apply_defense_stat_status(void *);
    void apply_attack_stat_status(void *);
    void clear_harmful_statuses();
    void apply_shock_status();
    void apply_movement_ailment(s32);
    void apply_confusion_status();
    void apply_slow_status();
    void apply_paralysis();
    void apply_poison_status();
    void refresh_target();
    void set_launch_position_velocity(const Vec *start, const Vec *target);
    void render();
    void set_state_by_distance(s32 time_left);
    void update_move_flag();
    void save_position();
    void run_task();
    // The boss's resource callbacks.
    static void load_resources();
    static void free_resources();

    u32 mine_flags;            // 1 hidden, 2 on the ground (shadow), 4 flashing, 0x100 launch requested
    Vec target_pos;
    Vec throw_dir;
    s32 spike_angle;           // how far the eight spikes are opened
    f32 blast_scale;
    u32 flash_level;           // flash colour, 0..255 in the high half
    f32 pulse;
    f32 pulse_step;
    s32 pulse_wait;
    s32 pulse_interval;
    s32 pulse_phase;           // 0 brightening, 1 fading, 2 waiting, 3 off
    s32 step;
    s32 timer;
    s32 m_3d0;
    u8 unk_3D4[0x4];
    s32 tilt;
    union {
        f32 throw_distance;    // the floor mine (TUnk_80482EC0)
        f32 launch_speed;      // the launched mine (TUnk_80482D04)
    };
    union {
        f32 throw_distance_left;
        f32 homing_weight;
    };
    f32 drop_distance;         // distance left when the thrown mine starts to fall
    f32 fall_speed;
    f32 throw_speed;
};
LAYOUT_ASSERT(TBoss2Mine_size, sizeof(TBoss2Mine) == 0x3F0);

#endif
