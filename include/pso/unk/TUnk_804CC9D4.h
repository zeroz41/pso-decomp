#ifndef PSO_UNK_TUNK_804CC9D4_H
#define PSO_UNK_TUNK_804CC9D4_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

// The selectable field of a telepipe (TTecLuker) or of a warp (TObjWarpBase): a 0.01 sphere the
// cursor offers as a telepipe action, latched once a player interacts with it.
class TUnk_804CC9D4 : public TObjCollidable {
public:
    TUnk_804CC9D4(Vec *pos, TObject *parent, s32 always_selectable);
    virtual ~TUnk_804CC9D4();
    virtual void run_task();
    virtual void interact(u16 client);
    // Inferred names: run_task offers the cursor action without the gathered-players check
    // when this is set (warps pass 1, telepipes 0); interact sets the latch TTecLuker polls.
    s32 always_selectable;
    s32 interacted;
};
LAYOUT_ASSERT(TUnk_804CC9D4_size, sizeof(TUnk_804CC9D4) == 0xB4);

#endif
