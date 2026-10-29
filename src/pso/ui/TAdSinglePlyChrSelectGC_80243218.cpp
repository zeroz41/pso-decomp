#include "types.h"
#include "pso/render/render_util.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 TAdPlayerLoadGC__sub_801E15A4(s32, s32, s32, s32, s32 *, s32);
int TAdPlayerLoadGC__sub_801E1944(void*, int, int, int);

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
int TAdSinglePlyChrSelectGC::load_player_slot(int a1, int a2) { return TAdPlayerLoadGC__sub_801E1944(this, a1, a2, 0); }

}
