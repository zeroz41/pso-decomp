#ifndef PSO_UI_KEYBOARD_TKEYBOARDCONTROL_80131C58_H
#define PSO_UI_KEYBOARD_TKEYBOARDCONTROL_80131C58_H

#include "types.h"

struct TKeyBoardControl;
extern "C" {
void TKeyBoardControl__sub_80131F5C(void);
void TKeyBoardControl__sub_80131F60(void);
bool TKeyBoardControl__sub_801321B4(s32 arg0);
bool TKeyBoardControl__sub_80132274(s32 arg0);
s32 TKeyBoardControl__sub_80132310(s32 arg0);
void TKeyBoardControl__sub_801327DC(s32 arg0, u8 chan);
u8 get_key_state__16TKeyBoardControlFPv(void *p);
bool is_key_57_pressed__16TKeyBoardControlFi(s32 arg0);
void render__16TKeyBoardControlFv(void);
void reset_inactive_keys__16TKeyBoardControlFv(s32 arg0);
void reset_state__16TKeyBoardControlFi(s32 arg0);
void run_task__16TKeyBoardControlFv(TKeyBoardControl *arg0);
}

#endif
