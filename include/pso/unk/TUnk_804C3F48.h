#ifndef PSO_UNK_TUNK_804C3F48_H
#define PSO_UNK_TUNK_804C3F48_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804C3F48 : public TObject {
public:
    virtual ~TUnk_804C3F48();
    virtual void run_task();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x4];
};
typedef char TUnk_804C3F48_size[sizeof(TUnk_804C3F48) == 0x28 ? 1 : -1];

#endif
