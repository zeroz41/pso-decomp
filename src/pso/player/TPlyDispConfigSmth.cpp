#include "types.h"
#include "pso/player/TPlyDispConfigSmth.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 bswap_32__FPUl();

void bswap__18TPlyDispConfigSmthFv(s32 config) {
    s32 off;
    saddr entry;
    s32 i;

    bswap_32__FPUl();
    i = 0;
    off = 0;
    do {
        entry = config + off;
        ((TObjPlayer *)(entry + 4))->bswap_disp_config_field();
        ((TObjPlayer *)(entry + 0x14))->bswap_disp_config_field();
        i += 1;
        off += 4;
    } while (i < 4);
}

}
