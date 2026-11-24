#ifndef PSO_UI_FRONTEND_TADSELECTTXTSUBGC_H
#define PSO_UI_FRONTEND_TADSELECTTXTSUBGC_H

#include "pso/system/task/TObject.h"
#include "pso/math/TMath.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "types.h"

struct TAdSelectTxtEntry;

// One line of a select text: grows from double size onto its cell of the
// 256x256 text texture over five frames.
class TAdSelectTxtSubGC : public TObject {
public:
    TAdSelectTxtSubGC(TObject *parent, TAdSelectTxtEntry *entry);
    virtual ~TAdSelectTxtSubGC();
    virtual void run_task();
    virtual void render();

    void render_status();

    s32 m_column;
    s32 m_texture;
    TexturedQuad m_rest;
    TexturedQuad m_quad;
    vec2f m_origin;
    f32 m_center_x;
    f32 m_center_y;
    f32 m_scale_x;
    f32 m_scale_y;
    s32 m_row;
    s32 m_color;
    s32 m_frame;
};

LAYOUT_ASSERT(TAdSelectTxtSubGC_size, sizeof(TAdSelectTxtSubGC) == 0x88);

extern "C" {
int TObjNpcHosa__sub_802A39B0(void);
}

#endif
