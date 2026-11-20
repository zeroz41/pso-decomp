#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecZarua.h"

void TObjPlayer::create_tec_zarua(void *arg0, void *arg1, void *arg2, void *arg3) {
    new TTecZarua((saddr)arg0, (Vec *)arg1, (TargetCursorList *)arg2, (saddr)arg3);
}
