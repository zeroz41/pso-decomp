#ifndef PSO_ENEMY_TOBJENEME1GEE_H
#define PSO_ENEMY_TOBJENEME1GEE_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TObjEneDD_ST.h"

struct TObjEneMe1Gee : public TObjEneDD_ST {
    virtual ~TObjEneMe1Gee();
    void init_state();
    virtual void vfunc_88();
    virtual u8 *vfunc_101(u8 *);
    virtual void vfunc_89();
    virtual void vfunc_105();
    virtual void vfunc_106();
    virtual void vfunc_107();
    virtual s32 vfunc_108();
    virtual int vfunc_109();
    virtual void vfunc_110(s32);
    virtual void vfunc_111(s32);
    virtual void vfunc_112(s32);
    virtual void vfunc_113();
    virtual void vfunc_114();
    virtual void vfunc_115();
    virtual int vfunc_116();
    virtual void vfunc_117(u32);
    virtual void vfunc_28();
    virtual void vfunc_63();
    virtual void vfunc_62();
    virtual void vfunc_61();
    void copy_pos();
    void sub_800CC0C4();
    void sub_800CBF58(f32);
    void sub_800CBE6C();
    void update_hover_height();
    void update_animation_frame();
    void update_fade_sequence();
    void update_packed_color();
    void sub_800CB60C();
    void sub_800CB5F0();
    void sub_800CB5D4();
    void sub_800CB5B8();
    void set_flag3c8_bit2();
    void state_attack_loop(s32);
    void render();
    void run_task();
    u8 unk_374[0x1C];
    u32 m_390;
    u8 unk_394[0xC];
    f32 m_3a0;
    u32 m_3c0;
    u32 m_3c4;
    u32 m_3c8;
    void* m_3cc;
    u8 _pad3D0[0x10];
    u32 m_3e0;

    u8 _padBeforeFade[0x4];
    MaterialOpacityFade fade;
    u32 m_404;
    u32 m_408;
    u8 _pad40C[0x4];
    u32 m_410;
    void* m_414;
    u8 _pad418[0x8];
    void* m_420;
    u8 _pad424[0xC];
    u32 m_430;
    u32 m_434;
    u8 _pad438[0x40];
    u32 m_478;
    u32 m_47c;
    u8 _pad480[0xC];
    u16 m_48c;
    static void load_resources();
    static void cache_result_805D6660();
    static void queue_debug_text(s32 arg0, char *arg1);
    u8 unk_472[0x1E];
    static void advance_camera_ctrl_step();
    void state_orbit(s32 arg1);
    void handle_event(s32 arg1);
    void state_return_home(s32 arg1);
    void state_attack(s32 arg1);
    void state_hover(s32 arg1);
    void state_move(s32 arg1);
    void set_flag3c8_bit40();
    void set_flag3c8_bit8();
    void update_photon_target();
    static s32 handle_message(s32 arg0, s32 arg1);
    s32 check_death_trigger();
    s32 check_can_attack();
    void update_angle();
    void update_from_float_sum();
    void set_move_speed_x();
    static void free_globals();
    static void *create(void *arg0);
    void set_flag3c8_bit4();
    void set_state_flag(s32 arg1, s32 arg2);
    void update();
};

typedef char TObjEneMe1GeeFadeOffset[offsetof(TObjEneMe1Gee, fade) == 0x3CC ? 1 : -1];

typedef char TObjEneMe1Gee_size[sizeof(TObjEneMe1Gee) == 0x490 ? 1 : -1];
#endif
