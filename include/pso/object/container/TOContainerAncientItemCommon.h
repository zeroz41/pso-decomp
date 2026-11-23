#ifndef PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMCOMMON_H
#define PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMCOMMON_H

#include "types.h"
#include "pso/player/TUnk_804B08BC.h"

struct TOContainerAncientItemCommon : public TUnk_804B08BC {
    TOContainerAncientItemCommon(void *set_data);
    virtual ~TOContainerAncientItemCommon();
    virtual void vfunc_6(s16 *, s32);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOContainerAncientItemCommon_size, sizeof(TOContainerAncientItemCommon) == 0x368);


#endif
