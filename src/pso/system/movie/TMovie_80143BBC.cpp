#include "types.h"
#include "pso/system/movie/TMovie.h"

extern "C" {

s32 DCStoreRangeNoSync(s32, s32);
s32 VIFlush();
u32 VIGetNextField();

extern s32 movie_current_frame_buffer;
extern s32 lbl_805D5694;
extern s32 movie_flip_counter;

void TMovie::flush_cache() {
    if (VIGetNextField() == 0U) {
        DCStoreRangeNoSync(movie_current_frame_buffer, lbl_805D5694);
        VIFlush();
        movie_flip_counter += 1;
    }
}

}
