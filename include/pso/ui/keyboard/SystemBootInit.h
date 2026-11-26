#ifndef PSO_UI_KEYBOARD_SYSTEMBOOTINIT_H
#define PSO_UI_KEYBOARD_SYSTEMBOOTINIT_H

#include "types.h"

extern "C" {
void run_end_of_render_tasks(void);
}
// The console's video standard: 0 NTSC (30 frames a second), 1 PAL (25); this build always says NTSC.
// Callers pick frame-rate dependent timings and the music program's ntsc or pal cue by it.
int get_video_standard();
s32 get_previous_main_phase(void);
void set_fallback_main_phase(s32 phase);
void set_queued_main_phase(s32 phase);
s32 switch_to_fallback_main_phase(void);
extern "C" {
void set_keyboard_input_flag(void);
void clear_keyboard_input_flag(void);
}
void request_main_phase(s32 phase);
void reset_main_phase_state(void);
// Calls TFogCtrl::clear_split_screen_fog().
void forward_clear_split_screen_fog(void);
void poll_input_devices_frame(void);
void activate_keyboard(void);
extern "C" {
void clear_keyboard_key_state(void);
}
void deactivate_keyboard(void);
extern "C" {
s32 get_main_phase(void);
}
void init_game_systems(void);
void init_gx_lighting_defaults(void);
extern "C" {
bool is_keyboard_active(void);
}
void mark_area_change_pending(void);
s32 request_queued_main_phase(void);
void shutdown_and_reset_system(void);

// Set while a memory card access runs.
extern s32 memcard_access_active;

#endif
