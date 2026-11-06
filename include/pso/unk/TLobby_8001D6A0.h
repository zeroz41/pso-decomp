#ifndef PSO_UNK_TLOBBY_8001D6A0_H
#define PSO_UNK_TLOBBY_8001D6A0_H

#include "types.h"

extern "C" {
void TLobby__sub_8001D9DC(void);
void TLobby__sub_8001D9E8(void *p);
void TLobby__sub_8001DBD8(s32 _w0);
void TLobby__sub_8001DC04(void *p);
void TLobby__sub_8001DE30(void *a0);
void TLobby__sub_8001DEA8(s32 arg0);
void TLobby__sub_8001DF58(s32 arg0, s32 ent);
void *TLobby__sub_8001E270(int a0, int a1);
void *TLobby__sub_8001E2A8(int a0, int a1);
s32 TLobby__sub_8001E75C(void *arg0);
void TLobby__sub_8001E998(f32 farg0, f32 farg1, f32 farg2, f32 farg3);
void TLobby__sub_8001EA5C(f32 x, f32 y, f32 size, f32 alpha);
void TLobby__sub_8001ED70(void);
void TLobby__sub_8001ED74(void);
}
void alloc_battle_param_tables(void);
extern "C" {
void broadcast_to_players__6TLobbyFii(s32 arg0, s32 arg1);
void bswap__12player_statsFv(void *arg0);
void copy_all_data__6TLobbyFii(s32 arg0, s32 arg1);
void copy_all_entries__6TLobbyFii(s32 arg0, s32 arg1);
void copy_data__6TLobbyFPvPv(void *arg0, void *arg1);
s32 default_clock_offset_frames(void);
u32 *free_and_delete__6TLobbyFPvs(u32 *arg0, s16 arg1);
s32 get_card_window_area__6TLobbyFv(void);
void *get_entry__6TLobbyFii(int a0, int a1);
int get_flag_bit0__6TLobbyFv(void);
void *get_player_entry__6TLobbyFii(int a0, int a1);
s32 *get_shared_text_buffer(void);
u8 is_valid_player_index__6TLobbyFi(s32 arg0);
}
void load_battle_param_entry(void);
extern "C" {
void set_difficulty__6TLobbyFi(s32 arg0);
}

#endif
