/* Records shared by the network stack's session, buffer and socket files. */
#ifndef PSO_NETWORK_NETSTACKTYPES_H
#define PSO_NETWORK_NETSTACKTYPES_H
#include "types.h"
#include <stddef.h>
#include "pso/network/NetworkRuntime.h"
#include "pso/network/PppFsm.h"

typedef struct p803FE518_UnkBuf803FF344 {
    u8* data;
    u16 len;
} p803FE518_UnkBuf803FF344;
typedef struct p803FE518_UnkSrc803FE518 {
    u8 pad0[2];
    u16 w2;
    u32 w4;
    u16 h8;
    u8 pad_a[2];
    u32 wc;
    u8 pad10[4];
    u8 b14;
} p803FE518_UnkSrc803FE518;
#pragma push
#pragma cplusplus off
static inline s16 fn_8040B758_len(char* s)
{
    s16 len = 0;
    s32 n;

    while (len < 255) {
        s8 c = *s;

        s++;
        if (c == 0) {
            len--;
            break;
        }
        n = c;
        if (len + n + 1 <= 255) {
            s += c;
        } else {
            len = 255;
            break;
        }
        len = n + len;
        len++;
    }
    return len;
}
#pragma pop

typedef struct {
    u16 flags;
    u8 pad2[2];
    u32 f4;
    u32 f8;
    u32 fC;
    u16 f10;
    s16 f12;
} Unk805BDD60Entry;



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

/* lbl_805C02D0: the CHAP buffers and settings (TLobby_803FC178.c).  init_net_buffer_table (NetworkTransport.c) points
 * the buffers into that file's static block and sets their sizes. */
typedef struct PppAuthState {
    u8 *p0;                     /* 0x00: the name in a challenge received */
    u8 *p4;                     /* 0x04: the name received */
    u8 *p8;                     /* 0x08: the challenge sent */
    u8 *pC;                     /* 0x0C: the challenge received */
    u8 *p10;                    /* 0x10: the value received */
    u8 *p14;                    /* 0x14: the response's hash input (identifier, secret, challenge) */
    u8 *p18;                    /* 0x18: the hash input (identifier, secret, challenge) */
    u8 *p1C;                    /* 0x1C: the response sent (value size, digest, name) */
    char *p20;                  /* 0x20: the digest, then the message sent */
    s16 size0;                  /* 0x24: the sizes of p0 .. p20 */
    s16 size4;
    s16 size8;
    s16 sizeC;
    s16 size10;
    s16 size14;
    s16 size18;
    s16 size1C;
    s16 size20;
    u8 f36;                     /* 0x36: copied to the FSM's proto.b9 */
    u8 f37;                     /* 0x37: proto.bA */
    u16 f38;                    /* 0x38: the FSM's timeout, in seconds */
    u8 pad3A[6];
} PppAuthState;
LAYOUT_ASSERT(PppAuthState_size_check, sizeof(PppAuthState) == 0x40);

/* lbl_805C0620: the PAP buffers and settings (TLobby_803FCF44.c), set by init_net_block_620_params. */
typedef struct PppPapState {
    u8 *peer_id;                /* the peer id received */
    u8 *password;               /* 0x04: the password received */
    u8 *message;                /* 0x08: the message received */
    s16 peer_id_size;           /* 0x0C */
    s16 password_size;          /* 0x0E */
    s16 message_size;           /* 0x10 */
    u8 f12;                     /* 0x12 .. 0x14: as PppAuthState.f36 .. f38 */
    u8 f13;
    s16 f14;
    u8 pad16[2];
} PppPapState;
LAYOUT_ASSERT(PppPapState_size_check, sizeof(PppPapState) == 0x18);

/* lbl_805C04A8: the PPP frame buffers (TLobby_803FCF44.c), set by init_net_buffer_desc.  Each buffer starts with its
 * PppFrame record; its data starts ((headroom + 0x83) & ~3) bytes in. */
typedef struct PppBuffers {
    s32 headroom;
    u8 *pool;                   /* 0x04: npool buffers of pool_words words (init_net_buffer_entry) */
    s16 npool;                  /* 0x08 */
    s16 pool_words;             /* 0x0A */
    PppFrame *packet;           /* 0x0C: TLobby__sub_80401B20's */
    PppFrame *frame_out;        /* 0x10: the HDLC frame being sent */
    PppFrame *ip_out;           /* 0x14: the IP packet being sent (TLobby__sub_803FD21C) */
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
extern PppAuthState lbl_805C02D0;
extern PppPapState lbl_805C0620;
extern PppBuffers lbl_805C04A8;
#ifdef __cplusplus
}
#endif

#endif
