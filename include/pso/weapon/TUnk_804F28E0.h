#ifndef PSO_WEAPON_TUNK_804F28E0_H
#define PSO_WEAPON_TUNK_804F28E0_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TUnk_804F28E0 : public TUnk_804A4948 {
public:
    TUnk_804F28E0(TObject *parent, u8 *item);
    static TItem *create(u8 *item); // weapon_factory_table entry
    virtual ~TUnk_804F28E0();
    virtual void update_idle();
    virtual void update_attack();
    virtual void emit_marker_effects();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
    virtual void vfunc_60();
    f32 muzzle_offset;
};

#endif
