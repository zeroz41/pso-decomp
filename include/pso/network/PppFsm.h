#ifndef PSO_NETWORK_PPPFSM_H
#define PSO_NETWORK_PPPFSM_H

#include "types.h"

typedef struct PppFsm PppFsm;
struct Hdr_803FC4B4;
struct PppFrame;

/* The protocol callbacks the FSM calls on its transitions (called with the FSM and its protocol); the checks take a
 * received packet and return 0 to accept it. */
typedef struct PppFsmProtocol PppFsmProtocol;
typedef void (*PppFsmAction)(PppFsm *fsm, PppFsmProtocol *proto);
typedef s16 (*PppFsmCheck)(PppFsm *fsm, struct Hdr_803FC4B4 *hdr, void *pkt);

/* The fixed description of a protocol that runs on the FSM (PAP's is named "Pap"): its PPP protocol number, retry
 * counts, timeout and callbacks. */
struct PppFsmProtocol {
    const char *name;
    u16 proto;                  /* 0x04: 0xC023 PAP */
    u16 h6;
    u8 b8;
    u8 b9;                      /* 0x09: copied to PppFsm.f4 */
    u8 bA;                      /* 0x0A: copied to PppFsm.f7 */
    u8 bB;                      /* 0x0B: copied to PppFsm.f5 */
    s32 timeout;                /* 0x0C: in ms */
    PppFsmAction f10;
    PppFsmAction f14;
    PppFsmAction f18;
    PppFsmAction f1C;
    PppFsmAction f20;
    PppFsmAction f24;
    struct PppFrame *(*f28)(PppFsm *fsm, PppFsmProtocol *proto); /* builds the packet to (re)send */
    PppFsmCheck f2C;
    PppFsmCheck f30;
    PppFsmCheck f34;
    PppFsmCheck f38;
};

/* The FSM's retry timer (TLobby__sub_80405298 arms it). */
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

struct PppFsm {
    u8 state;
    u8 f1;
    u8 f2;
    u8 retries;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    s16 f8;
    u8 padA[2];
    u8 *sub;                    /* 0x0C: the link the FSM runs on */
    PppFsmTimer timer;          /* 0x10 */
    PppFsmProtocol *proto;      /* 0x2C */
    u8 *opts;                   /* 0x30: the protocol's own state */
};

typedef char PppFsmProtocol_size_check[sizeof(PppFsmProtocol) == 0x3C ? 1 : -1];
typedef char PppFsmTimer_size_check[sizeof(PppFsmTimer) == 0x1C ? 1 : -1];
typedef char PppFsm_size_check[sizeof(PppFsm) == 0x34 ? 1 : -1];

#endif
