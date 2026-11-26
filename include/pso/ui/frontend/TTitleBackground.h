#ifndef PSO_UI_FRONTEND_TTITLEBACKGROUND_H
#define PSO_UI_FRONTEND_TTITLEBACKGROUND_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TTitleScene;

// The title screen's background layer: the logo, the pulse and the rotating
// rings, animated from a frame counter.
class TTitleBackground : public TObject {
public:
    TTitleBackground(TTitleScene *scene);
    virtual ~TTitleBackground();
    virtual void render();
    virtual void run_task();
    TTitleScene *scene;
    s32 frame;
};
LAYOUT_ASSERT(TTitleBackground_size, sizeof(TTitleBackground) == 0x24);

// The background's drawing helpers.
void rotate_title_background_quad(s32 owner, u8 *quad, u8 *center, saddr angle, f32 radius);
void draw_title_background_pulse(s32 owner, f32 depth, s32 frame);
void draw_title_rings(s32 owner, f32 depth, s32 frame);

extern "C" {
void TLobby__sub_80336E44(void);
void TLobby__sub_80336E64(void);
void TLobby__sub_80336E68(void);
}
void clear_lobby_global_flags(void);

struct TitlePulseQuad {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

struct TitleQuad {
    f32 x, y, z;
    f32 bx, by, cx, cy;
    u8 pad_1C[0x4];
    f32 u, v, uw, ux, vx, vh;
    u8 pad_38[0x8];
};

#endif
