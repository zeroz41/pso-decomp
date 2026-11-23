#ifndef PSO_UI_KEYBOARD_TKEYBOARDCONTROL_8000F824_H
#define PSO_UI_KEYBOARD_TKEYBOARDCONTROL_8000F824_H

#include "types.h"

extern "C" {
int TKeyBoardControl__sub_8000F828(void);
s32 get_previous_main_phase(void);
void TKeyBoardControl__sub_8000F90C(s32 phase);
void set_queued_main_phase(s32 phase);
s32 TKeyBoardControl__sub_8000F92C(void);
void TKeyBoardControl__sub_8000F950(void);
void TKeyBoardControl__sub_8000F95C(void);
void request_main_phase(s32 phase);
void reset_main_phase_state(void);
}
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
void mark_area_change_pending(void);
s32 request_queued_main_phase(void);
}
void shutdown_and_reset_system(void);

#endif
