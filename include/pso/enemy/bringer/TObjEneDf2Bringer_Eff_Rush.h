#ifndef PSO_ENEMY_BRINGER_TOBJENEDF2BRINGER_EFF_RUSH_H
#define PSO_ENEMY_BRINGER_TOBJENEDF2BRINGER_EFF_RUSH_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>
class TObjBase;
class TObjChara;

class TObjEneDf2Bringer_Eff_Rush : public TObject {
public:
    // Pushes recipient away from source, turned 0x1800 off source's facing toward the side recipient is on;
    // speed decays by 0.8 a frame (TObjEneDellBiter_Eff_Rush's twin).
    TObjEneDf2Bringer_Eff_Rush(TObject *parent, TObjBase *source, TObjChara *recipient, f32 speed);
    virtual ~TObjEneDf2Bringer_Eff_Rush();
    virtual void run_task();
    virtual void render();
    TObjChara *target;
    Vec direction;
    f32 strength;
    s32 pad_30;  // zeroed by the ctor, never read (pad_30 in TObjEneDellBiter_Eff_Rush)
};
LAYOUT_ASSERT(TObjEneDf2Bringer_Eff_Rush_size, sizeof(TObjEneDf2Bringer_Eff_Rush) == 0x34);

#endif
