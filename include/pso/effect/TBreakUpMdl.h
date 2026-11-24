#ifndef PSO_EFFECT_TBREAKUPMDL_H
#define PSO_EFFECT_TBREAKUPMDL_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/system/task/TObject.h"

struct NJS_OBJECT;
struct NJS_MOTION;
struct NJS_TEXLIST;

// One node record of a breakup model: where its piece starts and how it flies off (the De Rol Le breakup
// effects copy pos into each piece's position and rotate vel into its velocity).
struct BreakupNodeRecord {
    void *model;    // the node's model
    Vec pos;
    Vec vel;
};

// A breakup model: the visible nodes of a model with where each sits and the xz direction it flies off in.
class TBreakUpMdlData {
public:
    s32 m_count;
    BreakupNodeRecord *m_records;
    s32 is_ginja;   // the node models are Ginja models (else chunk models)
    TBreakUpMdlData(long model, long motion, f32 frame);
    TBreakUpMdlData(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame);
    TBreakUpMdlData(NJS_OBJECT *model);
    virtual ~TBreakUpMdlData();
    void alloc_breakup_piece_records(NJS_OBJECT *model);
    s32 collect_node_positions(NJS_OBJECT *node, s32 index);
    s32 build_node_records(NJS_OBJECT *node, s32 index);
};

// How the pieces of a TBreakUpMdl fly and fade; the ctor uses breakup_default_param_row when the
// caller passes none.
struct BreakUpParamRow {
    s32 fade_frames;
    f32 fade;
    f32 speed;
    f32 damping;
    f32 gravity;
    f32 rise_base;
    f32 rise_scale;
    void copy(BreakUpParamRow *src);
};

// One flying piece of a TBreakUpMdl: a node of the breakup model.
struct BreakUpPiece {
    Vec pos;
    Vec velocity;
    s32 angle[3];
    s32 spin;       // added to angle[0] each frame, half of it to angle[1]
};

// A model that falls apart: each node of a breakup model flies off from where it sits and the whole
// thing fades out.
struct TBreakUpMdl : public TObject {
    TBreakUpMdl(TObject *parent, TBreakUpMdlData *model, BreakUpParamRow *params, NJS_TEXLIST *texlist,
                Vec *position, s32 rotation_y);
    virtual ~TBreakUpMdl();
    s32 piece_count;
    TBreakUpMdlData *model;
    NJS_TEXLIST *texlist;
    f32 alpha;
    u8 pad_2C[4];
    f32 speed;
    BreakUpPiece *pieces;
    BreakUpParamRow params;
    virtual void render();
    virtual void run_task();
    void init_alpha(s32 frames, f32 fade);
    static const char *class_name;
};

LAYOUT_ASSERT(TBreakUpMdl_size, sizeof(TBreakUpMdl) == 0x54);

#endif
