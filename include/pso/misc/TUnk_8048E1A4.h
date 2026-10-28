#ifndef PSO_MISC_TUNK_8048E1A4_H
#define PSO_MISC_TUNK_8048E1A4_H
#include "types.h"
#include "pso/player/TObjChara.h"

class TUnk_8048E1A4 : public TObjChara {
public:
    virtual ~TUnk_8048E1A4();
    void freeze_shell_grow();
    s32 freeze_shell_hold();
    void update_freeze_shell_timer();
    virtual void apply_knockback_from_attacker(u8 *);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_physical_attack(void *, f32);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual s32 select_melee_contact_body(void *, f32);
    virtual void render();
    virtual void run_task();
    u8 unk_334[0x4];
    f32 m_338;
    u8 unk_33C[0x4];
    f32 m_340;
    u8 unk_344[0xC];
    void * m_350;
    s32 m_354;
    u8 unk_358[0x10];
};
typedef char TUnk_8048E1A4_size[sizeof(TUnk_8048E1A4) == 0x368 ? 1 : -1];

#endif
