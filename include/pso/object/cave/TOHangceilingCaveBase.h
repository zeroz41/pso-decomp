#ifndef PSO_OBJECT_CAVE_TOHANGCEILINGCAVEBASE_H
#define PSO_OBJECT_CAVE_TOHANGCEILINGCAVEBASE_H
#include "types.h"
#include "pso/object/base/TObjChara.h"

// Base of the TOHangceilingCave01 hanging-ceiling objects.
class TObjPlayer;

class TOHangceilingCaveBase : public TObjChara {
public:
    TOHangceilingCaveBase(TObject *parent, ObjectSetData *set_data);
    virtual ~TOHangceilingCaveBase();
    virtual void run_task();
    virtual void render();
    virtual s32 select_melee_contact_body(TObjChara *, f32);
    virtual int calc_distance_accuracy_penalty(TObjChara *, CollisionBody *, const Vec *, float);
    virtual f32 receive_physical_attack(TObjChara *, f32);
    virtual f32 receive_direct_attack(TObjBase *, DirectAttackPayload, CollisionBody *, s32, s32);
    virtual f32 receive_weapon_special_attack(TObjChara *, CollisionBody *);
    virtual void apply_knockback_from_attacker(TObjBase *, f32);
    virtual void begin_wait();
    virtual void update_state();
    virtual f32 calc_damage(f32);
    s32 is_in_view();
    void add_hit_player(TObjPlayer *player);
    void init_geometry();
    void hit_touching_players();
    void play_mode_sound();
    void set_mode(s32);
    s32 has_hit_player(TObjPlayer *player);
    void advance_frame();
    void clear_hit_players();
    void set_damage(f32);
    u8 pad_334[0x4];
    f32 damage;  // the base hit power; calc_damage scales it by the difficulty
    TObjPlayer *hit_players[4];  // 0x33C: players hit_touching_players already hit (inferred name)
    s32 hit_player_count; // 0x34C: entries used in hit_players (inferred name)
    f32 wait_interval;  // frames of one wait step (the lights show one step each)
    f32 wait_timer;     // frames left before it drops; the indicator lights follow it
    u32 display_mode;   // set_params[2]: 0 lights follow the timer, else the switch colours the model
    s32 switch_id;  // 0x35C: set_params[0], the floor switch it waits on (inferred name)
};

LAYOUT_ASSERT(TOHangceilingCaveBase_size, sizeof(TOHangceilingCaveBase) == 0x360);

// calc_damage's damage multiplier for each difficulty (hang_ceiling_cave_scale_params).
struct HangCeilingCaveDamageScale { f32 by_difficulty[4]; };

#endif
