#ifndef PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTENEMYRARE_H
#define PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTENEMYRARE_H

#include "types.h"
#include "pso/object/container/TOContainerAncientEnemy.h"

struct TOContainerAncientEnemyRare : public TOContainerAncientEnemy {
    TOContainerAncientEnemyRare(void *set_data);
    virtual ~TOContainerAncientEnemyRare();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOContainerAncientEnemyRare_size, sizeof(TOContainerAncientEnemyRare) == 0x368);


// --- C functions defined in TOContainerAncientEnemyRare.cpp ---
// --- end of C functions

#endif
