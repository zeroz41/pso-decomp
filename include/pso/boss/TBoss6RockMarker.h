#ifndef PSO_BOSS_TBOSS6ROCKMARKER_H
#define PSO_BOSS_TBOSS6ROCKMARKER_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include <dolphin/mtx.h>

// The second object of a TBoss6Rock (TBoss6Rock::marker, made by
// TBoss6Rock::create()): it draws the rock's model at the falling rock's
// position while the rock is airborne (inferred: the rock's falling shadow).
class TBoss6RockMarker : public TObject {
public:
    TBoss6RockMarker(TObject *parent);
    virtual ~TBoss6RockMarker();
    virtual void run_task();
    virtual void render();
    void set_target(s32 enabled, Vec *position, s32 *rotation, NJS_TEXLIST *texlist, NJS_OBJECT *model, f32 radius);
    s32 enabled;
    Vec position;
    f32 radius;
    s32 rotation_x;
    s32 rotation_y;
    s32 rotation_z;
    NJS_TEXLIST *texlist;
    NJS_OBJECT *model;
};
LAYOUT_ASSERT(TBoss6RockMarker_size, sizeof(TBoss6RockMarker) == 0x44);

#endif
