#include "types.h"
#include "pso/unk/TLobby.h"

s32 TLobby::get_scroll_offset() {
    u8 *arg0 = (u8 *)this;
    return *(s32 *)((s8 *)arg0 + 0x2B0);
}
