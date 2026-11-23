#ifndef PSO_UNK_TEXT_8028A820_H
#define PSO_UNK_TEXT_8028A820_H

struct BmlResource;
struct NJS_TEXLIST;

extern "C" {
extern BmlResource *green_door_bml_resource;
extern NJS_TEXLIST *green_door_texture_handle;

NJS_TEXLIST *get_green_door_textures();
}

void load_green_door_resources(void);

#endif
