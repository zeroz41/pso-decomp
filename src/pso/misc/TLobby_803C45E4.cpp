#include "types.h"
#include "pso/unk/text_803D31A4.h"
#include "pso/misc/TLobby.h"

extern "C" {

s32 memset(void *, int, int);

void TLobby::set_packet_flags(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x20) = arg1;
}

void TLobby::clear_entry() {
    s32 arg0 = (s32)this;
    if (arg0 != 0) {
        TLobby::init_once();
        memset((void *)arg0, 0, 0x30);
        TLobby::release_ref();
    }
}

extern s32 TLobby__init_ref_count;

void TLobby::release_ref() {
    s32 temp_r0;

    temp_r0 = TLobby__init_ref_count - 1;
    TLobby__init_ref_count = temp_r0;
    if (temp_r0 == 0) {
        TLobby__sub_803D3988();
    }
}

void TLobby::init_once() {
    if ((s32) TLobby__init_ref_count == 0) {
        TLobby__sub_803D39C0();
    }
    TLobby__init_ref_count += 1;
}

}
