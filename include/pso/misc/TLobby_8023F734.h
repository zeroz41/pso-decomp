#ifndef PSO_MISC_TLOBBY_8023F734_H
#define PSO_MISC_TLOBBY_8023F734_H

#include "types.h"

extern "C" {
void TLobby__sub_8023F754(s32 arg0, s32 arg1);
s32 TLobby__sub_8023F880(s32 arg0);
int TLobby__sub_802401C8(void);
void *TLobby__sub_80240808(void *arg0, s16 arg1);
void TLobby__sub_802409E4(void *p);
void TLobby__sub_802409F0(struct SoundRequestVoice *v);
void TLobby__sub_80240F38(void);
void TLobby__sub_80241A0C(void);
void TLobby__sub_802422EC(void *arg0, void *arg1);
void TLobby__sub_8024259C(s32 arg0);
void TLobby__sub_8024285C(void *p);
void *TLobby__sub_802428C4(void *p);
s32 TLobby__sub_802428F8(void *p);
s32 advance_rng__6TLobbyFPv(void *arg0);
char *build_text_from_comma_list__6TLobbyFPv(char *list);
s32 resolve_sound_effect_bank(struct Owner_8023FBBC *owner, s32 kind, s32 bank, s32 index);
s32 start_voice_fade(struct Voice_80241FD8 *v, s32 step);
void clamp_field9c__6TLobbyFPvf(void *arg0, f32 farg0);
void clamp_params__6TLobbyFPv(void *arg0);
void construct_entry_arrays__6TLobbyFv(void);
void fade_out_sound_slot(s32 slot, s32 step);
void fade_voice_channels__6TLobbyFi(s32 arg0);
void find_and_load_com_card__6TLobbyFUi(u32 arg0);
int forward_8024273C__6TLobbyFPv(void *p);
int get_com_card_data__6TLobbyFv(void);
void *get_com_card_entry__6TLobbyFi(int a0);
s32 get_field_0x280__6TLobbyFPv(void *p);
f32 get_field_2a4__6TLobbyFPv(void *p);
s32 get_field_308__6TLobbyFPv(void *p);
void init_player_entry__6TLobbyFPvPv(u8 *arg0, u8 *arg1);
s32 init_sound_voice__6TLobbyFPviiii(void *lobby, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
u8 is_ready__6TLobbyFPv(void *arg0);
char *parse_csv_token__6TLobbyFPvPv(char *src, char *dst);
s32 pop_sound_groups__6TLobbyFPvi(void *p, s32 arg1);
s32 remove_com_card_by_id__6TLobbyFUi(u32 arg0);
void remove_com_card_entry__6TLobbyFi(s32 arg0);
void reset_sound_group_fade__6TLobbyFv(void);
void reset_sound_owner_state(u8 *arg0);
s32 reset_sound_state__6TLobbyFPv(u8 *arg0);
void reset_state_805D63DC__6TLobbyFv(void *);
void reset_state__6TLobbyFPv(void *p);
void send_find_user_self_tag__6TLobbyFi(s32 arg0);
void set_clamped_field27c__6TLobbyFPvf(void *arg0, f32 farg0);
void set_field0__6TLobbyFPvi(struct SoundRequestVoice *voice, void *owner);
void set_menu_index__6TLobbyFPvi(void *p, s32 v);
void set_mode__6TLobbyFPvi(void *arg0, s32 arg1);
void set_sound_slot_pitch(s32 slot, s32 pitch, s32 duration);
void set_sound_slot_special_scale(s32 slot, f32 scale);
char *skip_to_comma_field__6TLobbyFPvii(char *s, s32 a, s32 b);
void update__6TLobbyFPv(void *arg0);
u16 update_crc16_ccitt__6TLobbyFUsUc(u16 crc, u8 c);
void update_random_flip_flag__6TLobbyFPv(u8 *arg0);
s32 validate_and_set_selection__6TLobbyFPvi(void *arg0, s32 arg1);
}

s32 set_voice_pitch_slide(u8 *arg0, s32 arg1, s32 arg2);
s32 tick_sound_voice(struct SoundRequestVoice *v);

// --- C functions defined in TLobby_8023F734.cpp ---
extern "C" {
void TLobby__sub_8023F754(s32 arg0, s32 arg1);
s32 TLobby__sub_8023F880(s32 arg0);
int TLobby__sub_802401C8(void);
void *TLobby__sub_80240808(void *arg0, s16 arg1);
void TLobby__sub_802409E4(void *p);
void TLobby__sub_802409F0(struct SoundRequestVoice *v);
void TLobby__sub_80240F38(void);
void TLobby__sub_80241A0C(void);
void TLobby__sub_802422EC(void *arg0, void *arg1);
void TLobby__sub_8024259C(s32 arg0);
void TLobby__sub_8024285C(void *p);
void *TLobby__sub_802428C4(void *p);
s32 TLobby__sub_802428F8(void *p);
s32 advance_rng__6TLobbyFPv(void *arg0);
s32 alloc_looping_sound_slot(u32 id, s32 actor, const void *position, s32 base, s32 flags);
s32 alloc_one_shot_sound_slot(u32 id, const void *position, s32 base, s32 flags);
char *build_text_from_comma_list__6TLobbyFPv(char *list);
void construct_entry_arrays__6TLobbyFv(void);
void fade_out_sound_slot(s32 slot, s32 step);
void fade_voice_channels__6TLobbyFi(s32 arg0);
void find_and_load_com_card__6TLobbyFUi(u32 arg0);
int forward_8024273C__6TLobbyFPv(void *p);
int get_com_card_data__6TLobbyFv(void);
void *get_com_card_entry__6TLobbyFi(int a0);
s32 get_field_0x280__6TLobbyFPv(void *p);
f32 get_field_2a4__6TLobbyFPv(void *p);
s32 get_field_308__6TLobbyFPv(void *p);
void init_player_entry__6TLobbyFPvPv(u8 *arg0, u8 *arg1);
u8 is_ready__6TLobbyFPv(void *arg0);
char *parse_csv_token__6TLobbyFPvPv(char *src, char *dst);
s32 pop_sound_groups__6TLobbyFPvi(void *p, s32 arg1);
s32 remove_com_card_by_id__6TLobbyFUi(u32 arg0);
void remove_com_card_entry__6TLobbyFi(s32 arg0);
void reset_sound_group_fade__6TLobbyFv(void);
void reset_sound_owner_state(u8 *arg0);
s32 reset_sound_state__6TLobbyFPv(u8 *arg0);
void reset_state_805D63DC__6TLobbyFv(void *);
void reset_state__6TLobbyFPv(void *p);
void send_find_user_self_tag__6TLobbyFi(s32 arg0);
void set_clamped_field27c__6TLobbyFPvf(void *arg0, f32 farg0);
void set_menu_index__6TLobbyFPvi(void *p, s32 v);
void set_mode__6TLobbyFPvi(void *arg0, s32 arg1);
void set_sound_slot_pitch(s32 slot, s32 pitch, s32 duration);
void set_sound_slot_special_scale(s32 slot, f32 scale);
char *skip_to_comma_field__6TLobbyFPvii(char *s, s32 a, s32 b);
s32 validate_and_set_selection__6TLobbyFPvi(void *arg0, s32 arg1);
}
// --- end of C functions

#endif
