#ifndef PSO_PLAYER_TOBJPLAYER_801C0808_H
#define PSO_PLAYER_TOBJPLAYER_801C0808_H

#include "types.h"
#include "pso/network/protocol/subcmd_6x.h"

struct SubcmdBodyCopy78 {
    u8 bytes[0x78];
};

struct SubcmdPacketCopy6xAC {
    u8 header[4];
    s32 count;
    SubcmdBodyCopy78 body;
};

extern "C" {
void *TObjPlayer__sub_801C092C(void *packet, void *src);
void TObjPlayer__sub_801C0C04(G_SetOrClearPlayerFlags_6x2E *packet);
void TObjPlayer__sub_801C0D7C(G_FeedMag_6x28 *packet);
u8 *TObjPlayer__sub_801C0F10(u8 *packet, u8 *src);
u8 *TObjPlayer__sub_801C106C(u8 *packet, u8 *src);
u8 *TObjPlayer__sub_801C1268(u8 *packet, u8 *src);
u8 *TObjPlayer__sub_801C1664(u8 *packet, u8 *src);
void apply_status_effect__10TObjPlayerFPv(void *p);
void bswap_fields__10TObjPlayerFi(saddr packet);
void bswap_pkt_u16x2_u32__10TObjPlayerFPv(void *p);
void swap_endian__10TObjPlayerFi(saddr packet);
}

#endif
