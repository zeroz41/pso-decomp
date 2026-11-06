#include "types.h"
#include "pso/system/memory.h"
#include "pso/unk/TLobby.h"
#include "pso/system/movie/TMovie.h"

extern "C" {

s32 release__6TMovieFv();

s32 close__6TMovieFis(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        release__6TMovieFv();
        ((TMovie *)arg0)->free_buffer();
        TLobby::stop_audio_streams();
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

}
