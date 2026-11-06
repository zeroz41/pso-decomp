#include "types.h"
#include "pso/system/RefCountedWorkBuffer.h"
#include "pso/unk/TLobby.h"

extern "C" {

s32 memset(void *, int, int);

u8 ref_counted_load_buffer[0xC00];
s32 lobby_buffer_refcount;

void TLobby::dec_ref_and_clear_buffer() {
    s32 temp_r0;
    temp_r0 = lobby_buffer_refcount - 1;
    lobby_buffer_refcount = temp_r0;
    if (temp_r0 == 0) {
        memset(ref_counted_load_buffer, 0, 0xC00);
    }
}

void TLobby__sub_803D2ED4(void) {
    if ((s32) lobby_buffer_refcount == 0) {
        memset(ref_counted_load_buffer, 0, 0xC00);
    }
    lobby_buffer_refcount += 1;
}

}
