#ifndef PSO_BOSS_OLGAFLOW_TBOSS6CRUSHROCK_H
#define PSO_BOSS_OLGAFLOW_TBOSS6CRUSHROCK_H

#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "types.h"
#include <stddef.h>

struct GinjaTextureList;

class TBoss6CrushRock : public TObject {
public:
    TBoss6CrushRock(TObject *parent, const Vec *point, s32 model_index);
    virtual ~TBoss6CrushRock();
    virtual void run_task();
    virtual void render();
    static s32 is_falz_alive();

    struct Angles { s32 x, y, z; };
    void *model;
    GinjaTextureList *texture_list;
    Vec position;
    Vec velocity;
    Angles angles;
    Angles angular_velocity;
};

typedef char CrushRockSize[sizeof(TBoss6CrushRock) == 0x54 ? 1 : -1];
typedef char CrushRockPosition[offsetof(TBoss6CrushRock, position) == 0x24 ? 1 : -1];
typedef char CrushRockVelocity[offsetof(TBoss6CrushRock, velocity) == 0x30 ? 1 : -1];
typedef char CrushRockAngles[offsetof(TBoss6CrushRock, angles) == 0x3C ? 1 : -1];
typedef char CrushRockAngularVelocity[offsetof(TBoss6CrushRock, angular_velocity) == 0x48 ? 1 : -1];

#endif
