#ifndef PSO_UNK_TEXT_8028A820_H
#define PSO_UNK_TEXT_8028A820_H

struct BmlResource;
struct GinjaTextureList;

extern "C" {
extern BmlResource *green_door_bml_resource;
extern GinjaTextureList *green_door_texture_handle;

GinjaTextureList *get_green_door_textures();
}

void load_green_door_resources(void);

#endif
