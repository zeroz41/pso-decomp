#ifndef PSO_OBJECT_WARP_TOBJMAPWARPFOREST_H
#define PSO_OBJECT_WARP_TOBJMAPWARPFOREST_H
#include "types.h"
#include "pso/object/warp/TObjMapWarp.h"
struct ForestWarpMotion { u32 data,frameCount; };
struct TObjMapWarpForest : public TObjMapWarp {
    TObjMapWarpForest(TObject *parent, void *set_data);
    f32 frame;
    void* baseModel;
    void* beamModel;
    ForestWarpMotion* motion;
    void* textures;
    virtual void run_task();
    virtual void render();
    // Declared after run_task, the key function that places the vtable.
    virtual ~TObjMapWarpForest();
};
typedef char ForestWarpSize[sizeof(TObjMapWarpForest)==0x110?1:-1];
#endif
