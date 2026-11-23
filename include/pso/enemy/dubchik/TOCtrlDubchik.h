#ifndef PSO_ENEMY_DUBCHIK_TOCTRLDUBCHIK_H
#define PSO_ENEMY_DUBCHIK_TOCTRLDUBCHIK_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct TOCtrlDubchik : public TObjEnemy {
    TOCtrlDubchik(TObject *parent, void *set_data);
    virtual ~TOCtrlDubchik();
    virtual f32 receive_weapon_special_attack(void *, void *);
    // The handlers run_task picks by mode.
    void update_waiting();      // mode 0: hovers high until a Dubchik of its room goes down
    void update_bobbing();      // mode 1: sinks and spreads the parts apart
    void update_effect_grow();  // mode 2: grows the effect part, then becomes hittable
    void update_spin();         // mode 3: spins the effect part
    void kill_room_dubchiks();  // start_dying on every Dubchik (variant 0) of its room
    void run_demo_task();       // run_task's demo branch (empty)
    virtual void apply_knockback_from_attacker(u8 *, f32);
    virtual s32 roll_physical_accuracy(void *, s32, f32);
    virtual s32 try_start_action(s32, s32);
    virtual s32 select_melee_contact_body(void *, f32);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual void render();
    f32 view_range;    // update_object_view_visibility's arguments
    f32 model_radius;  // the model's bounding radius
    f32 hover_height;  // apply_actor_gravity's height; 20 + sin(bob_phase), shrinks the shadow
    s32 bob_phase;     // advanced by 2184 per frame
    f32 part_spread;   // the parts' vertical spread in render
    f32 effect_scale;  // the effect part's scale in render
    u32 spin_angle;    // the spinning part's y rotation
    Vec shadow_pos;    // apply_actor_gravity's position; the shadow is drawn there
    s32 visible;       // the last update_object_view_visibility result
    void clear_part_offsets();
    void complete_and_destroy();
    void decay_timer_and_clear_flag();
    void decay_timer_and_finish();
    virtual void run_task();
    static void *create(void *set_data);
    static void destroy_instance();
    static void load_shared_resource();
    static saddr create_font(saddr pos, s32 color, s32 life, const char *text);
};

LAYOUT_ASSERT(TOCtrlDubchik_size, sizeof(TOCtrlDubchik) == 0x3A0);
#endif
