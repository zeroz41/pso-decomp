#ifndef PSO_BOSS_DRAGON_TBOSS1DRAGONCOLLI_H
#define PSO_BOSS_DRAGON_TBOSS1DRAGONCOLLI_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/dragon/TBoss1DragonColli_C.h"

// The Dragon's three blocking sphere chains (head, body, tail).
class TBoss1DragonColli : public TObject {
public:
    TBoss1DragonColli_C *objects[3];
public:
    TBoss1DragonColli(TObject *parent);
    virtual ~TBoss1DragonColli();
public:
    TBoss1DragonColli_C *get_object(s32 index);
    void disable_blocking_bodies();
    void enable_blocking_bodies(Vec *pos, s32 angle);
};

#endif
