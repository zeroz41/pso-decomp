#ifndef PSO_MISC_TOKEYANCIENT02_H
#define PSO_MISC_TOKEYANCIENT02_H

#include "types.h"
#include "pso/misc/TOKey.h"

struct TOKeyAncient02 : public TOKey {
    virtual ~TOKeyAncient02();
    virtual void update_switch_on();
    virtual void update_switch_off();
    virtual void vfunc_25();
    void render();
    static void *create(void *arg0);
    static void free_static();
    static void load_resources();
    s32 m_e8;
    s32 m_ec;
};

typedef char TOKeyAncient02_size[sizeof(TOKeyAncient02) == 0xF0 ? 1 : -1];
#endif
