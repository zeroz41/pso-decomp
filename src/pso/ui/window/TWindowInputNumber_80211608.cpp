#include "types.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

int TWindowInputNumber::is_confirmed() { return (this->inputFlags >> 1) & 0x1; }
