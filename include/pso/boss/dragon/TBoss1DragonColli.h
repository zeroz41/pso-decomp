#ifndef PSO_BOSS_DRAGON_TBOSS1DRAGONCOLLI_H
#define PSO_BOSS_DRAGON_TBOSS1DRAGONCOLLI_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TBoss1DragonColli : public TObject {
public:
    TObject *objects[3];
public:
    virtual void render();
    virtual ~TBoss1DragonColli();
};

extern "C" {
s32 TBoss1DragonColli_C__ct(int arg0, void *arg1, int arg2, void *arg3, f32 scale);
u8 *TBoss1DragonColli__ct(u8 *arg0, s32 arg1);
void TBoss1DragonColli__sub_8002B35C(void *p);
void *__dt__19TBoss1DragonColli_CFv(void *arg0, s16 arg1);
void draw__17TBoss1DragonColliFPvPvPv(void *p, void *a1, void *a2);
}

#endif
