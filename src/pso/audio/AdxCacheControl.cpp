#include "pso/audio/AdxCacheControl.h"
#include <dolphin/os/OSCache.h>
#include "pso/unk/TLobby.h"

extern "C" {

void adx_invalidate_cache(void *start, u32 length) {
    DCInvalidateRange(start, length);
}

}
