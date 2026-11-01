#include "types.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/misc/TWindowSubStatusDisp.h"

void TWindowMenuIconLine::clear_decided() {
    this->state_flags = (u16) (this->state_flags & 0xFFFFFFFD);
    if (this->status_display != NULL) {
        ((TWindowSubStatusDisp *)this->status_display)->set_entry_state(1);
    }
}
