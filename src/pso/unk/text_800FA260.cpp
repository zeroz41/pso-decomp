#include "pso/unk/text_800FA464.h"
#include "types.h"
#include "pso/unk/text_800FA260.h"
#include "pso/unk/TLobby.h"

void process_pending_resources(void) {
    AsyncFileReadRequest *p;
    TLobby::pump_frames();
    for (p = async_file_read_current_request; p != 0; p = p->next) {
        p->flags |= 0x200;
    }
}
