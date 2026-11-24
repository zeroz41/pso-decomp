#include "types.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/window/TWindowShortListCtrl.h"

void TWindowMenuIconLine::set_flag70_bit10() { this->state_flags |= 0x10; }

void TShopJudgmentItemEntry::set(TItem *item, s32 index) {
    this->index = index;
    this->item = item;
}
