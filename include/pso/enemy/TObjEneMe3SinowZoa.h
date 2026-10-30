#ifndef PSO_ENEMY_TOBJENEME3SINOWZOA_H
#define PSO_ENEMY_TOBJENEME3SINOWZOA_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TObjEneDD_ST.h"

struct TObjEneMe3SinowZoa : public TObjEneDD_ST {
    virtual ~TObjEneMe3SinowZoa();
    void sub_8031AC74();
    void sub_80319E74(s32);
    virtual void run_task();
    virtual void render();
    u8 check_body_collision_at(s32, f32);
    s32 sub_8031A4D0();
    u8 is_outside_visible_range();
    u8 sub_8031A454();
    void sub_8031A3D8();
    s32 render_model_if_visible();
    virtual void vfunc_88();
    virtual void vfunc_95();
    virtual void vfunc_96();
    virtual void vfunc_89();
    virtual void vfunc_105();
    virtual u8 is_target_in_range();
    virtual void vfunc_107();
    virtual void vfunc_108();
    virtual s32 try_run_effect_m6();
    virtual s32 try_run_effect_m7();
    virtual void vfunc_111();
    virtual void vfunc_112();
    virtual void action(s32);
    virtual void vfunc_115();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    u8 unk_374[0x30];
    u32 m_3c0;
    u8 _pad3C4[0x8];
    u32 m_3cc;
    u8 unk_3D0[0x10];
    u32 m_3e0;
    u8 unk_3E4[0x30];
    void* m_414;
    u8 _padBeforeFade[0x18];
    MaterialOpacityFade fade;
    void state_knockback(s32 arg1);
    void handle_state_substate(s32 arg1);
    void state_chase_target(s32 arg1);
    void update_state_action(s32 arg1);
    void state_chase(s32 arg1);
    void update_distance_state();
    f32 get_node_height();
    void setup_move_bounds();
    void copy_pos_with_height_offset();
    s32 check_floor_contact(void *arg1);
    void check_and_notify();
    static void set_entry_value_clamped(s32 arg0, f32 farg0);
    static void free_resources();
};

typedef char TObjEneMe3SinowZoaFadeOffset[offsetof(TObjEneMe3SinowZoa, fade) == 0x414 ? 1 : -1];

#endif
