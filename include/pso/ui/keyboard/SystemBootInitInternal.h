#ifndef PSO_UI_KEYBOARD_SYSTEMBOOTINITINTERNAL_H
#define PSO_UI_KEYBOARD_SYSTEMBOOTINITINTERNAL_H

#include "types.h"

struct SystemVideoInitConfig {
    void *rmode;
    s32 count;
    u32 fb[3];
    u32 fbsize;
    u32 heap;
    u32 heapsize;
};

void init_adx_audio_system(void);
void init_disc_error_messages(void);

extern void *video_initial_draw_framebuffer;
extern void *video_initial_display_framebuffer;

extern "C" {
extern s32 lbl_805D62B0;
u32 calc_framebuffer_size_bytes(int, void *);
s32 TLobby__sub_80226BA4(void);
void fn_800FFE0C(void);
void fn_800FFE10(void);
}

#endif
