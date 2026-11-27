#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_803DA038_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_803DA038_H

#include "types.h"

// TRUE for the GX colour-index formats (C4, C8, C14X2), which need a palette; only the low byte is the format.
s32 is_palette_texture_format(s32 format);
// Copies name to dest, adding ext unless name already ends in it.
void append_extension_if_missing(char *dest, char *name, char *ext);

#endif
