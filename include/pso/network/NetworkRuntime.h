#ifndef PSO_NETWORK_NETWORKRUNTIME_H
#define PSO_NETWORK_NETWORKRUNTIME_H

#include "types.h"

typedef struct Ent_803F9B48 Ent_803F9B48;
typedef struct Ent_803F9C78 Ent_803F9C78;
typedef struct Blk_803FA2A8 Blk_803FA2A8;
typedef union U_803FA2A8 U_803FA2A8;
typedef struct Q_803FA2A8 Q_803FA2A8;
typedef struct P_803FA2A8 P_803FA2A8;
typedef struct A_803FADA0 A_803FADA0;
typedef struct PppFrame PppFrame;
typedef struct Msg_803FA664 Msg_803FA664;
struct Ent_803F9B48 { s32 active; u32 key; u8 pad[0x328 - 8]; };
struct Ent_803F9C78 { s32 active; u32 key; u8 pad[0x318 - 8]; void (*fn)(struct Ent_803F9C78 *); u8 pad2[0x328 - 0x31C]; };
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
typedef char PppFrame_size_check[sizeof(struct PppFrame) == 8 ? 1 : -1];
struct A_803FADA0 { u8 pad0[4]; u32 a; u32 b; };
struct Msg_803FA664 { u8 pad0; u8 b1; s16 h2; };
/* The network stack's thread (lbl_805C18A0, TLobby_804048E8.c): the mutex the stack's callers hold, the thread running
 * run_net_thread_loop (start_network_thread) and how long that loop sleeps between polls. */
typedef struct NetThreadState {
    s32 mutex;
    s32 thread;                 /* 0x04 */
    s16 poll_ms;                /* 0x08: 40 (TLobby__sub_803F79B0), set by TLobby__sub_804050DC */
    u8 padA[6];
} NetThreadState;
typedef char NetThreadState_size_check[sizeof(NetThreadState) == 0x10 ? 1 : -1];
#ifdef __cplusplus
extern "C" {
#endif
extern NetThreadState lbl_805C18A0;
/* NetworkRuntime.c: the stack's OS layer (time, mutexes, threads, alarms, message queues) and string helpers. */
s32 cancel_pending_alarms(void);
void get_time_seconds(s32* out);
void get_time_ms(s32* out);
void clear_slot_for_handle(u32 handle);
void unlock_mutex(int mutex);
void lock_mutex(int mutex);
void signal_alarm_queue(void* alarm);
void resume_thread(s32 thread);
void cancel_thread_if_running(void* thread);
void deactivate_entry_by_key(u32 key);
s32 run_current_thread_callback(void);
s32 NetSetDefaultThreadPriority(s32 priority);
s32 check_connection_status(void* connection);
s32 clear_flag_bit4(s32 unused, u8* flags);
void init_net_state_entry(void* entry);
void NetIPv6CPCancelTimer(s32 timer);
void NetYieldThread(void);
void NetStoreTick(s32* tick);
void NetStoreCurrentThread(s32* thread);
void NetSuspendCurrentThread(void);
void NetResumeThread(u32 thread);
void NetReceiveMessage(u32 handle, void* destination, s32 size);
void NetReleaseMutex(u32 handle);

s16 NetIPv4IsLoopback(s32 address);
s16 NetIPv4IsUnspecified(u32 address);
s16 NetIPv6IsMulticast(u8* address);
s32 NetIPv6CPSetInterfaceIdentifier(u8* state, s32 identifier);

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
extern u8 lbl_805D7A70[1];
extern u8 lbl_805D7A74[1];
extern s32 lbl_805D4810;
void TLobby__sub_803FA2A8(P_803FA2A8 *o);
void TLobby__sub_803FADA0(PppFrame **pbuf, A_803FADA0 *hdr, s32 type, s32 total_len, void *src);
#ifdef __cplusplus
}
#endif

#endif
