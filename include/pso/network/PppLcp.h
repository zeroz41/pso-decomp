#ifndef PSO_NETWORK_PPPLCP_H
#define PSO_NETWORK_PPPLCP_H

#include "types.h"
#include "pso/network/PppFsm.h"

/* Option bits of LcpVals.mask (bit N = LCP option type N). */
#define LCP_OPT_ACCM (1 << 2)
#define LCP_OPT_PFC (1 << 7)
#define LCP_OPT_ACFC (1 << 8)

/* LCP option values; mask has bit N set for option type N. */
typedef struct LcpVals {
    s16 mask;
    s16 mru;
    u32 accm;
    u16 auth_proto;
    u8 pad0A[2];
    u32 magic;
    u8 pad10[4];
    u8 chap_alg;
    u8 auth_negotiable;
    u8 pad16[2];
} LcpVals;
LAYOUT_ASSERT(LcpVals_size_check, sizeof(LcpVals) == 0x18);

/* One side of the LCP negotiation: the options wanted and the ones agreed. */
typedef struct LcpSide {
    s16 mask;
    u8 pad2[2];
    LcpVals want;
    LcpVals got;
} LcpSide;
LAYOUT_ASSERT(LcpSide_size_check, sizeof(LcpSide) == 0x34);

s32 configure_mode_by_type(LcpSide *side, s16 type);

/* The LCP options object (fsm->p30, lcp_state's opts). */
typedef struct LcpOpts {
    LcpSide local;
    LcpSide remote;
} LcpOpts;
LAYOUT_ASSERT(LcpOpts_size_check, sizeof(LcpOpts) == 0x68);

/* The LCP settings apply_lcp_config_to_sides copies into the wanted options of both sides. auth_mode goes to
   configure_mode_by_type. Callers pass it at the head of a
   larger connect record. */
typedef struct LcpConfig {
    u32 accm;
    union {
        s16 no_acfc; /* 0: ask for Address-and-Control-Field-Compression (option 8) */
        u16 no_acfc_u;
    };
    u16 auth_mode;
    u32 magic;
    u16 mru;
    union {
        s16 no_pfc;  /* 0: ask for Protocol-Field-Compression (option 7) */
        u16 no_pfc_u;
    };
} LcpConfig;
LAYOUT_ASSERT(LcpConfig_size_check, sizeof(LcpConfig) == 0x10);

/* lcp_state: the LCP protocol header and its options. */
typedef struct LcpState {
    PppFsmProtocol proto;
    LcpOpts opts;
    u8 padA4[4];
} LcpState;
LAYOUT_ASSERT(LcpState_size_check, sizeof(LcpState) == 0xA8);
extern LcpState lcp_state;

/* Reads one option of a received Configure-Request (remote 1) or Configure-Nak (remote 0) from *src into side. */
s16 parse_lcp_option(struct PppFrame **src, LcpOpts *opts, LcpSide *side, u8 *hdr, s16 remote);

#endif
