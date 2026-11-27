#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/render/GinjaDrawUtil.h"
#include "pso/render/ScreenPrimitiveDraw.h"
#include "pso/player/TObjPlayer.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#include <dolphin/os/OSTime.h>
#undef PSO_SDK_COMPACT_MATH

#pragma scheduling off


// The Gekko write-gather pipe.
#define GX_FIFO (*(volatile GxFifoValue *)0xCC008000)


s32 constant_material_color;

void begin_screen_draw(s32 mode) {
    load_screen_space_matrix();
    if (mode != 0) {
        setup_blended_textured_draw();
        return;
    }
    setup_opaque_textured_draw();
}

void end_screen_draw() {
    end_primitive_draw();
}

#define FIFO_POSITION3F32(x, y, z) (GX_FIFO.f32v = (x), GX_FIFO.f32v = (y), GX_FIFO.f32v = (z))
#define FIFO_COLOR1U32(c) (GX_FIFO.u32v = (c))
#define FIFO_TEXCOORD2F32(s, t) { f32 t_ = (t); f32 s_ = (s); GX_FIFO.f32v = s_; GX_FIFO.f32v = t_; }
#pragma push
#pragma scheduling off
#pragma peephole off
#pragma opt_common_subs off
#pragma optimize_for_size off
void draw_textured_quad_at_depth(f32 *q, f32 depth) {
    u32 color = (u32)constant_material_color;
    f32 z = -1.0f / depth;
    f32 x0 = q[0] * z;
    f32 x1 = q[2] * z;
    f32 y0 = q[1] * z;
    f32 y1 = q[3] * z;
    GXBegin((GXPrimitive)0x80, (GXVtxFmt)4, 4);
    FIFO_POSITION3F32(x0, y0, z);
    FIFO_COLOR1U32(color);
    FIFO_TEXCOORD2F32(q[4], q[5]);
    FIFO_POSITION3F32(x0, y1, z);
    FIFO_COLOR1U32(color);
    FIFO_TEXCOORD2F32(q[4], q[7]);
    FIFO_POSITION3F32(x1, y1, z);
    FIFO_COLOR1U32(color);
    FIFO_TEXCOORD2F32(q[6], q[7]);
    FIFO_POSITION3F32(x1, y0, z);
    FIFO_COLOR1U32(color);
    FIFO_TEXCOORD2F32(q[6], q[5]);
}
#pragma pop

#pragma push
#pragma scheduling off
void draw_rotated_quad(f32 *q) {
    f32 z = -1.0f / q[2];
    u32 color = (u32)constant_material_color;
    f32 y0, x0, u0, v0;
    f32 x1, y1, u1, v1;
    f32 x3, y3, u3, v3;
    GXBegin((GXPrimitive)0x80, (GXVtxFmt)4, 4);
    x0 = q[0] * z;
    y0 = q[1] * z;
    u0 = q[8];
    v0 = q[9];
    GX_FIFO.f32v = x0;
    GX_FIFO.f32v = y0;
    GX_FIFO.f32v = z;
    GX_FIFO.u32v = color;
    GX_FIFO.f32v = u0;
    GX_FIFO.f32v = v0;
    x1 = x0 + q[3] * z;
    y1 = y0 + q[4] * z;
    u1 = u0 + q[10];
    v1 = v0 + q[11];
    GX_FIFO.f32v = x1;
    GX_FIFO.f32v = y1;
    GX_FIFO.f32v = z;
    GX_FIFO.u32v = color;
    GX_FIFO.f32v = u1;
    GX_FIFO.f32v = v1;
    x1 = x1 + q[5] * z;
    y1 = y1 + q[6] * z;
    u1 = u1 + q[12];
    v1 = v1 + q[13];
    GX_FIFO.f32v = x1;
    GX_FIFO.f32v = y1;
    GX_FIFO.f32v = z;
    GX_FIFO.u32v = color;
    GX_FIFO.f32v = u1;
    GX_FIFO.f32v = v1;
    y3 = y0 + q[6] * z;
    x3 = x0 + q[5] * z;
    GX_FIFO.f32v = x3;
    GX_FIFO.f32v = y3;
    GX_FIFO.f32v = z;
    GX_FIFO.u32v = color;
    v3 = v0 + q[13];
    u3 = u0 + q[12];
    GX_FIFO.f32v = u3;
    GX_FIFO.f32v = v3;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma scheduling off
#pragma peephole off
void set_draw_texture_and_color(s32 idx, s32 color) {
    load_list_texture((idx), 0, 0, 0);
    constant_material_color = ((color & 0xFFFFFF) << 8) | ((u32) (color & 0xFF000000) >> 0x18U);
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void set_constant_material_color(u32 x) {
    constant_material_color = (s32)(((x & 0xFFFFFF) << 8) | ((x & 0xFF000000) >> 24));
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off

u32 get_coarse_time(void) {
    return OSGetTime() >> 6;
}
#pragma pop

s32 calc_delta(s32 start, s32 end) {
    return end - start;
}

#pragma push
#pragma scheduling off
#pragma peephole off
#pragma optimize_for_size off
// The OS timer runs at 40.5 MHz, so a get_coarse_time difference (ticks / 64) times 512 / 324 is microseconds.
u32 coarse_time_to_usec(u32 x) {
    return ((u32)(x << 6) * 8) / 324;
}
#pragma pop
