#include "pso/unk/TWindowLayoutEntry.h"
#include "types.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

struct ItemMatchView { u8 pad[0x76]; s16 count; };

void THunterGuildSeqOffline::advance_matching_entries(s32 finalize, s32 item) {
    s32 i;
    saddr e;
    for (i = 0; i < ((ItemMatchView *)this)->count; i++) {
        e = reinterpret_cast<saddr>(((TWindowBase *)this)->get_array_entry(i));
        if (e != 0 && ((TWindowLayoutEntry *)e)->is_flag_4_set() != 0 && item == ((ItemListRow *)e)->get_item()) {
            if (finalize != 0) {
                ((ItemListRow *)e)->finalize_state();
            } else {
                ((ItemListRow *)e)->advance_state();
            }
        }
    }
}
