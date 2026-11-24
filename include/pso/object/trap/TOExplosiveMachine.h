#ifndef PSO_OBJECT_TRAP_TOEXPLOSIVEMACHINE_H
#define PSO_OBJECT_TRAP_TOEXPLOSIVEMACHINE_H

#include "pso/object/base/TObjMotion.h"

struct NJS_OBJECT;
struct GinjaTextureList;

struct ExplosiveMachineModel {
    u8 unknown00[0x14];
    f32 radius;
};

struct TOExplosiveMachine : public TObjBase {
    TOExplosiveMachine();
    virtual ~TOExplosiveMachine();
    virtual void run_task();
    virtual void render();

    static void destroy_static_lobby();
    static void load_shared_resource();

    f32 view_distance;
    f32 view_radius;
    f32 trigger_radius;
    NJS_OBJECT *debris_models[2];
    NJS_TEXLIST *debris_textures[2];
};

LAYOUT_ASSERT(TOExplosiveMachine_size, sizeof(TOExplosiveMachine) == 0xAC);
#endif
