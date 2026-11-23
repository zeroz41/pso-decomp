#include <dolphin/os/OSCache.h>
#include "pso/unk/TLobby.h"

extern "C" {

void TLobby::invalidate_cache(void *start, u32 length) {
    DCInvalidateRange(start, length);
}

}
