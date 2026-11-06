#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

int release_texture_list();

void TObjPlayer::free_if_valid(s32 arg0) {
    if (arg0 != 0) {
        release_texture_list();
        TAdSinglePlyChrSelectGC::safe_free(arg0);
    }
}

}
