#ifndef PSO_PLAYER_TOBJPLAYER_801C0808_H
#define PSO_PLAYER_TOBJPLAYER_801C0808_H

#include "types.h"

struct SubcmdBodyCopy78 {
    u8 bytes[0x78];
};

struct SubcmdPacketCopy6xAC {
    u8 header[4];
    s32 count;
    SubcmdBodyCopy78 body;
};

extern "C" {
void *TObjPlayer__sub_801C092C(void *arg0, void *arg1);
void TObjPlayer__sub_801C0C04(u8 *arg0);
void TObjPlayer__sub_801C0D7C(u8 *arg0);
u8 *TObjPlayer__sub_801C0F10(u8 *arg0, u8 *source);
u8 *TObjPlayer__sub_801C106C(u8 *arg0, u8 *source);
u8 *TObjPlayer__sub_801C1268(u8 *arg0, u8 *source);
u8 *TObjPlayer__sub_801C1664(u8 *arg0, u8 *source);
void apply_status_effect__10TObjPlayerFPv(void *p);
void bswap_fields__10TObjPlayerFi(saddr arg0);
void bswap_pkt_u16x2_u32__10TObjPlayerFPv(void *p);
void swap_endian__10TObjPlayerFi(saddr packet);
}

// --- C functions defined in TObjPlayer_801C0808.cpp ---
extern "C" {
void *TObjPlayer__sub_801C092C(void *arg0, void *arg1);
void TObjPlayer__sub_801C0C04(u8 *arg0);
void TObjPlayer__sub_801C0D7C(u8 *arg0);
u8 *TObjPlayer__sub_801C0F10(u8 *arg0, u8 *source);
u8 *TObjPlayer__sub_801C106C(u8 *arg0, u8 *source);
u8 *TObjPlayer__sub_801C1268(u8 *arg0, u8 *source);
u8 *TObjPlayer__sub_801C1664(u8 *arg0, u8 *source);
void apply_status_effect__10TObjPlayerFPv(void *p);
void bswap_fields__10TObjPlayerFi(saddr arg0);
void bswap_pkt_u16x2_u32__10TObjPlayerFPv(void *p);
void swap_endian__10TObjPlayerFi(saddr packet);
}
// --- end of C functions

#endif
