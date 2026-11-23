#include "pso/technique/TechniqueRingwaveList.h"

// The technique ringwave texture names and their list.

NJS_TEXNAME technique_ringwave_texnames[9] = {
    {technique_ringwave_texname_lightning01, 0, 0}, {technique_ringwave_texname_ring01, 0, 0}, {technique_ringwave_texname_ring02, 0, 0},
    {technique_ringwave_texname_ring03, 0, 0}, {technique_ringwave_texname_ring04, 0, 0}, {technique_ringwave_texname_ring05, 0, 0},
    {technique_ringwave_texname_ring06, 0, 0}, {technique_ringwave_texname_ring07, 0, 0}, {technique_ringwave_texname_ring08, 0, 0},
};

NJS_TEXLIST technique_ringwave_texture_list = {technique_ringwave_texnames, 9};
