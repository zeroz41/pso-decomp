#include "types.h"
#include "pso/misc/TWindowSubComCard_80269064.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/misc/TWindowMeseta.h"
#include "pso/misc/TWindowSubStatusDisp.h"

s32 TWindowSubComCard::get_entry_id() { return *(s32*)((char*)this + 0x18); }

int TWindowSubComCard__sub_8026906C(void* p) { return *(u16*)((char*)p + 0x0) & 0x80; }
void fn_80269078(u8 *arg0, s32 arg1) {
    *(s32 *)((s8 *)arg0 + 0x68) = arg1;
    ((TWindowSubStatusDisp *)(((TWindowBase *)arg0)->get_array_entry(1)))->set_all_values((int) (*(s32 *)((s8 *)arg0 + 0x68)));
}
