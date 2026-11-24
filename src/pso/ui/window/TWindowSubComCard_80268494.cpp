#include "types.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/TWindowMenuInfomation.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowBase.h"


extern "C" {

// Keep the label pointer in its original register across the entry scan.
void set_string__20TWindowSubStatusDispFUl(TWindowSubStatusDisp *, void *);

struct Ent_802684BC { u8 p0[0x1C]; s32 f1C; };

s32 TWindowMenuInfomation::update_selected_entry() {
    return ((TWindowSubComCard *)get_array_entry(index))->get_entry_id();
}

s32 TWindowMenuInfomation::find_entry_value_by_id(s32 key) {
    s32 i;
    Ent_802684BC *e;
    for (i = 0; i < entry_capacity; i++) {
        e = (Ent_802684BC *)get_array_entry(i);
        if (e != NULL && ((TWindowSubComCard *)e)->is_flag_4_set() != 0 && key == ((TWindowSubComCard *)e)->get_entry_id()) {
            return e->f1C;
        }
    }
    return 0;
}
void TWindowMenuInfomation::mark_entry_by_id(s32 entry_id) {
    s32 i;
    u8 *e;
    for (i = 0; i < entry_capacity; i++) {
        e = (u8 *)get_array_entry(i);
        if (e != 0 && ((TWindowSubComCard *)e)->is_flag_4_set() != 0 && entry_id == ((TWindowSubComCard *)e)->get_entry_id()) {
            *(u16 *)e |= 1;
            ((WindowTextEntry *)e)->color = -1;
        }
    }
}
void TWindowMenuInfomation::disable_entry_by_id(s32 id) {
    s32 i;
    u8 *e;
    for (i = 0; i < entry_capacity; i++) {
        e = (u8 *)get_array_entry(i);
        if (e != 0 && ((TWindowSubComCard *)e)->is_flag_4_set() != 0 && id == ((TWindowSubComCard *)e)->get_entry_id()) {
            *(u16 *)e &= 0xFFFE;
            ((WindowTextEntry *)e)->color = 0xFF909090;
        }
    }
}
void TWindowMenuInfomation::set_entry_string_by_id(void *id, s32 entry_id) {
    s32 i;
    u8 *e;
    for (i = 0; i < entry_capacity; i++) {
        e = (u8 *)get_array_entry(i);
        if (e != 0 && ((TWindowSubComCard *)e)->is_flag_4_set() != 0 && entry_id == ((TWindowSubComCard *)e)->get_entry_id()) {
            set_string__20TWindowSubStatusDispFUl((TWindowSubStatusDisp *)e, id);
        }
    }
}

void TWindowMenuInfomation::update_next_entry(s32 arg1, s32 string, s32 arg3) {
    s16 next_row;

    next_row = next_entry;
    if (next_row < entry_capacity) {
        ((TWindowSubStatusDisp *)(get_array_entry(next_row)))->set_text(arg1, string, arg3);
        ++next_entry;
    }
}

}
