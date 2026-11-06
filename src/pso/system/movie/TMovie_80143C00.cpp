#include "types.h"
#include "pso/system/movie/TMovie.h"
typedef void (*RecoveredCallback_6d14191ba232)(u32, s32, s32, void *);
extern "C" {
void pack_movie_frame(void *);
void VISetNextFrameBuffer(void *);
void VISetBlack(int);
extern void *movie_current_frame_buffer;
extern void *movie_frame_buffer_size;
extern void *lbl_805D5690;
extern s32 lbl_805D5698;
extern u32 movie_flip_counter;
extern u32 lbl_805D56A0;
extern s32 lbl_805D56A4;
extern s32 lbl_805D56A8;
extern RecoveredCallback_6d14191ba232 lbl_805D6BF4;
void TMovie::flip_frame_buffer() {
    u32 sp8[4];
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
        lbl_805D6BF4(lbl_805D56A0, lbl_805D56A4, lbl_805D56A8, sp8);
        pack_movie_frame(sp8);
        VISetNextFrameBuffer(movie_current_frame_buffer);
        lbl_805D56A0 = 0U;
    }
}

}
