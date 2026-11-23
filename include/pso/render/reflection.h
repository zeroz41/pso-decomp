#ifndef PSO_RENDER_REFLECTION_H
#define PSO_RENDER_REFLECTION_H
#include "types.h"
#include <dolphin/mtx.h>

s32 push_reflection_matrix(Vec *point);
s32 push_player_reflection_matrix(u16 client_id, s32 clip);
s32 set_reflection_scissor(void *point, s32 _w1);
void restore_render_scissor(s32 reset_scissor);
void reset_reflection_tev_stages();
void play_reflection_particles(s16 effect_id);
void destroy_reflection_target();
void create_reflection_target();
// Forces the next reflection pass even when the player's floor ray missed.
void request_reflection_render();

extern "C" {
s32 fn_8029E7BC(saddr arg0, u8 *arg1);
void TObjPlayer__sub_8029EE2C(void);
}

#endif
