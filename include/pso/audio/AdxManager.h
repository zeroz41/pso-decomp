#ifndef PSO_AUDIO_ADXMANAGER_H
#define PSO_AUDIO_ADXMANAGER_H

#include "types.h"
#include "pso/audio/AdxCallbacks.h"

// --- C functions defined in AdxManager.cpp ---
extern "C" {
void setup_adx_file_systems(s32 *arg0);
void TLobby__sub_803CB7F8(s32 context, const char *message, void *detail);
void TLobby__sub_803CB81C(void);
s32 TLobby__sub_803CB844(void);
void TLobby__sub_803CBA18(AdxMessageCallback callback, s32 context);
void TLobby__sub_803CBA38(void);
void TLobby__sub_803CBB14(void);
void __OSCallResetFunctions(s32 context);
void fn_803CBCA0(s32 context);
}
// --- end of C functions

#endif
