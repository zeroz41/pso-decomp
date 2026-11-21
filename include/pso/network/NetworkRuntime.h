#ifndef PSO_NETWORK_NETWORKRUNTIME_H
#define PSO_NETWORK_NETWORKRUNTIME_H

#include "types.h"

typedef uaddr NetThreadHandle;
typedef struct NetworkThreadSlot NetworkThreadSlot;
typedef void (*NetThreadEntry)(void);
typedef struct Blk_803FA2A8 Blk_803FA2A8;
typedef union U_803FA2A8 U_803FA2A8;
typedef struct Q_803FA2A8 Q_803FA2A8;
typedef struct P_803FA2A8 P_803FA2A8;
typedef struct A_803FADA0 A_803FADA0;
typedef struct PppFrame PppFrame;
struct Blk_803FA2A8 { s32 w[6]; };
union U_803FA2A8 { s16 h4; Blk_803FA2A8 src; };
struct Q_803FA2A8 {
    s16 h0; s16 h2;
    U_803FA2A8 u;
    Blk_803FA2A8 dst;
    s16 h34; s16 h36; s16 h38; s16 h3A;
    s32 w3C; s32 w40;
    u8 pad44[0x50 - 0x44];
    s16 h50;
};
struct P_803FA2A8 { u8 pad[0x30]; Q_803FA2A8 *q; };
/* A PPP frame or packet: its data and length.  It sits at the start of its buffer (PppBuffers); the readers advance
 * data and count len down. */
struct PppFrame { u8 *data; u16 len; };
LAYOUT_ASSERT(PppFrame_size_check, sizeof(struct PppFrame) == 8);
struct A_803FADA0 { u8 pad0[4]; u32 a; u32 b; };
/* An IPv6CP option set: the mask of the options it holds, then their values (TLobby__sub_803FACD8 appends the options
 * a mask selects). */
typedef struct Ipv6cpOptionSet {
    s16 mask;
    u8 pad_02[0x16];
} Ipv6cpOptionSet;
/* IPv6CP's option state (its PppFsm's opts, ppp_ipv6cp_protocol_state + 0x3C). */
typedef struct Ipv6cpOptions {
    u8 pad_00[0x1C];
    Ipv6cpOptionSet requested;  /* 0x1C: the options the last Configure-Request carried */
} Ipv6cpOptions;
struct PppFsm;
struct PppHeader;
/* The network stack's thread (lbl_805C18A0, TLobby_804048E8.c): the mutex the stack's callers hold, the thread running
 * run_net_thread_loop (start_network_thread) and how long that loop sleeps between polls. */
typedef struct NetThreadState {
    s32 mutex;
    NetThreadHandle thread;                 /* 0x04 */
    s16 poll_ms;                /* 0x08: 40 (TLobby__sub_803F79B0), set by TLobby__sub_804050DC */
    u8 padA[6];
} NetThreadState;
LAYOUT_ASSERT(NetThreadState_size_check, sizeof(NetThreadState) == 0x10);
#ifdef __cplusplus
extern "C" {
#endif
extern NetThreadState lbl_805C18A0;
s16 TLobby__sub_803F8E9C(void);
/* NetworkRuntime.c: the stack's OS layer (time, mutexes, threads, alarms, message queues) and string helpers. */
s32 cancel_pending_alarms(void);
void get_time_seconds(s32* out);
void get_time_ms(s32* out);
void clear_slot_for_handle(u32 handle);
void unlock_mutex(saddr mutex);
void lock_mutex(saddr mutex);
void signal_alarm_queue(void* alarm);
void resume_thread(saddr thread);
void cancel_thread_if_running(void* thread);
void deactivate_entry_by_key(u32 key);
/* The thread key is the original native address word stored by the pool. */
s16 TLobby__sub_803F9B94(NetThreadEntry entry, NetThreadHandle *out_key);
void *run_current_thread_callback(void *unused);
s32 NetSetDefaultThreadPriority(s32 priority);
s16 check_connection_status(void *connection);
s16 clear_flag_bit4(s32 unused, u8 *flags);
void init_net_state_entry(void* entry);
void NetIPv6CPCancelTimer(saddr timer);
void NetYieldThread(void);
void NetStoreTick(s32* tick);
void NetStoreCurrentThread(s32* thread);
void NetSuspendCurrentThread(void);
void NetResumeThread(uaddr thread);
void NetReceiveMessage(u32 handle, void* destination, s32 size);
void NetReleaseMutex(u32 handle);

s16 NetIPv4IsLoopback(s32 address);
s16 NetIPv4IsUnspecified(u32 address);
s16 NetIPv6IsMulticast(u8* address);
s16 NetIPv6CPSetInterfaceIdentifier(u8 *state, saddr identifier);

char* NetAppendString(char* destination, const char* source);
s32 NetCompareStringsN(const char* left, const char* right, u32 size);
s32 NetCompareStrings(const char* left, const char* right);
char* NetCopyString(char* destination, const char* source);
u32 NetStringLength(const char* text);
void* NetMemmove(void* destination, const void* source, u32 size);

s32 NetMemcmp(void* left, void* right, int size);
void NetMemcpy(void* destination, void* source, int size);
void NetMemset(void* destination, int value, int size);

void TLobby__sub_803FA234(void);
void TLobby__sub_803FA238(u8* state);
void TLobby__sub_803FA280(void);
extern s32 net_default_thread_priority;
void TLobby__sub_803FA2A8(P_803FA2A8 *o);
s32 verify_message_sequence(struct PppFsm *fsm, struct PppHeader *msg, uaddr expected);
void TLobby__sub_803FADA0(PppFrame **pbuf, A_803FADA0 *hdr, s32 type, s32 total_len, void *src);
#ifdef __cplusplus
}
#endif

#endif
