#include "types.h"
#include "pso/system/movie/TMovie_80143DF0.h"
#include "pso/system/movie/TMovie.h"

extern "C" {
void TMovie__sub_80144324(void *,const s8 *);
void play_area_music(const s8 *);
extern s8 lbl_8043F30C[];
extern s8 lbl_8043F31C[];
extern s8 lbl_8043F330[];
s32 get_opening_movie_selector();
s8 get_opening_movie_purpose();
}
u8 *initialize_movie_with_soundtrack(u8 *movie, s8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    *(s32 *)((s8 *)movie + 0xCC) = arg2;
    *(s32 *)((s8 *)movie + 0) = 0;
    TMovie__sub_80144324(movie, arg1);
    ((TMovie *)movie)->init_sfd_player(arg3, arg4);
    if (arg3 != 0) {
        play_area_music(lbl_8043F30C);
    } else if ((get_opening_movie_purpose() == 0) && (get_opening_movie_selector() == 1)) {
        play_area_music(lbl_8043F31C);
    } else {
        play_area_music(lbl_8043F330);
    }
    return movie;
}
