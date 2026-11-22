#ifndef PSO_UNK_TUNK_804EE470_H
#define PSO_UNK_TUNK_804EE470_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804EE470 : public TObject {
public:
    TUnk_804EE470(TObject *parent);
    virtual ~TUnk_804EE470();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
};
LAYOUT_ASSERT(TUnk_804EE470_size, sizeof(TUnk_804EE470) == 0x20);

#endif
