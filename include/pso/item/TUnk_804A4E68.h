#ifndef PSO_ITEM_TUNK_804A4E68_H
#define PSO_ITEM_TUNK_804A4E68_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A4E68 : public TItemWeapon {
public:
    virtual ~TUnk_804A4E68();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    void *init_vtable_and_clear_field1f8();
    u8 unk_1F8[0x4];
};

#endif
