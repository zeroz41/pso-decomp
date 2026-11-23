#ifndef PSO_UI_FRONTEND_TADGAMESTARTBACKGC_H
#define PSO_UI_FRONTEND_TADGAMESTARTBACKGC_H

#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdGameStartSubGC.h"
#include "types.h"

// The plate behind the GAME START letters: shrinks from five times its size
// onto its resting quad, then fades out after frame 28.
class TAdGameStartBackGC : public TObject {
public:
    TAdGameStartBackGC(TObject *parent);
    virtual ~TAdGameStartBackGC();
    virtual void run_task();
    virtual void render();

    void render_background_status();

    GameStartQuad m_rest;
    GameStartQuad m_quad;
    vec2f m_origin;
    f32 m_center_x;
    f32 m_center_y;
    f32 m_scale_x;
    f32 m_scale_y;
    s32 pad_74;
    s32 m_alpha;
    s32 m_frame;
};

LAYOUT_ASSERT(TAdGameStartBackGC_size, sizeof(TAdGameStartBackGC) == 0x80);

#endif
