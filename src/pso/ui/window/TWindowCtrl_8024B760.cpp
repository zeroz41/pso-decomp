#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowEffectParty.h"

    extern int tl_07;
void TWindowCtrl::create_party_effect(void* a0, void* a1) { TWindowEffectParty::create((void *)tl_07, (s32)a0, (s32)a1, (u32)((void*)0)); }
