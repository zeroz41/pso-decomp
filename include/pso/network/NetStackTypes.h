/* Records shared by the network stack's session, buffer and socket files. */
#ifndef PSO_NETWORK_NETSTACKTYPES_H
#define PSO_NETWORK_NETSTACKTYPES_H
#include "types.h"
#include <stddef.h>
#include "pso/network/NetworkRuntime.h"
#include "pso/network/PppFsm.h"

/* CHAP state, in PppFsm.opts of the CHAP connection. */
typedef struct PppChap {
    const char *name;
    const char *secret;
    const char *msg;
    s16 active;
    u8 id;
    u8 padF;
    u16 len;
} PppChap;
LAYOUT_ASSERT(PppChap_size_check, sizeof(PppChap) == 0x14);
LAYOUT_ASSERT(PppChap_len_check, offsetof(PppChap, len) == 0x10);

/* chap_state: the CHAP buffers and settings (PppChap.c).  init_net_buffer_table (NetworkTransport.c) points
 * the buffers into that file's static block and sets their sizes. */
typedef struct PppAuthState {
    u8 *rx_challenge_name;                     /* 0x00: the name in a challenge received */
    u8 *rx_name;                     /* 0x04: the name received */
    u8 *tx_challenge;                     /* 0x08: the challenge sent */
    u8 *rx_challenge;                     /* 0x0C: the challenge received */
    u8 *rx_value;                    /* 0x10: the value received */
    u8 *response_input;                    /* 0x14: the response's hash input (identifier, secret, challenge) */
    u8 *hash_input;                    /* 0x18: the hash input (identifier, secret, challenge) */
    u8 *response;                    /* 0x1C: the response sent (value size, digest, name) */
    char *message;                  /* 0x20: the digest, then the message sent */
    s16 rx_challenge_name_size;                  /* 0x24: the sizes of the buffers above */
    s16 rx_name_size;
    s16 tx_challenge_size;
    s16 rx_challenge_size;
    s16 rx_value_size;
    s16 response_input_size;
    s16 hash_input_size;
    s16 response_size;
    s16 message_size;
    u8 max_request_attempts;                     /* 0x36: copied to the FSM protocol's limits */
    u8 max_peer_attempts;                     /* 0x37 */
    u16 timeout_secs;                    /* 0x38: the FSM's timeout, in seconds */
    u8 pad3A[6];
} PppAuthState;
LAYOUT_ASSERT(PppAuthState_size_check, sizeof(PppAuthState) == 0x40);

/* pap_state: the PAP buffers and settings (Ppp.c), set by init_net_block_620_params. */
typedef struct PppPapState {
    u8 *peer_id;                /* the peer id received */
    u8 *password;               /* 0x04: the password received */
    u8 *message;                /* 0x08: the message received */
    s16 peer_id_size;           /* 0x0C */
    s16 password_size;          /* 0x0E */
    s16 message_size;           /* 0x10 */
    u8 max_request_attempts;                     /* 0x12 .. 0x14: as PppAuthState.max_request_attempts .. timeout_secs */
    u8 max_peer_attempts;
    s16 timeout_secs;
    u8 pad16[2];
} PppPapState;
LAYOUT_ASSERT(PppPapState_size_check, sizeof(PppPapState) == 0x18);

/* ppp_buffers: the PPP frame buffers (Ppp.c), set by init_net_buffer_desc.  Each buffer starts with its
 * PppFrame record; its data starts ((headroom + 0x83) & ~3) bytes in. */
typedef struct PppBuffers {
    s32 headroom;
    u8 *pool;                   /* 0x04: npool buffers of pool_words words (init_net_buffer_entry) */
    s16 npool;                  /* 0x08 */
    s16 pool_words;             /* 0x0A */
    PppFrame *packet;           /* 0x0C: ppp_buffer_from_bytes's */
    PppFrame *frame_out;        /* 0x10: the HDLC frame being sent */
    PppFrame *ip_out;           /* 0x14: the IP packet being sent (ppp_link_send_packet) */
    PppFrame *frame_in;         /* 0x18: the frame being received */
    PppFrame *reply;            /* 0x1C: ppp_fsm_send_packet's packet when it is given none */
    s16 packet_words;           /* 0x20: the sizes of packet .. reply, in words */
    s16 frame_out_words;
    s16 ip_out_words;
    s16 frame_in_words;
    s16 reply_words;
    u8 pad2A[6];
} PppBuffers;
LAYOUT_ASSERT(PppBuffers_size_check, sizeof(PppBuffers) == 0x30);
#ifdef __cplusplus
extern "C" {
#endif
extern PppAuthState chap_state;
extern PppPapState pap_state;
extern PppBuffers ppp_buffers;
#ifdef __cplusplus
}
#endif

#endif
