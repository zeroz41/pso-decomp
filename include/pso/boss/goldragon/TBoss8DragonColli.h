#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGONCOLLI_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGONCOLLI_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/goldragon/TBoss8DragonColli_C.h"

// The Gol Dragon's three blocking sphere chains (head, body, tail), as TBoss1DragonColli.
class TBoss8DragonColli : public TObject {
public:
    TBoss8DragonColli(TObject *parent);
    virtual ~TBoss8DragonColli();
    void disable_blocking_bodies();
    void enable_blocking_bodies(Vec *pos, s32 angle);
    TBoss8DragonColli_C *objects[3];
};

#endif
