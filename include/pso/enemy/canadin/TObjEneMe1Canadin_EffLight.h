#ifndef PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLIGHT_H
#define PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLIGHT_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

// One point of the light trail: the strip is drawn width either side of pos, along the camera's up vector.
struct TObjEneMe1Canadin_EffLightPoint {
    // Shrinks the width by scale and the alpha by step; nonzero once the point has faded out.
    s32 fade_alpha_step(f32 scale, s32 step);

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
    void push_history_entry(f32 width, Vec *pos, u32 color);
    s32 capacity;
    s32 head;
    s32 tail;
    TObjEneMe1Canadin_EffLightVertex *vertices;
    TObjEneMe1Canadin_EffLightPoint *points;
    s32 alpha_step;
    f32 width_decay;
};
LAYOUT_ASSERT(TObjEneMe1Canadin_EffLight_size, sizeof(TObjEneMe1Canadin_EffLight) == 0x38);

#endif
