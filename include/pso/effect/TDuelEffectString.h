#ifndef PSO_EFFECT_TDUELEFFECTSTRING_H
#define PSO_EFFECT_TDUELEFFECTSTRING_H
#include "pso/system/task/TObject.h"
#include "types.h"


// One text quad of a duel banner: offset from the effect position (scaled with
// it), size, and texel origin in the duel texture.
struct DuelEffectQuad {
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    f32 u;
    f32 v;
};

// The text banner of a duel: kind 0 when the start countdown runs out, kind 1
// when the duel ends. It shrinks into place, fades, and lives for 30 frames.
class TDuelEffectString : public TObject {
public:
    static const char *class_name;
    TDuelEffectString(TObject *parent, f32 *pos, s32 kind);
    virtual ~TDuelEffectString();
    void draw_layout_quad(const DuelEffectQuad *quad, f32 scale);
    void render_end_banner(f32 scale);
    void render_start_banner(f32 scale);
    void calc_scale_and_alpha(f32 *scale, f32 *alpha, s32 time);
    virtual void run_task();
    virtual void render();
    f32 pos[2];  // screen position
    s32 kind;
    s32 timer;   // frames since the banner appeared
};

f32 pow(f32 x, f32 y);

#endif
