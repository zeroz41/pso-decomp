#ifndef PSO_WEAPON_TUNK_804E20FC_H
#define PSO_WEAPON_TUNK_804E20FC_H
#include "types.h"
#include "pso/weapon/TUnk_804E23F0.h"

class TUnk_804E20FC : public TUnk_804E23F0 {
public:
    TUnk_804E20FC(TObject *parent, u8 *item);
    virtual ~TUnk_804E20FC();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
};

#endif
