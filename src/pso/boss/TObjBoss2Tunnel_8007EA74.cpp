#include "types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/boss/TObjBoss2Tunnel_8007EA74.h"
#include "pso/system/byteswap.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/player/TObjPlayer.h"

void TObjBoss2Tunnel::finalize_and_send_60() {
    bswap_6xB2_play_sound((TObjPlayer *)this);
    send_subcommand((u8 *)this);
}

void bswap_6xB2_play_sound(TObjPlayer *player) {
    player->read_be16_field2();
    bswap_16((u16 *)((char *)player + 6));
    bswap_32((u32 *)((char *)player + 8));
}

void TObjBoss2Tunnel__sub_8007EAE4(u8 *arg0) {
    *(u8 *)((s8 *)arg0 + 0) = 0xB2;
    *(s8 *)((s8 *)arg0 + 1) = 3;
}
