#ifndef PSO_BOSS_DARKFALZ_TOBJDFDEMOF_H
#define PSO_BOSS_DARKFALZ_TOBJDFDEMOF_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct AnimationMotion;
struct GinjaTextureList;
struct NJS_OBJECT;

struct TObjDFDemoF : public TObjBase {
    TObjDFDemoF(TObject *parent);
    virtual ~TObjDFDemoF();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_13() = 0;
    static TObjDFDemoF *create(TObject *parent);

    s32 timer;
    NJS_OBJECT *models[3];
    GinjaTextureList *textures[3];
    AnimationMotion *motions[3];
    f32 frame;
};

typedef char TObjDFDemoF_size[sizeof(TObjDFDemoF) == 0xBC ? 1 : -1];
typedef char TObjDFDemoF_models_offset[offsetof(TObjDFDemoF, models) == 0x94 ? 1 : -1];
#endif
