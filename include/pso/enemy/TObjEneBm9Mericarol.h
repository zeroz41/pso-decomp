#ifndef PSO_ENEMY_TOBJENEBM9MERICAROL_H
#define PSO_ENEMY_TOBJENEBM9MERICAROL_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TObjEneDD_ST.h"

struct TObjEneBm9Mericarol : public TObjEneDD_ST {
    virtual ~TObjEneBm9Mericarol();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_88();
    virtual void vfunc_105();
    virtual void draw_color_variant();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    u8 unk_374[0x1C];
    s32 m_390;
    u8 unk_394[0xC];
    f32 m_3a0;
    u32 m_3c0;
    u32 m_3c4;
    void* m_3c8;
    u8 _pad3CC[0x6C];
    u32 m_438;
    u8 _pad43C[0x10];
    u32 m_44c;
    u32 m_450;
    u32 m_454;
    u32 m_458;
    u8 _pad45C[0x10];
    void* m_46c;
    u8 _pad470[0x10];
    u32 m_480;
    u8 _pad484[0x4];

    MaterialOpacityFade fade;

    u8 _pad4A4[0x8];
    u32 m_4ac;
    s32 get_phase();
    void init_size_tier_and_offsets();
    s32 find_nearby_target();
    s32 try_set_mode8_if_flag2();
    void sync_center_position();
    static void free_shared_instances();
    static void *create(void *arg0);
    static void update_particle_effect();
    s32 get_clamped_level();
    void handle_motion_event(s32 arg1);
    void handle_state_message(s32 msg);
    void state_burrow(s32 arg1);
    void handle_event(s32 arg1);
    void handle_action(s32 arg1);
    u8 unk_494[0x1C];
    s32 check_attack_hits();
    void handle_shot_state(s32 arg1);
};

typedef char TObjEneBm9MericarolFadeOffset[offsetof(TObjEneBm9Mericarol, fade) == 0x46C ? 1 : -1];

typedef char TObjEneBm9Mericarol_size[sizeof(TObjEneBm9Mericarol) == 0x4B0 ? 1 : -1];
#endif
