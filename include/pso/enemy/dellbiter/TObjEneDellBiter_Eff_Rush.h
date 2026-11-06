#ifndef PSO_ENEMY_DELLBITER_TOBJENEDELLBITER_EFF_RUSH_H
#define PSO_ENEMY_DELLBITER_TOBJENEDELLBITER_EFF_RUSH_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>
class TObjBase;
class TObjChara;

class TObjEneDellBiter_Eff_Rush : public TObject {
public:
    TObjEneDellBiter_Eff_Rush(TObject *, TObjBase *, TObjChara *, f32);
    virtual ~TObjEneDellBiter_Eff_Rush();
    virtual void render();
    virtual void run_task();
    TObjChara *target;
    Vec direction;
    f32 strength;
    s32 field_30;
};
typedef char TObjEneDellBiter_Eff_Rush_size[sizeof(TObjEneDellBiter_Eff_Rush) == 0x34 ? 1 : -1];

#endif
