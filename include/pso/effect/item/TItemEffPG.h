#ifndef PSO_EFFECT_ITEM_TITEMEFFPG_H
#define PSO_EFFECT_ITEM_TITEMEFFPG_H

#include <stddef.h>
#include "types.h"
#include "pso/item/TUnk_804E355C.h"

struct GinjaTextureList;
struct NJS_OBJECT;
class TUnk_804F0BF0;

// TItemEffPG's parameters (init_params fills in the defaults).
struct S_8035016C : S_802E451C {
    f32 pad_28;          // copied to TItemEffPG::pad_C4, at most 50
    f32 required_charge; // copied to TItemEffPG::required_charge
    f32 pad_30;          // copied to TItemEffPG::m_c8
    NJS_OBJECT *pad_34;  // the weapon's second model
    GinjaTextureList *pad_38;
    S_8035016C *init_params();
};

struct TItemEffPG : public TUnk_804E355C {
    TItemEffPG(TObject *parent, S_8035016C *params);
    virtual ~TItemEffPG();
    virtual s32 vfunc_7();
    f32 pad_C4;   // run_task grows body.radius by m_c8 a frame up to it
    f32 m_c8;
    f32 required_charge; // inferred: compared with the player's photon blast charge, then spent
    TUnk_804F0BF0 *m_d0;
    virtual void run_task();
    static void create(TObject *parent, S_8035016C *params);
    static void create(TObject *parent, S_8035016C *params, s32 count); // makes a TUnk_804F0C08
};

LAYOUT_ASSERT(S_8035016C_size, sizeof(S_8035016C) == 0x3C);
LAYOUT_ASSERT(TItemEffPG_charge_offset, offsetof(TItemEffPG, required_charge) == 0xCC);
LAYOUT_ASSERT(TItemEffPG_visual_offset, offsetof(TItemEffPG, m_d0) == 0xD0);
LAYOUT_ASSERT(TItemEffPG_size, sizeof(TItemEffPG) == 0xD4);

extern "C" {
TItem *TObjPlayer__sub_8034F1AC(u8 *item);
void TItemEffPG__begin_visual_fade(TUnk_804F0BF0 *visual);
}

#endif
