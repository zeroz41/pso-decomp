#ifndef PSO_OBJECT_WARP_TOBJAREAWARPENDING_H
#define PSO_OBJECT_WARP_TOBJAREAWARPENDING_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct NJS_MOTION;
struct NJS_TEXLIST;
struct NJS_OBJECT;

struct TObjAreaWarpEnding : public TObjAreaWarp {
    static const char *class_name;
    TObjAreaWarpEnding(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjAreaWarpEnding();
    virtual void debug_print_area_num();
    virtual void confirm_area_transfer(TObjPlayer *player);
    virtual void open_confirm_window(s32 client_id);
    void render();
    void run_task();
    f32 beam_frame;  // frame of the beam motion, advanced 4 a task
    u32 beam_rotation;
    NJS_OBJECT *warp_model;                // forest warp model 0, fs_obj_warp.gj
    NJS_OBJECT *beam_model;                // model 1, fs_obj_warp_beam.gj
    NJS_MOTION *beam_motion;  // motion 0, fs_obj_warp_beam.njm
    NJS_TEXLIST *textures;                  // get_forest_warp_textures(), fs_obj_warp.gvm
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TObjAreaWarpEnding_size, sizeof(TObjAreaWarpEnding) == 0xDC);
#endif
