#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_800FA848.h"

extern "C" {

s32 strncpy(void *, s32, s32);

void TLobby::add_named_entry(s32 arg0, s32 arg1) {
    u8 *var_r31;

    var_r31 = (u8 *)TLobby::alloc_from_heap(0x68);
    if (var_r31 != NULL) {
        var_r31 = (u8 *)link_into_list(var_r31);
    }
    strncpy(var_r31 + 8, arg1, 0x20);
    *(s32 *)((s8 *)var_r31 + 0) = 4;
    *(s32 *)((s8 *)var_r31 + 0x64) = arg0;
}

}
