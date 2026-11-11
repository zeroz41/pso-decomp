#include "types.h"
#include "pso/player/TObjPlayer_803E21B8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/player/TObjPlayer.h"

typedef struct ProjectedStripVertex { f32 x, y, w, u, v; u32 color; } ProjectedStripVertex;

typedef union WGPipe_803E2D70 {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} WGPipe_803E2D70;

extern "C" {
void GXBegin(int, int, u16);
void draw_projected_textured_strip(ProjectedStripVertex *v, s32 n);
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline void GXPosition3f32_803E2D70(f32 x, f32 y, f32 z) {
    (*(volatile WGPipe_803E2D70 *)0xCC008000).f32 = x;
    (*(volatile WGPipe_803E2D70 *)0xCC008000).f32 = y;
    (*(volatile WGPipe_803E2D70 *)0xCC008000).f32 = z;
}
static inline void GXColor1u32_803E2D70(u32 c) {
    (*(volatile WGPipe_803E2D70 *)0xCC008000).u32 = c;
}
static inline void GXTexCoord2f32_803E2D70(f32 s, f32 t) {
    (*(volatile WGPipe_803E2D70 *)0xCC008000).f32 = s;
    (*(volatile WGPipe_803E2D70 *)0xCC008000).f32 = t;
}
void draw_projected_textured_strip(ProjectedStripVertex *v, s32 n) {
    f32 inv;
    u32 c;
    GXBegin(0x98, 4, n);
    for (; n > 0; n--) {
        inv = -1.0f / v->w;
        GXPosition3f32_803E2D70(v->x * inv, v->y * inv, inv);
        c = v->color;
        GXColor1u32_803E2D70(((c & 0xFFFFFF) << 8) | ((c & 0xFF000000) >> 24));
        GXTexCoord2f32_803E2D70(v->u, v->v);
        v++;
    }
}
#pragma pop

void TLobby__sub_803E2EE4(s32 blended) {
    TObjPlayer::load_screen_space_matrix();
    if (blended != 0) {
        setup_blended_textured_draw();
    } else {
        TObjPlayer::setup_render();
    }
    load_context_texture_obj();
}
