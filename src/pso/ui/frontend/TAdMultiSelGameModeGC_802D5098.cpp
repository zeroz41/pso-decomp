#include "types.h"
#include "pso/ui/frontend/TAdMultiSelGameModeGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"

void TAdMultiSelGameModeGC::set_selection_state(s32 v) { *(s32*)((char*)this + 0x700) = v; }
