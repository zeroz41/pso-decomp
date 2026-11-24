#ifndef PSO_TEFFSTARLIGHTCHILD_H
#define PSO_TEFFSTARLIGHTCHILD_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/render/ColorLineList.h"

// One segment of a star light's trail: a screen-space edge across the path
// that shrinks to its middle, then disappears.
class TEffStarLightChild : public TObject {
public:
    static const char *class_name;
    TEffStarLightChild(ColorLineVertex *from, ColorLineVertex *to, TObject *parent, f32 width, f32 speed);
    virtual ~TEffStarLightChild();
    virtual void run_task();
public:
    virtual void render();
    f32 shrink_distance;  // each end moves this far toward the middle per frame
    ColorLineVertex edges[2];
};

LAYOUT_ASSERT(TEffStarLightChildSize, sizeof(TEffStarLightChild) == 0x30);

#endif
