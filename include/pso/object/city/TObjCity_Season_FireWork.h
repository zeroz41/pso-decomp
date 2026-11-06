#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_FIREWORK_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_FIREWORK_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TObjCity_Season_FireWork : public TObject {
public:
    TObjCity_Season_FireWork(TObject* parent, void* position, f32 riseHeight);
    virtual ~TObjCity_Season_FireWork();
    virtual void run_task();
    f32 pos[3];
    s32 state;
    void* handle;
    f32 limit;
    s32 timer;
    s32 burstEffectId;
    f32 riseDistance;
};
#include <stddef.h>
typedef char FireWorkBaseSize[(sizeof(TObject)==0x1C)?1:-1];
typedef char FireWorkSize[(sizeof(TObjCity_Season_FireWork)==0x40)?1:-1];
#define FIREWORK_OFFSET(field,offset) typedef char FireWorkOffset_##field[(offsetof(TObjCity_Season_FireWork,field)==offset)?1:-1]
FIREWORK_OFFSET(pos,0x1C); FIREWORK_OFFSET(state,0x28); FIREWORK_OFFSET(handle,0x2C);
FIREWORK_OFFSET(limit,0x30); FIREWORK_OFFSET(timer,0x34); FIREWORK_OFFSET(burstEffectId,0x38); FIREWORK_OFFSET(riseDistance,0x3C);
#undef FIREWORK_OFFSET
#endif
