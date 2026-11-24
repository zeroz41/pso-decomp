#ifndef PSO_UNK_TLOBBY_80227A2C_H
#define PSO_UNK_TLOBBY_80227A2C_H

#include "types.h"

struct Vec;
#include "pso/unk/TLobby_800FD78C.h"

extern "C" {
void *TLobby__sub_80227A4C(u32 size);
void TLobby__sub_80227A6C(void);
int TLobby__sub_80227A70(void *p);
void TLobby__sub_80227A90(s32, const char *);
void TLobby__sub_80227AA8(s32 tracks);
int TLobby__sub_80227AF8(void *p);
int TLobby__sub_80227D38(void);
void TLobby__sub_8022804C(void);
void TLobby__sub_8022809C(void);
void apply_clamped_field_27c__6TLobbyFv(void);
}
extern "C" {
void get_menu_field_280__6TLobbyFv(void);
int get_music_base_gain(void);
}
extern "C" {
void is_sound_enabled(void);
}
s32 is_special_sound_id(u32 x);
extern "C" {
void load_floor_sound_bank(s32 arg0);
}
s32 normalize_sound_request(u32 id, const void *actor, const Vec *position, s32 arg3, s32 arg4);
s32 play_packed_sound_once(u32 id, saddr arg1, s32 arg2, s32 arg3);
void release_sound_with_fade(s32 slot);
extern "C" {
void update_global_sound_frame(void);
}

#endif
