#ifndef PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMRARE_H
#define PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEMRARE_H

#include "types.h"
#include "pso/object/container/TOContainerAncientItem.h"

struct QuestObjectEntry;

struct TOContainerAncientItemRare : public TOContainerAncientItem {
    TOContainerAncientItemRare(ObjectSetData *set_data);
    virtual ~TOContainerAncientItemRare();
    virtual void apply_saved_state(QuestObjectEntry *, s32);
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TOContainerAncientItemRare_size, sizeof(TOContainerAncientItemRare) == 0x368);


#endif
