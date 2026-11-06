#include "types.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

void TWindowSubTradeMain::clear_flag() { this->m_70 &= 0xffffffbf; }

void TWindowSubTradeMain::clear_flag70_bit80() { this->m_70 &= 0xffffff7f; }
