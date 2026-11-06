#include "pso/network/protocol/subcommand_validation.h"
#include "pso/network/protocol/subcommand_validation_photon_blast.h"

extern "C" {
s32 is_valid_technique_id__10TObjPlayerFs(s32);
s32 is_valid_technique_slot__10TObjPlayerFUc(u8);
}

s32 validate_photon_blast_parameters(void *parameters) {
    s8 temp_r4;
    s16 temp_r4_2;
    temp_r4 = *(s8 *)((s8 *)parameters + 0);
    if (((temp_r4 != -1) && (temp_r4 < 0)) || (temp_r4 >= 6)) {
        return 0;
    }
    if (*(s8 *)((s8 *)parameters + 1) < 0) {
        return 0;
    }
    temp_r4_2 = *(s16 *)((s8 *)parameters + 2);
    if ((temp_r4_2 < 0) || (temp_r4_2 > 0xA)) {
        return 0;
    }
    if (*(s16 *)((s8 *)parameters + 4) < 0) {
        return 0;
    }
    return ((u32) *(s16 *)((s8 *)parameters + 6) >> 0x1FU) ^ 1;
}

s32 validate_6x48_cast_technique_complete(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    return is_valid_technique_id__10TObjPlayerFs(*(s16 *)((s8 *)packet + 4)) != 0 ? 1 : 0;
}

s32 validate_6x8D_set_technique_level_override(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    return is_valid_technique_slot__10TObjPlayerFUc(*(u8 *)((s8 *)packet + 4)) != 0 ? 1 : 0;
}
