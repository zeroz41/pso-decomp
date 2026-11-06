#ifndef PSO_UNK_TUNK_80499988_H
#define PSO_UNK_TUNK_80499988_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_80499988 : public TObject {
public:
    virtual ~TUnk_80499988();
    virtual void run_task();
    s32 sub_800F8250(f32);
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0xC];
};
typedef char TUnk_80499988_size[sizeof(TUnk_80499988) == 0x30 ? 1 : -1];

#endif
