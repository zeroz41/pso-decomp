#ifndef PSO_ENEMY_SORCERER_TOBJENERE4SORCERER_H
#define PSO_ENEMY_SORCERER_TOBJENERE4SORCERER_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"

struct TObjEneRe4Sorcerer : public TObjEneDD_ST {
    virtual ~TObjEneRe4Sorcerer();
    virtual void vfunc_88();
    virtual u8 *vfunc_101(u8 *);
    virtual u8 *vfunc_102();
    virtual s32 vfunc_83();
    virtual void vfunc_106();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    void render();
    void run_task();
    u8 unk_374[0x30];
    s16 m_3c0;
    u8 _pad3C2[0x6];
    u32 m_3c8;
    void* m_3cc;
    u8 _pad3D0[0x2C];
    void* m_3fc;
    u8 _pad400[0x10];
    u32 m_410;
    u8 _pad414[0x4];
    void* m_418;
    u8 _pad41C[0x58];
    void* m_474;
    static void step_effect_sequence();
    void handle_death_state(s32 arg1);
    void update_state_machine(void *arg1p);
    void state_wait(s32 arg1);
    s32 handle_state(s32 arg1);
    void create_effect();
    s32 cast_resta();
    s32 cast_technique();
    void turn_to_target();
    void calc_orb_positions();
    void apply_mylla_effect();
    void set_photon_state();
    static s32 check_shield(s32 arg0, void *arg1);
    void advance_anim_frame();
    void request_death_effect();
    s32 try_attack(f32 farg0, f32 farg1);
    void update_collision_center();
    void init_enemy();
    static void free_bits();
    void *create();
    static void load_resources();
    u8 unk_45C[0x94];
    void set_flag3cc_bit2000();
    void invoke_state_callbacks();
    void clear_state_flag_0x10();
    void set_flag_and_notify();
    void set_attack_flag();
    void set_state_flag_and_mode(s32 arg1);
    void*get_spell_data();
    s32 get_state();
    s32 update_farthest_target(s32 arg1, f32 *arg2);
};

typedef char TObjEneRe4Sorcerer_size[sizeof(TObjEneRe4Sorcerer) == 0x4F0 ? 1 : -1];
#endif
