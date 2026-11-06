#include "types.h"
#include "pso/unk/text_803CC294.h"
#include "pso/unk/TLobby.h"

extern "C" {

u8 *alloc_from_heap__6TLobbyFPv(s32);
s32 adxf_open__6TLobbyFUii(s32, s32);
u8 *link_into_list__6TLobbyFv();
s32 strncpy(void *, s32, s32);

struct Ent_800fa388;

s32 TLobby::request_file_read(s32 arg0, s32 arg1, s32 *arg2, void **arg3) {
    struct Ent_800fa388 *var_r31;
    s32 temp_r3;

    if (arg3 != NULL) {
        *arg3 = NULL;
    }
    temp_r3 = adxf_open__6TLobbyFUii(arg0, 0);
    if (temp_r3 == 0) {
        return -2;
    }
    var_r31 = (struct Ent_800fa388 *)alloc_from_heap__6TLobbyFPv(0x68);
    if (var_r31 != NULL) {
        var_r31 = (struct Ent_800fa388 *)link_into_list__6TLobbyFv();
    }
    strncpy((u8 *)var_r31 + 8, arg0, 0x20);
    *(s32 *)((s8 *)var_r31 + 0) = 1;
    *(s32 *)((s8 *)var_r31 + 0x28) = arg1;
    *(s32 *)((s8 *)var_r31 + 0x2C) = ((TLobby *)temp_r3)->adxf_get_fsize_byte();
    *(s32 *)((s8 *)var_r31 + 0x30) = TLobby__sub_803CC53C((u8 *)temp_r3);
    ((TLobby *)temp_r3)->close_adxf_handle();
    *(s32 **)((s8 *)var_r31 + 0x34) = arg2;
    if (arg2 != NULL) {
        *arg2 = 0;
    }
    *(s32 *)((s8 *)var_r31 + 0x40) = 0;
    if (arg3 != NULL) {
        *arg3 = var_r31;
    }
    return *(s32 *)((s8 *)var_r31 + 0x2C);
}

}
