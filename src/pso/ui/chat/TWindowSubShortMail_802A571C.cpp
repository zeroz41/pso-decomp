#include "types.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"

void TWindowSubShortMail::notify_warp_flag70() { void* m = *(void* *)&this->m_2c; if (m) ((TWindowSubComCardList *)m)->set_flag70_bit10(); }
