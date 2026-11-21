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
LAYOUT_ASSERT(RenderFadeAdjustmentOffset, offsetof(RenderFadeState, color) == 0);
LAYOUT_ASSERT(RenderFadeDirectionOffset, offsetof(RenderFadeState, restoring) == 0x18);
LAYOUT_ASSERT(RenderFadeSize, sizeof(RenderFadeState) == 0x1C);

#endif
