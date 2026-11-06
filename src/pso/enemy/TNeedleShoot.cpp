#include "types.h"
#include "pso/enemy/TNeedleShoot.h"

extern "C" {

s32 update_lifetime__22TObjEneMe1GiGueMissileFv(void *);
s32 TNeedleShoot__sub_802A4668();
s32 update_position__12TNeedleShootFv();

void TNeedleShoot::run_task() {
    if ((s32) this->m_b8 == 1) {
        update_position__12TNeedleShootFv();
        update_lifetime__22TObjEneMe1GiGueMissileFv(this);
        return;
    }
    TNeedleShoot__sub_802A4668();
}

}
