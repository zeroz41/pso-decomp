#ifndef PSO_ITEM_TUNK_804A403C_H
#define PSO_ITEM_TUNK_804A403C_H
#include "types.h"
#include "pso/unk/TUnk_804A4948.h"
#include "pso/system/FlagWord.h"

class TUnk_804A403C : public TUnk_804A4948 {
public:
    TUnk_804A403C(TObject *parent, u8 *item);
    virtual ~TUnk_804A403C();
    virtual void vfunc_60();
    virtual void reserved_53();
    virtual void emit_marker_effects();
    FlagWord flags;                 // 1: drawing the second barrel, 2: ring out, 4: firing
    WeaponVector shot_origins[2];   // get_joint_position(1) per barrel, launch_shot origins
};

extern "C" {
// The weapon's hit callback (hit_callback).
void TObjPlayer__sub_80128A74(s32 a, u32 b, s32 c, s32 d);
}

#endif
