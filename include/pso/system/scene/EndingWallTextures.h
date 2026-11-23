#ifndef PSO_SYSTEM_SCENE_ENDING_WALL_TEXTURES_H
#define PSO_SYSTEM_SCENE_ENDING_WALL_TEXTURES_H

#include "types.h"

struct NJS_TEXLIST;

extern "C" {
extern NJS_TEXLIST *ending_ab_wall_texture_list;
extern s32 TEndingAB__fade_sequence_state;
}

NJS_TEXLIST *get_ending_ab_wall_texture_list(void);

#endif
