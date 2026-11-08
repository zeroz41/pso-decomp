#ifndef PSO_NETWORK_NETWORKRUNTIME_H
#define PSO_NETWORK_NETWORKRUNTIME_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif
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

s32 NetIPv4IsLoopback(s32 address);
s32 NetIPv4IsUnspecified(u32 address);
s32 NetIPv6IsMulticast(u8* address);
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
#ifdef __cplusplus
}
#endif

#endif
