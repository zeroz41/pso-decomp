#ifndef PSO_UI_FRONTEND_TADGAMESTARTLINEGC_H
#define PSO_UI_FRONTEND_TADGAMESTARTLINEGC_H
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdGameStartGC.h"
#include "pso/math/TMath.h"
#include "types.h"

// The two light streaks of the GAME START banner: they shrink onto the band
// over ten frames and slide apart from frame 29 on.
class TAdGameStartLineGC : public TObject {
public:
    TAdGameStartLineGC(TObject *parent);
    virtual ~TAdGameStartLineGC();
    virtual void run_task();
    virtual void render();

    void draw_lines();

    GameStartQuad m_rest[4];
    GameStartQuad m_quads[4];
    f32 m_left_x;
    f32 m_left_y;
    f32 m_right_x;
    f32 m_right_y;
    vec2f m_centers[4];
    f32 m_scale_x;
    f32 m_scale_y;
    s32 pad_154;
    s32 m_color;
    s32 m_frame;
};

LAYOUT_ASSERT(TAdGameStartLineGC_size, sizeof(TAdGameStartLineGC) == 0x160);

#endif
