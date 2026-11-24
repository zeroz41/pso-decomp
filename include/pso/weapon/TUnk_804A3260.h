#ifndef PSO_WEAPON_TUNK_804A3260_H
#define PSO_WEAPON_TUNK_804A3260_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A3260 : public TItemWeapon {
public:
    TUnk_804A3260(saddr parent, u8 *item);
    virtual ~TUnk_804A3260();
    virtual void transform_model_node();
    virtual void draw_held_model();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    Vec muzzle[2];
    s32 effectJoint;
    s32 effectAngle;
    s32 effectScaleJoint;
    s32 effectFrame;
};

#endif
