#ifndef PSO_UI_KEYBOARD_TKEYBOARDCONTROL_8000F764_H
#define PSO_UI_KEYBOARD_TKEYBOARDCONTROL_8000F764_H

#include "types.h"

extern "C" {
void TKeyBoardControl__sub_8000F764(void);
void TKeyBoardControl__sub_8000F7FC(void);
int TKeyBoardControl__sub_8000F828(void);
s32 TKeyBoardControl__sub_8000F8EC(void);
void TKeyBoardControl__sub_8000F90C(s32 arg0);
void TKeyBoardControl__sub_8000F91C(s32 arg0);
s32 TKeyBoardControl__sub_8000F92C(void);
void TKeyBoardControl__sub_8000F950(void);
void TKeyBoardControl__sub_8000F95C(void);
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
void TKeyBoardControl__sub_8000F9E4(void);
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
