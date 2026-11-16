#include "types.h"
#include "pso/render/render_util.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 start_memcard_write(s32, s32, s32, s32, s32 *, s32);
s32 start_memcard_read(s32 chan, const char *name, void *buf, u32 blocks);

void TAdSinglePlyChrSelectGC::draw_window_bg(s32 arg0, s32 arg1, s32 buf, s32 blocks) {
    s32 sp8;

    get_current_date_stamp((DateStamp *)(&sp8));
    start_memcard_write(arg0, arg1, buf, blocks, &sp8, 0x800000FF);
}
void TAdSinglePlyChrSelectGC::load_player(s32 arg0, s32 arg1, s32 buf, s32 blocks) {
    s32 sp8;

    get_current_date_stamp((DateStamp *)(&sp8));
    start_memcard_write(arg0, arg1, buf, blocks, &sp8, 0x80000000);
}
s32 TAdSinglePlyChrSelectGC::load_player_slot(s32 chan, const char *file_name, void *buffer) {
    return start_memcard_read(chan, file_name, buffer, 0);
}

}
