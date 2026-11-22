#include "pso/system/Adxf.h"
#include "types.h"
#include <string.h>
#include "pso/unk/text_803CC294.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_800FA848.h"

extern "C" {


struct Ent_800fa164;

s32 TLobby::create_file_load_entry(saddr arg0, s32 arg1, u32 arg2, saddr src, void **arg4) {
    struct Ent_800fa164 *var_r31;
    AdxfHandle *file;

    if (arg4 != NULL) {
        *arg4 = NULL;
    }
    file = ADXF_Open((const void *)arg0, 0);
    if (file == 0) {
        return -2;
    }
    if (ADXF_GetFsizeByte(file) > 0x40000) {
        ADXF_Close(file);
        return -3;
    }
    var_r31 = (struct Ent_800fa164 *)(u8 *)TLobby::alloc_from_heap(0x68);
    if (var_r31 != NULL) {
        var_r31 = (struct Ent_800fa164 *)link_into_list(var_r31);
    }
    strncpy((char *)var_r31 + 8, (const char *)arg0, 0x20);
    *(s32 *)((s8 *)var_r31 + 0) = 2;
    *(s32 *)((s8 *)var_r31 + 0x3C) = arg1;
    *(s32 *)((s8 *)var_r31 + 0x30) = ADXF_GetFsizeSct(file);
    ADXF_Close(file);
    *(s32 *)((s8 *)var_r31 + 0x34) = 0;
    *(u32 *)((s8 *)var_r31 + 0x40) = arg2;
    if (arg2 != 0U) {
        ((TLobby *)((u8 *)var_r31 + 0x44))->move_words((u32 *)src, 8);
    }
    if (arg4 != NULL) {
        *arg4 = var_r31;
    }
    return 0;
}

}
