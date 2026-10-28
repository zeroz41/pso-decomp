#ifndef PSO_ITEM_TUNK_804F112C_H
#define PSO_ITEM_TUNK_804F112C_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_804F112C : public TItemObject {
public:
    TUnk_804F112C(TObject *parent, u8 *item);
    // Declared first: its TU (0x803531FC, not matched yet) emits the vtable,
    // not the files holding the destructor and constructor.
    virtual void apply_use_effect();
    virtual ~TUnk_804F112C();
    static TUnk_804F112C *create(u8 *item);
};

#endif
