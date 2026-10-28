#ifndef PSO_PLAYER_TUNK_804B6C24_H
#define PSO_PLAYER_TUNK_804B6C24_H
#include "types.h"
#include "pso/player/TObjChara.h"

class TUnk_804B6C24 : public TObjChara {
public:
    virtual ~TUnk_804B6C24();
    BOOL check_value_equals(s32);
    virtual void vfunc_79();
    virtual void vfunc_80();
    virtual void vfunc_81();
    virtual void debug_print_item_box_info();
    void *destroy_container_object(s16);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_physical_attack(void *, f32);
    void spawn_item(s32);
    virtual void vfunc_6(s16 *, s32);
    virtual s32 roll_physical_accuracy(void *, s32, f32);
    virtual s32 try_start_action(s32, s32);
    virtual void apply_knockback_from_attacker(u8 *);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual void render();
    virtual void run_task();
    u8 unk_334[0x4];
    f32 m_338;
    u8 unk_33C[0x24];
    s32 m_360;
    s32 m_364;
};

#endif
