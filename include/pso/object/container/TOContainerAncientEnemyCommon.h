#ifndef PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTENEMYCOMMON_H
#define PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTENEMYCOMMON_H

#include "types.h"
#include "pso/object/container/TOContainerAncientEnemy.h"

struct TOContainerAncientEnemyCommon : public TOContainerAncientEnemy {
    TOContainerAncientEnemyCommon(void *set_data);
    virtual ~TOContainerAncientEnemyCommon();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOContainerAncientEnemyCommon_size, sizeof(TOContainerAncientEnemyCommon) == 0x368);
#endif
