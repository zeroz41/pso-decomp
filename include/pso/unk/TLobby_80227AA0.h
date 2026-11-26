#ifndef PSO_UNK_TLOBBY_80227AA0_H
#define PSO_UNK_TLOBBY_80227AA0_H

#include "types.h"
#include "pso/system/SoundEffect.h"

struct Vec;
struct AdxtPlayer;

// --- C functions defined in TLobby_80227AA0.cpp ---
void TLobby__sub_80227AA8(AdxtPlayer *tracks);
void set_sound_request_position(s32 slot, const Vec *position);
void TLobby__sub_80227D38(void);
void TLobby__sub_8022804C(void);
void reset_sound_control_state(void);
void set_sound_reverb_level(f32 level);
s32 get_sound_voice_volume_adjustment(void);
int get_music_base_gain(void);
void is_sound_enabled(void);
s32 is_special_sound_id(u32 x);
extern "C" {
void load_floor_sound_bank(s32 floor);
}
s32 normalize_sound_request(u32 id, const void *actor, const Vec *position, s32 offset, s32 options);
s32 play_packed_sound_once(u32 id, saddr position, s32 offset, s32 options);
void release_sound_with_fade(s32 slot);
void update_global_sound_frame(void);
// --- end of C functions

#endif
