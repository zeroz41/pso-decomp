#ifndef PSO_UNK_TLOBBY_80226C3C_H
#define PSO_UNK_TLOBBY_80226C3C_H

#include "types.h"

// The MusyX allocation hook and the retrace and stream callbacks the sound
// setup installs.
void *musyx_malloc_hook(u32 size);
extern "C" {
void pre_retrace_callback(void);
}
int post_retrace_callback(void *p);
extern "C" {
void TLobby__sub_80227A90(s32, const char *);
}

// Starts the loading music stream of the given index (0-3).
void start_bgm_stream(s32 index);

struct UpdateMusicSequencerPassage { s16 first, repeat, count, transition, next; };

struct TLoadCtrlProgram { char archive[32]; s32 count, ntsc, pal; UpdateMusicSequencerPassage *modes[2]; };

#endif
