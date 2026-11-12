#include "types.h"
#include "pso/item/MagStats.h"
#include "pso/item/TItemData.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int TItemData::test_flag3() { return TObjPlayer::get_slot_value((s32 *)((char*)this + 0xd04), 3); }
int TItemData::get_item_field_2() { return TObjPlayer::get_slot_value((s32 *)((char*)this + 0xd04), 2); }


}

MagStats *MagStats::init() { clear(); return this; }
