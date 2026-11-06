#ifndef PSO_ENEMY_TOBJENEDF2BRINGER_EFF_RUSH_H
#define PSO_ENEMY_TOBJENEDF2BRINGER_EFF_RUSH_H
#include "types.h"
#include "pso/TObject.h"
#include <dolphin/mtx/GeoTypes.h>
class TObjBase;
class TObjChara;

class TObjEneDf2Bringer_Eff_Rush : public TObject {
public:
    virtual ~TObjEneDf2Bringer_Eff_Rush();
    virtual void run_task();
    virtual void render();
    TObjChara *target;
    Vec direction;
    f32 strength;
    s32 field_30;
};
typedef char TObjEneDf2Bringer_Eff_Rush_size[sizeof(TObjEneDf2Bringer_Eff_Rush) == 0x34 ? 1 : -1];

#endif
