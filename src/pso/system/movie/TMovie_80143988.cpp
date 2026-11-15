#include "types.h"
#include "pso/system/movie/TMovie.h"

extern "C" {

// Packs a planar 4:2:0 frame into the YUYV external frame buffer, centred,
// two lines per pass, one cache touch per four words. Every named local keeps
// one register for the whole function (unit flags in configure.py).
void pack_movie_frame(MovieFramePlanes *frame) {
    u32 *row_end;
    u32 *end;
    u32 *y2;
    u32 width;
    u32 *cr;
    u32 *cb;
    u32 *y;
    u32 *dst;
    u32 *low;
    u32 yw;
    u32 height;
    u32 *cr_src;
    u32 *cb_src;
    u32 *luma_src;
    u32 lw;
    u32 y_pad;
    u32 uw;
    u32 vw;
    u32 hi;
    int touch;
    u32 dst_pad;
    u32 lo;
    u32 c_pad;

    dst = static_cast<u32 *>(movie_current_frame_buffer);
    width = lbl_805D56A4;
    height = lbl_805D56A8;
    touch = 32;
    dst += ((640 - width) * 2 / 2) / 4;
    cb_src = frame->u;
    dst += ((480 - height) * 640) / 4;
    low = dst + 320 - 1;
    luma_src = frame->y;
    cr_src = frame->v;
    dst -= 1;
    // A decrement of a separate source pointer stays where it is written;
    // an in-place `p -= 1` is sunk to the next use by the forward peephole.
    y = luma_src - 1;
    y2 = y + frame->y_pitch / 4;
    end = dst + height * 320;
    cb = cb_src - 1;
    y_pad = (frame->y_pitch / 4) * 2 - width / 4;
    cr = cr_src - 1;
    c_pad = frame->uv_pitch / 4 - width / 8;
    dst_pad = 640 - width / 2;

    while (end > dst) {
        row_end = dst + (width * 2 * 2 / 2) / 4;
        while (row_end > dst) {
            // The two-statement chroma extract keeps the first half above the
            // 100-pcode block limit, so the block split lands on the second
            // __dcbt. The second luma pair is reloaded before the second
            // word's stores.
            __dcbt(y, touch);
            uw = *++cb;
            vw = *++cr;
            yw = *++y;
            lw = *++y2;
            hi = uw >> 8;
            hi &= 0x00FF0000;
            hi = (vw >> 24) | (hi & ~0xFFu);
            lo = hi;
            hi = (yw & 0xFF000000) | (hi & ~0xFF000000u);
            hi = ((yw >> 8) & 0x0000FF00) | (hi & ~0x0000FF00u);
            lo = (lw & 0xFF000000) | (lo & ~0xFF000000u);
            lo = ((lw >> 8) & 0x0000FF00) | (lo & ~0x0000FF00u);
            *++dst = hi;
            *++low = lo;
            hi = uw;
            hi &= 0x00FF0000;
            hi = ((vw >> 16) & 0xFF) | (hi & ~0xFFu);
            lo = hi;
            hi = ((yw << 16) & 0xFF000000) | (hi & ~0xFF000000u);
            hi = ((yw << 8) & 0x0000FF00) | (hi & ~0x0000FF00u);
            lo = ((lw << 16) & 0xFF000000) | (lo & ~0xFF000000u);
            lo = ((lw << 8) & 0x0000FF00) | (lo & ~0x0000FF00u);
            yw = *++y;
            lw = *++y2;
            *++dst = hi;
            *++low = lo;
            hi = uw << 8;
            hi &= 0x00FF0000;
            hi = ((vw >> 8) & 0xFF) | (hi & ~0xFFu);
            lo = hi;
            hi = (yw & 0xFF000000) | (hi & ~0xFF000000u);
            hi = ((yw >> 8) & 0x0000FF00) | (hi & ~0x0000FF00u);
            lo = (lw & 0xFF000000) | (lo & ~0xFF000000u);
            lo = ((lw >> 8) & 0x0000FF00) | (lo & ~0x0000FF00u);
            *++dst = hi;
            *++low = lo;
            hi = uw << 16;
            hi &= 0x00FF0000;
            hi = (vw & 0xFF) | (hi & ~0xFFu);
            lo = hi;
            hi = ((yw << 16) & 0xFF000000) | (hi & ~0xFF000000u);
            hi = ((yw << 8) & 0x0000FF00) | (hi & ~0x0000FF00u);
            lo = ((lw << 16) & 0xFF000000) | (lo & ~0xFF000000u);
            lo = ((lw << 8) & 0x0000FF00) | (lo & ~0x0000FF00u);
            *++dst = hi;
            *++low = lo;
            __dcbt(y2, touch);
            uw = *++cb;
            vw = *++cr;
            yw = *++y;
            lw = *++y2;
            hi = uw >> 8;
            hi &= 0x00FF0000;
            hi = (vw >> 24) | (hi & ~0xFFu);
            lo = hi;
            hi = (yw & 0xFF000000) | (hi & ~0xFF000000u);
            hi = ((yw >> 8) & 0x0000FF00) | (hi & ~0x0000FF00u);
            lo = (lw & 0xFF000000) | (lo & ~0xFF000000u);
            lo = ((lw >> 8) & 0x0000FF00) | (lo & ~0x0000FF00u);
            *++dst = hi;
            *++low = lo;
            hi = uw;
            hi &= 0x00FF0000;
            hi = ((vw >> 16) & 0xFF) | (hi & ~0xFFu);
            lo = hi;
            hi = ((yw << 16) & 0xFF000000) | (hi & ~0xFF000000u);
            hi = ((yw << 8) & 0x0000FF00) | (hi & ~0x0000FF00u);
            lo = ((lw << 16) & 0xFF000000) | (lo & ~0xFF000000u);
            lo = ((lw << 8) & 0x0000FF00) | (lo & ~0x0000FF00u);
            yw = *++y;
            lw = *++y2;
            *++dst = hi;
            *++low = lo;
            hi = uw << 8;
            hi &= 0x00FF0000;
            hi = ((vw >> 8) & 0xFF) | (hi & ~0xFFu);
            lo = hi;
            hi = (yw & 0xFF000000) | (hi & ~0xFF000000u);
            hi = ((yw >> 8) & 0x0000FF00) | (hi & ~0x0000FF00u);
            lo = (lw & 0xFF000000) | (lo & ~0xFF000000u);
            lo = ((lw >> 8) & 0x0000FF00) | (lo & ~0x0000FF00u);
            *++dst = hi;
            *++low = lo;
            hi = uw << 16;
            hi &= 0x00FF0000;
            hi = (vw & 0xFF) | (hi & ~0xFFu);
            lo = hi;
            hi = ((yw << 16) & 0xFF000000) | (hi & ~0xFF000000u);
            hi = ((yw << 8) & 0x0000FF00) | (hi & ~0x0000FF00u);
            lo = ((lw << 16) & 0xFF000000) | (lo & ~0xFF000000u);
            lo = ((lw << 8) & 0x0000FF00) | (lo & ~0x0000FF00u);
            *++dst = hi;
            *++low = lo;
        }
        dst += dst_pad;
        low += dst_pad;
        y += y_pad;
        y2 += y_pad;
        cb += c_pad;
        cr += c_pad;
    }
}


}
