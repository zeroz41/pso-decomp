#ifndef PSO_OBJECT_TDEADSPOT_H
#define PSO_OBJECT_TDEADSPOT_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TDeadSpot : public TObject {
public:
    TDeadSpot(TObject *parent, Vec *point, void *texture, s32 selector, s32 delay, f32 maxScale);
    virtual ~TDeadSpot();
    virtual void run_task();
    virtual void render();
    u8 m_1C[0xC8 - 0x1C];
};

class TUnk_80494A10 : public TDeadSpot {
public:
    TUnk_80494A10(TObject *parent, Vec *point, void *texture, s32 selector, s32 delay, f32 maxScale);
    virtual ~TUnk_80494A10();
    virtual void run_task();
    u8 m_C8[0x4];
};
LAYOUT_ASSERT(TDeadSpot_size, sizeof(TDeadSpot) == 0xC8);
LAYOUT_ASSERT(TUnk_80494A10_size, sizeof(TUnk_80494A10) == 0xCC);

extern "C" {
void render__9TDeadSpotFv(u8 *arg0);
}

#endif
