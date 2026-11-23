#ifndef PSO_OBJECT_TRAP_TOTRAPCHAINSAWDAMAGE_H
#define PSO_OBJECT_TRAP_TOTRAPCHAINSAWDAMAGE_H

#include "types.h"
#include "pso/object/trap/TOTrapChainSaw.h"

struct TOTrapChainSawDamage : public TOTrapChainSaw {
    TOTrapChainSawDamage(TObject *parent, void *set_data);
    virtual ~TOTrapChainSawDamage();
    virtual void vfunc_16();
    virtual void vfunc_18(TObjPlayer *player);
    virtual void update_state();
    virtual void decode_params();
    virtual void vfunc_25();
    virtual void vfunc_14();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    u32 m_f8;
    u8 _padFC[0x4];
    u32 m_100;
    u32 m_104;
    u32 m_108;
    void set_damage(s32 v);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOTrapChainSawDamage_size, sizeof(TOTrapChainSawDamage) == 0x10C);
#endif
