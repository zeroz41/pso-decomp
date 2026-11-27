#include "types.h"
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/os/OSSerial.h>
#include "pso/system/SiPolling.h"

extern "C" {
uaddr si_polling_callback;
s32 key_board_control_polling_channel_mask;
}

void call_si_polling_callback(__OSInterrupt interrupt, OSContext *saved_context) {
    OSContext ctx;
    if (si_polling_callback != 0) {
        OSClearContext(&ctx);
        OSSetCurrentContext(&ctx);
        ((void (*)(void))si_polling_callback)();
        OSClearContext(&ctx);
        OSSetCurrentContext(saved_context);
    }
}

uaddr set_si_polling_callback(uaddr callback) {
    uaddr previous;
    previous = si_polling_callback;
    si_polling_callback = callback;
    if (callback != 0U) {
        SIRegisterPollingHandler(((call_si_polling_callback)));
    } else {
        SIUnregisterPollingHandler(((call_si_polling_callback)));
    }
    return previous;
}
