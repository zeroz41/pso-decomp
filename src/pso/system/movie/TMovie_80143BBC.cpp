#include "types.h"
#include "pso/system/movie/TMovie.h"
#include "pso/system/movie/TMovie_80143C94.h"

typedef void (*RecoveredCallback_6d14191ba232)(u32, s32, s32, void *);

extern "C" {

s32 DCStoreRangeNoSync(void *, s32);
s32 VIFlush();
u32 VIGetNextField();
void VISetNextFrameBuffer(void *);
void VISetBlack(int);

extern void *movie_frame_buffer_size;
extern void *lbl_805D5690;
extern s32 lbl_805D5694;
extern s32 lbl_805D5698;
extern u32 movie_flip_counter;
extern u32 lbl_805D56A0;
extern RecoveredCallback_6d14191ba232 lbl_805D6BF4;

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

}
