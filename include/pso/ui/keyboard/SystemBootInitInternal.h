#ifndef PSO_UI_KEYBOARD_SYSTEMBOOTINITINTERNAL_H
#define PSO_UI_KEYBOARD_SYSTEMBOOTINITINTERNAL_H

#include "types.h"
#include "pso/render/gjSystem.h"


void init_adx_audio_system(void);
void init_disc_error_messages(void);

// The 512 KB scratch buffer resources are decompressed into before they are parsed.
extern u8 *resource_decompress_buffer;


extern "C" {
extern s32 sound_requests_enabled;
s32 TLobby__sub_80226BA4(void);
void fn_800FFE0C(void);
void fn_800FFE10(void);
}

#endif
