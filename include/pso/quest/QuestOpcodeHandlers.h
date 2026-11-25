#ifndef PSO_QUEST_QUESTOPCODEHANDLERS_H
#define PSO_QUEST_QUESTOPCODEHANDLERS_H

#include "types.h"
#include "pso/quest/QuestVm.h"

struct TItemData;
struct TObjPlayer;

extern "C" {
int test_player_action_10000(TObjPlayer *p);
int test_player_action_400(TObjPlayer *p);
int test_player_action_200(TObjPlayer *p);
int test_player_action_100(TObjPlayer *p);
int test_player_action_E0(TObjPlayer *p);
int test_player_action_2(TObjPlayer *p);
void gba_set_identifiers(int a0, int a1);
int get_gba_download_state(void);
void set_screen_bw(void);
void clear_lobby_count(void);
void set_ult_map(void);
void override_warp_dest_floor(void);
void disable_quest_warp(void);
int TLobby__sub_801F36F0(s32);
int TLobby__sub_801F36F8(s32, s32, s32, TItemData *);
int TLobby__sub_801F3700(s32);
int TLobby__sub_801F3708(s32, s32, s32, TItemData *);
char *get_entered_item_name(void);
}
quest_suspend_reason dispatch_quest_opcode(void);
// Closes every window and item-name entry the running quest script opened.
void close_windows();
extern "C" {
void clear_player_flag_4096(TObjPlayer *p);
void set_player_flag_4096(TObjPlayer *p);
s32 fn_get_field_3ac(void *p);
}
s32 get_field_d4(void *p);

extern int quest_active_flag;
// Random-enemy mode the quest script selected (0 = off).
extern int evt2_random_enemies_mode;

#endif
