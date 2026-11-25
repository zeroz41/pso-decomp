#include "types.h"
#include "pso/network/NetworkWaitIcon.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject.h"

void update_network_wait_icon(void) {
    advance_network_wait_icon();
    draw_network_wait_icon();
}
