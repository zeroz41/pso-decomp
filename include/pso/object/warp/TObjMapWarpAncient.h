#ifndef PSO_OBJECT_WARP_TOBJMAPWARPANCIENT_H
#define PSO_OBJECT_WARP_TOBJMAPWARPANCIENT_H

#include "types.h"
#include "pso/object/warp/TObjMapWarp.h"

struct AnimationMotion;
struct NJS_TEXLIST;
struct NJS_OBJECT;

struct TObjMapWarpAncient : public TObjMapWarp {
    TObjMapWarpAncient(TObject *parent, void *set_data);
    virtual ~TObjMapWarpAncient();
    virtual void draw_debug_destinations();
    virtual void render();
    virtual void run_task();
    static void free_globals();
    // Indices are into bm_o_warp_ancient.bml's model and motion name tables (TObjMapWarpAncient.cpp);
    // the field names are inferred from those file names.
    f32 beam_frame;                // motion frame of beam_motion, +4 per run_task
    NJS_OBJECT *beam_model;                // model 2, de_obj1_swarp_beam_n.gj
    NJS_OBJECT *ksita_model;               // model 0, dd_obj3_swarp_ksita.gj
    NJS_OBJECT *nsita_model;               // model 4, fd_obj2_swarp_nsita_1.gj
    NJS_TEXLIST *beam_textures;             // TObjGoalWarpAncient::get_archive_textures(2)
    NJS_TEXLIST *ksita_textures;            // TObjGoalWarpAncient::get_archive_textures(0)
    NJS_TEXLIST *nsita_textures;            // TObjGoalWarpAncient::get_archive_textures(4)
    AnimationMotion *beam_motion;  // motion 1, de_obj1_swarp_beam_n.njm
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjMapWarpAncient_size, sizeof(TObjMapWarpAncient) == 0x11C);
#endif
