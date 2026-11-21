#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowEffectParty.h"

    extern saddr tl_07;
void TWindowCtrl::create_party_effect(void* a0, void* a1) { TWindowEffectParty::create((void *)tl_07, (saddr)a0, (saddr)a1, (uaddr)((void*)0)); }
