#ifndef PSO_OBJECT_WARP_TOBJAREAWARPQUEST_H
#define PSO_OBJECT_WARP_TOBJAREAWARPQUEST_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct AnimationMotion;
struct NJS_TEXLIST;
struct NJS_OBJECT;

struct TObjAreaWarpQuest : public TObjAreaWarp {
    static const char *class_name;
    TObjAreaWarpQuest(TObject *parent, void *set_data);
    virtual ~TObjAreaWarpQuest();
    virtual void debug_print_area_num();
    virtual void confirm_area_transfer(TObjPlayer *player);
    void render();
    void run_task();
    s32 player_set_id;  // inferred from "<- PLAYER SET ID : %d"
    f32 beam_frame;                // frame of beam_motion
    u32 beam_rotation;
    NJS_OBJECT *warp_model;                // forest warp model 0, fs_obj_warp.gj
    NJS_OBJECT *beam_model;                // model 1, fs_obj_warp_beam.gj
    AnimationMotion *beam_motion;  // motion 0, fs_obj_warp_beam.njm
    NJS_TEXLIST *textures;                  // get_forest_warp_textures(), fs_obj_warp.gvm
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjAreaWarpQuest_size, sizeof(TObjAreaWarpQuest) == 0xE0);
#endif
