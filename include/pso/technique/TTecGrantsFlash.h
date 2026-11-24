#ifndef PSO_TECHNIQUE_TTECGRANTSFLASH_H
#define PSO_TECHNIQUE_TTECGRANTSFLASH_H
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"

// The flash TTecGrantsEffect spawns every fifth frame: a ring-wave sprite that
// follows its owner entity, grows towards 1.2 and fades out.
// inferred names: owner_id, position, scale, color, frame, scale_rate.
class TTecGrantsFlash : public TObject {
public:
    TTecGrantsFlash(s32 owner_id, TObject *parent, Vec *pos, f32 start_scale);
    virtual ~TTecGrantsFlash();
    virtual void render();
    virtual void run_task();
    u16 owner_id;     // find_entity_by_id'd each frame; 0xFFFF = no owner, use pos
    Vec position;     // the owner's position, copied each frame
    Vec scale;        // approaches 1.2 at scale_rate
    NJS_ARGB color;   // fades to zero; the flash ends once alpha reaches 0
    s32 frame;        // ring-wave texture frame, cycles 0..6
    f32 scale_rate;
};
LAYOUT_ASSERT(TTecGrantsFlash_size, sizeof(TTecGrantsFlash) == 0x50);

#endif
