#ifndef PSO_OBJECT_TUNK_804AF7B0_H
#define PSO_OBJECT_TUNK_804AF7B0_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804AF7B0 : public TObject {
public:
    virtual ~TUnk_804AF7B0();
    virtual void run_task();
    u8 unk_1C[0x10];
};
typedef char TUnk_804AF7B0_size[sizeof(TUnk_804AF7B0) == 0x2C ? 1 : -1];

#endif
