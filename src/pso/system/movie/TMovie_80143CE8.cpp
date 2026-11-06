#include "types.h"
#include "pso/system/movie/TMovie_80143CE8.h"
#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/system/movie/TMovie.h"

extern void *TMovie__framebuffer_video_mode;
extern s32 movie_frame_buffer_size;
extern s32 lbl_805D5690;
extern s32 lbl_805D5694;
extern "C" {

void TMovie::calc_frame_buffer_size(s32 arg0, s32 arg1) {
    movie_frame_buffer_size = arg0;
    lbl_805D5690 = arg1;
    lbl_805D5694 = ((*(u16 *)((s8 *)TMovie__framebuffer_video_mode + 4) + 0xF) & 0xFFF0) * *(u16 *)((s8 *)TMovie__framebuffer_video_mode + 8) * 2;
}

s32 DCFlushRangeNoSync(s32, s32);
s32 GXGetTexBufferSize(s32, s32, s32, s32, s32);
}
extern s32 (*framebuffer_flush_callback)(s32, s32, s32);
extern s32 (*movie_flush_framebuffer_callback)(s32, s32, s32);

void flush_framebuffer(s32 arg1, s32 arg2, s32 arg3) {

    movie_flush_framebuffer_callback(arg2, 0x280, 0x1E0);
    framebuffer_flush_callback(arg2, arg3, TObjPlayer__sub_800845F8());
    DCFlushRangeNoSync(TObjPlayer__sub_800845F8(), GXGetTexBufferSize(0x280, 0x1E0, 6, 0, 0));
}
