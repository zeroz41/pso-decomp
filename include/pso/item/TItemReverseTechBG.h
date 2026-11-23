#ifndef PSO_ITEM_TITEMREVERSETECHBG_H
#define PSO_ITEM_TITEMREVERSETECHBG_H

#include "pso/system/task/TObject.h"
#include "pso/effect/sprite/TQuadSprite.h"
#include "types.h"

// One picture of the reverse tech scene, as TItemReverseTechPart2 keeps it and
// a TItemReverseTechBG built from it shows it (a sprite layout; name unknown).
struct TItemReverseTech_8011A54C {
    TItemReverseTech_8011A54C();
    s32 hold_time;  // frames at full alpha
    s32 fade_time;  // frames of each fade, in and out
    void *texlist;
    s32 texture;
    f32 x;
    f32 y;
    f32 width;
    f32 height;
    f32 u1;  // texture extent, 1.0 unless set
    f32 v1;
    f32 depth;
};

class TItemReverseTechBG : public TObject {
public:
    TItemReverseTechBG(TObject *parent, TItemReverseTech_8011A54C *picture);
    virtual ~TItemReverseTechBG();
    virtual void run_task();
    virtual void render();

    s32 hold_time;
    s32 fade_time;
    u32 alpha;
    u32 alpha_step;
    void *texlist;
    s32 texture;
    u32 color;  // alpha << 24 | white
    QuadSpriteRect quad;
    f32 depth;
    s32 timer;
    s32 state;  // 0 fade in, 1 hold, 2 fade out, 3 done
};
LAYOUT_ASSERT(TItemReverseTechBGSize, sizeof(TItemReverseTechBG) == 0x64);

#endif
