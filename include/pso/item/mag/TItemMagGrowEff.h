#ifndef PSO_ITEM_MAG_TITEMMAGGROWEFF_H
#define PSO_ITEM_MAG_TITEMMAGGROWEFF_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

class TParticleCtrl;
class TItemMagSub;

// The grow effect a mag sub shows after its mag changes form.
class TItemMagGrowEff : public TObject {
public:
    s32 progress_ticks;
    TParticleCtrl *effect;
    TItemMagSub *mag;

    TItemMagGrowEff(TObject *parent, TItemMagSub *sub);
    virtual ~TItemMagGrowEff();
    virtual void run_task();
};

typedef char TItemMagGrowEff_progress_ticks_offset[(offsetof(TItemMagGrowEff, progress_ticks) == 0x1C) ? 1 : -1];
typedef char TItemMagGrowEff_effect_offset[(offsetof(TItemMagGrowEff, effect) == 0x20) ? 1 : -1];
typedef char TItemMagGrowEff_mag_offset[(offsetof(TItemMagGrowEff, mag) == 0x24) ? 1 : -1];

#endif
