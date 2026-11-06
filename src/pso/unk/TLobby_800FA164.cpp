#include "types.h"
#include "pso/unk/text_803CC294.h"
#include "pso/unk/TLobby.h"

extern "C" {

u8 *alloc_from_heap__6TLobbyFPv(s32);
s32 adxf_get_fsize_byte__6TLobbyFv();
s32 adxf_open__6TLobbyFUii(s32, s32);
u8 *link_into_list__6TLobbyFv();
s32 strncpy(void *, s32, s32);

struct Ent_800fa164;

s32 TLobby::create_file_load_entry(s32 arg0, s32 arg1, u32 arg2, s32 arg3, void **arg4) {
    struct Ent_800fa164 *var_r31;
    s32 temp_r3;

    if (arg4 != NULL) {
        *arg4 = NULL;
    }
    temp_r3 = adxf_open__6TLobbyFUii(arg0, 0);
    if (temp_r3 == 0) {
        return -2;
    }
    if (adxf_get_fsize_byte__6TLobbyFv() > 0x40000) {
        ((TLobby *)temp_r3)->close_adxf_handle();
        return -3;
    }
    var_r31 = (struct Ent_800fa164 *)alloc_from_heap__6TLobbyFPv(0x68);
    if (var_r31 != NULL) {
        var_r31 = (struct Ent_800fa164 *)link_into_list__6TLobbyFv();
    }
    strncpy((u8 *)var_r31 + 8, arg0, 0x20);
    *(s32 *)((s8 *)var_r31 + 0) = 2;
    *(s32 *)((s8 *)var_r31 + 0x3C) = arg1;
    *(s32 *)((s8 *)var_r31 + 0x30) = TLobby__sub_803CC53C((u8 *)temp_r3);
    ((TLobby *)temp_r3)->close_adxf_handle();
    *(s32 *)((s8 *)var_r31 + 0x34) = 0;
    *(u32 *)((s8 *)var_r31 + 0x40) = arg2;
    if (arg2 != 0U) {
        ((TLobby *)((u8 *)var_r31 + 0x44))->move_words((u32 *)arg3, 8);
    }
    if (arg4 != NULL) {
        *arg4 = var_r31;
    }
    return 0;
}

}
