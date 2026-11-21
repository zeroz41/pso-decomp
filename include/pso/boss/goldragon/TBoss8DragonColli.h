#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGONCOLLI_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGONCOLLI_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TBoss8DragonColli : public TObject {
public:
    TBoss8DragonColli(TObject *parent);
    virtual ~TBoss8DragonColli();
    TObject *objects[3];
};

extern "C" {
void TBoss8DragonColli__sub_802F3074(void *p);
void init__17TBoss8DragonColliFPvPvPv(void *p, void *a1, void *a2);
}

#endif
