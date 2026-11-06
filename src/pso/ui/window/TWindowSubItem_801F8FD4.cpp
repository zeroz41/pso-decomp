#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

void TWindowMenuIconLine::clear_decided() {
    this->state_flags = (u16) (this->state_flags & 0xFFFFFFFD);
    if (this->status_display != NULL) {
        ((TWindowSubStatusDisp *)this->status_display)->set_entry_state(1);
    }
}
