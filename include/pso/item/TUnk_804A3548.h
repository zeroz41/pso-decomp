#ifndef PSO_ITEM_TUNK_804A3548_H
#define PSO_ITEM_TUNK_804A3548_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A3548 : public TItemWeapon {
public:
    virtual ~TUnk_804A3548();
    void *init_vtable_804A3548();
};

extern "C" {
void *__dt__13TUnk_804A3548Fv(void *arg0, s16 arg1);
}

#endif
