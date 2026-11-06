#ifndef PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMRARE_H
#define PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMRARE_H

#include "types.h"
#include "pso/player/TUnk_804B08BC.h"

struct TOContainerAncientItemRare : public TUnk_804B08BC {
    virtual ~TOContainerAncientItemRare();
    virtual void vfunc_6(s16 *, s32);
};

typedef char TOContainerAncientItemRare_size[sizeof(TOContainerAncientItemRare) == 0x368 ? 1 : -1];

extern "C" {
void *__dt__26TOContainerAncientItemRareFv(void *arg0, s16 arg1);
}

#endif
