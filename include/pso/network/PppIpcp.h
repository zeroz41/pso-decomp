#ifndef PSO_NETWORK_PPPIPCP_H
#define PSO_NETWORK_PPPIPCP_H

#include "types.h"
#include "pso/network/TLobby_803FCF44.h"

/* One set of IPCP option values. Bit n of flags marks option n (n < 8) or option 0x78 + n (n < 0x20) as in use. */
typedef struct IpcpOptions {
    s16 flags;
    u8 pad2[2];
    s32 our_addr;  /* option 3, and option 1's first address */
    s32 his_addr;  /* option 1's second address */
    s16 vj_protocol; /* option 2: 0x2D for Van Jacobson compression */
    s16 vj_slots;    /* option 2: max slot id + 1 */
    u8 vj_comp_slot; /* option 2: slot id may be compressed */
    u8 pad11[3];
    s32 dns[2];      /* options 0x81 and 0x83 (RFC 1877) */
    s32 his_dns[2];
} IpcpOptions;
typedef char IpcpOptions_size_check[sizeof(IpcpOptions) == 0x24 ? 1 : -1];

/* One end of the link: the options it may use, wants and has agreed. */
typedef struct IpcpSide {
    s16 flags;
    u8 pad2[2];
    IpcpOptions want;
    IpcpOptions got;
} IpcpSide;
typedef char IpcpSide_size_check[sizeof(IpcpSide) == 0x4C ? 1 : -1];

/* The IPCP state machine's option block (the FSM's options pointer). */
typedef struct IpcpConfig {
    IpcpSide local;
    IpcpSide peer;
    u32 net_list; /* init_net_list(local VJ slots, peer VJ slots) */
} IpcpConfig;
typedef char IpcpConfig_size_check[sizeof(IpcpConfig) == 0x9C ? 1 : -1];

typedef struct IpcpState {
    Obj_803FEF4C proto;
    IpcpConfig config;
} IpcpState;
typedef char IpcpState_size_check[sizeof(IpcpState) == 0xD8 ? 1 : -1];

/* Reads one option (hdr = type, length) from the packet at cursor into side->got and settles it against cfg. c is 1
 * for the peer's Configure-Request, 0 for a reply to ours. Returns the PPP reply code 2 (ack), 3 (nak), 4 (reject),
 * or -1 on a short packet. */
s16 TLobby__sub_803FFB84(void *cursor, IpcpConfig *cfg, IpcpSide *side, u8 *hdr, s16 c);

/* Option setters for one side of the IPCP configuration; addr -1 turns the option off. */
s32 ipcp_set_vj_compression(s16 disabled, IpcpSide *side);
s32 ipcp_set_peer_secondary_dns(IpcpSide *side, s32 addr);
s32 ipcp_set_peer_primary_dns(IpcpSide *side, s32 addr);
s32 ipcp_set_local_secondary_dns(IpcpSide *side, s32 addr);
s32 ipcp_set_local_primary_dns(IpcpSide *side, s32 addr);
s32 ipcp_set_peer_address(IpcpSide *side, s32 addr);
s32 ipcp_set_local_address(IpcpSide *side, s32 addr);

#endif
