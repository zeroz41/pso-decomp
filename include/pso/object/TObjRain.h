#ifndef PSO_OBJECT_TOBJRAIN_H
#define PSO_OBJECT_TOBJRAIN_H

#include "pso/TObject.h"
#include "types.h"

class TObjRain : public TObject {
public:
    virtual ~TObjRain();
    void update_drops();
    virtual void run_task();
    virtual void render();
public:
    void draw_streaks();
    void init_drops();
};

extern "C" {
u8 *__ct__8TObjRainFv(u8 *rain, s32 arg1, u32 arg2);
}

#endif
