#include "types.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/object/warp/TObjCityMainWarp.h"

extern "C" {

int open_yes_no_prompt(void* a0 = 0, void* a1 = 0, void* a2 = 0, void* a3 = 0);

void TAdChrSelASlotGC::forward_slot_selection(void* a1, void* a2) { open_yes_no_prompt(this, (void*)0, a1, a2); }

}
