#ifndef PSO_NETWORK_TLOBBY_80429598_H
#define PSO_NETWORK_TLOBBY_80429598_H

#include "types.h"

struct OSContext;

// --- C functions defined in TLobby_80429598.c ---
#ifdef __cplusplus
extern "C" {
#endif
void TLobby__sub_80429AC8(void);
void TLobby__sub_8042B58C(u32 arg0, s32 arg1);
void TLobby__sub_8042BA48(u16 *types, s32 count);
/* The EXI Ethernet adapter driver. */
void wake_network_thread(void);
void exi_write(s32 reg, void *data, s32 len);
void start_exi_dma_read(u16 reg);
void start_exi_dma_write(s32 chan, struct OSContext *ctx);
void start_exi_send(s32 data, s32 len, void (*callback)(u8));
void exi_start_send_dma(s32 chan, struct OSContext *ctx);
void copy_6_byte_config(void *out);
void copy_mac_address(void *address);
s32 poll_exi_status(s32 *status);
u32 exi_read_status_byte(void);
void enable_network_multicast_address(void *address);
#ifdef __cplusplus
}
#endif
// --- end of C functions

#endif
