#include <dolphin/os/OSCache.h>
#include "pso/unk/TLobby.h"

extern "C" {

void DCInvalidateRange(void *, u32);

void TLobby::invalidate_cache(void *start, u32 length) {
    DCInvalidateRange(start, length);
}

}
