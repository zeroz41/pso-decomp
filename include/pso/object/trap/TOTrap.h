#ifndef PSO_OBJECT_TRAP_TOTRAP_H
#define PSO_OBJECT_TRAP_TOTRAP_H

#include "types.h"
#include "pso/object/base/TObjChara.h"

struct TOTrap : public TObjChara {
    TOTrap(TObject *parent);
    virtual ~TOTrap();
    virtual void find_target_player();
    virtual void submit_cursor_and_notify();
    virtual void vfunc_81();
    virtual void vfunc_82();
    virtual s32 is_any_player_matching_stat();
    virtual void vfunc_84();
    virtual void play_sounds();
    virtual void vfunc_86();
    virtual f32 scale_by_table_value(f32 farg0);
    virtual void vfunc_88();
    virtual void vfunc_89();
    virtual f32 receive_physical_attack(void *, f32);
    virtual void vfunc_6(s16 *, s32);
    virtual void run_task();
    virtual void render();
    // Attacks from anyone but the held player count as a plain physical hit.
    virtual s32 try_start_action(s32 arg1, s32) { return (u8)(arg1 != (s32)target); }
    virtual s32 roll_physical_accuracy(void *attacker, s32, f32) { return (u8)(attacker != target); }
    virtual s32 select_melee_contact_body(void *attacker, f32) { return (u8)(attacker != target); }
    virtual int calc_distance_accuracy_penalty(void *attacker, void *, void *, float) { return (u8)(attacker != target); }
    virtual f32 receive_direct_attack(void *attacker, DirectAttackPayload, void *, s32, s32) {
        if (attacker != target) {
            receive_physical_attack(NULL, 1.0f);
        }
        return 0.0f;
    }
    virtual f32 receive_weapon_special_attack(void *attacker, void *) {
        if (attacker != target) {
            receive_physical_attack(NULL, 1.0f);
        }
        return 0.0f;
    }
    virtual void apply_knockback_from_attacker(u8 *, f32) {}
    f32 range;
    f32 dist;
    u16 player;
    u8 _pad33E[0x2];
    s32 m_340;
};

typedef char TOTrap_size[sizeof(TOTrap) == 0x344 ? 1 : -1];
#endif
