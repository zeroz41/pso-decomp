#include "pso/network/protocol/subcommand_validation.h"
#include "pso/network/protocol/subcommand_validation_technique.h"

extern "C" {
s32 is_valid_technique_id__10TObjPlayerFs(s32);
}

s32 validate_technique_parameters(void *parameters) {
    s8 b3;
    if (is_valid_technique_id__10TObjPlayerFs((s32) *(s8 *)((s8 *)parameters + 0)) == 0) {
        return 0;
    }
    if (*(s8 *)((s8 *)parameters + 1) < 0) {
        return 0;
    }
    b3 = *(s8 *)((s8 *)parameters + 3);
    if ((b3 < 0) || (b3 > 0xA)) {
        return 0;
    }
    return 1;
}

s32 validate_cast_target_entry(void *parameters) {
    return ((u32) *(s16 *)((s8 *)parameters + 2) >> 0x1FU) ^ 1;
}

s32 validate_6x46_attack_finished(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    return validate_attack_target_list((s32 *)((u8 *)packet + 4)) != 0 ? 1 : 0;
}
