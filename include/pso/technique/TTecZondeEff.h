#ifndef PSO_TECHNIQUE_TTECZONDEEFF_H
#define PSO_TECHNIQUE_TTECZONDEEFF_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

struct ParticleStripVertex;

class TTecZondeEff : public TObject {
public:
    TTecZondeEff(TObject *parent, s32 decay, s32 start, f32 scale);
    TTecZondeEff(TObject *parent, Vec *from, Vec *dir, s32 decay, s32 start, f32 length, f32 scale);
    TTecZondeEff(TObject *parent, Vec *from, Vec *dir, f32 length);
    virtual ~TTecZondeEff();
    void randomize_bolt_jitter();
    void calc_lightning_scatter_direction(s32 axis, Vec *out);
    s32 build_lightning_strip(ParticleStripVertex *out, Vec *points, f32 *widths, f32 *heights);
    s32 project_lightning_points(Vec *out, f32 *strip_widths, f32 *strip_heights);
    virtual void run_task();
    virtual void render();
public:
    s32 calc_dominant_axis();
    void init_bolt_points();
    static void init_resources();

    Vec origin;
    Vec direction;  // unit vector from origin to the far end; length holds the distance
    f32 length;
    s32 point_count;  // at most 13
    Vec base_points[13];
    Vec points[13];
    Vec jitter_dirs[13];
    f32 widths[13];
    f32 scale;
    s32 timer;
    u32 power;
    s32 idx;
    u32 decay;
    s32 start;
    s16 frame;  // the texture row (frame & 7) and texture (frame & 8)
    s16 active;
};

void clear_zonde_beam_vertex_pointer(void);

#endif
