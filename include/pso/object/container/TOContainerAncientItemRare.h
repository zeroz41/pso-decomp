#ifndef PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMRARE_H
#define PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMRARE_H

#include "types.h"
#include "pso/player/TUnk_804B08BC.h"

struct TOContainerAncientItemRare : public TUnk_804B08BC {
    TOContainerAncientItemRare(void *set_data);
    virtual ~TOContainerAncientItemRare();
    virtual void vfunc_6(s16 *, s32);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOContainerAncientItemRare_size, sizeof(TOContainerAncientItemRare) == 0x368);


#endif
