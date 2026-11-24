#ifndef PSO_PLAYER_TOBJPLAYER_8023E480_H
#define PSO_PLAYER_TOBJPLAYER_8023E480_H

#include "types.h"
#include "pso/render/GinjaMaterialState.h"

extern "C" {
s32 bind_gvm_texture_list(const char *name, NJS_TEXLIST *texlist);
s32 load_streamed_prs_texture(saddr name, saddr texlist);
s32 load_disc_prs_texture(saddr name, saddr texlist);
s32 load_texture_if_valid(NJS_TEXLIST *texlist);
s32 free_texture_if_valid(NJS_TEXLIST *texlist);
void init_buffers(void);
}

// Makes texlist the current texture list; 0 when texlist is null.
s32 set_texlist(NJS_TEXLIST *texlist);

#endif
