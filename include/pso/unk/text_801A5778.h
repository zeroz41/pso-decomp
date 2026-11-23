#ifndef PSO_UNK_TEXT_801A5778_H
#define PSO_UNK_TEXT_801A5778_H

#include "types.h"

struct GvplPalette;

extern "C" {
// Loads a GVPL palette file into `palette`.
void load_gvpl_palette_file(const char *filename, GvplPalette *palette);
}

#endif
