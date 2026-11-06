#include "types.h"
#include "pso/ui/TAdMultiSelGameModeGC.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"

void TAdMultiSelGameModeGC::set_selection_state(s32 v) { *(s32*)((char*)this + 0x700) = v; }
