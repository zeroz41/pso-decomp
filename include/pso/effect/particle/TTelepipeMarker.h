#ifndef PSO_EFFECT_PARTICLE_TTELEPIPEMARKER_H
#define PSO_EFFECT_PARTICLE_TTELEPIPEMARKER_H
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/task/TObject.h"

class TEffIndirectSampler;

// Camera-facing distortion quad drawn through an indirect effect task (the
// telepipe marker of TTecLuker).
class TTelepipeMarker : public TObject {
public:
    TTelepipeMarker(const Vec *position, s8 indirect_kind, s8 texture, TObject *parent, s32 depth_override,
                  s32 lifetime, f32 width, f32 height);
    virtual ~TTelepipeMarker();
    virtual void render();
    virtual void run_task();

    f32 width;
    f32 height;
    Vec position;
    s8 indirect_kind;
    u8 texture;
    u8 pad_32[0x2];
    s32 depth_override;
    s32 visible;
    s32 lifetime; // frames left; 0 keeps it alive
    TEffIndirectSampler *indirect;
};
LAYOUT_ASSERT(TTelepipeMarker_size, sizeof(TTelepipeMarker) == 0x44);

#endif
