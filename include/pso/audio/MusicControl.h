#ifndef PSO_AUDIO_MUSICCONTROL_H
#define PSO_AUDIO_MUSICCONTROL_H

#include "types.h"

// The MusyX allocation hook and the retrace and stream callbacks the sound
// setup installs.
void *musyx_malloc_hook(u32 size);
void pre_retrace_callback(void);
int post_retrace_callback(void *p);
void TLobby__sub_80227A90(s32, const char *);

// Starts the loading music stream of the given index (0-3).
void start_bgm_stream(s32 index);

struct UpdateMusicSequencerPassage { s16 first, repeat, count, transition, next; };

struct TLoadCtrlProgram { char archive[32]; s32 count, ntsc, pal; UpdateMusicSequencerPassage *modes[2]; };

void start_music_crossfade(s32 frames);
void play_area_music(char *name);
void update_music_fade(void);
// Nonzero while area music plays.
extern s32 music_state;

#endif
