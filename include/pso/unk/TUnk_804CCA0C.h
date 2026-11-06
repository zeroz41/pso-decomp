#ifndef PSO_UNK_TUNK_804CCA0C_H
#define PSO_UNK_TUNK_804CCA0C_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804CCA0C : public TObject {
public:
    virtual ~TUnk_804CCA0C();
    virtual void run_task();
    u8 unk_1C[0xC];
    void * m_28;
    u8 unk_2C[0x18];
};
typedef char TUnk_804CCA0C_size[sizeof(TUnk_804CCA0C) == 0x44 ? 1 : -1];

#endif
