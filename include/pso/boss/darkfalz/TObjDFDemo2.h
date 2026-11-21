#ifndef PSO_BOSS_DARKFALZ_TOBJDFDEMO2_H
#define PSO_BOSS_DARKFALZ_TOBJDFDEMO2_H

#include "types.h"
#include <stddef.h>
#include "pso/boss/darkfalz/DarkFalzScenePart.h"
#include "pso/object/base/TObjMotion.h"

struct TObjDFDemo2 : public TObjBase {
    TObjDFDemo2(TObject *parent, const Vec *position, s32 angle, s32 variant);
    virtual ~TObjDFDemo2();
    virtual void run_task();
    virtual void render();
    static TObjDFDemo2 *create(TObject *parent, const Vec *position, s32 angle, s32 variant);

    DarkFalzScenePart parts[2];
    s32 variant;
    Vec camera_position;
    s32 angle;
    s32 timer;
    f32 frame;
};

LAYOUT_ASSERT(TObjDFDemo2_size, sizeof(TObjDFDemo2) == 0xC4);
LAYOUT_ASSERT(TObjDFDemo2CameraPositionOffset, offsetof(TObjDFDemo2, camera_position) == 0xAC);
#endif
