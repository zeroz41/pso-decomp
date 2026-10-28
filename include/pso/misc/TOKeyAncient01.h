#ifndef PSO_MISC_TOKEYANCIENT01_H
#define PSO_MISC_TOKEYANCIENT01_H

#include "types.h"
#include "pso/misc/TOKey.h"

struct TOKeyAncient01 : public TOKey {
    virtual ~TOKeyAncient01();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_25();
    void render();
    static void *create(void *arg0);
    static void free_shared_resources();
    static void load_resources();
    u8 unk_D8[0x10];
};

typedef char TOKeyAncient01_size[sizeof(TOKeyAncient01) == 0xE8 ? 1 : -1];
#endif
