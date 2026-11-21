#include "types.h"
#include "pso/unk/text_80396328.h"

extern "C" {
s32 GetTRKConnected();
u8 TRKCloseFile(int, void *);
s32 __close_console(saddr arg0) {
    if (GetTRKConnected() == 0) {
        return 1;
    }
    switch ((s32) (TRKCloseFile(0xD3, (void *)arg0))) {
    case 0:
        return 0;
    case 2:
        return 2;
    case 1:
    default:
        return 1;
    }
}

}
