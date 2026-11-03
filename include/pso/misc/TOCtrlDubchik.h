#ifndef PSO_MISC_TOCTRLDUBCHIK_H
#define PSO_MISC_TOCTRLDUBCHIK_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct TOCtrlDubchik : public TObjEnemy {
    virtual ~TOCtrlDubchik();
    virtual f32 receive_weapon_special_attack(void *, void *);
    void sub_8015CE80();
    void update_bobbing();
    void sub_8015CCF4();
    void update_spin();
    void sub_8015CA74();
    virtual void apply_knockback_from_attacker(u8 *, f32);
    virtual s32 roll_physical_accuracy(void *, s32, f32);
    virtual s32 try_start_action(s32, s32);
    virtual s32 select_melee_contact_body(void *, f32);
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
    static void *create(void *arg0);
    static void destroy_instance();
    static void load_shared_resource();
    static s32 create_font(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
};

typedef char TOCtrlDubchik_size[sizeof(TOCtrlDubchik) == 0x3A0 ? 1 : -1];
#endif
