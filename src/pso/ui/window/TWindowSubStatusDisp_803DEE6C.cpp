#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/player/TObjPlayer_803E21B8.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"

#pragma scheduling off

union Pipe_803DEECC { u8 u8v; u16 u16v; u32 u32v; s32 s32v; f32 f32v; };

#define FIFO_803DF00C (*(volatile Pipe_803DF00C *)0xCC008000)
union Pipe_803DF00C { u8 u8v; u16 u16v; u32 u32v; s32 s32v; f32 f32v; };

s32 constant_material_color;
extern "C" {
void GXBegin(u32, u32, u16);
s64 OSGetTime(void);

void begin_screen_draw(s32 arg0) {
    TObjPlayer::load_screen_space_matrix();
    if (arg0 != 0) {
        setup_blended_textured_draw();
        return;
    }
    TObjPlayer::setup_render();
}

void TWindowSubStatusDisp::get_player() {
    TObjPlayer__sub_803E2248();
}

#define FIFO_803DEECC (*(volatile Pipe_803DEECC *)0xCC008000)
#define GXPosition3f32_803DEECC(x, y, z) (FIFO_803DEECC.f32v = (x), FIFO_803DEECC.f32v = (y), FIFO_803DEECC.f32v = (z))
#define GXColor1u32_803DEECC(c) (FIFO_803DEECC.u32v = (c))
#define GXTexCoord2f32_803DEECC(s, t) { f32 t_ = (t); f32 s_ = (s); FIFO_803DEECC.f32v = s_; FIFO_803DEECC.f32v = t_; }
#pragma push
#pragma scheduling off
#pragma peephole off
#pragma opt_common_subs off
#pragma optimize_for_size off
void draw_textured_quad_at_depth(f32 *q, f32 depth) {
    u32 color = (*(u32 *)&constant_material_color);
    f32 z = -1.0f / depth;
    f32 x0 = q[0] * z;
    f32 x1 = q[2] * z;
    f32 y0 = q[1] * z;
    f32 y1 = q[3] * z;
    GXBegin(0x80, 4, 4);
    GXPosition3f32_803DEECC(x0, y0, z);
    GXColor1u32_803DEECC(color);
    GXTexCoord2f32_803DEECC(q[4], q[5]);
    GXPosition3f32_803DEECC(x0, y1, z);
    GXColor1u32_803DEECC(color);
    GXTexCoord2f32_803DEECC(q[4], q[7]);
    GXPosition3f32_803DEECC(x1, y1, z);
    GXColor1u32_803DEECC(color);
    GXTexCoord2f32_803DEECC(q[6], q[7]);
    GXPosition3f32_803DEECC(x1, y0, z);
    GXColor1u32_803DEECC(color);
    GXTexCoord2f32_803DEECC(q[6], q[5]);
}
#pragma pop

#pragma push
#pragma scheduling off
void DVDConvertEntrynumToPath(f32 *q) {
    f32 z = -1.0f / q[2];
    u32 color = (*(u32 *)&constant_material_color);
    f32 y0, x0, u0, v0;
    f32 x1, y1, u1, v1;
    f32 x3, y3, u3, v3;
    GXBegin(0x80, 4, 4);
    x0 = q[0] * z;
    y0 = q[1] * z;
    u0 = q[8];
    v0 = q[9];
    FIFO_803DF00C.f32v = x0;
    FIFO_803DF00C.f32v = y0;
    FIFO_803DF00C.f32v = z;
    FIFO_803DF00C.u32v = color;
    FIFO_803DF00C.f32v = u0;
    FIFO_803DF00C.f32v = v0;
    x1 = x0 + q[3] * z;
    y1 = y0 + q[4] * z;
    u1 = u0 + q[10];
    v1 = v0 + q[11];
    FIFO_803DF00C.f32v = x1;
    FIFO_803DF00C.f32v = y1;
    FIFO_803DF00C.f32v = z;
    FIFO_803DF00C.u32v = color;
    FIFO_803DF00C.f32v = u1;
    FIFO_803DF00C.f32v = v1;
    x1 = x1 + q[5] * z;
    y1 = y1 + q[6] * z;
    u1 = u1 + q[12];
    v1 = v1 + q[13];
    FIFO_803DF00C.f32v = x1;
    FIFO_803DF00C.f32v = y1;
    FIFO_803DF00C.f32v = z;
    FIFO_803DF00C.u32v = color;
    FIFO_803DF00C.f32v = u1;
    FIFO_803DF00C.f32v = v1;
    y3 = y0 + q[6] * z;
    x3 = x0 + q[5] * z;
    FIFO_803DF00C.f32v = x3;
    FIFO_803DF00C.f32v = y3;
    FIFO_803DF00C.f32v = z;
    FIFO_803DF00C.u32v = color;
    v3 = v0 + q[13];
    u3 = u0 + q[12];
    FIFO_803DF00C.f32v = u3;
    FIFO_803DF00C.f32v = v3;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma scheduling off
#pragma peephole off
void set_draw_texture_and_color(s32 idx, s32 arg1) {
    load_list_texture((idx), 0, 0, 0);
    constant_material_color = ((arg1 & 0xFFFFFF) << 8) | ((u32) (arg1 & 0xFF000000) >> 0x18U);
}
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void set_constant_material_color(u32 x) {
    (*(u32 *)&constant_material_color) = ((x & 0xFFFFFF) << 8) | ((x & 0xFF000000) >> 24);
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off

u32 TLobby__sub_803DF1CC(void) {
    return OSGetTime() >> 6;
}
#pragma pop
