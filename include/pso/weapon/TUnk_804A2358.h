#ifndef PSO_WEAPON_TUNK_804A2358_H
#define PSO_WEAPON_TUNK_804A2358_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A2358 : public TItemWeapon {
public:
    TUnk_804A2358(TObject *parent, u8 *item);
    virtual ~TUnk_804A2358();
    virtual void vfunc_57();
    virtual void reserved_53();
    virtual void emit_marker_effects();
};

#endif
