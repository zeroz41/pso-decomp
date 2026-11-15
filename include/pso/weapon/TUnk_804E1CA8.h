#ifndef PSO_WEAPON_TUNK_804E1CA8_H
#define PSO_WEAPON_TUNK_804E1CA8_H
#include "types.h"
#include "pso/weapon/TUnk_804E23F0.h"

class TUnk_804E1CA8 : public TUnk_804E23F0 {
public:
    TUnk_804E1CA8(TObject *parent, u8 *item);
    virtual ~TUnk_804E1CA8();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
};

#endif
