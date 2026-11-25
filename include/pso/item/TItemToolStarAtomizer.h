#ifndef PSO_ITEM_TITEMTOOLSTARATOMIZER_H
#define PSO_ITEM_TITEMTOOLSTARATOMIZER_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TItemToolStarAtomizer : public TItemObject {
public:
    TItemToolStarAtomizer(TObject *parent, u8 *item);
    virtual ~TItemToolStarAtomizer();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
};


#endif
