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

void turn_on_bgm_p2(void);
void turn_off_bgm_p2(void);
// Plays an ADX file on the cue stream.
void play_cue_stream_file(const char *name);
void set_cue_stream_gain(s32 gain);
void init_music_sequencer(s32 program);
void set_dark_falz_music_request(s32 request);
void set_music_streams_volume(s32 total);
void stop_cue_stream(void);
void update_music_sequencer(void);

#endif
