#ifndef PSO_OBJECT_WARP_TOBJMAPWARPFOREST_H
#define PSO_OBJECT_WARP_TOBJMAPWARPFOREST_H
#include "types.h"
#include "pso/object/warp/TObjMapWarp.h"
struct AnimationMotion;
struct NJS_TEXLIST;
struct NJS_OBJECT;

struct TObjMapWarpForest : public TObjMapWarp {
    static const char *class_name;
    TObjMapWarpForest(TObject *parent, void *set_data);
    f32 frame;
    NJS_OBJECT *baseModel;              // forest warp model 4, fs_obj_warp_n.gj
    NJS_OBJECT *beamModel;              // model 5, fs_obj_warp_n_beam.gj
    AnimationMotion *motion;    // motion 2, fs_obj_warp_n_beam.njm
    NJS_TEXLIST *textures;               // get_forest_warp_textures(), fs_obj_warp.gvm
    virtual void run_task();
    virtual void render();
    // Declared after run_task, the key function that places the vtable.
    virtual ~TObjMapWarpForest();
    static void *create(void *set_data);
};
LAYOUT_ASSERT(ForestWarpSize, sizeof(TObjMapWarpForest)==0x110);
#endif
