#include "types.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowInputNumber.h"

void TWindowInputNumber::set_scale(f32 x, f32 y) { scaleX = x; scaleY = y; }

    extern int lbl_80513DA8[];
int TCheckRoomSequence::get_room_data(int a0) {  return lbl_80513DA8[a0]; }

    extern int lbl_80513D98[];
int TCheckRoomSequence::get_room_table_entry(int a0) {  return lbl_80513D98[a0]; }
