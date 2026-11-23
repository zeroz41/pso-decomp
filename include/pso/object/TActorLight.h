#ifndef PSO_OBJECT_TACTORLIGHT_H
#define PSO_OBJECT_TACTORLIGHT_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"

class TObjBase;

// A light task tied to `source` for `duration` frames: its direction and scalars move from the
// scene light towards `desired`, `peak` and `intensity` for the first half, then back.
class TActorLight : public TObject {
public:
    TActorLight(f32 step, f32 peak, f32 intensity, NJS_ARGB *color, Vec *desired, s32 duration, TObjBase *source,
                  TObject *parent);
    TActorLight(f32 step, NJS_ARGB *color, Vec *desired, s32 duration, TObjBase *source, TObject *parent);
    virtual ~TActorLight();
    virtual void run_task();
    s32 duration;
    u32 phase;
    NJS_ARGB color;
    Vec desired;
    Vec direction;
    s32 age;
    f32 step;
    TObjBase *source;
    f32 peak;
    f32 intensity;
    u16 actor;
    u8 pad_62[0x2];
};
LAYOUT_ASSERT(TActorLight_size, sizeof(TActorLight) == 0x64);

#endif
