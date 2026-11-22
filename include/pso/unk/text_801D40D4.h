#ifndef PSO_UNK_TEXT_801D40D4_H
#define PSO_UNK_TEXT_801D40D4_H

#include "types.h"

extern "C" {
void TObjPlayer__sub_801D45B0(s32 *rec, saddr arg1);
u8 *TObjPlayer__sub_801D4678(u8 *arg0, s16 arg1);
u8 *TObjPlayer__sub_801D46D4(u8 *arg0, s32 arg1);
void TObjPlayer__sub_801D4730(void *p);
void TObjPlayer__sub_801D47D8(void *p, void *q);
s32 TObjPlayer__sub_801D47EC(saddr arg0, s32 arg1, s32 arg2);
s32 check_player_action_allowed(void);
s32 export_inventory_entry__10TObjPlayerFiPv(saddr arg0, u8 *arg1);
s32 fn_801D4270(s32 id);
}
void remove_list_entry_by_id(s32 arg0);
extern "C" {
saddr reset(void *p);
}

// --- C functions defined in text_801D40D4.cpp ---
extern "C" {
void TObjPlayer__sub_801D45B0(s32 *rec, saddr arg1);
u8 *TObjPlayer__sub_801D4678(u8 *arg0, s16 arg1);
u8 *TObjPlayer__sub_801D46D4(u8 *arg0, s32 arg1);
void TObjPlayer__sub_801D4730(void *p);
void TObjPlayer__sub_801D47D8(void *p, void *q);
s32 TObjPlayer__sub_801D47EC(saddr arg0, s32 arg1, s32 arg2);
s32 check_player_action_allowed(void);
s32 export_inventory_entry__10TObjPlayerFiPv(saddr arg0, u8 *arg1);
s32 fn_801D4270(s32 id);
}
void remove_list_entry_by_id(s32 arg0);
extern "C" {
saddr reset(void *p);
}
// --- end of C functions

#endif
