#include "types.h"
#include "pso/ui/window/TWindowSubCustomSelect.h"
#include "pso/ui/window/TWindowSubCustomEquip.h"

int TWindowSubCustomSelect::is_active() { return this->state_flags & 0x1; }
int TWindowSubCustomSelect::is_cancelled() { return this->state_flags & 0x2; }
