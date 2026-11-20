#ifndef PSO_ITEM_DROP_TITEMDROPSUB_H
#define PSO_ITEM_DROP_TITEMDROPSUB_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TItemDropSub : public TObject {
public:
    u32 m_1c;
    TItemDropSub(TObject *parent);
    virtual ~TItemDropSub();
public:
    static void create_instance(s32 arg0);
};

#endif
