#ifndef PSO_UNK_TUNK_80488AF0_H
#define PSO_UNK_TUNK_80488AF0_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_80488AF0 : public TObject {
public:
    virtual ~TUnk_80488AF0();
    virtual void run_task();
    u8 unk_1C[0x24];
};
typedef char TUnk_80488AF0_size[sizeof(TUnk_80488AF0) == 0x40 ? 1 : -1];

#endif
