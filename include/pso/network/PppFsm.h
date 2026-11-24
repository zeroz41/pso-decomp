#ifndef PSO_NETWORK_PPPFSM_H
#define PSO_NETWORK_PPPFSM_H

#include "types.h"

typedef struct PppFsm PppFsm;
typedef struct PppProtoBlocks PppProtoBlocks;
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
    u8 max_request_attempts; /* 0x09: copied to PppFsm.max_request_attempts */
    u8 max_peer_attempts; /* 0x0A: copied to PppFsm.max_peer_attempts */
    u8 max_terminate_attempts; /* 0x0B: copied to PppFsm.max_terminate_attempts */
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

/* The FSM's retry timer: lobby_timer_add links it into lobby_timer_list_head, lobby_timer_start arms it and
 * process_expired_timers calls the callback once now - start_time passes timeout. */
typedef void (*PppFsmTimerCallback)(PppFsm *fsm);
typedef struct PppFsmTimer {
    struct PppFsmTimer *next;
    u32 period;                 /* 0x04: lobby_timer_add */
    u32 timeout;                /* 0x08: the period, at least 1 */
    s32 start_time;             /* 0x0C: get_time_ms */
    PppFsmTimerCallback callback;
    PppFsm *arg;
    u8 state;                   /* 0x18: 0 stopped, 1 running, 2 firing */
    u8 pad19[3];
} PppFsmTimer;

/* PAP's options block (PppFsm.opts): the peer id and password sent in an authenticate request, and the message of
 * the last reply. */
typedef struct PapOptions {
    u8 *peer_id;
    u8 *password;
    u8 *message;
} PapOptions;

struct PppFsm {
    u8 state;
    u8 id;                      /* 0x01: the identifier of the last request sent */
    u8 flags;                   /* 0x02: 0x80 restart and 0x40 passive pick Stopped over Initial; 0x10 and 0x20 auth pending */
    u8 retries;
    u8 max_request_attempts;    /* 0x04: PppFsmProtocol.max_request_attempts; reloads retries */
    u8 max_terminate_attempts;  /* 0x05: PppFsmProtocol.max_terminate_attempts */
    u8 peer_attempts_left;      /* 0x06: counts down per peer request; at 0 the session is closed */
    u8 max_peer_attempts;       /* 0x07: PppFsmProtocol.max_peer_attempts; reloads peer_attempts_left */
    s16 abort;                  /* 0x08: set when the FSM closes; the connect waits poll it */
    u8 padA;
    u8 ack_count;               /* 0x0B: the Configure-Acks the protocol's ack check accepted */
    PppProtoBlocks *blocks;     /* 0x0C: the PPP session the FSM belongs to */
    PppFsmTimer timer;          /* 0x10 */
    PppFsmProtocol *proto;      /* 0x2C */
    void *opts;                 /* 0x30: the protocol's own state */
};

LAYOUT_ASSERT(PppFsmProtocol_size_check, sizeof(PppFsmProtocol) == 0x3C);
LAYOUT_ASSERT(PppFsmTimer_size_check, sizeof(PppFsmTimer) == 0x1C);
LAYOUT_ASSERT(PppFsm_size_check, sizeof(PppFsm) == 0x34);

#endif
