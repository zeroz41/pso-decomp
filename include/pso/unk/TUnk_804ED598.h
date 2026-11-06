#ifndef PSO_UNK_TUNK_804ED598_H
#define PSO_UNK_TUNK_804ED598_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804ED598 : public TObject {
public:
    virtual ~TUnk_804ED598();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
    f32 m_20;
    u8 unk_24[0xC];
    s8 m_30;
    u8 unk_31[0x3];
    s32 m_34;
    u8 unk_38[0x4];
    s32 m_3c;
    u8 unk_40[0x4];
};
typedef char TUnk_804ED598_size[sizeof(TUnk_804ED598) == 0x44 ? 1 : -1];

#endif
