#ifndef PSO_OBJECT_TRAP_TOTRAPANCIENT02R_H
#define PSO_OBJECT_TRAP_TOTRAPANCIENT02R_H

#include "types.h"
#include "pso/object/trap/TOTrapAncient02.h"

struct TOTrapAncient02R : public TOTrapAncient02 {
    virtual ~TOTrapAncient02R();
    void init_trap_object_id();
    void clamp_trap_level_param();
    void init_trap_param_clamped();
    virtual s32 is_any_player_matching_stat();
    virtual void submit_cursor_and_notify();
    virtual void find_target_player();
    virtual void vfunc_82();
    virtual void vfunc_88();
    virtual void vfunc_86();
    virtual s32 roll_physical_accuracy(void *, s32, f32);
    virtual s32 try_start_action(s32, s32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_physical_attack(void *, f32);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual s32 select_melee_contact_body(void *, f32);
    u32 m_35c;
    u32 m_360;
    u32 m_364;
    u32 m_368;
    void calc_trap_count();
    static void *create(void *arg0);
};

typedef char TOTrapAncient02R_size[sizeof(TOTrapAncient02R) == 0x36C ? 1 : -1];
#endif
