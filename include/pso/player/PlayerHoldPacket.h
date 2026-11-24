#ifndef PSO_PLAYER_PLAYERHOLDPACKET_H
#define PSO_PLAYER_PLAYERHOLDPACKET_H

#include "types.h"

struct TObjPlayer;
struct Vec;

// The caller passes both words unextended. The packet keeps their low halfwords.
extern "C" void send_6x2C_impose_hold(TObjPlayer *player, Vec *pos, s32 frames, s32 mode, f32 radius);

#endif
