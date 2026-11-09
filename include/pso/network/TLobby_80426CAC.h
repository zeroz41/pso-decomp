#ifndef PSO_NETWORK_TLOBBY_80426CAC_H
#define PSO_NETWORK_TLOBBY_80426CAC_H

#include "types.h"

// --- C functions defined in TLobby_80426CAC.c (the PPPoE discovery client) ---
#ifdef __cplusplus
extern "C" {
#endif
s32 TLobby__sub_80428358(void);
s32 TLobby__sub_80428360(void);
s16 build_ethernet_frame_header(void *frame, void *src, void *mac, u16 type, u8 code, u16 session, u16 len);
s32 write_pppoe_ac_name_tag(s32 *cursor, u8 *slot);
s32 skip_pppoe_tags(s32 slot, u8 *tags, u16 len);
s16 get_pppoe_session_id(s16 slot);
s16 pppoe_recv_packet(void *buf, u16 bufLen, u16 *outLen);
s16 TLobby__sub_80427F48(s16 slot, u8 *frame, u16 len);
#ifdef __cplusplus
}
#endif
// --- end of C functions

#endif
