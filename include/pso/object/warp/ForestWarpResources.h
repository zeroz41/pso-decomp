#ifndef PSO_OBJECT_WARP_FORESTWARPRESOURCES_H
#define PSO_OBJECT_WARP_FORESTWARPRESOURCES_H

#include "types.h"

struct AnimationMotion;
struct GinjaTextureList;
struct NJS_OBJECT;

// fs_obj_warp.bml and fs_obj_warp.gvm, shared by the forest-style warps (TObjMapWarpForest,
// TObjAreaWarpForest, TObjAreaWarpEnding, TObjAreaWarpQuest); TObjWarpBase::free_globals frees them.
// Defined in TObjAreaWarpEndingJung.cpp; the getter names are inferred from their bodies.
void load_forest_warp_resources(void);
NJS_OBJECT *get_forest_warp_model(s32 index);                // get_bml_model of fs_obj_warp.bml
AnimationMotion *get_forest_warp_motion(s32 index);  // get_bml_motion of fs_obj_warp.bml
GinjaTextureList *get_forest_warp_textures();                      // the fs_obj_warp.gvm texture list

#endif
