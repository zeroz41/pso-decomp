#ifndef PSO_UI_FRONTEND_TADGAMESTARTSUBGC_H
#define PSO_UI_FRONTEND_TADGAMESTARTSUBGC_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/math/TMath.h"

// Where one of the GAME START letters flies in: its cell in the letter strip,
// its resting position and its letter colour.
struct GameStartLetterLayout {
    s32 cell;
    f32 x;
    f32 y;
    s32 color;
};

struct GameStartQuad {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

// One letter of the GAME START banner: shrinks from triple size onto its
// resting quad, then grows and fades out.
class TAdGameStartSubGC : public TObject {
public:
    TAdGameStartSubGC(TObject *parent, GameStartLetterLayout *layout);
    virtual ~TAdGameStartSubGC();
    virtual void run_task();
    virtual void render();

    void draw_background();
    static void destroy_instance();

    s32 m_cell;
    GameStartQuad m_rest;
    GameStartQuad m_quad;
    vec2f m_origin;
    f32 m_center_x;
    f32 m_center_y;
    f32 m_scale_x;
    f32 m_scale_y;
    s32 pad_78;
    s32 m_color;
    s32 m_alpha;
    s32 m_frame;
};

LAYOUT_ASSERT(TAdGameStartSubGC_size, sizeof(TAdGameStartSubGC) == 0x88);

#endif
