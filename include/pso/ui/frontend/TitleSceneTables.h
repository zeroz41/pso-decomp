#ifndef PSO_UI_FRONTEND_TITLE_SCENE_TABLES_H
#define PSO_UI_FRONTEND_TITLE_SCENE_TABLES_H

#include "pso/render/SpriteDescriptor.h"
#include "pso/render/GinjaMaterialState.h"

struct TitleTextureFilenameTable {
    const char *archive[5];
};

__declspec(section ".data") extern GinjaTextureList title_texture_list;
extern SpriteDescriptor lobby_record_table[46];

#endif
