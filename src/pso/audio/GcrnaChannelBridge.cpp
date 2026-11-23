#include "types.h"
#include "pso/audio/GcrnaChannelBridge.h"

void TLobby__sub_803D4704(GcrnaChannelTarget *target, s32 channel_count) {
    if (target != NULL) {
        target->channel_count = channel_count;
    }
}
