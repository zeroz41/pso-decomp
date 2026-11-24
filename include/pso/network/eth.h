#ifndef PSO_NETWORK_ETH_H
#define PSO_NETWORK_ETH_H

#include "types.h"

struct OSContext;

typedef void (*ExiSendCompletionCallback)(u8 status);

// --- C functions defined in eth.c ---
#ifdef __cplusplus
extern "C" {
#endif
void bba_receive_dma_done(void);
void bba_set_receive_callbacks(u32 alloc_callback, s32 receive_callback);
void bba_set_receive_filter_types(u16 *types, s32 count);
/* The EXI Ethernet adapter driver. */
void wake_network_thread(void);
void exi_write(s32 reg, void *data, s32 len);
void start_exi_dma_read(u16 reg);
void start_exi_dma_write(s32 chan, struct OSContext *ctx);
void start_exi_send(u8 *data, s32 len, ExiSendCompletionCallback callback);
void exi_start_send_dma(s32 chan, struct OSContext *ctx);
void copy_6_byte_config(void *out);
void copy_mac_address(void *address);
s32 poll_exi_status(s32 *status);
u32 exi_read_status_byte(void);
void enable_network_multicast_address(void *address);

s32 init_bba_exi_adapter(s32 nego_mode);

#ifdef __cplusplus
}
#endif
// --- end of C functions

#endif
