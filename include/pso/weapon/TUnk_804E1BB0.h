#ifndef PSO_WEAPON_TUNK_804E1BB0_H
#define PSO_WEAPON_TUNK_804E1BB0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804E1BB0 : public TItemWeapon {
public:
    // The constructor, still written by hand: the vtable is lbl_804E1BB0.
    void *init_state_513(TObject *parent, u8 *item);
    static TItem *create(u8 *item); // weapon_factory_table entry
    virtual ~TUnk_804E1BB0();
    virtual void reserved_53();
};

#endif
