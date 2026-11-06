#include "types.h"
#include "pso/system/vector.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

extern "C" {

void subtract_vector(void *, void *);

struct VOff_802F4480_arg0 { char pad_0[0x410]; char f_410[1]; char pad_411[0xB]; char f_41C[1]; };

void TBoss8Dragon::copy_vectors() {
    struct VOff_802F4480_arg0 *self = (struct VOff_802F4480_arg0 *)this;
    VecCopy((Vec *)self->f_410, (const Vec *)((char *)this + 1004));
    VecCopy((Vec *)self->f_41C, (const Vec *)((char *)this + 1016));
    subtract_vector(self->f_41C, self->f_410);
    VecCopy((Vec *)((char *)this + 1064), (const Vec *)((char *)this + 1028));
}

}
