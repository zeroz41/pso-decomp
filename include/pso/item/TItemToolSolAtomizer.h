#ifndef PSO_ITEM_TITEMTOOLSOLATOMIZER_H
#define PSO_ITEM_TITEMTOOLSOLATOMIZER_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TItemToolSolAtomizer : public TItemObject {
public:
    TItemToolSolAtomizer(TObject *parent, u8 *item);
    virtual ~TItemToolSolAtomizer();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
};


#endif
