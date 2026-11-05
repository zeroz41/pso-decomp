#ifndef PSO_ITEM_TUNK_804A3738_H
#define PSO_ITEM_TUNK_804A3738_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A3738 : public TItemWeapon {
public:
    virtual ~TUnk_804A3738();
    void *init_vtable_804A3738();
};

extern "C" {
void *__dt__13TUnk_804A3738Fv(void *arg0, s16 arg1);
}

#endif
