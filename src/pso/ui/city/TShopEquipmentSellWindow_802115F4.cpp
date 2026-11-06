#include "types.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowInputNumber.h"

int TShopEquipmentSellWindow::is_confirmed() { return (this->m_60 >> 2) & 0x1; }
s32 TShopEquipmentSellWindow::get_result() { return this->m_6c; }
