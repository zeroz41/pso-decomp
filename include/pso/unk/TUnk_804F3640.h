#ifndef PSO_UNK_TUNK_804F3640_H
#define PSO_UNK_TUNK_804F3640_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F3640 : public TObject {
public:
    virtual ~TUnk_804F3640();
    virtual void run_task();
    u8 unk_1C[0x14];
};
LAYOUT_ASSERT(TUnk_804F3640_size, sizeof(TUnk_804F3640) == 0x30);

#endif
