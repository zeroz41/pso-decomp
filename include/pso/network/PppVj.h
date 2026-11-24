#ifndef PSO_NETWORK_PPPVJ_H
#define PSO_NETWORK_PPPVJ_H

#include "types.h"
#include "pso/network/NetworkRuntime.h"

/* PppVjCompress.c: the stack's connection list (node pools). */


/* An IPv4 header decoded by NetIPv4ReadHeader. */
typedef struct ParsedIpHeader {
    u32 src;
    u32 dst;
    u16 len;
    u16 id;
    u16 frag;
    u16 cksum;
    u8 pad10;
    u8 df;
    u8 mf;
    u8 version;
    u8 tos;
    u8 ttl;
    u8 proto; /* IP protocol (VJ compression stores the slot id here) */
    u8 optlen;
    u8 opts[0x40 - 0x18];
} ParsedIpHeader;
LAYOUT_ASSERT(ParsedIpHeader_size_check, sizeof(ParsedIpHeader) == 0x40);

/* A TCP header decoded for VJ compression. */
typedef struct ParsedTcpHeader {
    u16 src_port;
    u16 dst_port;
    u32 seq;
    u32 ack;
    u16 window;
    u16 checksum;
    u16 urgent;
    u16 mss;
    u8 pad_14;
    u8 urg;
    u8 ack_flag;
    u8 psh;
    u8 rst;
    u8 syn;
    u8 fin;
    u8 option_len;
    u8 options[0x28];
} ParsedTcpHeader;
LAYOUT_ASSERT(ParsedTcpHeader_size_check, sizeof(ParsedTcpHeader) == 0x44);

/* A VJ compression connection state. */
typedef struct PppVjConnectionState {
    u8 id;
    u8 pad1[3];
    struct PppVjConnectionState *next;
    ParsedIpHeader a;
    ParsedTcpHeader b;
} PppVjConnectionState;
LAYOUT_ASSERT(PppVjConnectionState_size, sizeof(PppVjConnectionState) == 0x8C);

/* The VJ compression state. */
typedef struct PppVjCompressionState {
    PppVjConnectionState *tstate;
    PppVjConnectionState *rstate; /* receive slots, indexed by connection id (cur) */
    u8 max_tx;
    u8 max;
    u8 last_cs;
    u8 last_xmit;
    u8 cur;
    u8 flags;
    u8 padE[2];
    /* Statistics, as in RFC 1144's slcompress (sls_searches .. sls_tossed). */
    s32 out_not_tcp;
    s32 out_not_compressible;
    s32 out_uncompressed;
    s32 out_compressed;
    s32 searches;
    s32 misses;
    s32 in_uncompressed;
    s32 in_compressed;
    s32 in_errors;
    s32 in_tossed;
} PppVjCompressionState;
LAYOUT_ASSERT(PppVjCompressionState_size, sizeof(PppVjCompressionState) == 0x38);

#ifdef __cplusplus
extern "C" {
#endif
void vj_release_state(PppVjCompressionState *state);
PppVjCompressionState *init_net_list(s16 count1, s16 count2);
s16 sl_uncompress_tcp(PppVjCompressionState *state, PppFrame **frame);
s32 sl_compress_tcp(PppVjCompressionState *state, PppFrame **frame, s16 compress_cid);
s32 NetIPv4ReadHeader(ParsedIpHeader *out, PppFrame **src);
PppFrame *NetIPv4WriteHeader(ParsedIpHeader *ip, PppFrame *frame, s32 preserve_checksum);
s32 NetTcpReadHeader(ParsedTcpHeader *record, PppFrame **frame);
PppFrame *NetTcpWriteHeader(ParsedTcpHeader *record, PppFrame *frame, u8 *checksum_state);
#ifdef __cplusplus
}
#endif

#endif
