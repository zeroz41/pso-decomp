#ifndef PSO_EFFECT_ITEM_TUNK_804F0C08_H
#define PSO_EFFECT_ITEM_TUNK_804F0C08_H
#include "types.h"
#include "pso/effect/item/TItemEffPG.h"

class TUnk_804F0C08 : public TItemEffPG {
public:
    TUnk_804F0C08(TObject *parent, S_8035016C *params, s32 count);
    virtual ~TUnk_804F0C08();
    virtual s32 vfunc_7();
    s32 pad_D4; // vfunc_7 counts it down and fails at 0
};
typedef char TUnk_804F0C08_size[sizeof(TUnk_804F0C08) == 0xD8 ? 1 : -1];

#endif
