#ifndef PSO_OBJECT_TRAP_TOTRAPCHAINSAWKEY_H
#define PSO_OBJECT_TRAP_TOTRAPCHAINSAWKEY_H

#include "types.h"
#include "pso/object/trap/TOTrapChainSaw.h"

struct TOTrapChainSawKey : public TOTrapChainSaw {
    virtual ~TOTrapChainSawKey();
    virtual void update_state();
    virtual void decode_params();
    virtual void vfunc_16();
    virtual void vfunc_18();
    virtual void vfunc_14();
    virtual void vfunc_25();
    virtual int check_player_contact();
    virtual void vfunc_27();
    u32 m_f8;
    u32 m_fc;
    u32 m_100;
    void *create();
    static u8 *get_motion(s32 arg0);
    static u8 *get_model(s32 arg0);
    u8 unk_104[0x8];
};

typedef char TOTrapChainSawKey_size[sizeof(TOTrapChainSawKey) == 0x10C ? 1 : -1];
#endif
