#ifndef PSO_UNK_TUNK_80488AD8_H
#define PSO_UNK_TUNK_80488AD8_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_80488AD8 : public TObject {
public:
    virtual ~TUnk_80488AD8();
    virtual void run_task();
    u8 unk_1C[0x18];
    s32 m_34;
};
typedef char TUnk_80488AD8_size[sizeof(TUnk_80488AD8) == 0x38 ? 1 : -1];

#endif
