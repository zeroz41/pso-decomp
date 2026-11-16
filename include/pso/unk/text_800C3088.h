#ifndef PSO_UNK_TEXT_800C3088_H
#define PSO_UNK_TEXT_800C3088_H

#include "types.h"

struct TObjEneDD;
extern "C" {
void fn_800C3088(u8 *arg0, int arg1);
void fn_800C32DC(u8 *owner, s32 arg1);
}
void handle_flower_state_change(TObjEneDD *arg0, s32 arg1);

// --- C functions defined in text_800C3088.cpp ---
extern "C" {
void fn_800C3088(u8 *arg0, int arg1);
void fn_800C32DC(u8 *owner, s32 arg1);
}
void handle_flower_state_change(TObjEneDD *ene_dd, s32 arg1);
// --- end of C functions

#endif
