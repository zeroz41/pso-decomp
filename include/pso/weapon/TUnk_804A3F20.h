#ifndef PSO_WEAPON_TUNK_804A3F20_H
#define PSO_WEAPON_TUNK_804A3F20_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TUnk_804A3F20 : public TUnk_804A4948 {
public:
    TUnk_804A3F20(TObject *parent, u8 *item);
    virtual ~TUnk_804A3F20();
    virtual void reserved_53();
    virtual void emit_marker_effects();
    // The two points emit_marker_effects shoots from (launch_shot origins);
    // reserved_53 fills them (draw_status_icons).
    WeaponVector shot_origins[2];
};

#endif
