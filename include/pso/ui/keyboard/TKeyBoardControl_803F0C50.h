#ifndef PSO_UI_KEYBOARD_TKEYBOARDCONTROL_803F0C50_H
#define PSO_UI_KEYBOARD_TKEYBOARDCONTROL_803F0C50_H

#include "types.h"

extern "C" {
void TKeyBoardControl__sub_803F0E8C(void);
s32 TKeyBoardControl__sub_803F0E90(s32 arg0, void *arg1);
void TKeyBoardControl__sub_803F107C(s32 chan, u32 type);
u8 TKeyBoardControl__sub_803F1548(s32 arg0);
u32 kb_sum_803F1604(u32 *p);
}
s32 poll_keyboard_port(s32 chan, u8 *out);

// --- C functions defined in TKeyBoardControl_803F0C50.cpp ---
extern "C" {
void TKeyBoardControl__sub_803F0E8C(void);
s32 TKeyBoardControl__sub_803F0E90(s32 arg0, void *arg1);
void TKeyBoardControl__sub_803F107C(s32 chan, u32 type);
u8 TKeyBoardControl__sub_803F1548(s32 arg0);
u32 kb_sum_803F1604(u32 *p);
}
// --- end of C functions

#endif
