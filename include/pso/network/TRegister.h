#ifndef PSO_NETWORK_TREGISTER_H
#define PSO_NETWORK_TREGISTER_H

#include "types.h"

extern "C" {
s32 __ct__14QuestListEntryFRC14QuestListEntry(s32 arg0, s32 arg1);
s32 __ct__9TRegisterFv(s32 arg0);
void bswap__9TRegisterFv(s32 arg0);
int bswap_quest_list_entry(void *p);
}

// --- C functions defined in TRegister.cpp ---
extern "C" {
s32 __ct__9TRegisterFv(s32 arg0);
void bswap__9TRegisterFv(s32 arg0);
int bswap_quest_list_entry(void *p);
}
// --- end of C functions

#endif
