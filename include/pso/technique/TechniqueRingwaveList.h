#ifndef PSO_TECHNIQUE_TECHNIQUERINGWAVELIST_H
#define PSO_TECHNIQUE_TECHNIQUERINGWAVELIST_H

#include "pso/render/GinjaMaterialState.h"

// The technique textures bound from the "technic_pt" archive: f032_lightning01 and f064_ring01-08.
// Their file names, in .rodata (TechniqueRingwaveNames.cpp).
extern char technique_ringwave_texname_lightning01[];
extern char technique_ringwave_texname_ring01[];
extern char technique_ringwave_texname_ring02[];
extern char technique_ringwave_texname_ring03[];
extern char technique_ringwave_texname_ring04[];
extern char technique_ringwave_texname_ring05[];
extern char technique_ringwave_texname_ring06[];
extern char technique_ringwave_texname_ring07[];
extern char technique_ringwave_texname_ring08[];
extern NJS_TEXNAME technique_ringwave_texnames[9];
extern NJS_TEXLIST technique_ringwave_texture_list;

#endif
