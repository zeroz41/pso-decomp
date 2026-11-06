#include "types.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

int TWindowSubStatusDisp::is_flag80_set() { return *(u16 *)&this->m_name & 0x80; }
