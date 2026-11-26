#ifndef PSO_RENDER_GINJATEXTUREHEADER_H
#define PSO_RENDER_GINJATEXTUREHEADER_H

#include "types.h"

struct GinjaTextureState;

// Reverses the byte order of a 32-bit word in place (GVPL chunk words are stored the other way round).
void swap_u32_bytes(u32 *word);
// Selects the palette bank (tlut_name) a colour-indexed texture loads its palette from.
void set_texture_palette_bank(GinjaTextureState *texture, s32 bank);

#endif
