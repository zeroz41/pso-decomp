#include "types.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXFrameBuffer.h>
#include <dolphin/gx/GXTexture.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/vi.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/system/movie/TMovie.h"
#include "pso/system/movie/TMovie_80143C94.h"
#include "pso/system/movie/TMovie_80143CE8.h"
#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/unk/text_80320358.h"

// Packs a planar 4:2:0 frame into the YUYV external frame buffer, centred,
// two lines per pass, one cache touch per four words.
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
    width = movie_pending_frame_width;
    height = movie_pending_frame_height;
    touch = 32;
    dst += ((640 - width) * 2 / 2) / 4;
    cb_src = frame->u;
    dst += ((480 - height) * 640) / 4;
    low = dst + 320 - 1;
    luma_src = frame->y;
    cr_src = frame->v;
    dst -= 1;
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



GXRenderModeObj *movie_framebuffer_video_mode = &GXNtsc480Int;

void *movie_current_frame_buffer;
void *movie_frame_buffer_a;
void *movie_frame_buffer_b;
u32 movie_frame_buffer_bytes;
s32 movie_first_frame_unblank;
u32 movie_flip_counter;
u32 movie_pending_frame_addr;
s32 movie_pending_frame_width;
s32 movie_pending_frame_height;

void TMovie::flush_cache() {
    if (VIGetNextField() == 0U) {
        DCStoreRangeNoSync(movie_current_frame_buffer, movie_frame_buffer_bytes);
        VIFlush();
        movie_flip_counter += 1;
    }
}

void TMovie::flip_frame_buffer() {
    MovieFramePlanes planes;
    if (movie_pending_frame_addr != 0U) {
        if (movie_flip_counter & 1) {
            movie_current_frame_buffer = movie_frame_buffer_b;
        } else {
            movie_current_frame_buffer = movie_frame_buffer_a;
        }
        if (movie_first_frame_unblank == 1) {
            VISetBlack(0);
            movie_first_frame_unblank = 0;
        }
        lbl_805D6BF4(movie_pending_frame_addr, movie_pending_frame_width, movie_pending_frame_height, &planes);
        pack_movie_frame(&planes);
        VISetNextFrameBuffer(movie_current_frame_buffer);
        movie_pending_frame_addr = 0U;
    }
}

void TMovie__sub_80143C94(int frame_addr, int width, int height) {
    movie_pending_frame_addr = frame_addr;
    movie_pending_frame_width = width;
    movie_pending_frame_height = height;
}

void TMovie::flush_and_reset() {
    TMovie::flush_cache();
    wait_for_movie_retrace();
}

void wait_for_movie_retrace() {
    VIWaitForRetrace();
}

void TMovie::calc_frame_buffer_size(saddr fb_a, saddr fb_b) {
    movie_frame_buffer_a = reinterpret_cast<void *>(fb_a);
    movie_frame_buffer_b = reinterpret_cast<void *>(fb_b);
    movie_frame_buffer_bytes = ((movie_framebuffer_video_mode->fbWidth + 0xF) & 0xFFF0) * movie_framebuffer_video_mode->xfbHeight * 2;
}

void flush_framebuffer(s32 movie_state, s32 sfd_player, s32 frame_info) {
    mwPlyFxSetOutBufSize_hook(sfd_player, 0x280, 0x1E0);
    mwPlyFxCnvFrmARGB8888_hook(sfd_player, frame_info, get_capture_texture_pixels());
    DCFlushRangeNoSync(reinterpret_cast<void *>(get_capture_texture_pixels()), GXGetTexBufferSize(0x280, 0x1E0, 6, 0, 0));
}
