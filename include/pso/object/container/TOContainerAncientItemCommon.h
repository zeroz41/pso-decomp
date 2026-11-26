#ifndef PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMCOMMON_H
#define PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMCOMMON_H

#include "types.h"
#include "pso/object/container/TOContainerAncientItem.h"

struct TOContainerAncientItemCommon : public TOContainerAncientItem {
    TOContainerAncientItemCommon(void *set_data);
    virtual ~TOContainerAncientItemCommon();
    virtual void apply_saved_state(s16 *, s32);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOContainerAncientItemCommon_size, sizeof(TOContainerAncientItemCommon) == 0x368);


#endif
