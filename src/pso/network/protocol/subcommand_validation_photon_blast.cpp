#include "pso/network/protocol/subcommand_validation.h"
#include "pso/network/protocol/subcommand_validation_photon_blast.h"
#include "pso/network/protocol/subcmd_6x.h"
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

s32 validate_photon_blast_parameters(G_ExecutePhotonBlastParams_6x49 *params) {
    s8 photon_blast;
    s16 target_count;
    photon_blast = params->photon_blast;
    if (((photon_blast != -1) && (photon_blast < 0)) || (photon_blast >= 6)) {
        return 0;
    }
    if (params->unused1 < 0) {
        return 0;
    }
    target_count = params->target_count;
    if ((target_count < 0) || (target_count > 0xA)) {
        return 0;
    }
    if (params->pb_meter_value < 0) {
        return 0;
    }
    return params->unused2 < 0 ? 0 : 1;
}

s32 validate_6x48_cast_technique_complete(G_CastTechniqueComplete_6x48 *packet) {
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    return PlayerTechniqueState::is_valid_technique_id(packet->technique_number) != 0 ? 1 : 0;
}

s32 validate_6x8D_set_technique_level_override(G_SetTechniqueLevelOverride_6x8D *packet) {
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    return TObjPlayer::is_valid_technique_slot(packet->level_upgrade) != 0 ? 1 : 0;
}
