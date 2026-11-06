#ifndef PSO_PLAYER_TUNK_804F27E0_H
#define PSO_PLAYER_TUNK_804F27E0_H
#include "types.h"
#include "pso/unk/TUnk_804A4948.h"

class TUnk_804F27E0 : public TUnk_804A4948 {
public:
    TUnk_804F27E0(TObject *parent, u8 *item);
    virtual ~TUnk_804F27E0();
    virtual void vfunc_60();
    virtual void update_weapon();
    virtual void reserved_53();
    virtual void emit_marker_effects();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
    s32 pad_1fc;
};

#endif
