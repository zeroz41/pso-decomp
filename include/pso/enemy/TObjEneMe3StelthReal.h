#ifndef PSO_ENEMY_TOBJENEME3STELTHREAL_H
#define PSO_ENEMY_TOBJENEME3STELTHREAL_H

#include "types.h"
#include "pso/enemy/TObjEneMe3Stelth.h"

struct TObjEneMe3StelthReal : public TObjEneMe3Stelth {
    virtual ~TObjEneMe3StelthReal();
    virtual void vfunc_107();
    virtual void vfunc_111();
    void init_common();
    void vfunc_63();
    void vfunc_62();
    static void *create(void *arg0);
    u8 unk_420[0x2C];
};

typedef char TObjEneMe3StelthReal_size[sizeof(TObjEneMe3StelthReal) == 0x44C ? 1 : -1];
#endif
