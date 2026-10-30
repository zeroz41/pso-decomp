#ifndef PSO_ENEMY_TOBJENEEPSILONGUARD_H
#define PSO_ENEMY_TOBJENEEPSILONGUARD_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TObjEneEpsilon.h"

struct TObjEneEpsilonGuard : public TObjEneEpsilon {
    virtual ~TObjEneEpsilonGuard();
    void sub_803626A8(s32, s32);
    void update_guard_state();
    void sub_8035EA90();
    void handle_event(s32);
    void render_guard_effect();
    virtual void vfunc_88();
    virtual void vfunc_89();
    virtual f32 receive_physical_attack(void *, f32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    void render();
    void run_task();
    u8 unk_3A8[0x90];
    s32 m_438; // 0x438
    u8 unk_43C[0x4];
    s32 m_440; // 0x440
    void* m_460;
    u8 _pad464[0x8];
    u32 m_46c;
    u16 m_470;
    u8 _pad472[0x4A];
    void* m_4bc;
    void *create(void *arg1, void *arg2, void *arg3, void *arg4);
    void init_model_and_state();
    s32 all_children_gone();
    static void update_attack_pattern(void *arg0);
    void tick_stun_timer();
    void tick_timer_set_flag();
    static void record_camera_angle_samples();
    void draw_debug_line();
    void update_step();
    void update_position();
    void dispatch_state(u32 arg1, s32 arg2);
    static s32 create_damage_font(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    static void free_shared_resources();
    static void load_assets();

    u8 _padBeforeFade[0x18];
    MaterialOpacityFade fade;
    s32 is_guard_active();
    s32 is_state_flag_set();
    s32 is_guard_ready();
    void clear_and_flag_state();
    void set_flag_8_and_notify();
    void set_target(s32 arg1, s32 arg2, s32 arg3);
    static void advance_camera_ctrl_step();
    void handle_message(s32 arg1);
    void handle_break_state(s32 arg1);
    void state_orbit(s32 arg1);
    void update_center_position();
    s32 calc_angle_to_target();
    void set_orbit_destination(s32 arg1);
    s32 assign_guard_targets();
    void action_destroy(s32 arg1);
    void update_fade(s32 arg1);
    void handle_warp_state(s32 arg1);
};

typedef char TObjEneEpsilonGuardFadeOffset[offsetof(TObjEneEpsilonGuard, fade) == 0x4BC ? 1 : -1];

typedef char TObjEneEpsilonGuard_size[sizeof(TObjEneEpsilonGuard) == 0x4D8 ? 1 : -1];
#endif
