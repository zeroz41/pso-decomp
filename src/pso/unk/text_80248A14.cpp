#include "types.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct Obj_80248A14 { u8 pad[0x76]; s16 count; };

void THunterGuildSeqOffline::advance_matching_entries(s32 arg1, s32 arg2) {
    s32 i;
    s32 e;
    for (i = 0; i < ((Obj_80248A14 *)this)->count; i++) {
        e = ((TWindowBase *)this)->get_array_entry(i);
        if (e != 0 && ((TWindowSubStatusDisp *)e)->is_flag_4_set() != 0 && arg2 == ((TWindowSubItem *)e)->get_cursor_pos()) {
            if (arg1 != 0) {
                ((TWindowSubStatusDisp *)e)->finalize_state();
            } else {
                ((TWindowSubStatusDisp *)e)->advance_state();
            }
        }
    }
}
