#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {

u8 *alloc_from_heap__6TLobbyFPv(s32);
u8 *link_into_list__6TLobbyFv();
s32 strncpy(void *, s32, s32);

void TLobby::add_named_entry(s32 arg0, s32 arg1) {
    u8 *var_r31;

    var_r31 = alloc_from_heap__6TLobbyFPv(0x68);
    if (var_r31 != NULL) {
        var_r31 = link_into_list__6TLobbyFv();
    }
    strncpy(var_r31 + 8, arg1, 0x20);
    *(s32 *)((s8 *)var_r31 + 0) = 4;
    *(s32 *)((s8 *)var_r31 + 0x64) = arg0;
}

}
