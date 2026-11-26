#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TLobby.h"

DamageStatSlot::DamageStatSlot() {
    init();
}

void DamageStatSlot::init() {
    set_total(0.0f);
    set_accumulated(0.0f);
    set_normal_weight(1.0f);
    set_bonus_weight(1.0f);
}
