#ifndef PSO_OBJECT_WARP_TOBJAREAWARPENDING_H
#define PSO_OBJECT_WARP_TOBJAREAWARPENDING_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct AnimationMotion;
struct GinjaTextureList;
struct NJS_OBJECT;

struct TObjAreaWarpEnding : public TObjAreaWarp {
    TObjAreaWarpEnding(TObject *parent, void *set_data);
    virtual ~TObjAreaWarpEnding();
    virtual void debug_print_area_num();
    virtual void confirm_area_transfer(void *player);
    virtual void open_confirm_window(s32 client_id);
    void render();
    void run_task();
    f32 m_c4;
    u8 unk_C8[0x4];
    NJS_OBJECT *warp_model;                // forest warp model 0, fs_obj_warp.gj
    NJS_OBJECT *beam_model;                // model 1, fs_obj_warp_beam.gj
    AnimationMotion *beam_motion;  // motion 0, fs_obj_warp_beam.njm
    GinjaTextureList *textures;                  // get_forest_warp_textures(), fs_obj_warp.gvm
};

typedef char TObjAreaWarpEnding_size[sizeof(TObjAreaWarpEnding) == 0xDC ? 1 : -1];
#endif
