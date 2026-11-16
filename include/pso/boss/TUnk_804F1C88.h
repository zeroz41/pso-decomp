#ifndef PSO_BOSS_TUNK_804F1C88_H
#define PSO_BOSS_TUNK_804F1C88_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F1C88 : public TObject {
public:
    virtual ~TUnk_804F1C88();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
    s32 m_20; // 0x20
    u8 unk_24[0x10];
    f32 m_34; // 0x34
    u8 unk_38[0x4];
    f32 m_3c; // 0x3C
    u8 unk_40[0x4];
    f32 m_44; // 0x44
    u8 unk_48[0x4];
    s32 m_4c; // 0x4C
    u8 unk_50[0x4];
    f32 m_54; // 0x54
    u8 unk_58[0x4];
    f32 m_5c; // 0x5C
};
typedef char TUnk_804F1C88_size[sizeof(TUnk_804F1C88) == 0x60 ? 1 : -1];

#endif
