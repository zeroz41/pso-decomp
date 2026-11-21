#ifndef PSO_BOSS_DARKFALZ_TOBJDFDEMO3_H
#define PSO_BOSS_DARKFALZ_TOBJDFDEMO3_H

#include "types.h"
#include <stddef.h>
#include "pso/boss/darkfalz/DarkFalzScenePart.h"
#include "pso/object/base/TObjMotion.h"

struct TObjFish;
class TParticleCtrl;

struct TObjDFDemo3 : public TObjBase {
    TObjDFDemo3(TObject *parent, const Vec *position, s32 angle);
    virtual ~TObjDFDemo3();
    virtual void run_task();
    virtual void render();
    static TObjDFDemo3 *create(TObject *parent, const Vec *position, s32 angle);

    TParticleCtrl *emitters[1];
    DarkFalzScenePart part;
    Vec camera_position;
    s32 angle;
    s32 timer;
    f32 frame;
    TObjFish *node_list;
    Vec emitter_position;
};

typedef char TObjDFDemo3_size[sizeof(TObjDFDemo3) == 0xC8 ? 1 : -1];
typedef char TObjDFDemo3_camera_position_offset[offsetof(TObjDFDemo3, camera_position) == 0xA0 ? 1 : -1];
typedef char TObjDFDemo3_emitter_position_offset[offsetof(TObjDFDemo3, emitter_position) == 0xBC ? 1 : -1];
#endif
