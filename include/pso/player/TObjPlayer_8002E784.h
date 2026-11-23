#ifndef PSO_PLAYER_TOBJPLAYER_8002E784_H
#define PSO_PLAYER_TOBJPLAYER_8002E784_H

#include "types.h"
#include "pso/player/TUnk_804820C0.h"

extern "C" {
s32 TObjPlayer__sub_8002EDCC(BreakupPiece *piece);
}

// TObjPlayer::calc_random_scaled: rand() * random_unit_scale * random_angle_range
// is a random angle in [0, 0x10000).
extern const f32 random_unit_scale;
extern const f32 random_angle_range;
// Breakup debris that misses the platform starts sinking below this height.
extern const f32 boss2_water_level;
extern const f32 boss2_tunnel_splash_y;
extern const f32 boss2_model_scale;
// Debris bounces and photon bullets hit inside [boss2_platform_min, boss2_platform_max].
extern const f32 boss2_platform_max;
extern const f32 boss2_platform_min;

#endif
