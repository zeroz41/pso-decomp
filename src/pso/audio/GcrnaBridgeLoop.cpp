#include "types.h"
#include "pso/audio/GcrnaControlBridge.h"
#include "pso/unk/TLobby.h"

typedef void (*GcrnaLoopTrampolineFn)(void);

void TLobby::apply_field() {
    ((GcrnaLoopTrampolineFn)gcrna_set_loop_flag)();
}
