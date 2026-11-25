#ifndef PSO_OBJECT_TACTORLIGHTTABLE_H
#define PSO_OBJECT_TACTORLIGHTTABLE_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TActorLightTable : public TObject {
public:
    TActorLightTable(TObject *parent);
    virtual ~TActorLightTable();
    virtual void run_task();
};
LAYOUT_ASSERT(TActorLightTable_size, sizeof(TActorLightTable) == 0x1C);

#endif
