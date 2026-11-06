#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"

extern "C" {

void fn_8033BCDC(TWindowSubComCard *card, s32 kind, s32 menu_kind, s32 sub_entry, s32 alt_sub_entry);

void TWindowSubComCard::update_card_display(void* a1, void* a2, void* a3, void* a4) { close_windows(); fn_8033BCDC((TWindowSubComCard *)this, (s32)a1, (s32)a2, (s32)a3, (s32)a4); }

}
