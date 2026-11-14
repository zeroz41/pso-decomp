#include "types.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXFrameBuffer.h>
#include <dolphin/gx/GXTexture.h>
#include <dolphin/vi.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/system/movie/TMovie.h"
#include "pso/system/movie/TMovie_80143C94.h"
#include "pso/system/movie/TMovie_80143CC8.h"
#include "pso/system/movie/TMovie_80143CE8.h"
#include "pso/player/TObjPlayer_80083B38.h"

typedef void (*RecoveredCallback_6d14191ba232)(u32, s32, s32, void *);

extern "C" {

s32 DCStoreRangeNoSync(void *, s32);
s32 DCFlushRangeNoSync(s32, s32);

extern RecoveredCallback_6d14191ba232 lbl_805D6BF4;

GXRenderModeObj *TMovie__framebuffer_video_mode = &GXNtsc480Int;

void *movie_current_frame_buffer;
void *movie_frame_buffer_size;
void *lbl_805D5690;
s32 lbl_805D5694;
s32 lbl_805D5698;
u32 movie_flip_counter;
u32 lbl_805D56A0;
s32 lbl_805D56A4;
s32 lbl_805D56A8;

void TMovie::flush_cache() {
    if (VIGetNextField() == 0U) {
        DCStoreRangeNoSync(movie_current_frame_buffer, lbl_805D5694);
        VIFlush();
        movie_flip_counter += 1;
    }
}

void TMovie::flip_frame_buffer() {
    MovieFramePlanes planes;
    if (lbl_805D56A0 != 0U) {
        if (movie_flip_counter & 1) {
            movie_current_frame_buffer = lbl_805D5690;
        } else {
            movie_current_frame_buffer = movie_frame_buffer_size;
        }
        if (lbl_805D5698 == 1) {
            VISetBlack(0);
            lbl_805D5698 = 0;
        }
        lbl_805D6BF4(lbl_805D56A0, lbl_805D56A4, lbl_805D56A8, &planes);
        pack_movie_frame(&planes);
        VISetNextFrameBuffer(movie_current_frame_buffer);
        lbl_805D56A0 = 0U;
    }
}

void TMovie__sub_80143C94(int a0, int a1, int a2) {
    lbl_805D56A0 = a0;
    lbl_805D56A4 = a1;
    lbl_805D56A8 = a2;
}

void TMovie::flush_and_reset() { TMovie::flush_cache(); TMovie__sub_80143CC8(); }

void TMovie__sub_80143CC8(void) { VIWaitForRetrace(); }

}

extern s32 (*framebuffer_flush_callback)(s32, s32, s32);
extern s32 (*movie_flush_framebuffer_callback)(s32, s32, s32);

void TMovie::calc_frame_buffer_size(s32 arg0, s32 arg1) {
    movie_frame_buffer_size = (void *)arg0;
    lbl_805D5690 = (void *)arg1;
    lbl_805D5694 = ((TMovie__framebuffer_video_mode->fbWidth + 0xF) & 0xFFF0) * TMovie__framebuffer_video_mode->xfbHeight * 2;
}

void flush_framebuffer(s32 arg1, s32 arg2, s32 arg3) {

    movie_flush_framebuffer_callback(arg2, 0x280, 0x1E0);
    framebuffer_flush_callback(arg2, arg3, TObjPlayer__sub_800845F8());
    DCFlushRangeNoSync(TObjPlayer__sub_800845F8(), GXGetTexBufferSize(0x280, 0x1E0, 6, 0, 0));
}
