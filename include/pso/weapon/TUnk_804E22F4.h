#ifndef PSO_WEAPON_TUNK_804E22F4_H
#define PSO_WEAPON_TUNK_804E22F4_H
#include "types.h"
#include "pso/weapon/TUnk_804E23F0.h"

class TUnk_804E22F4 : public TUnk_804E23F0 {
public:
    TUnk_804E22F4(TObject *parent, u8 *item);
    virtual ~TUnk_804E22F4();
    virtual void vfunc_62(Vec *pos);
};

#endif
