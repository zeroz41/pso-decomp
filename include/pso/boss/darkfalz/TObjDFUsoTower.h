#ifndef PSO_BOSS_DARKFALZ_TOBJDFUSOTOWER_H
#define PSO_BOSS_DARKFALZ_TOBJDFUSOTOWER_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjDFUsoTower : public TObjBase {
    TObjDFUsoTower(TObject *parent);
    virtual ~TObjDFUsoTower();
    u32 fade_state;
    static TObjDFUsoTower *create(TObject *parent);
    virtual void render();
    virtual void run_task();
    f32 fade_alpha;
    void set_fade_state(s32 state);
};

LAYOUT_ASSERT(TObjDFUsoTower_state_offset, offsetof(TObjDFUsoTower, fade_state) == 0x90);
LAYOUT_ASSERT(TObjDFUsoTower_alpha_offset, offsetof(TObjDFUsoTower, fade_alpha) == 0x94);
LAYOUT_ASSERT(TObjDFUsoTower_size, sizeof(TObjDFUsoTower) == 0x98);

#endif
