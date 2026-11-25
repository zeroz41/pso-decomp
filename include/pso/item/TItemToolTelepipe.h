#ifndef PSO_ITEM_TITEMTOOLTELEPIPE_H
#define PSO_ITEM_TITEMTOOLTELEPIPE_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TItemToolTelepipe : public TItemObject {
public:
    TItemToolTelepipe(TObject *parent, u8 *item);
    virtual ~TItemToolTelepipe();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
};


#endif
