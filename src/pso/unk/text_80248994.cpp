#include "pso/unk/TWindowLayoutEntry.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

struct Obj_80248994 { u8 pad[0x76]; s16 count; };

extern "C" void fn_80248994(TWindowBase *list, u32 color, s32 pos);

void fn_80248994(TWindowBase *list, u32 color, s32 pos) {
    s32 i;
    saddr e;
    for (i = 0; i < ((Obj_80248994 *)list)->count; i++) {
        e = reinterpret_cast<saddr>(list->get_array_entry(i));
        if (e != 0 && ((TWindowLayoutEntry *)e)->is_flag_4_set() != 0 && pos == ((ItemListRow *)e)->get_item()) {
            ((ItemListRow *)e)->category_style = color;
            ((ItemListRow *)e)->style = color;
        }
    }
}
