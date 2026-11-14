#ifndef PSO_WEAPON_TUNK_804F26E0_H
#define PSO_WEAPON_TUNK_804F26E0_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TUnk_804F26E0 : public TUnk_804A4948 {
public:
    TUnk_804F26E0(TObject *parent, u8 *item);
    virtual ~TUnk_804F26E0();
    virtual void vfunc_57();  // equip hook: sets the owner's EVP
    virtual void vfunc_58();
    virtual void vfunc_62();  // marker effect at the owner's knuckle joint
};

#endif
