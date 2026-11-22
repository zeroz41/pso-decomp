#ifndef PSO_BOSS_DRAGON_TBOSS1DRAGONCOLLI_C_H
#define PSO_BOSS_DRAGON_TBOSS1DRAGONCOLLI_C_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct Vec;

class TBoss1DragonColli_C : public TObjCollidable {
public:
    TBoss1DragonColli_C(TObject *parent, s32 count, Vec *pos, f32 scale);
    virtual ~TBoss1DragonColli_C();
    void set_segment_flags();
    void clear_segment_flags();
    void enable_at(Vec *pos, s32 angle);
    void disable();
    virtual void render();
    Vec local_position;  // the chain's center relative to the dragon (enable_at places it)
};
LAYOUT_ASSERT(TBoss1DragonColli_C_size, sizeof(TBoss1DragonColli_C) == 0xB8);

#endif
