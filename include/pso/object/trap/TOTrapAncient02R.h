#ifndef PSO_OBJECT_TRAP_TOTRAPANCIENT02R_H
#define PSO_OBJECT_TRAP_TOTRAPANCIENT02R_H

#include "types.h"
#include "pso/object/trap/TOTrapAncient02.h"

struct TOTrapAncient02R : public TOTrapAncient02 {
    TOTrapAncient02R(TObject *parent, ObjectSetData *set_data);
    virtual ~TOTrapAncient02R();
    void init_trap_object_id();
    void clamp_trap_level_param();
    void init_trap_param_clamped();
    virtual s32 is_any_player_matching_stat();
    virtual void submit_cursor_and_notify();
    virtual void find_target_player();
    virtual void update_springing();
    virtual void update_holding();
    virtual void run_demo();
    virtual void draw_debug_home_marker();
    virtual s32 roll_physical_accuracy(TObjChara *, s32, f32);
    virtual s32 try_start_action(TObjChara *, s32, f32);
    virtual f32 receive_weapon_special_attack(TObjChara *, CollisionBody *);
    virtual f32 receive_direct_attack(TObjBase *, DirectAttackPayload, CollisionBody *, s32, s32);
    virtual f32 receive_physical_attack(TObjChara *, f32);
    virtual int calc_distance_accuracy_penalty(TObjChara *, CollisionBody *, const Vec *, float);
    virtual s32 select_melee_contact_body(TObjChara *, f32);
    s32 technique;  // name inferred: set param 6 clamped to 0-4, picks the technique update_springing casts (Foie, Zonde, Gibarta, Megid, Gifoie)
    s32 tech_level; // name inferred: scale.z + 2 * difficulty + 1, the level update_springing casts it at
    s32 switch_id;  // name inferred: set param 5, the floor switch find_target_player waits for (-1: none)
    s32 hits;       // name inferred: scale.y clamped to 1-256, counted down by receive_physical_attack
    void calc_trap_count();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TOTrapAncient02R_size, sizeof(TOTrapAncient02R) == 0x36C);
#endif
