#ifndef PSO_BOSS_DRAGON_TBOSS1DRAGONCOLLI_H
#define PSO_BOSS_DRAGON_TBOSS1DRAGONCOLLI_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TBoss1DragonColli : public TObject {
public:
    TObject *objects[3];
public:
    TBoss1DragonColli(TObject *parent);
    virtual ~TBoss1DragonColli();
public:
    void draw(void* a1, void* a2);
    void set_elem_flags();
};

extern "C" {
void TBoss1DragonColli__sub_8002B35C(void *p);
TObject *TBoss1Dragon__sub_8002B108(TBoss1DragonColli *self, s32 i);
void draw__17TBoss1DragonColliFPvPv(void *p, void *a1, void *a2);
}

#endif
