#ifndef PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMCOMMON_H
#define PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMCOMMON_H

#include "types.h"
#include "pso/player/TUnk_804B08BC.h"

struct TOContainerAncientItemCommon : public TUnk_804B08BC {
    virtual ~TOContainerAncientItemCommon();
    virtual void vfunc_6(s16 *, s32);
    s32 create();
};

typedef char TOContainerAncientItemCommon_size[sizeof(TOContainerAncientItemCommon) == 0x368 ? 1 : -1];

extern "C" {
void *TOContainerAncientItemCommon__ct(void *arg0, void *_w1);
void *__dt__28TOContainerAncientItemCommonFv(void *arg0, s16 arg1);
}

#endif
