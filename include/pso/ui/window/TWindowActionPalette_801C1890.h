#ifndef PSO_UI_WINDOW_TWINDOWACTIONPALETTE_801C1890_H
#define PSO_UI_WINDOW_TWINDOWACTIONPALETTE_801C1890_H

#include "types.h"

struct TObjPlayer;
struct TItem;
extern "C" {
s32 TLobby__sub_801C19D0(void *p);
void TObjPlayer__sub_801C18E0(void *p);
void TObjPlayer__sub_801C19C8(void *p, f32 v);
void *TObjPlayer__sub_801C1A00(void *p);
void TObjPlayer__sub_801C1A30(void *p);
void TObjPlayer__sub_801C1AC8(void *self);
void TObjPlayer__sub_801C1B0C(void);
int TObjPlayer__sub_801C1F50(void *p);
void TObjPlayer__sub_801C1F78(void *p, s16 v);
int TWindowActionPalette__sub_801C1C20(void *p);
u8 *TWindowActionPalette__sub_801C1D7C(s32 arg0, s32 i, s32 arg2);
s32 TWindowDuelResult__sub_801C19AC(f32 *arg0);
f32 fn_801C19A4(void *p);
void set_player_team_id(void *p, s32 v);
void fn_801C19E0(void *p, s32 v);
void fn_801C19E8(void *p);
void set_player_pk_mode_flag(void *p);
s32 fn_801C1B88(void *p);
s32 fn_801C1BA0(void *p);
void *ref_primary_action_palette(void *p);
void *ref_secondary_action_palette(void *p);
void clear_secondary_action_palette_bank(void *p);
void fn_801C1E98(void *p);
void clear_primary_action_palette_bank(void *p);
void set_secondary_action_palette_bank(void *p);
void fn_801C1EE8(void *p);
void set_primary_action_palette_bank(void *p);
void fn_801C1F1C(void *p);
void fn_801C1F40(s32 *arg0);
f32 get_lock_target_distance_sq(void *p);
u16 get_lock_target_id(void *p);
}
void init_6x21_inter_level_warp_packet(u8 *arg0);
extern "C" {
void is_action_channel_active(s32 *arg0, s32 arg1);
s32 is_item_equipped(TItem *item);
void set_photon_blast_kind(void *p, s16 v);
int test_photon_blast_modifier(void *p);
}

#endif
