#ifndef PSO_NETWORK_PPPFSM_H
#define PSO_NETWORK_PPPFSM_H

#include "types.h"

typedef struct PppFsm PppFsm;
struct PppHeader;
struct PppFrame;

/* The protocol callbacks take the active FSM. Checks also take the received header and frame and return 0 to accept it. */
typedef struct PppFsmProtocol PppFsmProtocol;
typedef void (*PppFsmAction)(PppFsm *fsm);
typedef s16 (*PppFsmCheck)(PppFsm *fsm, struct PppHeader *hdr, struct PppFrame *pkt);

/* The fixed description of a protocol that runs on the FSM (PAP's is named "Pap"): its PPP protocol number, retry
 * counts, timeout and callbacks. */
struct PppFsmProtocol {
    const char *name;
    u16 proto;                  /* 0x04: 0xC023 PAP */
    u16 h6;
    u8 tx_counter_index;
    u8 max_request_attempts; /* 0x09: copied to PppFsm.f4 */
    u8 max_peer_attempts; /* 0x0A: copied to PppFsm.f7 */
    u8 max_terminate_attempts; /* 0x0B: copied to PppFsm.f5 */
    s32 timeout;                /* 0x0C: in ms */
    PppFsmAction release_resources;
    PppFsmAction reset_options;
    PppFsmAction start_negotiation;
    PppFsmAction link_opened;
    PppFsmAction link_closed;
    PppFsmAction finish_termination;
    struct PppFrame *(*build_config_request)(PppFsm *fsm); /* builds the packet to (re)send */
    PppFsmCheck check_config_request;
    PppFsmCheck check_config_ack;
    PppFsmCheck check_config_nak;
    PppFsmCheck check_config_reject;
};

/* The FSM's retry timer (lobby_timer_add arms it). */
typedef void (*PppFsmTimerCallback)(PppFsm *fsm);
typedef struct PppFsmTimer {
    u8 pad0[0x10];
    PppFsmTimerCallback callback;
    PppFsm *arg;
    u8 pad18[4];
} PppFsmTimer;

/* PAP's options block (PppFsm.opts): the peer id and password sent in an authenticate request, and the message of
 * the last reply. */
typedef struct PapOptions {
    u8 *peer_id;
    u8 *password;
    u8 *message;
} PapOptions;

/* The link the FSM runs on (PppFsm.sub): the next request identifier and a count of packets sent per protocol. */
typedef struct PppFsmLink {
    u8 state;
    u8 next_identifier;
    u8 unknown02[0x10A];
    u8 *pap_peer_id;            /* 0x10C */
    u8 pad110[8];
    s16 transmitted[4];         /* 0x118 */
} PppFsmLink;

struct PppFsm {
    u8 state;
    u8 id;                      /* 0x01: the identifier of the last request sent */
    u8 f2;
    u8 retries;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    s16 abort;                  /* 0x08: set when the FSM closes; the connect waits poll it */
    u8 padA;
    u8 ack_count;               /* 0x0B: the Configure-Acks the protocol's ack check accepted */
    u8 *sub;                    /* 0x0C: the link the FSM runs on */
    PppFsmTimer timer;          /* 0x10 */
    PppFsmProtocol *proto;      /* 0x2C */
    void *opts;                 /* 0x30: the protocol's own state */
};

LAYOUT_ASSERT(PppFsmProtocol_size_check, sizeof(PppFsmProtocol) == 0x3C);
LAYOUT_ASSERT(PppFsmTimer_size_check, sizeof(PppFsmTimer) == 0x1C);
LAYOUT_ASSERT(PppFsm_size_check, sizeof(PppFsm) == 0x34);

#endif
