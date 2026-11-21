#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_FIREWORK_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_FIREWORK_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

class TParticleCtrl;

class TObjCity_Season_FireWork : public TObject {
public:
    TObjCity_Season_FireWork(TObject* parent, void* position, f32 riseHeight);
    virtual ~TObjCity_Season_FireWork();
    virtual void run_task();
    Vec pos;
    s32 state;
    TParticleCtrl *handle;
    f32 limit;
    s32 timer;
    s32 burstEffectId;
    f32 riseDistance;
};
#include <stddef.h>
LAYOUT_ASSERT(FireWorkBaseSize, sizeof(TObject)==0x1C);
LAYOUT_ASSERT(FireWorkSize, sizeof(TObjCity_Season_FireWork)==0x40);
#define FIREWORK_OFFSET(field,offset) LAYOUT_ASSERT(FireWorkOffset_##field, offsetof(TObjCity_Season_FireWork,field)==offset)
FIREWORK_OFFSET(pos,0x1C); FIREWORK_OFFSET(state,0x28); FIREWORK_OFFSET(handle,0x2C);
FIREWORK_OFFSET(limit,0x30); FIREWORK_OFFSET(timer,0x34); FIREWORK_OFFSET(burstEffectId,0x38); FIREWORK_OFFSET(riseDistance,0x3C);
#undef FIREWORK_OFFSET
#endif
