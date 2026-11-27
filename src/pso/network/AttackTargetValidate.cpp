#include "types.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcommand_validation.h"
#include "pso/network/protocol/subcommand_validation_player.h"
#include "pso/player/CapturedTargetList.h"
s32 validate_attack_target_list(CapturedTargetList *list) {
    s32 i;
    if (validate_attack_target_count(&list->count) == 0) {
        return 0;
    }
    for (i = 0; i < list->count; i++) {
        if (validate_attack_target_entry(&list->entries[i]) == 0) {
            return 0;
        }
    }
    return 1;
}
