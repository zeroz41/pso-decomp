#ifndef PSO_BOSS_DRAGON_OBJBOSS1COMMONRESOURCE_H
#define PSO_BOSS_DRAGON_OBJBOSS1COMMONRESOURCE_H

#include "types.h"
#include "pso/system/BmlResourceDescriptor.h"

struct NJS_TEXLIST;

// The Dragon arena's ground archive (bm_obj_boss1_common.bml) and its textures.
extern BmlResourceDescriptor dragon_ground_resource_descriptor;
extern const char dragon_common_texture_filename[];
extern const char dragon_common_alternate_bml_filename[];
extern const char dragon_common_alternate_texture_filename[];
// The arena texture list TObjBoss1Crater loads and the arena objects make current before they draw.
extern NJS_TEXLIST *dragon_common_texture_list;

struct BmlResource;
// The loaded ground archive (load_dragon_ground_assets): model 0 the crater, 3 the burrow mound, 4 the mound
// meshes' material source, 5 the arena floor.
extern BmlResource *dragon_ground_resource;

#endif
