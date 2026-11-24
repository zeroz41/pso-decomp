#ifndef PSO_WEAPON_TUNK_804A4748_H
#define PSO_WEAPON_TUNK_804A4748_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TUnk_804A4748 : public TUnk_804A4948 {
public:
    TUnk_804A4748(TObject *parent, u8 *item);
    virtual ~TUnk_804A4748();
    virtual void draw_held_model();
    virtual void emit_marker_effects();
    // The two points emit_marker_effects shoots from (launch_shot origins);
    // draw_held_model fills them (draw_status_icons).
    Vec shot_origins[2];
};


#endif
