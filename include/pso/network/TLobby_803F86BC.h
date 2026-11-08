#ifndef PSO_NETWORK_TLOBBY_803F86BC_H
#define PSO_NETWORK_TLOBBY_803F86BC_H

#include "types.h"
#include "pso/network/NetworkRuntime.h"

/* TLobby_803F86BC.c: the network stack's configuration (thread pool, buffer slots and buffer pools). */

/* A buffer slot: `addr` is the buffer alloc_buffer_slot hands out, `active` the size in use (0 = free). */
typedef struct LobbyBufferSlot {
    s32 active;
    s32 size;
    u32 addr;
} LobbyBufferSlot;

#ifdef __cplusplus
extern "C" {
#endif
extern u16 lobby_buffer_slot_count;
extern u16 lobby_thread_pool_count;
extern Ent_803F9B48 *lobby_thread_pool_base;
extern LobbyBufferSlot *lobby_buffer_slots;
extern u32 lobby_buffer_pool_size;
extern u32 lbl_805D7C08;
extern u8 *lobby_buffer_pool_base;
extern u8 *lbl_805D7C04;
#ifdef __cplusplus
}
#endif

#endif
