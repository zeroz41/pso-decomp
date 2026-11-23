#include "types.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowInputNumber.h"

void TWindowInputNumber::set_scale(f32 x, f32 y) { scaleX = x; scaleY = y; }

int TCheckRoomSequence::get_room_data(int a0) {  return bank_meseta_by_slot[a0]; }

int TCheckRoomSequence::get_room_table_entry(int a0) {  return bank_item_count_by_slot[a0]; }
