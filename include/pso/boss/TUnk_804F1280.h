#ifndef PSO_BOSS_TUNK_804F1280_H
#define PSO_BOSS_TUNK_804F1280_H
#include "types.h"
#include "pso/TObject.h"
#include <dolphin/mtx.h>

// The second object of a TBoss6Rock (TBoss6Rock::marker, made by
// TBoss6Rock::create()): it draws the rock's model at the falling rock's
// position while the rock is airborne (inferred: the rock's falling shadow).
class TUnk_804F1280 : public TObject {
public:
    TUnk_804F1280(TObject *parent);
    virtual ~TUnk_804F1280();
    virtual void run_task();
    virtual void render();
    void set_target(s32 enabled, Vec *position, s32 *rotation, s32 texlist, s32 model, f32 radius);
    s32 enabled;
    Vec position;
    f32 radius;
    s32 rotation_x;
    s32 rotation_y;
    s32 rotation_z;
    s32 texlist;
    s32 model;
};
typedef char TUnk_804F1280_size[sizeof(TUnk_804F1280) == 0x44 ? 1 : -1];

#endif
