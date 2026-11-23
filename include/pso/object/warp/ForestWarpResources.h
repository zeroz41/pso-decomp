#ifndef PSO_OBJECT_WARP_FORESTWARPRESOURCES_H
#define PSO_OBJECT_WARP_FORESTWARPRESOURCES_H

#include "types.h"
#include "pso/system/BmlResourceDescriptor.h"
#include <dolphin/mtx/GeoTypes.h>

struct AnimationMotion;
struct BmlResource;
struct NJS_TEXLIST;
struct NJS_OBJECT;

union WarpScreenCoordinate {
    f32 value;
    u32 bits;
};

struct WarpStringScreenPosition {
    WarpScreenCoordinate x;
    WarpScreenCoordinate y;
};

LAYOUT_ASSERT(WarpStringScreenPosition_size, sizeof(WarpStringScreenPosition) == 8);

extern "C" {
extern BmlResourceDescriptor forest_warp_resource_descriptor;
extern BmlResource *forest_warp_bml_resource;
extern NJS_TEXLIST *forest_warp_texture_list;
extern const Vec map_warp_destination_offsets[4];
extern const WarpStringScreenPosition warp_string_screen_position_table[10];
extern s32 quest_warp_enabled;
extern s32 lobby_quest_progress_flag;
}

// fs_obj_warp.bml and fs_obj_warp.gvm, shared by the forest-style warps (TObjMapWarpForest,
// TObjAreaWarpForest, TObjAreaWarpEnding, TObjAreaWarpQuest); TObjWarpBase::free_globals frees them.
// Defined in TObjAreaWarpEndingJung.cpp; the getter names are inferred from their bodies.
void load_forest_warp_resources(void);
NJS_OBJECT *get_forest_warp_model(s32 index);                // get_bml_model of fs_obj_warp.bml
AnimationMotion *get_forest_warp_motion(s32 index);  // get_bml_motion of fs_obj_warp.bml
NJS_TEXLIST *get_forest_warp_textures();                      // the fs_obj_warp.gvm texture list

#endif
