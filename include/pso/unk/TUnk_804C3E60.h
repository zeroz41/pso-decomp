#ifndef PSO_UNK_TUNK_804C3E60_H
#define PSO_UNK_TUNK_804C3E60_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804C3E60 : public TObject {
public:
    virtual ~TUnk_804C3E60();
    virtual void run_task();
    u8 unk_1C[0x8];
};
typedef char TUnk_804C3E60_size[sizeof(TUnk_804C3E60) == 0x24 ? 1 : -1];

#endif
