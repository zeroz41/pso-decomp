#include "types.h"
#include "pso/boss/olgaflow/TBoss6EmptyWarp_802B0E2C.h"
#include "pso/boss/olgaflow/TBoss6Tube.h"

extern "C" {

s32 query_teammate_state__9TObjEneDDFv();

void TBoss6Tube::run_task() {

    if ((TBoss6EmptyWarp__sub_802B1018() == 0) && (query_teammate_state__9TObjEneDDFv() == 0)) {
        switch (this->m_1c) {
        case 0:
            update_timer();
            return;
        case 1:
            spawn_trap();
            sub_802B1218();
            return;
        case 2:
            update_wobble();
            break;
        }
    }
}

}
