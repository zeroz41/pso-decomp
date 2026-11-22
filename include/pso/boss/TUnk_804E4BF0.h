#ifndef PSO_BOSS_TUNK_804E4BF0_H
#define PSO_BOSS_TUNK_804E4BF0_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804E4BF0 : public TObject {
public:
    TUnk_804E4BF0(TObject *object, void *arg1p);
    virtual ~TUnk_804E4BF0();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x40];
};
LAYOUT_ASSERT(TUnk_804E4BF0_size, sizeof(TUnk_804E4BF0) == 0x5C);

#endif
