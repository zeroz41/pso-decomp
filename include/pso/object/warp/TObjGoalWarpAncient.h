#ifndef PSO_OBJECT_WARP_TOBJGOALWARPANCIENT_H
#define PSO_OBJECT_WARP_TOBJGOALWARPANCIENT_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct AnimationMotion;
struct NJS_TEXLIST;
struct NJS_OBJECT;

struct TObjGoalWarpAncient : public TObjAreaWarp {
    TObjGoalWarpAncient(TObject *parent, void *set_data);
    virtual ~TObjGoalWarpAncient();
    virtual void debug_print_area_num();
    void render();
    void run_task();
    static void load_resources();
    static NJS_TEXLIST *get_archive_textures(s32 index);
    static NJS_TEXLIST *get_goal_beam_textures();
    static AnimationMotion *register_warp(s32 index);
    // Indices are into bm_o_warp_ancient.bml's model and motion name tables (TObjMapWarpAncient.cpp);
    // the field names are inferred from those file names.
    f32 beam_frame;                // motion frame of beam_motion, +4 per run_task
    f32 naka_frame;                // motion frame of naka_motion, +0.25 per run_task
    NJS_OBJECT *beam_model;                // model 1, de_obj2_swarp_beam.gj
    NJS_OBJECT *gawa_model;                // model 3, fd_obj1_swarp_gawa.gj
    NJS_OBJECT *naka_model;                // model 5, fe_obj3_swarp_naka.gj
    NJS_TEXLIST *beam_textures;             // get_goal_beam_textures() for a goal (set_params[2] < 0), else get_archive_textures(1)
    NJS_TEXLIST *gawa_textures;             // get_archive_textures(3)
    NJS_TEXLIST *naka_textures;             // get_archive_textures(5)
    AnimationMotion *beam_motion;  // motion 0, de_obj2_swarp_beam.njm
    AnimationMotion *naka_motion;  // motion 2, fe_obj3_swarp_naka.njm
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjGoalWarpAncient_size, sizeof(TObjGoalWarpAncient) == 0xEC);
#endif
