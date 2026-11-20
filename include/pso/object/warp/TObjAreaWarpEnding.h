#ifndef PSO_OBJECT_WARP_TOBJAREAWARPENDING_H
#define PSO_OBJECT_WARP_TOBJAREAWARPENDING_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct AnimationMotion;

struct TObjAreaWarpEnding : public TObjAreaWarp {
    TObjAreaWarpEnding(TObject *parent, void *set_data);
    virtual ~TObjAreaWarpEnding();
    virtual void debug_print_area_num();
    virtual void confirm_area_transfer(TObjPlayer *player);
    virtual void open_confirm_window(s32 client_id);
    void render();
    void run_task();
    f32 m_c4;
    u8 unk_C8[0x4];
    s32 warp_model;                // forest warp model 0, fs_obj_warp.gj
    s32 beam_model;                // model 1, fs_obj_warp_beam.gj
    AnimationMotion *beam_motion;  // motion 0, fs_obj_warp_beam.njm
    u32 textures;                  // get_forest_warp_textures(), fs_obj_warp.gvm
};

typedef char TObjAreaWarpEnding_size[sizeof(TObjAreaWarpEnding) == 0xDC ? 1 : -1];
#endif
