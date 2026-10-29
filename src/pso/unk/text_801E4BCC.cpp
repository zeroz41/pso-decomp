#include "types.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer.h"
struct Wave_801E4BCC {
    s32 height;
    s32 width;
    u32 texture_id;
    u8 records[0x30];
    void *texture_list;
    u8 *image;
    u8 *output;
    u8 *displacement;
    s32 phase;
};

extern "C" {
void distort_texture_wave_image(Wave_801E4BCC *wave);
void distort_texture_wave_image(Wave_801E4BCC *wave) {
    s32 y;
    u8 *dx;
    u8 *dy;
    u16 *image;
    u16 *out;
    s32 x;
    y = 0;
    out = (u16 *)(wave->output + 0x20);
    dx = wave->displacement;
    image = (u16 *)(wave->image + 0x20);
    dy = dx + wave->height * wave->width;
    for (; y < wave->height; y++) {
        for (x = 0; x < wave->width; x++) {
            s32 at = wave->phase + x;
            u16 sx;
            u16 sy;
            u16 color;
            u8 ox;
            s32 idx;
            u8 oy;
            if (at >= wave->width) {
                at -= wave->width;
            }
            idx = at + y * wave->width;
            ox = dx[idx];
            oy = dy[idx];
            sx = ox + x;
            if (sx >= wave->width) {
                sx -= wave->width;
            }
            sy = oy + y;
            if (sy >= wave->height) {
                sy -= wave->height;
            }
            color = image[sx + sy * wave->width] | 0x8000;
            out[calc_gx_tile_index(x, y, wave->width)] = color;
        }
    }
    ((TObjPlayer *)0)->reload_texture((s32)(wave->output + 0x20), (u32)0x40000000, (void *)0);
}

}
