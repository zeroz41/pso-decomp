#include "types.h"
#include "pso/player/TPlyDispConfig.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/byteswap.h"

void TPlyDispConfigSmth::bswap() {
    s32 i;

    bswap_32(&bank);
    for (i = 0; i < 4; i++) {
        ((TObjPlayer *)&m_tags[i])->bswap_disp_config_field();
        ((TObjPlayer *)&m_tags1[i])->bswap_disp_config_field();
    }
}
