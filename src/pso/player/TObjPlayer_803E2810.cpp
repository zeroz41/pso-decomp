#include "types.h"
#include "pso/player/TObjPlayer_803E21B8.h"
#include "pso/player/TObjPlayer.h"

// Own TU: its .sdata2 pool holds a second -1.0f (0x805E1078, padded to 8) next to
// TObjPlayer_803E21B8's (0x805E1070), so draw_textured_vertices cannot share that TU.

typedef struct Vtx_803E2810 { f32 x, y, w; f32 s, t; u32 color; } Vtx_803E2810;

typedef union WGPipe_803E2810 {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} WGPipe_803E2810;

#pragma scheduling off
#pragma dont_inline off
#pragma inline_depth(4)
static inline void GXPosition3f32_803E2810(f32 x, f32 y, f32 z) {
    (*(volatile WGPipe_803E2810 *)0xCC008000).f32 = x;
    (*(volatile WGPipe_803E2810 *)0xCC008000).f32 = y;
    (*(volatile WGPipe_803E2810 *)0xCC008000).f32 = z;
}
static inline void GXColor1u32_803E2810(u32 c) {
    (*(volatile WGPipe_803E2810 *)0xCC008000).u32 = c;
}
static inline void GXTexCoord2f32_803E2810(f32 s, f32 t) {
    (*(volatile WGPipe_803E2810 *)0xCC008000).f32 = s;
    (*(volatile WGPipe_803E2810 *)0xCC008000).f32 = t;
}

extern "C" {
void GXBegin(int, int, u16);

void draw_textured_vertices__10TObjPlayerFPvii(Vtx_803E2810 *v, s32 n, s32 mode) {
    f32 inv;
    u32 c;
    TObjPlayer::load_screen_space_matrix();
    if (mode != 0) {
        setup_blended_textured_draw();
    } else {
        TObjPlayer::setup_render();
    }
    load_context_texture_obj();
    GXBegin(0x98, 4, n);
    for (; n > 0; n--) {
        inv = -1.0f / v->w;
        GXPosition3f32_803E2810(v->x * inv, v->y * inv, inv);
        c = v->color;
        GXColor1u32_803E2810(((c & 0xFFFFFF) << 8) | ((c & 0xFF000000) >> 24));
        GXTexCoord2f32_803E2810(v->s, v->t);
        v++;
    }
    end_primitive_draw();
}
}
