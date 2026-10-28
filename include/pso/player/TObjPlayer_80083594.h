#ifndef PSO_PLAYER_TOBJPLAYER_80083594_H
#define PSO_PLAYER_TOBJPLAYER_80083594_H

#include "types.h"

void load_projected_texture_matrix(f32 farg0);
void setup_particle_tev(s32 arg0);
// Undoes setup_particle_tev (not in split screen).
void reset_particle_tev();
// Loads texture matrix 0 with the screen projection rotated by rotation_y (not in split screen).
void load_projection_tex_matrix(s32 rotation_y);

#endif
