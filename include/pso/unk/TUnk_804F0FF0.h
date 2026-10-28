#ifndef PSO_UNK_TUNK_804F0FF0_H
#define PSO_UNK_TUNK_804F0FF0_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_804F0FF0 : public TItemObject {
public:
    TUnk_804F0FF0(TObject *parent, u8 *item);
    virtual ~TUnk_804F0FF0();
    virtual void apply_use_effect();
    static TUnk_804F0FF0 *create(u8 *item);
};

#endif
