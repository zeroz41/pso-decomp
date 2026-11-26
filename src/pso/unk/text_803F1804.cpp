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

void call_si_polling_callback(s32 arg0, void *arg1) {
    u8 ctx[0x2C8];
    if (si_polling_callback != 0) {
        OSClearContext(ctx);
        OSSetCurrentContext(ctx);
        ((void (*)(void))si_polling_callback)();
        OSClearContext(ctx);
        OSSetCurrentContext(arg1);
    }
}

uaddr set_si_polling_callback(uaddr arg0) {
    uaddr temp_r31;
    temp_r31 = si_polling_callback;
    si_polling_callback = arg0;
    if (arg0 != 0U) {
        SIRegisterPollingHandler((void *) (((s32 *)call_si_polling_callback)));
    } else {
        SIUnregisterPollingHandler((void *) (((s32 *)call_si_polling_callback)));
    }
    return temp_r31;
}
