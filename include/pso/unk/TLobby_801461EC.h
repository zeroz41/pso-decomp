#ifndef PSO_UNK_TLOBBY_801461EC_H
#define PSO_UNK_TLOBBY_801461EC_H

#include "types.h"

// --- C functions defined in TLobby_801461EC.cpp ---
extern "C" {
s32 TLobby__sub_80146588(s32 *arg0);
s32 TLobby__sub_801465C0(s32 *netmask);
s32 TLobby__sub_801466F4(u32 arg0);
int TLobby__sub_80146724(void);
void TLobby__sub_8014672C(s32 *arg0);
int TLobby__sub_80146740(void);
int TLobby__sub_8014677C(void);
s32 TLobby__sub_80146908(void);
void TLobby__sub_801469B8(void *p);
u8 *TLobby__sub_80146D14(void);
char *TLobby__sub_80146D44(void);
char *TLobby__sub_80146D50(s32 idx);
void TLobby__sub_8014715C(void *p, void *q);
s32 TLobby__sub_80147284(void);
s32 TLobby__sub_801478C4(s32 id);
void TLobby__sub_80147978(void);
}
s32 connect_modem(s32 idx, s16 id);
s32 connect_pppoe(s32 *out_value);
extern "C" {
void fn_80147A60(int a0);
void fn_80147A68(void);
void *get_account_entry(int idx);
}
void get_link_state(s16 *state, s16 *reason);
char *get_modem_phone_number(s32 idx);
// --- end of C functions

extern s32 net_session_mode;

#endif
