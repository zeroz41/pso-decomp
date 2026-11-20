#ifndef PSO_OBJECT_WARP_TOBJGOALWARPANCIENT_H
#define PSO_OBJECT_WARP_TOBJGOALWARPANCIENT_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct AnimationMotion;

struct TObjGoalWarpAncient : public TObjAreaWarp {
    TObjGoalWarpAncient(TObject *parent, void *set_data);
    virtual ~TObjGoalWarpAncient();
    virtual void debug_print_area_num();
    void render();
    void run_task();
    static void load_resources();
    static s32 register_warp_object(s32 index);  // get_bml_texlist of bm_o_warp_ancient.bml's model `index`
    static s32 get_instance();                   // the de_obj2_swarp_beam_r.gvm texture load_resources loads
    static AnimationMotion *register_warp(s32 index);  // get_bml_motion of bm_o_warp_ancient.bml
    // Indices are into bm_o_warp_ancient.bml's model and motion name tables (TObjMapWarpAncient.cpp);
    // the field names are inferred from those file names.
    f32 beam_frame;                // motion frame of beam_motion, +4 per run_task
    f32 naka_frame;                // motion frame of naka_motion, +0.25 per run_task
    saddr beam_model;              // model 1, de_obj2_swarp_beam.gj
    saddr gawa_model;              // model 3, fd_obj1_swarp_gawa.gj
    saddr naka_model;              // model 5, fe_obj3_swarp_naka.gj
    s32 beam_textures;             // get_instance() for a goal (set_params[2] < 0), else register_warp_object(1)
    s32 gawa_textures;             // register_warp_object(3)
    s32 naka_textures;             // register_warp_object(5)
    AnimationMotion *beam_motion;  // motion 0, de_obj2_swarp_beam.njm
    AnimationMotion *naka_motion;  // motion 2, fe_obj3_swarp_naka.njm
};

LAYOUT_ASSERT(TObjGoalWarpAncient_size, sizeof(TObjGoalWarpAncient) == 0xEC);
#endif
