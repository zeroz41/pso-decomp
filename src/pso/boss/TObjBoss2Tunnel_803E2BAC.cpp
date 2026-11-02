#include "types.h"
#include "pso/boss/TObjBoss2Tunnel_803E2BAC.h"
#include "pso/player/TObjPlayer_803E21B8.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/player/TObjPlayer.h"

#pragma scheduling off

struct Vtx_803E2BCC {
    f32 x, y, z;
    u32 color;
};

extern "C" {
s32 GXBegin(int, int, u16);
void draw_projected_quads__15TObjBoss2TunnelFPvi(Vtx_803E2BCC *p, s32 n);

void TObjBoss2Tunnel::reset_player_state() {
    TObjPlayer__sub_803E2248();
}

#pragma push
#pragma scheduling off
typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    s32 s32;
    f32 f32;
} WGPipe_803E2BCC;
#define GXWGFifo_803E2BCC (*(volatile WGPipe_803E2BCC *)0xCC008000)
void draw_projected_quads__15TObjBoss2TunnelFPvi(Vtx_803E2BCC *p, s32 n) {
    s32 i;
    f32 one;
    GXBegin(0x98, 4, n);
    one = -1.0f;
    for (i = 0; i != n; i++) {
        f32 x;
        f32 y;
        f32 w;
        u32 c;
        w = one / p->z;
        y = p->y * w;
        x = p->x * w;
        GXWGFifo_803E2BCC.f32 = x;
        GXWGFifo_803E2BCC.f32 = y;
        GXWGFifo_803E2BCC.f32 = w;
        c = p->color;
        GXWGFifo_803E2BCC.u32 = ((c & 0xFFFFFF) << 8) | ((c & 0xFF000000) >> 24);
        p++;
    }
}
#pragma pop

void TObjBoss2Tunnel__sub_803E2D10(s32 arg0) {
    TObjPlayer::load_screen_space_matrix();
    if (arg0 != 0) {
        TObjPlayer__sub_803E21DC();
        return;
    }
    setup_opaque_color_draw();
}

}
