#ifndef PSO_PLAYER_PRSTEXTURELOAD_H
#define PSO_PLAYER_PRSTEXTURELOAD_H

#include "types.h"
#include "pso/render/GinjaMaterialState.h"

s32 bind_gvm_texture_list(const char *name, NJS_TEXLIST *texlist);
s32 load_streamed_prs_texture(const char *name, NJS_TEXLIST *texlist);
s32 load_disc_prs_texture(const char *name, NJS_TEXLIST *texlist);
s32 load_texture_if_valid(NJS_TEXLIST *texlist);
s32 free_texture_if_valid(NJS_TEXLIST *texlist);
void init_buffers(void);

// Makes texlist the current texture list; 0 when texlist is null.
s32 set_texlist(NJS_TEXLIST *texlist);

#endif
