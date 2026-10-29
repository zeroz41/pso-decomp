#ifndef PSO_PLAYER_TOBJPLAYER_801AF2F0_H
#define PSO_PLAYER_TOBJPLAYER_801AF2F0_H

#include "types.h"

struct TObjPlayer;
struct Vec;

extern "C" {
TObjPlayer *get_player_by_client_id(s32 client);
void submit_cursor_candidate(void *object, s32 id);
// 6x2F: sets a player's HP (sender 0xFFFF for an object).
void send_6x2F_change_player_hp(s32 sender, s32 client, s16 hp);
// 6x2C: holds a player in place at pos for the given frames.
void send_6x2C_impose_hold(TObjPlayer *player, const Vec *pos, s16 frames, s16 arg3, f32 radius);
}

#endif
