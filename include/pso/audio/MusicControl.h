#ifndef PSO_AUDIO_MUSICCONTROL_H
#define PSO_AUDIO_MUSICCONTROL_H

#include "types.h"

// The MusyX allocation hook and the retrace and stream callbacks the sound
// setup installs.
void *musyx_malloc_hook(u32 size);
void musyx_free_hook(void *p);
void pre_retrace_callback(u32 retrace_count);
void post_retrace_callback(u32 retrace_count);
void adxt_error_callback_stub(s32, const char *);

// Starts the loading music stream of the given index (0-3).
void start_bgm_stream(s32 index);

struct UpdateMusicSequencerPassage { s16 first, repeat, count, transition, next; };

struct TLoadCtrlProgram { char archive[32]; s32 count, ntsc, pal; UpdateMusicSequencerPassage *modes[2]; };

void start_music_crossfade(s32 frames);
void play_area_music(char *name);
void update_music_fade(void);
// Nonzero while area music plays.
extern s32 music_state;

u8 *get_current_slot_entry();
void set_and_notify_default();
void send_neg30();
void release_bgm_resource();
void set_target_id(s32 target_id);
void stop_audio_streams();
void set_pre_retrace_callback();
void shutdown_buffers();

#endif
