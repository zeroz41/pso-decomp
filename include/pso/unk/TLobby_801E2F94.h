#ifndef PSO_UNK_TLOBBY_801E2F94_H
#define PSO_UNK_TLOBBY_801E2F94_H

#include "types.h"
#include "pso/system/NinjaChunk.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/Draw2D.h"

struct ColorLineVertex {
    f32 x, y;
};

struct ColorLineList {
    ColorLineVertex *verts;
    u32 *colors;
    NJS_TEX *tex;  // optional texture coordinates, NULL for flat lines
    s32 count;
};

extern "C" {
s32 TKeyBoardControl__sub_801E3E24(s32 id, saddr name, saddr arg2);
void TLobby__sub_801E3CF0(u32 *p);
s32 TLobby__sub_801E3E9C(s32 id, saddr name, saddr arg2);
void draw_color_lines(ColorLineList *lines, s32 n, s32 flags, f32 scale);
}
void reset_line_width(void);
void set_line_width(int a0);

// Draw a model posed by a motion at a frame.
void draw_motion(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame);

#endif
