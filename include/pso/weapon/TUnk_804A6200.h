#ifndef PSO_WEAPON_TUNK_804A6200_H
#define PSO_WEAPON_TUNK_804A6200_H
#include "pso/weapon/WeaponCanopyScale.h"
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Madam's Parasol weapon class (vtable 0x804A6200): the canopy opens while
// idle and closes during an attack; on_equipped starts a regeneration timer.
class TUnk_804A6200 : public TItemWeapon {
public:
    virtual void vfunc_60();
    virtual void on_equipped();
    virtual void update_idle();
    virtual void update_attack();
    virtual ~TUnk_804A6200();
    TUnk_804A6200(TObject *parent, u8 *item);
    WeaponCanopyScale scale;  // canopy scale (scale_current_matrix)
};

extern "C" TItem *TObjPlayer__sub_8012F298(u8 *item);

#endif
