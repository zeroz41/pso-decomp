#ifndef PSO_BOSS_DARKFALZ_TOBJDFDEMO4_H
#define PSO_BOSS_DARKFALZ_TOBJDFDEMO4_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/darkfalz/TObjDFDemo5.h"
#include "pso/unk/ModelNodeTables.h"

class ModelNodePositionCapture;

class TParticleCtrl;

struct TObjDFDemo4 : public TObjBase {
    TObjDFDemo4(TObject *parent, const Vec *pos, s32 angle);
    virtual ~TObjDFDemo4();
    void draw_zanzo_parts();
    void draw_body_parts();
    virtual void render();
    virtual void run_task();
    static TObjDFDemo4 *create(TObject *parent, const Vec *position, s32 angle);

    ModelNodeTables node_tables;
    TParticleCtrl *particle_emitters[2];
    DarkFalzScenePart zanzo_parts[2];
    DarkFalzScenePart body_parts[3];
    Vec pos;
    s32 angle;
    s32 timer;
    f32 frame;
    ModelNodePositionCapture *node_list; // tracks node_positions
    Vec node_positions[2];
    static const char *name;
};

LAYOUT_ASSERT(TObjDFDemo4_size, sizeof(TObjDFDemo4) == 0x11C);
#endif
