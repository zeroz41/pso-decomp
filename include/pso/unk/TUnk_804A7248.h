#ifndef PSO_UNK_TUNK_804A7248_H
#define PSO_UNK_TUNK_804A7248_H

#include "types.h"
#include "pso/player/TPlyGuildCardTag.h"

// Vtable 0x804A7248 {0, 0, dtor}. TLockOnCursor builds one at +0x520.
class TUnk_804A7248 : public gc_tag {
public:
    s32 unk_4;

    TUnk_804A7248();
    virtual ~TUnk_804A7248();
};

LAYOUT_ASSERT(TUnk_804A7248_size, sizeof(TUnk_804A7248) == 0xC);

#endif
