#ifndef PSO_BOSS_TBOSS8DRAGONDEMO_H
#define PSO_BOSS_TBOSS8DRAGONDEMO_H

#include "pso/TObject.h"
#include "types.h"

class TBoss8DragonDemo : public TObject {
public:
    virtual ~TBoss8DragonDemo();
    virtual void run_task();
    virtual void render();
public:
    int copy_position();
    static void render();
};

extern "C" {
f32 TBoss8DragonDemo__sub_802F2CB4(void *p);
f32 TBoss8DragonDemo__sub_802F2CBC(void *p);
void TBoss8DragonDemo__sub_802F2CC4(void);
u8 *__ct__16TBoss8DragonDemoFv(u8 *arg0, s32 arg1, s32 arg2, f32 farg0);
}

#endif
