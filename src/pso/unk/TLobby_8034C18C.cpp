#include "types.h"
#include "pso/unk/TLobby_8034C18C.h"
#include "pso/unk/TLobby.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Body_8034C1D0 { u32 w[0x234]; };

struct Big_8034C1D0 { u32 a; Body_8034C1D0 b; };

s32 info_board_state_flags;
uaddr information_board_response_buffer;
void TLobby::init_once(s32 src) {
    if (!(info_board_state_flags & 2) && (information_board_response_buffer != 0U)) {
        info_board_state_flags |= 2;
        TLobby__sub_8034C1D0(information_board_response_buffer, src);
    }
}

uaddr TLobby__sub_8034C1D0(uaddr dst, saddr src) {
    *(Big_8034C1D0 *)dst = *(Big_8034C1D0 *)src;
    return dst;
}

void *TLobby::get_info_board_ptr() {
    void *p;
    if (!(info_board_state_flags & 2)) {
        return NULL;
    }
    p = (void *)information_board_response_buffer;
    if (p != NULL) {
        return p;
    }
    return NULL;
}
