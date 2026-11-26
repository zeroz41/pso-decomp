#ifndef PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMRARE_H
#define PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMRARE_H

#include "types.h"
#include "pso/object/container/TOContainerAncientItem.h"

struct TOContainerAncientItemRare : public TOContainerAncientItem {
    TOContainerAncientItemRare(void *set_data);
    virtual ~TOContainerAncientItemRare();
    virtual void apply_saved_state(s16 *, s32);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOContainerAncientItemRare_size, sizeof(TOContainerAncientItemRare) == 0x368);


#endif
