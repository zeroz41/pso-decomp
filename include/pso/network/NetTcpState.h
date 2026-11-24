/* The TCP layer's state and control blocks (NetTcp.c). */
#ifndef PSO_NETWORK_NETTCPSTATE_H
#define PSO_NETWORK_NETTCPSTATE_H
#include "types.h"
#include "pso/network/TcpSendQueue.h"
#include "pso/network/IPv6Send.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/UdpRuntime.h"

typedef struct TcpTcb TcpTcb;

typedef struct TcpSackSeg {
    s32 start;
    s32 end;
    s32 edge;
    s32 stamp;
} TcpSackSeg;
LAYOUT_ASSERT(TcpSackSeg_size_check, sizeof(TcpSackSeg) == 0x10);
/* TCP sequence numbers wrap at 32 bits. Compare their unsigned difference as a signed distance. */
#define SEQ_LT(a, b) ((s32)((a) - (b)) < 0)
#define SEQ_LEQ(a, b) ((s32)((a) - (b)) <= 0)
#define SEQ_GT(a, b) ((s32)((a) - (b)) > 0)
#define SEQ_GEQ(a, b) ((s32)((a) - (b)) >= 0)
typedef struct TcpSeqRange {
    u32 start;
    u32 end;
} TcpSeqRange;
LAYOUT_ASSERT(TcpSeqRange_size_check, sizeof(TcpSeqRange) == 8);
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
LAYOUT_ASSERT(TcpHdr_size_check, sizeof(TcpHdr) == 0x14);
/* A user call blocked on (or with a callback for) a TCB operation (text_80421620.c). */
typedef struct TcpWait {
    u8 flags; /* 1 active, 2 a thread waits, 4 done, 8 callback mode */
    u8 count;
    s16 status;
    s32 thread;
} TcpWait;
LAYOUT_ASSERT(TcpWait_size_check, sizeof(TcpWait) == 8);
/* A TCP control block (0x544 bytes; tcp_protocol_state.tcbs[]). */
struct TcpTcb {
    u8 tag[3]; /* "TCB" */
    u8 index;
    u16 state; /* 0 free, 1 in use */
    s16 t_state;
    s16 listener;
    u8 shutdown;  /* 0x04 receive side shut, 0x08 send side shut (read as BSD's SS_CANTRCVMORE/SS_CANTSENDMORE); nothing sets them */
    /* 0x01 send an ACK now, 0x04 no send delay (option 0x2008), 0x08 FIN received, 0x10 FIN sent, 0x20 the close
       event was dispatched, 0x40 receive and send complete through callbacks (option 0x2020), 0x80 release the TCB
       when it closes (tcp_close) */
    u8 flags;
    u8 force;
    u8 dupacks; /* duplicate ACKs received in a row (fast retransmit) */
    u8 error; /* why the connection was dropped (tcp_drop) */
    u8 padF;
    /* send buffer: a ring of snd_bufsize bytes, plus up to 12 queued user buffers. While f204_b7 is set the ring holds
       16-byte TcpSendRequest records instead: snd_count counts them, snd_head is the index of
       the oldest. */
    NetBufferRef snd_buf;
    NetBufferRef snd_alloc; /* the block behind snd_buf, freed by buffer_pool_free */
    u32 snd_count; /* bytes in the ring, from the oldest unacknowledged one (records while f204_b7 is set) */
    u32 snd_head; /* ring offset of the oldest unacknowledged byte (record index while f204_b7 is set) */
    u32 snd_tail; /* ring offset where the next queued byte goes */
    NetPacket req; /* the queued send request (tcp_queue_send_request) */
    /* receive buffer: a ring of rcv_bufsize bytes, read into rcv_user */
    NetBufferRef rcv_buf;
    NetBufferRef rcv_alloc; /* the block behind rcv_buf */
    u32 rcv_count; /* bytes in the ring not yet read */
    u32 rcv_head; /* ring offset of the next byte to read */
    u32 rcv_tail; /* ring offset where the next received byte goes */
    NetBufferRef rcv_user; /* the pending tcp_receive buffer; its kind is cleared when the receive completes */
    u32 rcv_want; /* the pending tcp_receive's length */
    s32 rcv_done; /* bytes copied into rcv_user so far; the receive completes when it reaches rcv_want */
    /* out-of-order segments waiting for reassembly */
    u32 reasm_total;
    s16 reasm_n; /* index of the last range, -1 when none */
    s16 last_reasm;
    TcpSeqRange reasm[32];
    TcpCompletion send_done;
    TcpCompletion recv_done;
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
    NetworkAddress remote;
    NetworkAddress local;
    /* [0] tcp_receive, [2] tcp_send, [3] complete_accept_request. [1] counts the queued send requests still outstanding;
       complete_request_callback stores a queued request's status in [1] but marks [2] done. */
    TcpWait waits[4];
    s16 backlog; /* no more connections are accepted while pending is at it */
    s16 pending;
    TcpAcceptCallback accept_cb; /* callback of the waits[3] operation */
    NetSocketEventCallback accept_ctx; /* handed to the accepted TCB's event_ctx */
    NetSocketEventCallback event_ctx; /* passed to NetDispatchSocketEvent */
    s16 keepidle; /* keepalive time set by option 8; 0 uses tcp_protocol_state.keepidle */
    u8 ip4_opts[3]; /* dispatch_by_addr_family's IPv4 options (ttl, tos, df) */
    u8 pad2D9[3];
    u8 ip6_opts[0xC]; /* dispatch_by_addr_family's IPv6 send options */
    u8 sack_flags; /* 1 SACK enabled (option 0x2002), 2 the peer sent SACK-permitted */
    u8 pad2E9[3];
    s32 rexmit_bytes; /* bytes resent from the scoreboard: tcp_sack_mark_rexmit adds each resent range, ACKs take them off */
    s32 pipe; /* estimate of the bytes in flight during fast recovery (RFC 3517) */
    u32 recover; /* snd_nxt when fast recovery began; ACKs below it are partial (NewReno, RFC 6582) */
    TcpSeqRange sack[5]; /* SACK blocks to report */
    s16 seg_top; /* index of the last used entry of segs[], -1 when segs[] is empty */
    u8 pad322[2];
    s32 una;
    s32 edge;
    s32 stamp;
    TcpSackSeg segs[32];
    u32 snd_bufsize; /* option 0x1001 (SO_SNDBUF) */
    u32 rcv_bufsize; /* option 0x1002 (SO_RCVBUF) */
    s16 ack_delay;
    u8 pad53A[2];
    u32 ack_now; /* option 0x2001: ACK every data segment at once instead of delaying it */
    s32 initial_window; /* option 0x2004: congestion window after idle, 1 or 2 segments, 3 the RFC 3390 size */
};
LAYOUT_ASSERT(TcpTcb_size_check, sizeof(TcpTcb) == 0x544);
/* Offset of the byte holding f204_b7 and f204_b6 (offsetof cannot take a bit-field). */
#define TCPTCB_F204_BYTE (offsetof(TcpTcb, recv_done) + sizeof(((TcpTcb *)0)->recv_done))
LAYOUT_ASSERT(TcpTcb_f204_check, TCPTCB_F204_BYTE == 0x204);

/* The TCP layer's state (tcp_protocol_state). */
typedef struct TcpState {
    TcpTcb *tcbs;
    s16 count;
    s16 freed;
    u32 snd_bufsize; /* new TCBs' TcpTcb.snd_bufsize, and the most option 0x1001 may set */
    u32 rcv_bufsize; /* new TCBs' TcpTcb.rcv_bufsize, and the most option 0x1002 may set */
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
    s16 ack_now; /* new TCBs' TcpTcb.ack_now */
    u8 opts[0x28]; /* TCP options of the segment being built */
    u8 sack_flags; /* new TCBs' TcpTcb.sack_flags */
    u8 outflags[0xB]; /* header flags to send in each t_state (BSD tcp_outflags) */
    s16 backoff[13];
    u8 pad76[2];
    TcpSeqRange sack_opt[4]; /* SACK blocks parsed from the last segment's options */
    u8 pad98[8];
    s16 ack_ticks;
    u8 initial_window; /* new TCBs' TcpTcb.initial_window */
    u8 padA3[5];
} TcpState;
LAYOUT_ASSERT(TcpState_size_check, sizeof(TcpState) == 0xA8);
#ifdef __cplusplus
extern "C" {
#endif
extern TcpState tcp_protocol_state;

s16 AT_TCP_Rawsend(TcpTcb *tcb);
/* NetTcp.c: claim a free TCB, else the state-10 one with the smallest timers[3]; returns its index or -0x103. */
s16 tcp_alloc_tcb(void);
/* NetTcp.c: account the resent range [first, last) against the retransmit scoreboard (segs[]). */
void tcp_sack_mark_rexmit(TcpTcb *tp, s32 first, s32 last);
/* NetTcp.c: start sending a queued packet on connection arg0. */
s16 tcp_start_send(s16 id, NetPacket *req, TcpCompletion completion, u8 urgent);

/* SocketProtocolRuntime.c: the TCP send and receive queues. */
s32 tcp_user_receive(TcpTcb *self, NetBufferRef *destination, u32 len, TcpCompletion callback);
s32 tcp_notify_receiver(TcpTcb *self);
void expire_timeout_entries(TcpTcb *tcb);
s32 tcp_append_rcvbuf(NetPacket *pkt, u16 x, TcpTcb *self);
s32 tcp_reass(NetPacket *pkt, u16 x, TcpTcb *o, TcpHdr *th);
void tcp_reass_insert_block(TcpTcb *tcb, s16 index, u32 start, u32 end);
void tcp_update_sack_blocks(TcpTcb *tcb);
s32 tcp_drop_acked_data(u32 len, TcpTcb *self);
/* Add len bytes of queued send data, starting off bytes past the oldest unacknowledged byte, to pkt's fragment list
   (as buffer references, no copy; BSD tcp_output's m_copy). The fragments are stored last first. Returns -1 when off
   is past the queued data, or (while f204_b7 is set) when len is 0 or the ring is empty. */
s32 tcp_gather_send_data(u32 off, u32 len, NetPacket *pkt, TcpTcb *tp);
s16 tcp_input(NetPacket *pkt, NetworkAddress *remote, NetworkAddress *local);
s32 tcp_queue_send_request(NetPacket *req, TcpTcb *s, TcpCompletion done);

s16 tcp_set_option(s16 i, s16 opt, u32 *val);
s32 tcp_unlink_listener(s16 idx);

#ifdef __cplusplus
}
#endif

#endif
