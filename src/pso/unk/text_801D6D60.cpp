#include "types.h"
#include "pso/network/LobbyRuleSettings.h"

s8 LobbyRuleSettings::get_trap_count(s32 index) {
    s8 count = trap_counts[index];
    if (count < 0 || count > 20) {
        trap_counts[index] = 0;
    }
    return trap_counts[index];
}
