#ifndef PSO_AUDIO_ADXLOCK_H
#define PSO_AUDIO_ADXLOCK_H

#include "types.h"

// --- C functions defined in AdxLock.cpp ---
extern "C" {
void TLobby__sub_803C4698(void);
}
// --- end of C functions

extern "C" {
void adx_unlock();
void adx_lock();
}

#endif
