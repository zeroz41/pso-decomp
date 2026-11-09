/* The TCP layer's state and control blocks (NetTcp.c). */
#ifndef PSO_NETWORK_NETTCPSTATE_H
#define PSO_NETWORK_NETTCPSTATE_H
#include "types.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6Send.h"

typedef struct TcpTcb TcpTcb;

typedef struct TcpSackSeg {
    s32 start;
    s32 end;
    s32 edge;
    s32 stamp;
} TcpSackSeg;
typedef char TcpSackSeg_size_check[sizeof(TcpSackSeg) == 0x10 ? 1 : -1];
/* A range of sequence numbers. Both kinds are ordered through signed differences (seq - seq); the SACK blocks
   are u32 because their empty test (start == end) compares unsigned, the reassembly ranges are s32. */
typedef struct TcpReasmRange {
    s32 start;
    s32 end;
} TcpReasmRange;
typedef char TcpReasmRange_size_check[sizeof(TcpReasmRange) == 8 ? 1 : -1];
typedef struct TcpSeqRange {
    u32 start;
    u32 end;
} TcpSeqRange;
typedef char TcpSeqRange_size_check[sizeof(TcpSeqRange) == 8 ? 1 : -1];
/* A TCP header. */
typedef struct TcpHdr {
    u16 sport;
    u16 dport;
    u32 seq;
    u32 ack;
    u8 off; /* data offset in 32-bit words, in the high nibble */
    u8 flags;
    u16 win;
    u16 sum;
    u16 urp;
} TcpHdr;
typedef char TcpHdr_size_check[sizeof(TcpHdr) == 0x14 ? 1 : -1];
/* A user call blocked on (or with a callback for) a TCB operation (text_80421620.c). */
typedef struct TcpWait {
    u8 flags; /* 1 active, 2 a thread waits, 4 done, 8 callback mode */
    u8 count;
    s16 status;
    s32 thread;
} TcpWait;
typedef char TcpWait_size_check[sizeof(TcpWait) == 8 ? 1 : -1];
/* A TCP control block (0x544 bytes; tcp_protocol_state.tcbs[]). */
struct TcpTcb {
    u8 tag[3]; /* "TCB" */
    u8 index;
    u16 state; /* 0 free, 1 in use */
    s16 t_state;
    s16 listener;
    u8 fA;
    /* 0x01 send an ACK now, 0x04 no send delay (option 0x2008), 0x08 FIN received, 0x10 FIN sent, 0x20 the close
       event was dispatched, 0x40 receive and send complete through callbacks (option 0x2020), 0x80 release the TCB
       when it closes (TLobby__sub_8041B5C0) */
    u8 flags;
    u8 force;
    u8 dupacks; /* duplicate ACKs received in a row (fast retransmit) */
    u8 error; /* why the connection was dropped (TLobby__sub_8041A498) */
    u8 padF;
    /* send buffer: a ring of f530 bytes, plus up to 12 queued user buffers. While f204_b7 is set the ring holds 16-byte
       TcpSendEntry records instead (SocketProtocolRuntime.c): f20 counts them, f24 is the index of the oldest. */
    NetBufferRef snd_buf;
    NetBufferRef snd_alloc; /* the block behind snd_buf, freed by TLobby__sub_8041579C */
    u32 f20;
    u32 f24;
    u32 f28;
    NetPacket req; /* the queued send request (TLobby__sub_80420BD0) */
    /* receive buffer: a ring of f534 bytes, read into rcv_user */
    NetBufferRef rcv_buf;
    NetBufferRef rcv_alloc; /* the block behind rcv_buf */
    u32 fD8;
    u32 fDC;
    u32 fE0;
    NetBufferRef rcv_user; /* the pending tcp_receive buffer; its kind is cleared when the receive completes */
    u32 fEC;
    s32 fF0;
    /* out-of-order segments waiting for reassembly */
    s32 reasm_total;
    s16 reasm_n; /* index of the last range, -1 when none */
    s16 last_reasm;
    TcpReasmRange reasm[32];
    void (*send_done)(s16, s16);
    void (*recv_done)(s16, s16);
    u8 f204_b7 : 1;
    u8 f204_b6 : 1;
    u8 f204_rest : 6;
    u8 pad205[3];
    u32 snd_una;
    u32 snd_nxt;
    u32 snd_up;
    u32 snd_wl1; /* sequence number of the last window update */
    u32 snd_wl2; /* acknowledgement number of the last window update */
    u32 iss;
    u32 snd_wnd;
    u32 rcv_wnd;
    u32 rcv_nxt;
    u32 rcv_up;
    u32 irs; /* initial receive sequence number */
    u32 rcv_adv; /* right edge of the advertised window */
    u32 snd_max; /* highest sequence number sent */
    u32 snd_cwnd;
    u32 snd_ssthresh;
    s16 idle;
    s16 rtt;
    u32 rtseq; /* sequence number being timed */
    s16 srtt;
    s16 rttvar;
    u32 max_sndwnd; /* largest window the peer has offered */
    u16 rxtcur;
    u8 pad256[2];
    u32 rxtshift;
    s16 timers[4];
    u16 maxseg;
    u16 peer_mss; /* MSS from the peer's option 2; 536 until one arrives */
    TcpHdr hdr; /* template for outgoing segments: sport is the local port, dport the remote one */
    u8 remote[0x14];
    u8 local[0x14];
    /* [0] tcp_receive, [2] tcp_send, [3] TLobby__sub_80422AB8. [1] counts the queued send requests still outstanding;
       complete_request_callback stores a queued request's status in [1] but marks [2] done. */
    TcpWait waits[4];
    s16 f2C4;
    s16 pending;
    void (*accept_cb)(s16, s16, s32, s32); /* callback of the waits[3] operation */
    s32 accept_ctx; /* handed to the accepted TCB's event_ctx */
    s32 event_ctx; /* passed to NetDispatchSocketEvent */
    s16 keepidle; /* keepalive time set by option 8; 0 uses tcp_protocol_state.keepidle */
    u8 f2D6[3];
    u8 pad2D9[3];
    u8 f2DC[0xC];
    u8 sack_flags; /* 1 SACK enabled (option 0x2002), 2 the peer sent SACK-permitted */
    u8 pad2E9[3];
    s32 f2EC;
    s32 f2F0;
    u32 f2F4;
    TcpSeqRange sack[5]; /* SACK blocks to report */
    s16 seg_top; /* index of the last used entry of segs[], -1 when segs[] is empty */
    u8 pad322[2];
    s32 una;
    s32 edge;
    s32 stamp;
    TcpSackSeg segs[32];
    u32 f530;
    u32 f534;
    s16 ack_delay;
    u8 pad53A[2];
    u32 f53C;
    s32 f540;
};
typedef char TcpTcb_size_check[sizeof(TcpTcb) == 0x544 ? 1 : -1];
/* Offset of the byte holding f204_b7 and f204_b6 (offsetof cannot take a bit-field). */
#define TCPTCB_F204_BYTE (offsetof(TcpTcb, recv_done) + sizeof(((TcpTcb *)0)->recv_done))
typedef char TcpTcb_f204_check[TCPTCB_F204_BYTE == 0x204 ? 1 : -1];

/* The TCP layer's state (tcp_protocol_state). */
typedef struct TcpState {
    TcpTcb *tcbs;
    s16 count;
    s16 freed;
    u32 f8;
    u32 fC;
    u16 port;
    u16 port_min;
    u16 port_max;
    u8 pad16[2];
    u32 iss;
    u8 pad1C[2];
    s16 rexmtthresh; /* duplicate ACKs before a fast retransmit */
    s16 keepintvl;
    s16 keepidle;
    s16 maxidle;
    s16 f26;
    u8 opts[0x28]; /* TCP options of the segment being built */
    u8 sack_flags; /* new TCBs' TcpTcb.sack_flags */
    u8 outflags[0xB]; /* header flags to send in each t_state (BSD tcp_outflags) */
    s16 backoff[13];
    u8 pad76[2];
    TcpSeqRange sack_opt[4]; /* SACK blocks parsed from the last segment's options */
    u8 pad98[8];
    s16 ack_ticks;
    u8 fA2;
    u8 padA3[5];
} TcpState;
typedef char TcpState_size_check[sizeof(TcpState) == 0xA8 ? 1 : -1];
#ifdef __cplusplus
extern "C" {
#endif
extern TcpState tcp_protocol_state;

s32 TLobby__sub_8041A9AC(TcpTcb *tcb);
/* NetTcp.c: start sending a queued packet on connection arg0. */
s32 tcp_start_send(s16 arg0, NetPacket *arg1, void (*completion)(s16, s16), u8 arg3);

/* SocketProtocolRuntime.c: the TCP send and receive queues. */
s32 TLobby__sub_8041ED8C(TcpTcb *self, void *data, u32 len, s32 arg3);
s32 TLobby__sub_8041F11C(TcpTcb *self);
s32 TLobby__sub_8041F204(NetPacket *pkt, u16 x, TcpTcb *self);
s32 TLobby__sub_8041F914(NetPacket *pkt, u16 x, TcpTcb *o, TcpHdr *th);
s32 TLobby__sub_8041FFF8(u32 len, TcpTcb *self);
s32 TLobby__sub_80420410(s32 arg0, s32 arg1, NetPacket *pkt, TcpTcb *o);
s32 TLobby__sub_80420BD0(NetPacket *req, TcpTcb *s, void (*done)(s16, s16));
#ifdef __cplusplus
}
#endif

#endif
