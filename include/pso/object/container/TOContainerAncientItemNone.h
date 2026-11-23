#ifndef PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMNONE_H
#define PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMNONE_H

#include "types.h"
#include "pso/object/container/TOContainerAncientItemRare.h"

struct TOContainerAncientItemNone : public TOContainerAncientItemRare {
    TOContainerAncientItemNone(void *set_data);
    virtual ~TOContainerAncientItemNone();
    virtual void vfunc_6(s16 *, s32);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOContainerAncientItemNone_size, sizeof(TOContainerAncientItemNone) == 0x368);


#endif
