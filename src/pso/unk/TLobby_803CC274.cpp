#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {

s32 DCInvalidateRange();

void TLobby::invalidate_cache() {
    DCInvalidateRange();
}

}
