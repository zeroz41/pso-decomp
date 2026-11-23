#ifndef PSO_BOSS_DARKFALZ_TOBJDFDEMOF_H
#define PSO_BOSS_DARKFALZ_TOBJDFDEMOF_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct AnimationMotion;
struct NJS_TEXLIST;
struct NJS_OBJECT;

struct TObjDFDemoF : public TObjBase {
    TObjDFDemoF(TObject *parent);
    virtual ~TObjDFDemoF();
    virtual void run_task();
    virtual void render();
    static TObjDFDemoF *create(TObject *parent);

    s32 timer;
    NJS_OBJECT *models[3];
    NJS_TEXLIST *textures[3];
    AnimationMotion *motions[3];
    f32 frame;
};

LAYOUT_ASSERT(TObjDFDemoF_size, sizeof(TObjDFDemoF) == 0xBC);
LAYOUT_ASSERT(TObjDFDemoF_models_offset, offsetof(TObjDFDemoF, models) == 0x94);
#endif
