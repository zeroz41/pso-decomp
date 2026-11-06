#ifndef PSO_ENEMY_SINOWZOA_TOBJENEME3SINOWZOAREAL_H
#define PSO_ENEMY_SINOWZOA_TOBJENEME3SINOWZOAREAL_H

#include "types.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"

struct TObjEneMe3SinowZoaReal : public TObjEneMe3SinowZoa {
    TObjEneMe3SinowZoaReal(TObject *parent, void *set_data);
    virtual ~TObjEneMe3SinowZoaReal();
    void init_enemy();
    virtual void vfunc_107();
    virtual void vfunc_111();
    void vfunc_63();
    void vfunc_62();
    static void *create_instance(void *arg0);
};

typedef char TObjEneMe3SinowZoaReal_size[sizeof(TObjEneMe3SinowZoaReal) == 0x45C ? 1 : -1];


#endif
