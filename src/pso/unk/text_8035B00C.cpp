#include "types.h"
#include "pso/player/PhotonChairSeat.h"
#include "pso/player/TObjPlayer_801C7430.h"

void PhotonChairSeat::reset() {
    animation = ret_801D26AC();
    owner_id = 0xFFFF;
    delay_6xB0 = delay_6xAF = pad_4 = 0;
}
