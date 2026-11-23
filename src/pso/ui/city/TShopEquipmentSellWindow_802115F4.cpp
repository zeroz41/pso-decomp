#include "types.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowInputNumber.h"

int TWindowInputNumber::is_cancelled() { return (this->inputFlags >> 2) & 0x1; }
s32 TWindowInputNumber::get_value() { return this->value; }
