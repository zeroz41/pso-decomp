#ifndef PSO_MISC_TLOBBY_801E2F94_H
#define PSO_MISC_TLOBBY_801E2F94_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

struct ColorLineVertex {
    f32 x, y;
};

struct ColorLineList {
    ColorLineVertex *verts;
    u32 *colors;
    s32 unk_8;
    s32 count;
};

extern "C" {
void TCameraCtrl__sub_801E32D8(f32 farg0, f32 farg1);
s32 TKeyBoardControl__sub_801E3E24(s32 id, s32 name, s32 arg2);
s32 *TLobby__sub_801E38A0(s32 arg0, s32 *arg1, s32 *arg2, s32 *buf, s32 *arg4);
void TLobby__sub_801E3CF0(u32 *p);
s32 TLobby__sub_801E3E9C(s32 id, s32 name, s32 arg2);
void camera_renderer_setup_nop(void);
void draw_color_lines(ColorLineList *lines, s32 n, s32 flags, f32 scale);
void reset_line_width(void);
void set_line_width(int a0);
}

// Draw a model posed by a motion at a frame.
void draw_motion(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame);

#endif
