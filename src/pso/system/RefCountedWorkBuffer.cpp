#include "types.h"
#include <string.h>
#include "pso/system/RefCountedWorkBuffer.h"

extern "C" {

u8 ref_counted_load_buffer[0xC00];
s32 lobby_buffer_refcount;

void ref_counted_work_buffer_finish(void) {
    if (--lobby_buffer_refcount == 0) {
        memset(ref_counted_load_buffer, 0, 0xC00);
    }
}

void ref_counted_work_buffer_init(void) {
    if (lobby_buffer_refcount == 0) {
        memset(ref_counted_load_buffer, 0, 0xC00);
    }
    lobby_buffer_refcount += 1;
}

}
