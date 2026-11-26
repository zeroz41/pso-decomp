#include "types.h"
#include "pso/network/LobbyRuleSettings.h"

u8 LobbyRuleSettings::get_lives() {
    u8 v = lives;
    if (v > 99) {
        v = 0;
    }
    return v;
}
