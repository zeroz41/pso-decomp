#include "types.h"
#include "pso/render/render_util.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 TAdPlayerLoadGC__sub_801E15A4(s32, s32, s32, s32, s32 *, s32);
s32 TAdPlayerLoadGC__sub_801E1944(s32 chan, const char *name, void *buf, u32 blocks);

void TAdSinglePlyChrSelectGC::draw_window_bg(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp8;

    get_current_date_stamp((DateStamp *)(&sp8));
    TAdPlayerLoadGC__sub_801E15A4(arg0, arg1, arg2, arg3, &sp8, 0x800000FF);
}
void TAdSinglePlyChrSelectGC::load_player(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp8;

    get_current_date_stamp((DateStamp *)(&sp8));
    TAdPlayerLoadGC__sub_801E15A4(arg0, arg1, arg2, arg3, &sp8, 0x80000000);
}
s32 TAdSinglePlyChrSelectGC::load_player_slot(s32 chan, const char *file_name, void *buffer) {
    return TAdPlayerLoadGC__sub_801E1944(chan, file_name, buffer, 0);
}

}
