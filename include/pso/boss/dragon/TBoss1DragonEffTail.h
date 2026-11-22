#ifndef PSO_BOSS_DRAGON_TBOSS1DRAGONEFFTAIL_H
#define PSO_BOSS_DRAGON_TBOSS1DRAGONEFFTAIL_H

#include "types.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/system/vector.h"

class AreaAttackHistory;
class TBoss1Dragon;

// What the dragons' tails pass to call_vt16_with_default each frame (run_task).
struct TailAttackParams { f32 power; s32 kind; };

struct TBoss1DragonEffTail : public TUnk_804928CC {
    TBoss1DragonEffTail(TBoss1Dragon *dragon, Vec *nodes);
    virtual ~TBoss1DragonEffTail();
    virtual void apply_hit_if_active(void *, f32 *);
    virtual void run_task();
    virtual void area_attack_apply_recoil(void *, f32);
    TBoss1Dragon *dragon;  // its owner: run_task follows it and refreshes its tail hit points
    Vec *nodes;            // the owner's node positions the 17 bodies are placed on
    AreaAttackHistory *attack_history;
    s32 sweep_side;        // 1 after enable, 0 after disable: picks the sign of sweep_vector
    Vec sweep_vector;      // 5 units across rotation_y; area_attack_apply_recoil pushes the target by it
    virtual void render();
    void enable();
    void disable();
    void clear_attack_history();
};

LAYOUT_ASSERT(TBoss1DragonEffTail_size, sizeof(TBoss1DragonEffTail) == 0xCC);

#endif
