#ifndef PSO_UNK_TLOBBY_80227AA0_H
#define PSO_UNK_TLOBBY_80227AA0_H

#include "types.h"
#include "pso/system/SoundEffect.h"

struct Vec;

// --- C functions defined in TLobby_80227AA0.cpp ---
extern "C" {
void TLobby__sub_80227AA8(s32 tracks);
void TLobby__sub_80227AF8(s32 arg0, s32 arg1);
void TLobby__sub_80227D38(void);
void TLobby__sub_8022804C(void);
void TLobby__sub_8022809C(void);
void apply_clamped_field_27c__6TLobbyFv(f32 value);
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
s32 play_packed_sound_once(u32 id, saddr position, s32 arg2, s32 arg3);
void release_sound_with_fade(s32 slot);
extern "C" {
void update_global_sound_frame(void);
}
// --- end of C functions

#endif
