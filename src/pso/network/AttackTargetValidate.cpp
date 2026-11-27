#include "types.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcommand_validation.h"
#include "pso/network/protocol/subcommand_validation_player.h"
s32 validate_attack_target_list(s32 *list) {
    s32 i;
    if (validate_attack_target_count(list) == 0) {
        return 0;
    }
    for (i = 0; i < *list; i++) {
        if (validate_attack_target_entry((u8 *)list + 4 + i * 4) == 0) {
            return 0;
        }
    }
    return 1;
}
