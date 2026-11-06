#ifndef PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMNONE_H
#define PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMNONE_H

#include "types.h"
#include "pso/object/container/TOContainerAncientItemRare.h"

struct TOContainerAncientItemNone : public TOContainerAncientItemRare {
    virtual ~TOContainerAncientItemNone();
    virtual void vfunc_6(s16 *, s32);
    static void *create(void *arg0);
};

typedef char TOContainerAncientItemNone_size[sizeof(TOContainerAncientItemNone) == 0x368 ? 1 : -1];

extern "C" {
void *__dt__26TOContainerAncientItemNoneFv(void *arg0, s16 arg1);
}

#endif
