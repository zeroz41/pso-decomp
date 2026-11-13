#ifndef PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLIGHT_H
#define PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLIGHT_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

// One point of the light trail: the strip is drawn width either side of pos, along the camera's up vector.
struct TObjEneMe1Canadin_EffLightPoint {
    f32 width;
    u32 color;
    Vec pos;
};

struct TObjEneMe1Canadin_EffLightVertex {
    Vec pos;
    u32 color;
};

class TObjEneMe1Canadin_EffLight : public TObject {
public:
    TObjEneMe1Canadin_EffLight(TObject *parent, s32 count);
    virtual ~TObjEneMe1Canadin_EffLight();
    virtual void run_task();
    virtual void render();
    s32 m_1C;
    s32 m_20;
    s32 m_24;
    TObjEneMe1Canadin_EffLightVertex *m_28;
    TObjEneMe1Canadin_EffLightPoint *m_2C;
    s32 m_30;
    f32 m_34;
};
typedef char TObjEneMe1Canadin_EffLight_size[sizeof(TObjEneMe1Canadin_EffLight) == 0x38 ? 1 : -1];

extern "C" s32 fade_alpha_step__17TObjEneMe1CanadinFPvif(TObjEneMe1Canadin_EffLightPoint *point, f32 scale, s32 step);

#endif
