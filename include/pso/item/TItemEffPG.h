#ifndef PSO_ITEM_TITEMEFFPG_H
#define PSO_ITEM_TITEMEFFPG_H

#include "types.h"
#include "pso/item/TUnk_804E355C.h"

struct TItemEffPG : public TUnk_804E355C {
    virtual ~TItemEffPG();
    virtual s32 vfunc_7();
    u8 unk_C4[0x4];
    f32 m_c8;
    f32 required_charge; // inferred: compared with the player's photon blast charge, then spent
    u32 m_d0;
    u8 *create();
    virtual void run_task();
    static void create(void *arg0, void *arg1);
    void*init_params();
};

typedef char TItemEffPG_size[sizeof(TItemEffPG) == 0xD4 ? 1 : -1];

extern "C" {
void TItemEffPG__begin_visual_fade(void *p);
u8 *TItemEffPG__visual_ct(u8 *arg0, u8 *arg1, u8 *arg2);
void *__dt__13TUnk_804F0BF0Fv(void *arg0, s16 arg1);
}

#endif
