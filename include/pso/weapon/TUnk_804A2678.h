#ifndef PSO_WEAPON_TUNK_804A2678_H
#define PSO_WEAPON_TUNK_804A2678_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A2678 : public TItemWeapon {
public:
    TUnk_804A2678(TObject *parent, u8 *item);
    virtual ~TUnk_804A2678();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    s32 floor_area; // floor area update_weapon last spawned its follow effects in
};

#endif
