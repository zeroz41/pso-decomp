#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecJelin.h"

void TObjPlayer::create_tec_jelin(void *source, void *origin, void *targets, s32 level) {
    new TTecJelin((saddr)source, (Vec *)origin, (TargetCursorList *)targets, level);
}
