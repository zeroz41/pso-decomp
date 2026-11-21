#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecJelin.h"

void TObjPlayer::create_tec_jelin(void *arg0, void *arg1, void *arg2, void *arg3) {
    new TTecJelin((saddr)arg0, (Vec *)arg1, (TargetCursorList *)arg2, (saddr)arg3);
}
