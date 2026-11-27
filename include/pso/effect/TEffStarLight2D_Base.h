#ifndef PSO_TEFFSTARLIGHT2D_BASE_H
#define PSO_TEFFSTARLIGHT2D_BASE_H

#include "pso/object/base/TObjMotion.h"

class TEffStarLight2D;

class TEffStarLight2D_Base : public TObjBase {
public:
    static void *create(ObjectSetData *set_data);
    TEffStarLight2D_Base(TObject *parent, ObjectSetData *set_data);
    virtual ~TEffStarLight2D_Base();
    virtual void run_task();
    virtual void render();

    TEffStarLight2D *light;
};

LAYOUT_ASSERT(TEffStarLight2D_BaseSize, sizeof(TEffStarLight2D_Base) == 0x94);

#endif
