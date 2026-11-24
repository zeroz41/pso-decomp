#ifndef PSO_RENDER_FLOORREFLECTION_H
#define PSO_RENDER_FLOORREFLECTION_H
#include "types.h"
#include <dolphin/mtx.h>
#include "pso/system/task/TObject.h"
#include "pso/unk/text_803D8F74.h"

struct GinjaRenderTarget;
class TEffIndirectSampler;

// Renders the scene mirrored in the reflective floor under the player into a
// texture each frame (the Sora reflection pass). Its vtable
// 0x804DC7C4 is emitted by pso/render/reflection.cpp.
class TFloorReflection : public TObject {
public:
    TFloorReflection(TObject *parent = NULL);
    virtual ~TFloorReflection();
    virtual void run_task();
    virtual void render();
    virtual void render_shadows();
    TEffIndirectSampler *get_indirect_effect();
    // scene_sora_recon_object when the task was made (name inferred).
    GinjaRenderTarget *recon_object;
    // The TEffIndirectSampler(0x28, 1, tl_05) indirect effect task (name inferred).
    TEffIndirectSampler *indirect_effect;
    // The floor plane under the player that find_reflective_floor last found.
    ReflectionPlane reflect_plane;
};
LAYOUT_ASSERT(TFloorReflection_size, sizeof(TFloorReflection) == 0x3C);

#endif
