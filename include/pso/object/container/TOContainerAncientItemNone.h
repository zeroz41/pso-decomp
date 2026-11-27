#ifndef PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMNONE_H
#define PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMNONE_H

#include "types.h"
#include "pso/object/container/TOContainerAncientItemRare.h"

struct QuestObjectEntry;

struct TOContainerAncientItemNone : public TOContainerAncientItemRare {
    TOContainerAncientItemNone(ObjectSetData *set_data);
    virtual ~TOContainerAncientItemNone();
    virtual void apply_saved_state(QuestObjectEntry *, s32);
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TOContainerAncientItemNone_size, sizeof(TOContainerAncientItemNone) == 0x368);


#endif
