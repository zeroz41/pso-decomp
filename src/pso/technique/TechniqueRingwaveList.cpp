#include "pso/technique/TechniqueRingwaveList.h"

// The technique ringwave texture names (their strings sit in TechniqueRingwaveNames.cpp) and their list.

extern char lbl_8044D5D0[];
extern char lbl_8044D5E4[];
extern char lbl_8044D5F0[];
extern char lbl_8044D5FC[];
extern char lbl_8044D608[];
extern char lbl_8044D614[];
extern char lbl_8044D620[];
extern char lbl_8044D62C[];
extern char lbl_8044D638[];

NJS_TEXNAME technique_ringwave_texnames[9] = {
    {lbl_8044D5D0, 0, 0}, {lbl_8044D5E4, 0, 0}, {lbl_8044D5F0, 0, 0},
    {lbl_8044D5FC, 0, 0}, {lbl_8044D608, 0, 0}, {lbl_8044D614, 0, 0},
    {lbl_8044D620, 0, 0}, {lbl_8044D62C, 0, 0}, {lbl_8044D638, 0, 0},
};

NJS_TEXLIST technique_ringwave_texture_list = {technique_ringwave_texnames, 9};
