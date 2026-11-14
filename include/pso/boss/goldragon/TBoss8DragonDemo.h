#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGONDEMO_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGONDEMO_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss8DragonDemo : public TObject {
public:
    virtual ~TBoss8DragonDemo();
    virtual void run_task();
    virtual void render();
public:
    static void render();
};

extern "C" {
u8 *__ct__16TBoss8DragonDemoFv(u8 *arg0, s32 arg1, s32 arg2, f32 farg0);
}

#endif
