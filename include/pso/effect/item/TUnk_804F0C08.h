#ifndef PSO_EFFECT_ITEM_TUNK_804F0C08_H
#define PSO_EFFECT_ITEM_TUNK_804F0C08_H
#include "types.h"
#include "pso/effect/item/TItemEffPG.h"

class TUnk_804F0C08 : public TItemEffPG {
public:
    virtual ~TUnk_804F0C08();
    void *initialize(void *, void *, void *);
    void *destroy(s16);
    virtual s32 vfunc_7();
    u8 unk_D4[0x4];
};
typedef char TUnk_804F0C08_size[sizeof(TUnk_804F0C08) == 0xD8 ? 1 : -1];

#endif
