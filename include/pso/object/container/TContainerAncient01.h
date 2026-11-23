#ifndef PSO_OBJECT_CONTAINER_TCONTAINERANCIENT01_H
#define PSO_OBJECT_CONTAINER_TCONTAINERANCIENT01_H

#include "types.h"
#include <stddef.h>
#include "pso/object/base/TObjChara.h"

struct TContainerAncient01 : public TObjChara {
    TContainerAncient01(TObject *parent, void *set_data);
    virtual s32 roll_physical_accuracy(void *, s32, f32);
    virtual ~TContainerAncient01();
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual s32 select_melee_contact_body(void *, f32);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_physical_attack(void *, f32);
    void sub_8018B700();
    void sub_8018B48C();
    void sub_8018B284();
    virtual void vfunc_6(s16 *, s32);
    virtual s32 try_start_action(s32, s32);
    virtual void apply_knockback_from_attacker(u8 *, f32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    u8 unk_334[0x4];
    s16 m_338;
    u8 unk_33A[0x2];
    f32 m_33c;
    f32 range;
    Vec lower_effect_position;
    Vec upper_effect_position;
    u32 m_35c;
    Vec open_scale;
    void spawn_effect(const Vec *position, s32 effect_id);
    void reset_state();
    void update_wait_for_player();
    void init_state_vectors();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
    static void release_static_resource();
    static void load_resources();
    static s32 is_global_state_in_table();
    u32 m_36c;
    static int get_table_entry(int a0);
};

LAYOUT_ASSERT(TContainerAncient01_size, sizeof(TContainerAncient01) == 0x370);
LAYOUT_ASSERT(TContainerAncient01LowerEffectOffset, offsetof(TContainerAncient01, lower_effect_position) == 0x344);
LAYOUT_ASSERT(TContainerAncient01UpperEffectOffset, offsetof(TContainerAncient01, upper_effect_position) == 0x350);
LAYOUT_ASSERT(TContainerAncient01OpenScaleOffset, offsetof(TContainerAncient01, open_scale) == 0x360);
#endif
