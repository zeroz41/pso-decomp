#ifndef PSO_OBJECT_CONTAINER_TCONTAINERANCIENT01R_H
#define PSO_OBJECT_CONTAINER_TCONTAINERANCIENT01R_H

#include "types.h"
#include <stddef.h>
#include "pso/object/base/TObjChara.h"

struct TContainerAncient01R : public TObjChara {
    TContainerAncient01R(TObject *parent, void *set_data);
    virtual s32 roll_physical_accuracy(void *, s32, f32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual ~TContainerAncient01R();
    virtual s32 select_melee_contact_body(void *, f32);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_physical_attack(void *, f32);
    void open_container();
    void check_open_trigger();
    void update_spawning();
    void sub_8018A688();
    void reset_hp();
    virtual void vfunc_6(s16 *, s32);
    virtual s32 try_start_action(s32, s32);
    virtual void apply_knockback_from_attacker(u8 *, f32);
    virtual void render();
    virtual void run_task();
    static void init_table_entries();
    u8 unk_334[0x4];
    s16 m_338;
    u8 unk_33A[0x2];
    f32 m_33c;
    f32 m_340;
    f32 range;
    Vec lower_effect_position;
    Vec upper_effect_position;
    void init_positions();
    void trigger_spawn(const Vec *position, s32 effect_id);
    s32 m_360;
    Vec open_scale;
    u32 m_370;
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TContainerAncient01R_size, sizeof(TContainerAncient01R) == 0x374);
LAYOUT_ASSERT(TContainerAncient01RLowerEffectOffset, offsetof(TContainerAncient01R, lower_effect_position) == 0x348);
LAYOUT_ASSERT(TContainerAncient01RUpperEffectOffset, offsetof(TContainerAncient01R, upper_effect_position) == 0x354);
LAYOUT_ASSERT(TContainerAncient01ROpenScaleOffset, offsetof(TContainerAncient01R, open_scale) == 0x364);
#endif
