#ifndef PSO_UNK_TUNK_804F0C48_H
#define PSO_UNK_TUNK_804F0C48_H
#include "types.h"
#include "pso/item/TItemObject.h"

// Turns into one of the items its ItemPMT entry lists, picked at random.
class TUnk_804F0C48 : public TItemObject {
public:
    TUnk_804F0C48(TObject *parent, u8 *item);
    virtual ~TUnk_804F0C48();
    virtual void apply_use_effect();
    static TUnk_804F0C48 *create(u8 *item);
};

#endif
