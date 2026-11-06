#ifndef PSO_ENEMY_SINOWZOA_TOBJENEME3SINOWZOA_H
#define PSO_ENEMY_SINOWZOA_TOBJENEME3SINOWZOA_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"

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
    u8 pad_374[0x94];
    Vec unk_408; // filled with the target player's hand joint position, then a particle spawn point
    TUnk_80494938 fade;
    u8 pad_430[0x24];
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

#endif
