#ifndef PSO_NETWORK_TREGISTER_H
#define PSO_NETWORK_TREGISTER_H

#include "types.h"

extern "C" {
s32 __ct__14QuestListEntryFRC14QuestListEntry(saddr arg0, saddr arg1);
s32 __ct__9TRegisterFv(saddr arg0);
void bswap__9TRegisterFv(saddr arg0);
}
void bswap_quest_list_entry(void *p);

// --- C functions defined in TRegister.cpp ---
extern "C" {
s32 __ct__9TRegisterFv(saddr arg0);
void bswap__9TRegisterFv(saddr arg0);
}
void bswap_quest_list_entry(void *p);
// --- end of C functions

#endif
