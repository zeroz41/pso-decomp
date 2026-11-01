#include "types.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/misc/TWindowChoiceSetting.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

void TWindowSubTradeMain::clear_flag() { this->m_70 &= 0xffffffbf; }

void TWindowSubTradeMain::clear_flag70_bit80() { this->m_70 &= 0xffffff7f; }
