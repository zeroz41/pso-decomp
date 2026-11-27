#ifndef PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMCOMMON_H
#define PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMCOMMON_H

#include "types.h"
#include "pso/object/container/TOContainerAncientItem.h"

struct QuestObjectEntry;

struct TOContainerAncientItemCommon : public TOContainerAncientItem {
    TOContainerAncientItemCommon(ObjectSetData *set_data);
    virtual ~TOContainerAncientItemCommon();
    virtual void apply_saved_state(QuestObjectEntry *, s32);
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TOContainerAncientItemCommon_size, sizeof(TOContainerAncientItemCommon) == 0x368);


#endif
