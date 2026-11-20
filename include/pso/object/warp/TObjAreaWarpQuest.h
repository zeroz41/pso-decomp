#ifndef PSO_OBJECT_WARP_TOBJAREAWARPQUEST_H
#define PSO_OBJECT_WARP_TOBJAREAWARPQUEST_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct AnimationMotion;

struct TObjAreaWarpQuest : public TObjAreaWarp {
    TObjAreaWarpQuest(TObject *parent, void *set_data);
    virtual ~TObjAreaWarpQuest();
    virtual void debug_print_area_num();
    virtual void confirm_area_transfer(TObjPlayer *player);
    void render();
    void run_task();
    s32 get_dest_area();
    s32 player_set_id;  // inferred from "<- PLAYER SET ID : %d"
    f32 beam_frame;                // frame of beam_motion
    u8 unk_CC[0x4];
    s32 warp_model;                // forest warp model 0, fs_obj_warp.gj
    s32 beam_model;                // model 1, fs_obj_warp_beam.gj
    AnimationMotion *beam_motion;  // motion 0, fs_obj_warp_beam.njm
    u32 textures;                  // get_forest_warp_textures(), fs_obj_warp.gvm
};

typedef char TObjAreaWarpQuest_size[sizeof(TObjAreaWarpQuest) == 0xE0 ? 1 : -1];
#endif
