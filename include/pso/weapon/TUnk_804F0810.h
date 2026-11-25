#ifndef PSO_WEAPON_TUNK_804F0810_H
#define PSO_WEAPON_TUNK_804F0810_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804F0810 : public TItemWeapon {
public:
    virtual ~TUnk_804F0810();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    virtual void draw_held_model();
    virtual void emit_marker_effects();
    TUnk_804F0810(TObject *parent, u8 *item);
    static TItem *create(u8 *item); // weapon_factory_table entry
    s32 spin_angle;  // turned toward a target angle by update_idle/update_attack
};

#endif
