#include "types.h"
#include "pso/unk/text_803F1804.h"

extern "C" {
s32 SIRegisterPollingHandler(void *);
s32 SIUnregisterPollingHandler(void *);
uaddr si_polling_callback;
s32 TKeyBoardControl__polling_channel_mask;
void OSClearContext(void *);
void OSSetCurrentContext(void *);

void fn_803F1804(s32 arg0, void *arg1) {
    u8 ctx[0x2C8];
    if (si_polling_callback != 0) {
        OSClearContext(ctx);
        OSSetCurrentContext(ctx);
        ((void (*)(void))si_polling_callback)();
        OSClearContext(ctx);
        OSSetCurrentContext(arg1);
    }
}

uaddr fn_803F1864(uaddr arg0) {
    uaddr temp_r31;
    temp_r31 = si_polling_callback;
    si_polling_callback = arg0;
    if (arg0 != 0U) {
        SIRegisterPollingHandler((void *) (((s32 *)fn_803F1804)));
    } else {
        SIUnregisterPollingHandler((void *) (((s32 *)fn_803F1804)));
    }
    return temp_r31;
}

}
