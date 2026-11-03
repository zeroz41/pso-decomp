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
    f32 m_374;  // update_object_view_visibility's first argument
    f32 m_378;  // ... and its second
    f32 m_37c;
    s32 m_380;    // the bobbing phase, advanced by 2184 per frame
    f32 unk_384;  // the parts' vertical spread in render
    f32 m_388;    // the effect part's scale in render
    u32 m_38c;    // the spinning part's y rotation
    Vec m_390;    // apply_actor_gravity's position; the shadow is drawn there
    s32 m_39c;    // the last update_object_view_visibility result
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
