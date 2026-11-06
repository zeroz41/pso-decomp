#ifndef PSO_BOSS_DRAGON_TBOSS1DRAGONDEMO_H
#define PSO_BOSS_DRAGON_TBOSS1DRAGONDEMO_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss1DragonDemo : public TObject {
public:
    virtual ~TBoss1DragonDemo();
    virtual void run_task();
    virtual void render();
public:
    static void render();
};

extern "C" {
void TBoss1DragonDemo__sub_8002B68C(void);
void TBoss1DragonDemo__sub_8002B690(void);
u8 *__ct__16TBoss1DragonDemoFv(u8 *arg0, s32 arg1, s32 arg2, f32 farg0);
}

// --- C functions defined in TBoss1DragonDemo.cpp ---
extern "C" {
u8 *__ct__16TBoss1DragonDemoFv(u8 *object, s32 arg1, s32 arg2, f32 farg0);
}
// --- end of C functions

#endif
