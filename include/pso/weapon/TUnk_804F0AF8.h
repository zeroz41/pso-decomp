#ifndef PSO_WEAPON_TUNK_804F0AF8_H
#define PSO_WEAPON_TUNK_804F0AF8_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804F0AF8 : public TItemWeapon {
public:
    virtual ~TUnk_804F0AF8();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void reserved_53();
    virtual void update_attack();
    TUnk_804F0AF8(TObject *parent, u8 *item);
    static TItem *create(u8 *item); // weapon_factory_table entry
    s32 spin_angle;  // each turned toward a target angle by update_idle/update_attack
    s32 second_spin_angle;
};

#endif
