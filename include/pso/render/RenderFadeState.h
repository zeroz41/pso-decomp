#ifndef PSO_RENDER_RENDERFADESTATE_H
#define PSO_RENDER_RENDERFADESTATE_H

#include "pso/render/MaterialColorFade.h"

class RenderFadeState : public MaterialColorFade {
public:
    RenderFadeState();
    virtual ~RenderFadeState();
    virtual void set_flags_and_apply_damage_color();
    void activate_and_dispatch();
    s32 updateFromCamera(const f32* position);
    s32 isFading() const;
    void restore();
    void fadeOut();
    void update();
    void update_fast();
    s32 restoring;
};

#include <stddef.h>
typedef char RenderFadeAdjustmentOffset[(offsetof(RenderFadeState, color) == 0) ? 1 : -1];
typedef char RenderFadeDirectionOffset[(offsetof(RenderFadeState, restoring) == 0x18) ? 1 : -1];
typedef char RenderFadeSize[(sizeof(RenderFadeState) == 0x1C) ? 1 : -1];

#endif
