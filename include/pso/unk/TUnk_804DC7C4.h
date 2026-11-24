#ifndef PSO_UNK_TUNK_804DC7C4_H
#define PSO_UNK_TUNK_804DC7C4_H
#include "types.h"
#include <dolphin/mtx.h>
#include "pso/system/task/TObject.h"

struct GinjaRenderTarget;

// The Sora reflected-scene task (TSceneSora's reflection pass). Its vtable
// 0x804DC7C4 is emitted by pso/render/reflection.cpp.
class TUnk_804DC7C4 : public TObject {
public:
    TUnk_804DC7C4(TObject *parent = NULL);
    virtual ~TUnk_804DC7C4();
    virtual void run_task();
    virtual void render();
    virtual void render_shadows();
    // scene_sora_recon_object when the task was made (name inferred).
    GinjaRenderTarget *recon_object;
    // The TEffIndirectSampler(0x28, 1, tl_05) indirect effect task (name inferred).
    TObject *indirect_effect;
    // Floor point the reflection ray hits and the plane normal (0,1,0)
    // (names inferred from render_shadows / fn_8029E7BC).
    Vec reflect_pos;
    Vec reflect_normal;
};
LAYOUT_ASSERT(TUnk_804DC7C4_size, sizeof(TUnk_804DC7C4) == 0x3C);

#endif
