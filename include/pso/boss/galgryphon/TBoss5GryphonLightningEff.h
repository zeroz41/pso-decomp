#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNINGEFF_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNINGEFF_H

#include "pso/technique/TTecZondeEff.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"
#include "types.h"

// One vertex of the bolt's triangle strip; TTecZondeEff::build_lightning_strip fills the
// positions, calc_segment_uvs the texture coordinates.
struct LightningStripVertex {
    Vec pos;
    f32 u;
    f32 v;
    u32 color;
};

// The strip's two vertices at one bolt point (upper gets the texture row's top v).
struct LightningStripSegment {
    LightningStripVertex upper;
    LightningStripVertex lower;
};

class TBoss5GryphonLightningEff : public TTecZondeEff {
public:
    TBoss5GryphonLightningEff(TObject *parent, TBoss5GryphonLightningSegment *segments, int segment_count, f32 from,
                              f32 to, f32 scale);
    virtual ~TBoss5GryphonLightningEff();
    void set_two_sided();
    virtual void run_task();
    virtual void render();
public:
    s32 calc_segment_uvs(void *vertices);  // vertices: a LightningStripSegment strip
    // The f512_inazuma.gvm bolt textures: load_boss5_gryphon_resources loads them, TBoss5Gryphon::cleanup frees them.
    static void load_texture();
    static void release_texture();

    u8 two_sided;  // render draws the strip a second time with its sides swapped
};

#endif
