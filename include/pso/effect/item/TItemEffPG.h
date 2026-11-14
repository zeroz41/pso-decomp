#ifndef PSO_EFFECT_ITEM_TITEMEFFPG_H
#define PSO_EFFECT_ITEM_TITEMEFFPG_H

#include "types.h"
#include "pso/item/TUnk_804E355C.h"

// TItemEffPG's parameters (init_params fills in the defaults).
struct S_8035016C : S_802E451C {
    f32 pad_28;          // copied to TItemEffPG::pad_C4, at most 50
    f32 required_charge; // copied to TItemEffPG::required_charge
    f32 pad_30;          // copied to TItemEffPG::m_c8
    s32 pad_34;          // TUnk_804F1320::spawn_pg_effect: the weapon's second model
    s32 pad_38;
    S_8035016C *init_params();
};

struct TItemEffPG : public TUnk_804E355C {
    TItemEffPG(TObject *parent, S_8035016C *params);
    virtual ~TItemEffPG();
    virtual s32 vfunc_7();
    f32 pad_C4;   // run_task grows body.radius by m_c8 a frame up to it
    f32 m_c8;
    f32 required_charge; // inferred: compared with the player's photon blast charge, then spent
    u32 m_d0;
    u8 *create();
    virtual void run_task();
    static void create(void *arg0, void *arg1);
    static void create(void *parent, void *params, void *count); // makes a TUnk_804F0C08
};

typedef char TItemEffPG_size[sizeof(TItemEffPG) == 0xD4 ? 1 : -1];

extern "C" {
void TItemEffPG__begin_visual_fade(void *p);
u8 *TItemEffPG__visual_ct(u8 *arg0, u8 *arg1, u8 *arg2);
void *__dt__13TUnk_804F0BF0Fv(void *arg0, s16 arg1);
}

#endif
