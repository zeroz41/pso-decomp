#ifndef PSO_NETWORK_NETWORKRUNTIME_H
#define PSO_NETWORK_NETWORKRUNTIME_H

#include "types.h"
#include <stddef.h>

/* A thread the stack created (AT_CreateTask) or a caller waiting on it. */
typedef struct OSThread *NetThreadHandle;
/* A mutex from create_mutex: its slot's OSMutex. */
typedef struct OSMutex *NetMutexHandle;
/* A message queue from create_message_queue: its slot's OSMessageQueue. */
typedef struct OSMessageQueue *NetQueueHandle;
typedef struct NetworkThreadSlot NetworkThreadSlot;
typedef void (*NetThreadEntry)(void);
typedef struct PppFrame PppFrame;
/* A PPP frame or packet: its data and length.  It sits at the start of its buffer (PppBuffers); the readers advance
 * data and count len down. */
struct PppFrame { u8 *data; u16 len; };
LAYOUT_ASSERT(PppFrame_size_check, sizeof(struct PppFrame) == 8);
/* An IPv6CP option set: the mask of the options it holds, then their values (append_masked_ipv6cp_options appends the options
 * a mask selects). */
typedef struct Ipv6cpOptionSet {
    s16 mask;
    u8 pad_02[2];
    u32 words[4];  /* words[0..1]: the Interface-Identifier (option 1, RFC 5072) */
    s16 compression_protocol;
    u8 pad_16[2];
} Ipv6cpOptionSet;
LAYOUT_ASSERT(Ipv6cpOptionSet_compression_offset, offsetof(Ipv6cpOptionSet, compression_protocol) == 0x14);
LAYOUT_ASSERT(Ipv6cpOptionSet_words_offset, offsetof(Ipv6cpOptionSet, words) == 4);
LAYOUT_ASSERT(Ipv6cpOptionSet_size, sizeof(Ipv6cpOptionSet) == 0x18);
/* IPv6CP's option state (its PppFsm's opts, ppp_ipv6cp_protocol_state + 0x3C). */
typedef struct Ipv6cpOptions {
    s16 flags;
    u8 pad_02[2];
    Ipv6cpOptionSet current;
    Ipv6cpOptionSet requested;  /* 0x1C: the options the last Configure-Request carried */
} Ipv6cpOptions;
LAYOUT_ASSERT(Ipv6cpOptions_requested_offset, offsetof(Ipv6cpOptions, requested) == 0x1C);
LAYOUT_ASSERT(Ipv6cpOptions_size, sizeof(Ipv6cpOptions) == 0x34);

typedef struct Ipv6cpConfig {
    Ipv6cpOptions local;
    Ipv6cpOptions peer;
} Ipv6cpConfig;
LAYOUT_ASSERT(Ipv6cpConfig_peer_offset, offsetof(Ipv6cpConfig, peer) == 0x34);
struct PppFsm;
struct PppHeader;
/* The network stack's thread (net_thread_state, PppVjCompress.c): the mutex the stack's callers hold, the thread running
 * run_net_thread_loop (start_network_thread) and how long that loop sleeps between polls. */
typedef struct NetThreadState {
    NetMutexHandle mutex;
    NetThreadHandle thread;                 /* 0x04 */
    s16 poll_ms;                /* 0x08: 40 (init_thread_poll_config), set by set_net_poll_interval */
    u8 padA[6];
} NetThreadState;
LAYOUT_ASSERT(NetThreadState_size_check, sizeof(NetThreadState) == 0x10);
#ifdef __cplusplus
extern "C" {
#endif
extern NetThreadState net_thread_state;
s16 AT_InitializeRTOS(void);
/* NetworkRuntime.c: the stack's OS layer (time, mutexes, threads, alarms, message queues) and string helpers. */
s32 AT_TerminateRTOS(void);
void get_time_seconds(s32* out);
void get_time_ms(s32* out);
s16 create_message_queue(NetQueueHandle *out);
void clear_slot_for_handle(NetQueueHandle handle);
void send_message_queue(NetQueueHandle handle, void *source, s32 size);
void unlock_mutex(NetMutexHandle mutex);
void lock_mutex(NetMutexHandle mutex);
void signal_alarm_queue(void* alarm);
void resume_thread(NetThreadHandle thread);
void AT_TerminateTask(NetThreadHandle thread);
void AT_DeleteTask(NetThreadHandle thread);
/* The thread key is the original native address word stored by the pool. */
s16 AT_CreateTask(NetThreadEntry entry, NetThreadHandle *out_key);
void *run_current_thread_callback(void *unused);
s32 NetSetDefaultThreadPriority(s32 priority);
s16 check_connection_status(struct PppFsm *fsm);
s16 clear_flag_bit4(s32 unused, Ipv6cpOptions *options);
void ipv6cp_opening(struct PppFsm *entry);
void NetIPv6CPCancelTimer(struct PppFsm *entry);
void NetYieldThread(void);
void NetStoreTick(s32* tick);
void NetStoreCurrentThread(NetThreadHandle *thread);
void NetSuspendCurrentThread(void);
void AT_StartTask(NetThreadHandle thread);
void NetReceiveMessage(NetQueueHandle handle, void* destination, s32 size);
void NetReleaseMutex(NetMutexHandle handle);

s16 NetIPv4IsLoopback(s32 address);
s16 NetIPv4IsUnspecified(u32 address);
s16 NetIPv6IsMulticast(u8* address);
s16 NetIPv6CPSetInterfaceIdentifier(Ipv6cpOptions *options, u8 *identifier);

char* NetAppendString(char* destination, const char* source);
s32 NetCompareStringsN(const char* left, const char* right, u32 size);
s32 NetCompareStrings(const char* left, const char* right);
char* NetCopyString(char* destination, const char* source);
u32 NetStringLength(const char* text);
void* NetMemmove(void* destination, const void* source, u32 size);

s32 NetMemcmp(const void *left, const void *right, int size);
void NetMemcpy(void *destination, const void *source, int size);
void NetMemset(void* destination, int value, int size);

void ipv6cp_release_resources(struct PppFsm *fsm);
void ipv6cp_start_negotiation(struct PppFsm *entry);
void ipv6cp_link_closed(struct PppFsm *fsm);
extern s32 net_default_thread_priority;
void ipv6cp_reset_options(struct PppFsm *o);
s16 verify_message_sequence(struct PppFsm *fsm, struct PppHeader *msg, PppFrame *expected);
void append_ipv6cp_option(PppFrame **pbuf, Ipv6cpOptionSet *opts, s32 type, s32 total_len, void *src);
void append_masked_ipv6cp_options(uaddr *self, Ipv6cpOptionSet *opts, s32 mask);

void net_sleep_ms(s32 ms);
s32 NetCompareStringsCaseInsensitiveN(u8 *a, u8 *b, u32 n);

#ifdef __cplusplus
}
#endif

#endif
