#include "types.h"
#include "pso/player/TPlyDispConfigSmth.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 bswap_32__FPUl();

void bswap__18TPlyDispConfigSmthFv(s32 arg0) {
    s32 var_r31;
    s32 temp_r30;
    s32 var_r29;

    bswap_32__FPUl();
    var_r29 = 0;
    var_r31 = 0;
    do {
        temp_r30 = arg0 + var_r31;
        ((TObjPlayer *)(temp_r30 + 4))->bswap_disp_config_field();
        ((TObjPlayer *)(temp_r30 + 0x14))->bswap_disp_config_field();
        var_r29 += 1;
        var_r31 += 4;
    } while (var_r29 < 4);
}

}
