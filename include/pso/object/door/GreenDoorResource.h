#ifndef PSO_OBJECT_DOOR_GREENDOORRESOURCE_H
#define PSO_OBJECT_DOOR_GREENDOORRESOURCE_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

struct BmlResource;
struct BmlResourceDescriptor;
struct DragonAttackParams;
class TObject;
struct NJS_TEXLIST;
struct NJS_OBJECT;
struct AnimationMotion;

extern BmlResource *green_door_bml_resource;
extern NJS_TEXLIST *green_door_texture_handle;
extern BmlResourceDescriptor bm_obj_door_ruins_resource_descriptor;
extern BmlResourceDescriptor bm_obj_door_space_resource_descriptor;

NJS_TEXLIST *get_green_door_textures();

AnimationMotion *get_green_door_motion(s32 index);
NJS_TEXLIST *get_green_door_texlist(s32 index);
NJS_OBJECT *get_green_door_model(s32 index);
void load_green_door_resources(void);

void free_green_door_resources();

void break_floor_grass_in_range(TObject *floor_grass, const Vec *pos, const DragonAttackParams *params);

#endif
