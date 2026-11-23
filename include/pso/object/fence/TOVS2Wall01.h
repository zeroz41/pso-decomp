#ifndef PSO_OBJECT_FENCE_TOVS2WALL01_H
#define PSO_OBJECT_FENCE_TOVS2WALL01_H

#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/render/RenderFadeState.h"

struct TOVS2Wall01 : public TObjChara {
    TOVS2Wall01(void *set_data);
    virtual ~TOVS2Wall01();
    virtual void vfunc_6(s16 *, s32);
    f32 view_range;
    f32 m_338;
    u32 m_33c;
    RenderFadeState m_340;
    u32 m_35c;
    void spawn_debris(s32 index);
    void release();
    int interact_player_neg1();
    virtual void run_task();
    virtual void render();
    virtual s32 select_melee_contact_body(void *, f32);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual f32 receive_physical_attack(void *, f32);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual void apply_knockback_from_attacker(u8 *, f32);
    virtual s32 try_start_action(s32, s32);
    virtual s32 roll_physical_accuracy(void *, s32, f32);
    static void *create(void *set_data);
    static void release_model();
    static void load_resources();
    void break_wall();
    f32 take_hit(TObjBase *attacker);
    s32 remaining_hits();
    void set_remaining_hits(s32 count);
    void save_and_send_state(u16 arg1);
};

LAYOUT_ASSERT(TOVS2Wall01FadeOffset, offsetof(TOVS2Wall01, m_340) == 0x340);
LAYOUT_ASSERT(TOVS2Wall01_size, sizeof(TOVS2Wall01) == 0x360);
#endif
