#include "pso/network/protocol/subcommand_validation.h"
#include "pso/network/protocol/subcommand_validation_photon_blast.h"
#include "pso/player/TObjPlayer.h"


s32 validate_6x49_execute_photon_blast(G_ExecutePhotonBlast_6x49 *packet) {
    s32 i;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    if (validate_photon_blast_parameters(&packet->params) == 0) {
        return 0;
    }
    for (i = 0; i < packet->params.target_count; i++) {
        if (validate_cast_target_entry(&packet->targets[i]) == 0) {
            return 0;
        }
    }
    return 1;
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
    return TObjPlayer::is_valid_technique_id(*(s16 *)((s8 *)packet + 4)) != 0 ? 1 : 0;
}

s32 validate_6x8D_set_technique_level_override(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    return TObjPlayer::is_valid_technique_slot(*(u8 *)((s8 *)packet + 4)) != 0 ? 1 : 0;
}
