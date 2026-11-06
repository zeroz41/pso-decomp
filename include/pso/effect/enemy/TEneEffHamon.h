#ifndef PSO_EFFECT_ENEMY_TENEEFFHAMON_H
#define PSO_EFFECT_ENEMY_TENEEFFHAMON_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TEneEffHamon : public TObject {
public:
    virtual ~TEneEffHamon();
    virtual void render();
    virtual void run_task();
};

extern "C" {
void TEneEffHamon__sub_800A380C(void);
u8 *__ct__12TEneEffHamonFv(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0);
void init_fish_effects__12TEneEffHamonFv(void);
void run_task__12TEneEffHamonFv(u8 *arg0);
}

#endif
