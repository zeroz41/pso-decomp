#ifndef PSO_UNK_LOCKONPALETTEOVERRIDE_H
#define PSO_UNK_LOCKONPALETTEOVERRIDE_H

#include "types.h"
#include "pso/player/TPlyGuildCardTag.h"

// Vtable {0, 0, dtor}. TLockOnCursor builds one at +0x520.
class LockOnPaletteOverride : public gc_tag {
public:
    s32 active; // is_channel_active() as of the lock-on cursor's last run_task

    LockOnPaletteOverride();
    virtual ~LockOnPaletteOverride();
    void clear_active();
    void set_active();
    s32 is_active();
};

LAYOUT_ASSERT(LockOnPaletteOverride_size, sizeof(LockOnPaletteOverride) == 0xC);

#endif
