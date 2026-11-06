#ifndef PSO_WEAPON_TUNK_804A3E20_H
#define PSO_WEAPON_TUNK_804A3E20_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

// The S-rank Harisen weapon class (vtable 0x804A3E20), the S-rank form of
// TUnk_804A2E80: vfunc_62 flattens the fan, update_weapon grows it back.
class TUnk_804A3E20 : public TUnk_804A4948 {
public:
    virtual void vfunc_60();
    virtual void vfunc_62();
    virtual void update_weapon();
    virtual ~TUnk_804A3E20();
    TUnk_804A3E20(TObject *parent, u8 *item);
    WeaponVector scale;  // model scale (scale_current_matrix); y is animated
};

#endif
