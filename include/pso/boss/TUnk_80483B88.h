#ifndef PSO_BOSS_TUNK_80483B88_H
#define PSO_BOSS_TUNK_80483B88_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_80483B88 : public TObject {
public:
    TUnk_80483B88();
    virtual ~TUnk_80483B88();
    virtual void run_task();
};

LAYOUT_ASSERT(TUnk_80483B88_size, sizeof(TUnk_80483B88) == 0x1C);

#endif
