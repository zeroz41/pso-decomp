#include "types.h"
#include "pso/system/movie/TMovie.h"

extern "C" {

// Packs a planar 4:2:0 frame into the YUYV external frame buffer, centred,
// two lines per pass.
void pack_movie_frame(MovieFramePlanes *planes) {
    u32 w = lbl_805D56A4;
    u32 h = lbl_805D56A8;
    u32 *dst0 = (u32 *)movie_current_frame_buffer + ((640 - w) * 2 >> 3) + ((480 - h) * 640 >> 2);
    u32 *dst1 = dst0 + 319;
    u32 *y0 = planes->y - 1;
    u32 *y1 = y0 + (planes->y_pitch >> 2);
    u32 *up = planes->u - 1;
    u32 *vp = planes->v - 1;
    u32 *end;
    u32 *row_end;
    s32 dst_skip = 640 - (w >> 1);
    s32 y_skip = ((planes->y_pitch >> 2) << 1) - (w >> 2);
    s32 uv_skip = (planes->uv_pitch >> 2) - (w >> 3);

    dst0--;
    end = dst0 + h * 320;

    while (end > dst0) {
        row_end = dst0 + (w * 4 >> 3);
        while (row_end > dst0) {
            u32 u, v, ya, yb;

            __dcbt(y0, 32);
            u = *++up;
            v = *++vp;
            ya = *++y0;
            yb = *++y1;
            *++dst0 = (v >> 24) | ((u >> 8) & 0xFF0000) | (ya & 0xFF000000) | ((ya >> 8) & 0xFF00);
            *++dst1 = (v >> 24) | ((u >> 8) & 0xFF0000) | (yb & 0xFF000000) | ((yb >> 8) & 0xFF00);
            *++dst0 = ((v >> 16) & 0xFF) | (u & 0xFF0000) | ((ya << 16) & 0xFF000000) | ((ya << 8) & 0xFF00);
            *++dst1 = ((v >> 16) & 0xFF) | (u & 0xFF0000) | ((yb << 16) & 0xFF000000) | ((yb << 8) & 0xFF00);
            ya = *++y0;
            yb = *++y1;
            *++dst0 = ((v >> 8) & 0xFF) | ((u << 8) & 0xFF0000) | (ya & 0xFF000000) | ((ya >> 8) & 0xFF00);
            *++dst1 = ((v >> 8) & 0xFF) | ((u << 8) & 0xFF0000) | (yb & 0xFF000000) | ((yb >> 8) & 0xFF00);
            *++dst0 = (v & 0xFF) | ((u << 16) & 0xFF0000) | ((ya << 16) & 0xFF000000) | ((ya << 8) & 0xFF00);
            *++dst1 = (v & 0xFF) | ((u << 16) & 0xFF0000) | ((yb << 16) & 0xFF000000) | ((yb << 8) & 0xFF00);

            __dcbt(y1, 32);
            u = *++up;
            v = *++vp;
            ya = *++y0;
            yb = *++y1;
            *++dst0 = (v >> 24) | ((u >> 8) & 0xFF0000) | (ya & 0xFF000000) | ((ya >> 8) & 0xFF00);
            *++dst1 = (v >> 24) | ((u >> 8) & 0xFF0000) | (yb & 0xFF000000) | ((yb >> 8) & 0xFF00);
            *++dst0 = ((v >> 16) & 0xFF) | (u & 0xFF0000) | ((ya << 16) & 0xFF000000) | ((ya << 8) & 0xFF00);
            *++dst1 = ((v >> 16) & 0xFF) | (u & 0xFF0000) | ((yb << 16) & 0xFF000000) | ((yb << 8) & 0xFF00);
            ya = *++y0;
            yb = *++y1;
            *++dst0 = ((v >> 8) & 0xFF) | ((u << 8) & 0xFF0000) | (ya & 0xFF000000) | ((ya >> 8) & 0xFF00);
            *++dst1 = ((v >> 8) & 0xFF) | ((u << 8) & 0xFF0000) | (yb & 0xFF000000) | ((yb >> 8) & 0xFF00);
            *++dst0 = (v & 0xFF) | ((u << 16) & 0xFF0000) | ((ya << 16) & 0xFF000000) | ((ya << 8) & 0xFF00);
            *++dst1 = (v & 0xFF) | ((u << 16) & 0xFF0000) | ((yb << 16) & 0xFF000000) | ((yb << 8) & 0xFF00);
        }
        dst0 += dst_skip;
        dst1 += dst_skip;
        y0 += y_skip;
        y1 += y_skip;
        up += uv_skip;
        vp += uv_skip;
    }
}

}
