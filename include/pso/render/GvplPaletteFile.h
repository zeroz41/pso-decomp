#ifndef PSO_RENDER_GVPLPALETTEFILE_H
#define PSO_RENDER_GVPLPALETTEFILE_H

#include "types.h"

struct GvplPalette;

// Loads a GVPL palette file into `palette`.
void load_gvpl_palette_file(const char *filename, GvplPalette *palette);

#endif
