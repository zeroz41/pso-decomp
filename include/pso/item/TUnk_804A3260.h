#ifndef PSO_ITEM_TUNK_804A3260_H
#define PSO_ITEM_TUNK_804A3260_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A3260 : public TItemWeapon {
public:
    TUnk_804A3260(s32 parent, u8 *item);
    virtual ~TUnk_804A3260();
    virtual void vfunc_60();
    virtual void reserved_53();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    f32 muzzle[2][3];
    s32 effectJoint;
    s32 effectAngle;
    s32 effectScaleJoint;
    s32 effectFrame;
};

#endif
