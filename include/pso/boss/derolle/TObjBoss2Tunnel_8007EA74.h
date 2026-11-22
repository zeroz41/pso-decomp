#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_8007EA74_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_8007EA74_H

#include "types.h"

struct G_PlaySound_6xB2;
void send_6xB2_play_sound(G_PlaySound_6xB2 *cmd);
// Fills in the 6xB2 header: subcommand 0xB2, size 3 words.
void init_6xB2_play_sound(G_PlaySound_6xB2 *cmd);
extern "C" {
void bswap_6xB2_play_sound(G_PlaySound_6xB2 *cmd);
}

#endif
