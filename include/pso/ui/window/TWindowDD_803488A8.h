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
extern WindowTexturePoint word_select_quad_points[7][8];
void set_frame_row_vertices_y(WindowDrawContext *context, WindowVertex *vertices, s32 row);
void set_frame_column_vertices_x(WindowDrawContext *context, WindowVertex *vertices);
f32 word_select_inverse_depth(f32 depth, f32 offset);
saddr get_word_select_token_text(s16 id);
}

#endif
