#ifndef PSO_MISC_TOKEYGENERICSW_H
#define PSO_MISC_TOKEYGENERICSW_H

#include "types.h"
#include "pso/misc/TOKey.h"

struct TOKeyGenericSw : public TOKey {
    virtual ~TOKeyGenericSw();
    virtual void update_switch_on();
    virtual void update_switch_off();
    virtual void vfunc_25();
    void render();
    static void *create(void *arg0);
    static void free_shared_resources();
    static void load_resources();
    u8 m_e8;
    u8 unk_E9[0x3];
    s32 m_ec;
    u8 unk_F0[0x4];
    s32 m_f4;
    u8 unk_F8[0x4];
};

typedef char TOKeyGenericSw_size[sizeof(TOKeyGenericSw) == 0xFC ? 1 : -1];
#endif
