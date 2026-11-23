#ifndef PSO_UI_FRONTEND_TADTITLEGC_H
#define PSO_UI_FRONTEND_TADTITLEGC_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

class TAdDrawLineCtrl;

struct AdTitleQuad { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

class TAdDrawLineCtrl;

// One banner strip: its screen rectangle, then its texture coordinates (the eight floats
// draw_textured_quad_at_depth reads).
struct TAdTitleRect {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

class TAdTitleGC : public TObject {
public:
    TAdTitleGC(TObject *parent, s32 idx);
    virtual ~TAdTitleGC();
    virtual void run_task();
    virtual void render();
public:
    s32 draw_title_layer(s32 arg1, s32 color);
    void calc_text_pos(f32 *pos, const char *text);
    s32 update_title_rects();
    void set_field_134(s32 value);  // sets render_direct and the draw line ctrl's +0x28 to value
    s32 title;                        // 0x1C: the title's line in text group 0x13 and its banner strip
    TAdTitleRect rects[8];            // 0x20: slide in one after another
    f32 text_pos[2];                  // 0x120: calc_text_pos's x, y
    s32 frames;                       // 0x128: slide-in frames, -1 up to 10
    s32 alpha;                        // 0x12C: text alpha, fades in by 0xC a frame up to 0xFF
    TAdDrawLineCtrl *draw_line_ctrl;  // 0x130
    s32 render_direct;                // 0x134: 1 draws in the normal pass; 0 defers and restores depth/alpha
};

LAYOUT_ASSERT(TAdTitleGC_size, sizeof(TAdTitleGC) == 0x138);

#endif
