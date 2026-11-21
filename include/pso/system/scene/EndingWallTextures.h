#ifndef PSO_SYSTEM_SCENE_ENDING_WALL_TEXTURES_H
#define PSO_SYSTEM_SCENE_ENDING_WALL_TEXTURES_H

#include "types.h"

struct GinjaTextureList;

extern "C" {
extern GinjaTextureList *ending_ab_wall_texture_list;
extern s32 TEndingAB__fade_sequence_state;
}

GinjaTextureList *get_ending_ab_wall_texture_list(void);

#endif
