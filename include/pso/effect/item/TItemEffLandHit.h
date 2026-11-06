#ifndef PSO_EFFECT_ITEM_TITEMEFFLANDHIT_H
#define PSO_EFFECT_ITEM_TITEMEFFLANDHIT_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TItemEffLandHit : public TObject {
public:
 u8 _pad1C[0x38 - 0x1C];
 s32 m_38;

public:
    virtual ~TItemEffLandHit();
    virtual void run_task();
};

#endif
