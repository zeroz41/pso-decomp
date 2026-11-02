#ifndef PSO_BOSS_TUNK_804ECDC0_H
#define PSO_BOSS_TUNK_804ECDC0_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804ECDC0 : public TItemWeapon {
public:
    virtual ~TUnk_804ECDC0();
    virtual void emit_marker_effects();
    void *set_vtable_mode2_alt(s32, void *);
};

#endif
