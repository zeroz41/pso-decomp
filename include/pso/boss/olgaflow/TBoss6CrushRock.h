#ifndef PSO_BOSS_OLGAFLOW_TBOSS6CRUSHROCK_H
#define PSO_BOSS_OLGAFLOW_TBOSS6CRUSHROCK_H

#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "types.h"
#include <stddef.h>

struct NJS_TEXLIST;

class TBoss6CrushRock : public TObject {
public:
    TBoss6CrushRock(TObject *parent, const Vec *point, saddr model_index);
    virtual ~TBoss6CrushRock();
    virtual void run_task();
    virtual void render();
    static s32 is_falz_alive();

    struct Angles { s32 x, y, z; };
    void *model;
    NJS_TEXLIST *texture_list;
    Vec position;
    Vec velocity;
    Angles angles;
    Angles angular_velocity;
};

LAYOUT_ASSERT(CrushRockSize, sizeof(TBoss6CrushRock) == 0x54);
LAYOUT_ASSERT(CrushRockPosition, offsetof(TBoss6CrushRock, position) == 0x24);
LAYOUT_ASSERT(CrushRockVelocity, offsetof(TBoss6CrushRock, velocity) == 0x30);
LAYOUT_ASSERT(CrushRockAngles, offsetof(TBoss6CrushRock, angles) == 0x3C);
LAYOUT_ASSERT(CrushRockAngularVelocity, offsetof(TBoss6CrushRock, angular_velocity) == 0x48);

#endif
