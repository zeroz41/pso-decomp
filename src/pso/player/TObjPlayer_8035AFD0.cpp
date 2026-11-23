#include "types.h"
#include "pso/player/PhotonChairSeat.h"

PhotonChairSeat *PhotonChairSeat::conditional_delete_ex(s16 flag) {
    if (this != NULL && flag > 0) {
        ::operator delete(this);
    }
    return this;
}
