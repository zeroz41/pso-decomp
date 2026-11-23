#ifndef PSO_UI_FRONTEND_TADGAMESTARTSHINEGC_H
#define PSO_UI_FRONTEND_TADGAMESTARTSHINEGC_H
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdGameStartGC.h"
#include "pso/math/TMath.h"
#include "types.h"

// The flash over the GAME START banner: from frame 10 on it shows, widens and
// fades out.
class TAdGameStartShineGC : public TObject {
public:
    TAdGameStartShineGC(TObject *parent);
    virtual ~TAdGameStartShineGC();
    virtual void run_task();
    virtual void render();

    void render_status_box();

    f32 m_scale_x;
    f32 m_scale_y;
    vec2f m_origin;
    f32 m_rest_x0;
    f32 m_rest_y0;
    f32 m_rest_x1;
    f32 m_rest_y1;
    u8 pad_3c[0x10];
    f32 m_center_x;
    f32 m_center_y;
    GameStartQuad m_quad;
    s32 m_alpha;
    s32 m_frame;
    s32 m_visible;
};

LAYOUT_ASSERT(TAdGameStartShineGC_size, sizeof(TAdGameStartShineGC) == 0x80);

#endif
