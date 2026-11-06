#ifndef PSO_NETWORK_NETWORKRUNTIME_H
#define PSO_NETWORK_NETWORKRUNTIME_H

#include "types.h"

void NetYieldThread(void);
void NetIPv6CPCancelTimer(s32 timer);

extern "C" {
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
}

#endif
