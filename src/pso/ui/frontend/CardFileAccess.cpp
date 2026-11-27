#include "types.h"
#include "pso/render/render_util.h"
#include "pso/system/date.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_MemCard.h"
#include "pso/ui/frontend/CardFileAccess.h"



s32 write_card_file_protected(s32 chan, const char *filename, void *buf, s32 blocks) {
    CardWriteDate date;
    get_current_date_stamp(&date);
    return start_memcard_write(chan, filename, buf, blocks, &date, 0x800000FF);
}
s32 write_card_file(s32 chan, const char *filename, void *buf, s32 blocks) {
    CardWriteDate date;
    get_current_date_stamp(&date);
    return start_memcard_write(chan, filename, buf, blocks, &date, 0x80000000);
}
s32 read_card_file(s32 chan, const char *file_name, void *buffer) {
    return start_memcard_read(chan, file_name, buffer, 0);
}

