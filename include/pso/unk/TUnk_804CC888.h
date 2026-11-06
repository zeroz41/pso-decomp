#ifndef PSO_UNK_TUNK_804CC888_H
#define PSO_UNK_TUNK_804CC888_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804CC888 : public TObject {
public:
    TUnk_804CC888(u8 *src, s32 level, TObject *parent);
    virtual ~TUnk_804CC888();
    virtual void run_task();
    u8 unk_1C[0x20];
};
typedef char TUnk_804CC888_size[sizeof(TUnk_804CC888) == 0x3C ? 1 : -1];

#endif
