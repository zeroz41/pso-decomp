#include "types.h"
#include "pso/enemy/TNeedleShoot.h"
#include "pso/enemy/gigue/TObjEneMe1GiGueMissile.h"

extern "C" {

s32 TNeedleShoot__sub_802A4668();
s32 update_position__12TNeedleShootFv();

void TNeedleShoot::run_task() {
    if ((s32) this->m_b8 == 1) {
        update_position__12TNeedleShootFv();
        ((TObjEneMe1GiGueMissile *)this)->update_lifetime();
        return;
    }
    TNeedleShoot__sub_802A4668();
}

}
