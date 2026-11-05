#ifndef PSO_MISC_TLOBBY_80227A2C_H
#define PSO_MISC_TLOBBY_80227A2C_H

#include "types.h"

extern "C" {
int TLobby__sub_80227A4C(void *p);
void TLobby__sub_80227A6C(void);
int TLobby__sub_80227A70(void *p);
void TLobby__sub_80227A90(void);
void TLobby__sub_80227A94(void);
void TLobby__sub_80227AA8(s32 arg0);
int TLobby__sub_80227AF8(void *p);
int TLobby__sub_80227D38(void);
void TLobby__sub_8022804C(void);
void TLobby__sub_8022809C(void);
void apply_clamped_field_27c__6TLobbyFv(void);
void clear_work_buffer(u8 *arg0);
int free__6TLobbyFPv(void *p);
void get_menu_field_280__6TLobbyFv(void);
int get_music_base_gain(void);
void handle_6xB2_play_sound_from_player(void *arg0);
void is_sound_enabled(void);
s32 is_special_sound_id(u32 x);
void load_area_scene_and_init(u8 *arg0);
void load_floor_sound_bank(s32 arg0);
s32 normalize_sound_request(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 play_packed_sound_once(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
void promote_area_floor(u8 *arg0);
int release_sound_with_fade(void *p);
void run_area_scene_cleanup(u8 *arg0);
s32 select_area_entrance(void *arg0);
void update_global_sound_frame(void);
}

#endif
