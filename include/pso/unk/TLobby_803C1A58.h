#ifndef PSO_UNK_TLOBBY_803C1A58_H
#define PSO_UNK_TLOBBY_803C1A58_H

#include "types.h"

struct AdxbDecoder;

// C functions shared by the ADXB decoder units.
extern "C" {
void TLobby__sub_803C3570(AdxbDecoder *decoder);
s32 TLobby__sub_803C30E8(u8 *decoder, saddr hdr, s32 size);
void TLobby__sub_803C3984(u8 *arg0);
void TLobby__sub_803C39CC(u8 *arg0);
void TLobby__sub_803C3A04(u8 *arg0);
s32 TLobby__sub_803C3ABC(u8 *adxb_decoder);
s32 TLobby__sub_803C3AC4(u8 *adxb_decoder);
s32 TLobby__sub_803C3B38(const AdxbDecoder *decoder);
s32 TLobby__sub_803C3B44(u8 *adxb_decoder);
void TLobby__sub_803C3B5C(u8 *arg0, void (*arg1)(s32, s32 *, s32 *, s32 *), saddr arg2);
s32 TLobby__sub_803C3B68(saddr decoder, u16 *hdr, saddr size);
void TLobby__sub_803C4020(u8 *arg0, s32 arg1, s32 arg2);
void TLobby__sub_803C406C(void);
s32 TLobby__sub_803C43A8(void *decoder, void *hdr, void *size);
s32 TRK__write_aram(void *arg0p, void *hdr, void *size);
s32 get_progress_info__6TLobbyFPvPvPvPv(u8 *arg0, s32 *arg1, s32 *arg2, s32 *arg3);
u8 *fn_803C32EC(u8 *hdr, s32 size, s32 *rate, s32 *channels, s32 *bits, s32 *samples, s32 *format);
}

#endif
