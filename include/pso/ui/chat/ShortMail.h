#ifndef PSO_UI_CHAT_SHORTMAIL_H
#define PSO_UI_CHAT_SHORTMAIL_H

#include "types.h"

extern "C" {
void TLobby__sub_802258C8(void);
void *TLobby__sub_8022598C(int a0);
void TLobby__sub_80225C44(void *p);
void TLobby__sub_80225C64(void *p);
void TLobby__sub_80225C8C(void *p);
void TLobby__sub_80225CB8(void);
void clear_all_entries__6TLobbyFPv(void *_w0);
void clear_lobby_flag__6TLobbyFv(void);
void fill_list_entry__6TLobbyFPvPv(u8 *arg0, u8 *arg1);
s32 find_free_slot__6TLobbyFv(void);
void *find_short_mail_by_id__6TLobbyFUi(u32 id);
void *get_com_card_list__6TLobbyFPv(void *p);
s32 get_lobby_id__6TLobbyFPv(void *p);
int get_short_mail_ctrl__6TLobbyFv(void);
int is_flag_set__6TLobbyFPv(void *p);
void remove_entry_at__6TLobbyFi(s32 idx);
void send_simple_mail__6TLobbyFiPv(s32 arg0, void *arg1);
void try_close__6TLobbyFPv(void *p);
}

// --- C functions defined in ShortMail.cpp ---
extern "C" {
void TLobby__sub_802258C8(void);
void *TLobby__sub_8022598C(int a0);
void TLobby__sub_80225A08(void *p);
void TLobby__sub_80225C44(void *p);
void TLobby__sub_80225C64(void *p);
void TLobby__sub_80225C8C(void *p);
void TLobby__sub_80225CB8(void);
s32 find_free_slot__6TLobbyFv(void);
void *find_short_mail_by_id__6TLobbyFUi(u32 id);
void send_simple_mail__6TLobbyFiPv(s32 arg0, void *arg1);
void try_close__6TLobbyFPv(void *p);
}
// --- end of C functions

#endif
