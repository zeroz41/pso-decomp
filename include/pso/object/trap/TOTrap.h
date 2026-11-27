#ifndef PSO_OBJECT_TRAP_TOTRAP_H
#define PSO_OBJECT_TRAP_TOTRAP_H

#include "types.h"
#include "pso/object/base/TObjChara.h"

struct TOTrap : public TObjChara {
    static const char *class_name;
    TOTrap(TObject *parent);
    virtual ~TOTrap();
    virtual void find_target_player();
    virtual void submit_cursor_and_notify();
    virtual void update_springing();
    virtual void update_holding();
    virtual s32 is_any_player_matching_stat();
    virtual void update_effects();
    virtual void play_sounds();
    virtual void draw_debug_home_marker();
    virtual f32 scale_by_table_value(f32 table_value);
    virtual void run_demo();
    virtual void vfunc_89();
    virtual f32 receive_physical_attack(TObjChara *, f32);
    virtual void apply_saved_state(s16 *, s32);
    virtual void run_task();
    virtual void render();
    // Attacks from anyone but the held player count as a plain physical hit.
    virtual s32 try_start_action(TObjChara *attacker, s32, f32) { return (u8)(attacker != target); }
    virtual s32 roll_physical_accuracy(TObjChara *attacker, s32, f32) { return (u8)(attacker != target); }
    virtual s32 select_melee_contact_body(TObjChara *attacker, f32) { return (u8)(attacker != target); }
    virtual int calc_distance_accuracy_penalty(TObjChara *attacker, CollisionBody *, const Vec *, float) { return (u8)(attacker != target); }
    virtual f32 receive_direct_attack(TObjBase *attacker, DirectAttackPayload, CollisionBody *, s32, s32) {
        if (attacker != target) {
            receive_physical_attack(NULL, 1.0f);
        }
        return 0.0f;
    }
    virtual f32 receive_weapon_special_attack(TObjChara *attacker, CollisionBody *) {
        if (attacker != target) {
            receive_physical_attack(NULL, 1.0f);
        }
        return 0.0f;
    }
    virtual void apply_knockback_from_attacker(TObjBase *, f32) {}
    f32 range;
    f32 dist;
    u16 player;
    u8 _pad33E[0x2];
    s32 visible;  // update_object_view_visibility in render: 1 draws the trap
};

// The radius of an actor's collision body `body` (TOTrapAncient01's TU); the traps
// shrink their hold distance by the held player's body radius.

LAYOUT_ASSERT(TOTrap_size, sizeof(TOTrap) == 0x344);
#endif
