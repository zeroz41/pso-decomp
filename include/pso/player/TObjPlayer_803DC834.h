#ifndef PSO_PLAYER_TOBJPLAYER_803DC834_H
#define PSO_PLAYER_TOBJPLAYER_803DC834_H

#include "types.h"

// Called once a Ginja model draw ends (install_depth_alpha_state sets it).
typedef void (*GinjaDrawEndCallback)(void);

void set_ginja_draw_end_callback(GinjaDrawEndCallback callback);
void set_ginja_post_tev_stage_count(s32 x);
void set_ginja_post_texgen_count(s32 x);

#endif
