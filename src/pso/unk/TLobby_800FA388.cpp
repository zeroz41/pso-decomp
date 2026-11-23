#include "pso/system/Adxf.h"
#include "types.h"
#include <string.h>
#include "pso/unk/text_803CC294.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_800FA848.h"


struct Ent_800fa388;

s32 TLobby::request_file_read(const char *name, s32 arg1, s32 *arg2, void **arg3) {
    struct Ent_800fa388 *var_r31;
    AdxfHandle *file;

    if (arg3 != NULL) {
        *arg3 = NULL;
    }
    file = ADXF_Open(name, 0);
    if (file == 0) {
        return -2;
    }
    var_r31 = (struct Ent_800fa388 *)(u8 *)TLobby::alloc_from_heap(0x68);
    if (var_r31 != NULL) {
        var_r31 = (struct Ent_800fa388 *)link_into_list(var_r31);
    }
    strncpy((char *)var_r31 + 8, name, 0x20);
    *(s32 *)((s8 *)var_r31 + 0) = 1;
    *(s32 *)((s8 *)var_r31 + 0x28) = arg1;
    *(s32 *)((s8 *)var_r31 + 0x2C) = ADXF_GetFsizeByte(file);
    *(s32 *)((s8 *)var_r31 + 0x30) = ADXF_GetFsizeSct(file);
    ADXF_Close(file);
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

