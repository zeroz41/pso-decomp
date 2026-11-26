#ifndef PSO_OBJECT_DOOR_GREENDOORRESOURCE_H
#define PSO_OBJECT_DOOR_GREENDOORRESOURCE_H

#include "types.h"

struct BmlResource;
struct NJS_TEXLIST;

extern BmlResource *green_door_bml_resource;
extern NJS_TEXLIST *green_door_texture_handle;

NJS_TEXLIST *get_green_door_textures();

u8 *get_green_door_motion(s32 index);
NJS_TEXLIST *get_green_door_texlist(s32 index);
u8 *get_green_door_model(s32 index);
void load_green_door_resources(void);

void free_green_door_resources();

#endif
