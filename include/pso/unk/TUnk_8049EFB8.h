#ifndef PSO_UNK_TUNK_8049EFB8_H
#define PSO_UNK_TUNK_8049EFB8_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_8049EFB8 : public TObject {
public:
    virtual ~TUnk_8049EFB8();
    virtual void run_task();
    u8 unk_1C[0x4];
    u16 m_20;
    u8 unk_22[0x2];
};
typedef char TUnk_8049EFB8_size[sizeof(TUnk_8049EFB8) == 0x24 ? 1 : -1];

#endif
