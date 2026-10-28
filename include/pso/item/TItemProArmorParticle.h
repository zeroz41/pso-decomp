#ifndef PSO_ITEM_TITEMPROARMORPARTICLE_H
#define PSO_ITEM_TITEMPROARMORPARTICLE_H

#include "types.h"
#include "pso/item/TItemProArmor.h"

struct TItemProArmorParticle : public TItemProArmor {
    virtual ~TItemProArmorParticle();
    virtual void update_equipped();
    virtual void vfunc_45();
    virtual void vfunc_44();
    u32 m_198;
    u32 m_19c;
    u32 m_1a0;
    static void create(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
};

typedef char TItemProArmorParticle_size[sizeof(TItemProArmorParticle) == 0x1A4 ? 1 : -1];
#endif
