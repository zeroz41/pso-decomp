#ifndef PSO_MISC_TLOBBY_801F2D2C_H
#define PSO_MISC_TLOBBY_801F2D2C_H

#include "types.h"
#include "pso/quest/QuestVm.h"

extern "C" {
void TLobby__sub_801F3314(s32 arg0);
int TLobby__sub_801F3384(void *p);
int TLobby__sub_801F33A8(void *p);
int TLobby__sub_801F33CC(void *p);
int TLobby__sub_801F33F0(void *p);
int TLobby__sub_801F345C(void *p);
void TLobby__sub_801F34E8(int a0, int a1);
int TLobby__sub_801F34F8(void);
int TLobby__sub_801F3500(void *p);
void TLobby__sub_801F3568(void);
void TLobby__sub_801F3614(void);
int TLobby__sub_801F3694(void *p);
void TLobby__sub_801F36BC(void);
void TLobby__sub_801F36D8(void);
void TLobby__sub_801F36E4(void);
int TLobby__sub_801F36F0(void);
int TLobby__sub_801F36F8(void);
int TLobby__sub_801F3700(void);
int TLobby__sub_801F3708(void);
s32 *TObjItemOKWindow__sub_801F3268(void);
void bswap_header__6TLobbyFPv(void *p);
}
void build_6x77_sync_quest_register(void *p);
quest_suspend_reason dispatch_quest_opcode(void);
extern "C" {
int fn_801F3480(void *p);
int fn_801F34A0(void *p);
s32 fn_get_field_3ac(void *p);
}
s32 get_field_d4(void *p);
extern "C" {
int set_flag_4__6TLobbyFPv(void *p);
}

// --- C functions defined in TLobby_801F2D2C.cpp ---
extern "C" {
void TLobby__sub_801F3314(s32 arg0);
int TLobby__sub_801F3384(void *p);
int TLobby__sub_801F33A8(void *p);
int TLobby__sub_801F33CC(void *p);
int TLobby__sub_801F33F0(void *p);
int TLobby__sub_801F345C(void *p);
void TLobby__sub_801F34E8(int a0, int a1);
int TLobby__sub_801F34F8(void);
int TLobby__sub_801F3500(void *p);
void TLobby__sub_801F3568(void);
void TLobby__sub_801F3614(void);
int TLobby__sub_801F3694(void *p);
void TLobby__sub_801F36BC(void);
void TLobby__sub_801F36D8(void);
void TLobby__sub_801F36E4(void);
int TLobby__sub_801F36F0(void);
int TLobby__sub_801F36F8(void);
int TLobby__sub_801F3700(void);
int TLobby__sub_801F3708(void);
s32 *TObjItemOKWindow__sub_801F3268(void);
int fn_801F3480(void *p);
int fn_801F34A0(void *p);
s32 fn_get_field_3ac(void *p);
}
// --- end of C functions

#endif
