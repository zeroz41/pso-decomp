#include "types.h"
#include "pso/unk/text_803F1804.h"

extern "C" {
s32 SIRegisterPollingHandler(void *);
s32 SIUnregisterPollingHandler(void *);
uaddr si_polling_callback;
s32 key_board_control_polling_channel_mask;
void OSClearContext(void *);
void OSSetCurrentContext(void *);
}

void call_si_polling_callback(s32 unused, void *saved_context) {
    u8 ctx[0x2C8];
    if (si_polling_callback != 0) {
        OSClearContext(ctx);
        OSSetCurrentContext(ctx);
        ((void (*)(void))si_polling_callback)();
        OSClearContext(ctx);
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
