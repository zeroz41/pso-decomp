#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecZarua.h"

void TObjPlayer::create_tec_zarua(void *source, void *origin, void *targets, s32 level) {
    new TTecZarua((saddr)source, (Vec *)origin, (TargetCursorList *)targets, level);
}
