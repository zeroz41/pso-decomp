#ifndef PSO_ENEMY_TOBJENEME3SINOWZOAREAL_H
#define PSO_ENEMY_TOBJENEME3SINOWZOAREAL_H

#include "types.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"

struct TObjEneMe3SinowZoaReal : public TObjEneMe3SinowZoa {
    virtual ~TObjEneMe3SinowZoaReal();
    void init_enemy();
    virtual void vfunc_107();
    virtual void vfunc_111();
    void vfunc_63();
    void vfunc_62();
    static void *create_instance(void *arg0);
    u8 unk_430[0x2C];
};

typedef char TObjEneMe3SinowZoaReal_size[sizeof(TObjEneMe3SinowZoaReal) == 0x45C ? 1 : -1];

extern "C" {
u8 *TObjEneMe3SinowZoaReal__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__22TObjEneMe3SinowZoaRealFv(void *arg0, s16 arg1);
}

#endif
