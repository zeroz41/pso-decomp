#ifndef PSO_ITEM_TUNK_804A535C_H
#define PSO_ITEM_TUNK_804A535C_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A535C : public TItemWeapon {
public:
    virtual ~TUnk_804A535C();
    virtual void vfunc_60();
    virtual void reserved_53();
    virtual void emit_marker_effects();
    void *init_trade_action();
};

#endif
