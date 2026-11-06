#ifndef PSO_UNK_TUNK_804EEF64_H
#define PSO_UNK_TUNK_804EEF64_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804EEF64 : public TObject {
public:
    virtual ~TUnk_804EEF64();
    virtual void run_task();
    virtual void render();
    u8 *construct_title_scene();
    void *destroy(s16);
    void sub_8033645C();
    u8 unk_1C[0x4];
    void * m_20;
    u8 unk_24[0x4];
    s32 m_28;
    u8 unk_2C[0x4];
    s32 m_30;
    u8 unk_34[0x4];
    s32 m_38;
    u8 unk_3C[0x4];
    s32 m_40;
    u8 unk_44[0x4];
    s32 m_48;
};
typedef char TUnk_804EEF64_size[sizeof(TUnk_804EEF64) == 0x4C ? 1 : -1];

#endif
