#include "pso/system/memory.h"
#include "pso/system/Adxf.h"
#include "types.h"
#include <string.h>
#include "pso/unk/TLobby_800FA2A0.h"
#include "pso/unk/text_803CC294.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_800FA848.h"


s32 create_named_entry__6TLobbyFiiUiiPv(saddr name, s32 arg1, u32 arg2, void *src, void **arg4) {
    u8 *var_r31;
    AdxfHandle *file;

    if (arg4 != NULL) {
        *arg4 = NULL;
    }
    file = ADXF_Open((void *)name, 0);
    if (file == 0) {
        return -2;
    }
    var_r31 = (u8 *)TLobby::alloc_from_heap(0x68);
    if (var_r31 != NULL) {
        var_r31 = (u8 *)link_into_list(var_r31);
    }
    strncpy((char *)(var_r31 + 8), (const char *)name, 0x20);
    *(s32 *)((s8 *)var_r31 + 0) = 1;
    *(s32 *)((s8 *)var_r31 + 0x28) = arg1;
    *(s32 *)((s8 *)var_r31 + 0x2C) = ADXF_GetFsizeByte(file);
    *(s32 *)((s8 *)var_r31 + 0x30) = ADXF_GetFsizeSct(file);
    ADXF_Close(file);
    *(s32 *)((s8 *)var_r31 + 0x34) = 0;
    *(u32 *)((s8 *)var_r31 + 0x40) = arg2;
    if (arg2 != 0U) {
        move_words(reinterpret_cast<void *>(var_r31 + 0x44), reinterpret_cast<const void *>(src), 8);
    }
    if (arg4 != NULL) {
        *arg4 = var_r31;
    }
    return *(s32 *)((s8 *)var_r31 + 0x2C);
}

