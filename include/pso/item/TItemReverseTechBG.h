#ifndef PSO_ITEM_TITEMREVERSETECHBG_H
#define PSO_ITEM_TITEMREVERSETECHBG_H

#include "pso/system/task/TObject.h"
#include "pso/effect/sprite/TQuadSprite.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"

// One picture of the reverse tech scene: TItemReverseTechPart2 keeps seven and
// shows one by building a TItemReverseTechBG from it.
struct TItemReverseTechPicture {
    TItemReverseTechPicture();
    s32 hold_time;  // frames at full alpha
    s32 fade_time;  // frames of each fade, in and out
    NJS_TEXLIST *texlist;
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
    TItemReverseTechBG(TObject *parent, TItemReverseTechPicture *picture);
    virtual ~TItemReverseTechBG();
    virtual void run_task();
    virtual void render();

    s32 hold_time;
    s32 fade_time;
    u32 alpha;
    u32 alpha_step;
    NJS_TEXLIST *texlist;
    s32 texture;
    u32 color;  // alpha << 24 | white
    QuadSpriteRect quad;
    f32 depth;
    s32 timer;
    s32 state;  // 0 fade in, 1 hold, 2 fade out, 3 done
};
LAYOUT_ASSERT(TItemReverseTechBGSize, sizeof(TItemReverseTechBG) == 0x64);

#endif
