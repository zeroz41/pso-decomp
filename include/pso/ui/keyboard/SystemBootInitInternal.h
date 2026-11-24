#ifndef PSO_UI_KEYBOARD_SYSTEMBOOTINITINTERNAL_H
#define PSO_UI_KEYBOARD_SYSTEMBOOTINITINTERNAL_H

#include "types.h"
#include "pso/render/gjSystem.h"


void init_adx_audio_system(void);
void init_disc_error_messages(void);


extern "C" {
extern s32 lbl_805D62B0;
s32 TLobby__sub_80226BA4(void);
void fn_800FFE0C(void);
void fn_800FFE10(void);
}

#endif
