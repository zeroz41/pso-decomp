#ifndef PSO_ENEMY_SINOWZOA_TOBJENEME3SINOWZOA_H
#define PSO_ENEMY_SINOWZOA_TOBJENEME3SINOWZOA_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"

// Per-kind parameter block from TLobby::dispatch_shared_handler_a, one for each of
// the two Sinow Zoa kinds (load_resources).
struct TObjEneMe3SinowZoaParams {
    f32 m_0;
    f32 m_4;
    f32 m_8;
    f32 m_c;
    f32 m_10;
    f32 m_14;
    s32 m_18; // level of the techniques cast_technique casts
    s32 m_1c;
    s32 m_20;
    s32 m_24; // level of its Gibarta
};

struct TObjEneMe3SinowZoa : public TObjEneDD_ST {
    TObjEneMe3SinowZoa(TObject *parent);
    virtual ~TObjEneMe3SinowZoa();
    virtual f32 receive_direct_attack(void *source, DirectAttackPayload payload, void *collider, s32, s32);
    virtual s32 vfunc_104(f32);
    virtual void dispatch_action(u32 state, s32 reason);
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
    virtual void sub_8031A6A0();
    virtual u8 is_target_in_range();
    virtual void vfunc_107();
    virtual void vfunc_108();
    virtual s32 try_run_effect_m6();
    virtual s32 try_run_effect_m7();
    virtual void vfunc_111();
    virtual void vfunc_112();
    virtual void action(s32);
    virtual void action();
    virtual void vfunc_115();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    u8 unk_374[0x4];
    s32 m_378;
    f32 m_37c;
    u8 unk_380[0x10];
    TObjChara *m_390;
    Vec m_394;
    Vec m_3a0;
    f32 m_3ac;
    u8 unk_3B0[0x10];
    s32 m_3c0;
    s32 m_3c4;
    s32 m_3c8;
    s32 m_3cc;
    s32 m_3d0;
    Vec m_3d4;
    f32 m_3e0;
    f32 m_3e4;
    // The debug overlay labels these "TECNIQ ATTACK % (+0.4f)", "STELTH ON % (+0.3f)",
    // "STELTH OFF % (+0.1f)" and "WARP % (+0.5f)": setup_move_bounds adds those bases.
    f32 technique_chance;
    f32 stealth_on_chance;
    f32 stealth_off_chance;
    f32 warp_chance;
    u32 m_3f8;
    s32 m_3fc;
    s32 m_400;
    s16 m_404;
    u8 unk_406[0x2];
    Vec unk_408; // filled with the target player's hand joint position, then a particle spawn point
    TUnk_80494938 fade;
    s32 m_430;
    s32 m_434;
    s32 m_438;
    s32 m_43c;
    f32 m_440;
    f32 m_444;
    f32 m_448;
    f32 m_44c;
    f32 m_450;
    TObject *unk_454; // queued for destruction in the dtor; writer not in this TU
    TObject *unk_458; // queued for destruction in the dtor; writer not in this TU
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
    // load_resources (inferred): the floor resource loader paired with free_resources
    // in floor_resource_callbacks.
    static void load_resources();
    static void free_resources();
    s32 advance_timer(f32 farg0);
    void copy_position_vector(void* q);
    void set_field_10(f32 v);
    void init_death_params();
};

#include <stddef.h>
typedef char TObjEneMe3SinowZoa_m_3c0_offset[offsetof(TObjEneMe3SinowZoa, m_3c0) == 0x3C0 ? 1 : -1];
typedef char TObjEneMe3SinowZoa_fade_offset[offsetof(TObjEneMe3SinowZoa, fade) == 0x414 ? 1 : -1];
typedef char TObjEneMe3SinowZoa_size[sizeof(TObjEneMe3SinowZoa) == 0x45C ? 1 : -1];

#endif
