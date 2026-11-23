#ifndef PSO_OBJECT_WARP_TOBJAREAWARPFOREST_H
#define PSO_OBJECT_WARP_TOBJAREAWARPFOREST_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct AnimationMotion;
struct NJS_TEXLIST;
struct NJS_OBJECT;

struct TObjAreaWarpForest : public TObjAreaWarp {
    static const char *class_name;
    TObjAreaWarpForest(TObject *parent, void *set_data);
    virtual ~TObjAreaWarpForest();
    virtual void confirm_area_transfer(TObjPlayer *player);
    virtual void debug_print_area_num();
    void render();
    void run_task();
    f32 m_c4;
    u32 beam_rotation;
    NJS_OBJECT *warp_model;                // forest warp model 0, fs_obj_warp.gj
    NJS_OBJECT *beam_model;                // model 1, fs_obj_warp_beam.gj
    AnimationMotion *beam_motion;  // motion 0, fs_obj_warp_beam.njm
    NJS_TEXLIST *textures;                  // get_forest_warp_textures(), fs_obj_warp.gvm
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjAreaWarpForest_size, sizeof(TObjAreaWarpForest) == 0xDC);
#endif
