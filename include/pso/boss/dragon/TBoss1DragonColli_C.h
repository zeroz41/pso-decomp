#ifndef PSO_BOSS_DRAGON_TBOSS1DRAGONCOLLI_C_H
#define PSO_BOSS_DRAGON_TBOSS1DRAGONCOLLI_C_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct Vec;

class TBoss1DragonColli_C : public TObjCollidable {
public:
    TBoss1DragonColli_C(TObject *parent, s32 count, Vec *pos, f32 scale);
    virtual ~TBoss1DragonColli_C();
    void clear_segment_flags();
    virtual void render();
    u8 unk_AC[0xC];
};
LAYOUT_ASSERT(TBoss1DragonColli_C_size, sizeof(TBoss1DragonColli_C) == 0xB8);

#endif
