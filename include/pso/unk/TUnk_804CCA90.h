#ifndef PSO_UNK_TUNK_804CCA90_H
#define PSO_UNK_TUNK_804CCA90_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804CCA90 : public TObject {
public:
    virtual ~TUnk_804CCA90();
    virtual void run_task();
    u8 unk_1C[0x2];
    s16 m_1e;
    u8 unk_20[0x10];
};
typedef char TUnk_804CCA90_size[sizeof(TUnk_804CCA90) == 0x30 ? 1 : -1];

#endif
