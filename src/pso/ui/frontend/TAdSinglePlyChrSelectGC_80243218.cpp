#include "types.h"
#include "pso/render/render_util.h"
#include "pso/system/date.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 start_memcard_read(s32 chan, const char *name, void *buf, u32 blocks);

s32 TAdSinglePlyChrSelectGC::draw_window_bg(s32 chan, s32 arg1, s32 buf, s32 blocks) {
    CardWriteDate date;
    get_current_date_stamp(&date);
    return start_memcard_write(chan, reinterpret_cast<const char *>(arg1), reinterpret_cast<void *>(buf), blocks, &date, 0x800000FF);
}
s32 TAdSinglePlyChrSelectGC::load_player(s32 chan, s32 arg1, s32 buf, s32 blocks) {
    CardWriteDate date;
    get_current_date_stamp(&date);
    return start_memcard_write(chan, reinterpret_cast<const char *>(arg1), reinterpret_cast<void *>(buf), blocks, &date, 0x80000000);
}
s32 TAdSinglePlyChrSelectGC::load_player_slot(s32 chan, const char *file_name, void *buffer) {
    return start_memcard_read(chan, file_name, buffer, 0);
}

}
