#include "types.h"
#include "pso/ui/window/TWindowSubComCard_80269064.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/window/TWindowMeseta.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/LabelValueRow.h"

s32 LabelValueRow::get_entry_id() { return id; }

int TWindowSubComCard__sub_8026906C(void* p) { return *(u16*)((char*)p + 0x0) & 0x80; }
void TWindowMeseta::set_value(s32 value) {
    meseta = value;
    ((TWindowSubStatusDisp *)get_array_entry(1))->set_all_values((int)meseta);
}
