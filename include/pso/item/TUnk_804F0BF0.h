#ifndef PSO_ITEM_TUNK_804F0BF0_H
#define PSO_ITEM_TUNK_804F0BF0_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F0BF0 : public TObject {
public:
    virtual ~TUnk_804F0BF0();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
    u8 * m_20;
    u8 unk_24[0x4];
    f32 m_28;
    u8 unk_2C[0x4];
    f32 m_30;
    u8 unk_34[0x4];
    void * m_38;
    u8 unk_3C[0x4];
    s32 m_40;
    u8 unk_44[0x4];
    f32 m_48;
    u8 unk_4C[0x4];
    f32 m_50;
    u8 unk_54[0x4];
    s32 m_58;
    u8 unk_5C[0xC];
};
typedef char TUnk_804F0BF0_size[sizeof(TUnk_804F0BF0) == 0x68 ? 1 : -1];

#endif
