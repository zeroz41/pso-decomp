#include "types.h"
#include "pso/system/main_loop.h"
#include "pso/system/movie/TMovie.h"
#include "pso/unk/TLobby.h"

extern "C" {

s32 DVDCheckDisk();

void TMovie::render_until_finished() {
loop_1:
    if ((DVDCheckDisk() == 0) && (TLobby::run_disk_error_check() == 0)) {
        render_tick();
        goto loop_1;
    }
}

}
