#ifndef PSO_BOSS_DRAGON_TBOSS1DRAGONEFFTAIL_H
#define PSO_BOSS_DRAGON_TBOSS1DRAGONEFFTAIL_H

#include "types.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/system/vector.h"

class AreaAttackHistory;

struct TBoss1DragonEffTail : public TUnk_804928CC {
    virtual ~TBoss1DragonEffTail();
    virtual void apply_hit_if_active(void *, f32 *);
    virtual void run_task();
    virtual void area_attack_apply_recoil(void *, f32);
    u32 m_b0;
    u32 m_b4;
    AreaAttackHistory *attack_history;
    u32 m_bc;
    Vec m_c0;
    virtual void render();
    void enable();
    void disable();
    int is_visible();
};

typedef char TBoss1DragonEffTail_size[sizeof(TBoss1DragonEffTail) == 0xCC ? 1 : -1];

extern "C" {
void apply_hit_if_active__19TBoss1DragonEffTailFPvPf(TBoss1DragonEffTail *arg0, u8 *arg1);
void run_task__19TBoss1DragonEffTailFv(u8 *arg0);
}

#endif
