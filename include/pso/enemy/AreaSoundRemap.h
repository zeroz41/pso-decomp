#ifndef PSO_ENEMY_AREASOUNDREMAP_H
#define PSO_ENEMY_AREASOUNDREMAP_H

#include "types.h"

s32 remap_area_sound_id(s32 sound_id, s32 control);
s32 remap_area_sound_id(s32 sound_id);

struct AreaSoundRemapEntry {
    s32 base;
    s32 start;
};

#endif
