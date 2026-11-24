#ifndef PSO_NETWORK_NETPPPOE_H
#define PSO_NETWORK_NETPPPOE_H

#include "types.h"

/* The names a PPPoE discovery asks for (AC-Name and Service-Name tags); empty strings accept any. */
typedef struct PppoeNames {
    u8 name[0x100];
    u8 service[0x100];
} PppoeNames;

// --- C functions defined in NetPppoe.c (the PPPoE discovery client) ---
#ifdef __cplusplus
extern "C" {
#endif
s32 pppoe_term_rtos(void);
s16 pppoe_init_rtos(s32 unused);
s16 build_ethernet_frame_header(void *frame, void *dst_mac, void *src_mac, u16 type, u8 code, u16 session, u16 len);
/* Opens a discovery slot for names; returns the slot index or -1. */
s16 pppoe_open(PppoeNames *names);
typedef struct PppoeSlot PppoeSlot;
s16 write_pppoe_ac_name_tag(u8 **cursor, PppoeSlot *slot);
s32 skip_pppoe_tags(PppoeSlot *slot, u8 *tags, u16 len);
s16 get_pppoe_session_id(s16 slot);
s16 pppoe_recv_packet(void *buf, u16 bufLen, u16 *outLen);
s16 pppoe_send_session_frame(s16 slot, u8 *frame, u16 len);

s32 pppoe_close(s16 slot);

#ifdef __cplusplus
}
#endif
// --- end of C functions

#endif
