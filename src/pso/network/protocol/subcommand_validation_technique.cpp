#include "pso/network/protocol/subcommand_validation.h"
#include "pso/network/protocol/cast_packets.h"
#include "pso/player/PlayerTechniqueState.h"
#include "pso/network/protocol/subcmd_6x.h"


s32 validate_technique_parameters(G_CastTechniqueParams_6x47 *params) {
    s8 target_count;
    if (PlayerTechniqueState::is_valid_technique_id(params->technique_number) == 0) {
        return 0;
    }
    if (params->unused < 0) {
        return 0;
    }
    target_count = params->target_count;
    if ((target_count < 0) || (target_count > 0xA)) {
        return 0;
    }
    return 1;
}

s32 validate_cast_target_entry(PhotonBlastTarget *target) {
    return target->index < 0 ? 0 : 1;
}

s32 validate_6x46_attack_finished(G_AttackFinished_6x46 *packet) {
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    return validate_attack_target_list(&packet->targets) != 0 ? 1 : 0;
}
