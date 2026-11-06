#ifndef PSO_BOSS_TUNK_80484888_H
#define PSO_BOSS_TUNK_80484888_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

// Sprays the particle effect effect_id around pos for lifetime frames: rate
// particles per frame, each up to spread away in a random direction.
class TUnk_80484888 : public TObject {
public:
    s32 effect_id;
    s32 lifetime;
    f32 rate;
    f32 pending;
    Vec pos;
    s32 rotation[3];
    f32 spread;

    TUnk_80484888(Vec *pos, s32 effect_id, s32 lifetime, s32 *rotation, f32 rate, f32 spread);
    virtual ~TUnk_80484888();
    virtual void run_task();
};

typedef char TUnk_80484888_size[sizeof(TUnk_80484888) == 0x48 ? 1 : -1];

#endif
