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
    void sub_8004D9A0(s32 state);
};

typedef char TObjDFUsoTower_state_offset[offsetof(TObjDFUsoTower, fade_state) == 0x90 ? 1 : -1];
typedef char TObjDFUsoTower_alpha_offset[offsetof(TObjDFUsoTower, fade_alpha) == 0x94 ? 1 : -1];
typedef char TObjDFUsoTower_size[sizeof(TObjDFUsoTower) == 0x98 ? 1 : -1];

#endif
