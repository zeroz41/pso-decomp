#ifndef PSO_UNK_TUNK_804ED598_H
#define PSO_UNK_TUNK_804ED598_H
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/task/TObject.h"

class TUnk_804ED5B0;

// Camera-facing distortion quad drawn through an indirect effect task (the
// telepipe marker of TTecLuker).
class TUnk_804ED598 : public TObject {
public:
    TUnk_804ED598(const Vec *position, s8 indirect_kind, s8 texture, TObject *parent, s32 depth_override,
                  s32 lifetime, f32 width, f32 height);
    virtual ~TUnk_804ED598();
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
    TUnk_804ED5B0 *indirect;
};
LAYOUT_ASSERT(TUnk_804ED598_size, sizeof(TUnk_804ED598) == 0x44);

#endif
