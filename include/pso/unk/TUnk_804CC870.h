#ifndef PSO_UNK_TUNK_804CC870_H
#define PSO_UNK_TUNK_804CC870_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804CC870 : public TObject {
public:
    virtual ~TUnk_804CC870();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x1C];
    f32 m_38;
    u8 unk_3C[0xC];
    s32 m_48;
    u8 unk_4C[0x4];
};
typedef char TUnk_804CC870_size[sizeof(TUnk_804CC870) == 0x50 ? 1 : -1];

#endif
