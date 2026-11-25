#ifndef PSO_UNK_TUNK_804A7248_H
#define PSO_UNK_TUNK_804A7248_H

#include "types.h"
#include "pso/player/TPlyGuildCardTag.h"

// Vtable 0x804A7248 {0, 0, dtor}. TLockOnCursor builds one at +0x520.
class LockOnPaletteOverride : public gc_tag {
public:
    s32 unk_4;

    LockOnPaletteOverride();
    virtual ~LockOnPaletteOverride();
};

LAYOUT_ASSERT(LockOnPaletteOverride_size, sizeof(LockOnPaletteOverride) == 0xC);

#endif
