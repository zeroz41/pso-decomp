#ifndef PSO_UNK_TUNK_804CC870_H
#define PSO_UNK_TUNK_804CC870_H
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"

// The flash TUnk_804CC888 spawns every fifth frame: a ring-wave sprite that
// follows its owner entity, grows towards 1.2 and fades out.
// inferred names: owner_id, position, scale, color, frame, scale_rate.
class TUnk_804CC870 : public TObject {
public:
    TUnk_804CC870(s32 owner_id, TObject *parent, Vec *pos, f32 start_scale);
    virtual ~TUnk_804CC870();
    virtual void render();
    virtual void run_task();
    u16 owner_id;     // find_entity_by_id'd each frame; 0xFFFF = no owner, use pos
    Vec position;     // the owner's position, copied each frame
    Vec scale;        // approaches 1.2 at scale_rate
    NJS_ARGB color;   // fades to zero; the flash ends once alpha reaches 0
    s32 frame;        // ring-wave texture frame, cycles 0..6
    f32 scale_rate;
};
LAYOUT_ASSERT(TUnk_804CC870_size, sizeof(TUnk_804CC870) == 0x50);

#endif
