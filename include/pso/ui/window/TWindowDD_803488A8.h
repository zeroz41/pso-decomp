#ifndef PSO_UI_WINDOW_TWINDOWDD_803488A8_H
#define PSO_UI_WINDOW_TWINDOWDD_803488A8_H

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/WindowVertexBufferAbi.h"

struct WindowDrawContext;

// A pair of texture coordinates; the same representation the layout code uses for Vec2 positions.
typedef NJS_POINT2 WindowTexturePoint;
LAYOUT_ASSERT(WindowTexturePointSize, sizeof(WindowTexturePoint) == 8);

extern "C" {
extern WindowTexturePoint TWindowDD__data_805434E8[7][8];
void TWindowDD__sub_803489B8(WindowDrawContext *context, WindowVertex *vertices, s32 row);
void TWindowDD__sub_80348A2C(WindowDrawContext *context, WindowVertex *vertices);
f32 TWindowDD__sub_80348AD4(f32 depth, f32 offset);
saddr get_word_select_token_text(s16 id);
}

#endif
