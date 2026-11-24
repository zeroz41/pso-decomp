#include "pso/network/protocol/subcmd_6x.h"
#include "pso/network/protocol/subcommand_validation.h"
s32 validate_6x47_cast_technique(G_CastTechnique_6x47 *packet) {
    s32 i;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    if (validate_technique_parameters(&packet->params) == 0) {
        return 0;
    }
    for (i = 0; i < packet->params.target_count; i++) {
        if (validate_cast_target_entry(&packet->targets[i]) == 0) {
            return 0;
        }
    }
    return 1;
}
