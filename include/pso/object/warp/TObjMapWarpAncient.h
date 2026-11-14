#ifndef PSO_OBJECT_WARP_TOBJMAPWARPANCIENT_H
#define PSO_OBJECT_WARP_TOBJMAPWARPANCIENT_H

#include "types.h"
#include "pso/object/warp/TObjMapWarp.h"

struct AnimationMotion;

struct TObjMapWarpAncient : public TObjMapWarp {
    TObjMapWarpAncient(TObject *parent, void *set_data);
    virtual ~TObjMapWarpAncient();
    virtual void slot4C();
    virtual void render();
    virtual void run_task();
    static void free_globals();
    // Indices are into bm_o_warp_ancient.bml's model and motion name tables (TObjMapWarpAncient.cpp);
    // the field names are inferred from those file names.
    f32 beam_frame;                // motion frame of beam_motion, +4 per run_task
    s32 beam_model;                // model 2, de_obj1_swarp_beam_n.gj
    s32 ksita_model;               // model 0, dd_obj3_swarp_ksita.gj
    s32 nsita_model;               // model 4, fd_obj2_swarp_nsita_1.gj
    s32 beam_textures;             // TObjGoalWarpAncient::register_warp_object(2)
    s32 ksita_textures;            // TObjGoalWarpAncient::register_warp_object(0)
    s32 nsita_textures;            // TObjGoalWarpAncient::register_warp_object(4)
    AnimationMotion *beam_motion;  // motion 1, de_obj1_swarp_beam_n.njm
};

typedef char TObjMapWarpAncient_size[sizeof(TObjMapWarpAncient) == 0x11C ? 1 : -1];
#endif
