#ifndef PSO_BOSS_TBOSS1DRAGONCOLLI_C_H
#define PSO_BOSS_TBOSS1DRAGONCOLLI_C_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TBoss1DragonColli_C : public TObjCollidable {
public:
    virtual ~TBoss1DragonColli_C();
    void clear_segment_flags();
    virtual void render();
    u8 unk_AC[0xC];
};
typedef char TBoss1DragonColli_C_size[sizeof(TBoss1DragonColli_C) == 0xB8 ? 1 : -1];

#endif
