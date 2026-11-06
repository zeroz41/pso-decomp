#ifndef PSO_PLAYER_TPLYITEM_H
#define PSO_PLAYER_TPLYITEM_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TPlyItem : public TObject {
public:
    virtual ~TPlyItem();
};

extern "C" {
void *TPlyItem__ct(void *ply_item);
}

#endif
