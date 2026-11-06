#ifndef PSO_WEAPON_TUNK_804A3B20_H
#define PSO_WEAPON_TUNK_804A3B20_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TUnk_804A3B20 : public TUnk_804A4948 {
public:
    TUnk_804A3B20(TObject *parent, u8 *item);
    virtual ~TUnk_804A3B20();
    virtual void vfunc_62();
};

#endif
