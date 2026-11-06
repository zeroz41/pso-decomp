#ifndef PSO_OBJECT_TRAP_TOTRAPCHAINSAWDAMAGE_H
#define PSO_OBJECT_TRAP_TOTRAPCHAINSAWDAMAGE_H

#include "types.h"
#include "pso/object/trap/TOTrapChainSaw.h"

struct TOTrapChainSawDamage : public TOTrapChainSaw {
    virtual ~TOTrapChainSawDamage();
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
    void *create();
};

typedef char TOTrapChainSawDamage_size[sizeof(TOTrapChainSawDamage) == 0x10C ? 1 : -1];
#endif
