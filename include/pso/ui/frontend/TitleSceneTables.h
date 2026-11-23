#ifndef PSO_UI_FRONTEND_TITLE_SCENE_TABLES_H
#define PSO_UI_FRONTEND_TITLE_SCENE_TABLES_H

#include "pso/system/NinjaTypes.h"
#include "pso/render/GinjaMaterialState.h"

struct TitleTextureFilenameTable {
    const char *archive[5];
};

__declspec(section ".data") extern NJS_TEXLIST title_texture_list;
extern NJS_SPRITE lobby_record_table[46];

#endif
