#ifndef PSO_SYSTEM_SAVE_TCHECKMEMORYCARD_H
#define PSO_SYSTEM_SAVE_TCHECKMEMORYCARD_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TCheckMemoryCard : public TObject {
    TCheckMemoryCard(TObject *arg1, void *arg2, void *arg3, void *arg4);
    virtual ~TCheckMemoryCard();
    s32 sub_8033BB14();
    u32 m_1c;
    u32 m_20;
    u8 _pad24[0x4];
    u32 m_28;
    u8 unk_2C[0x4];
    void * m_30;
    u8 unk_34[0x4];
    u32 m_38;
    u32 m_3c;
    u8 _pad40[0x8];
    u32 m_48;
    u32 m_4c;
    virtual void render();
    virtual void run_task();
    void *create(void *arg1, void *arg2);
    u8 unk_50[0x200];
};

typedef char TCheckMemoryCard_size[sizeof(TCheckMemoryCard) == 0x250 ? 1 : -1];

extern "C" {
void *__dt__16TCheckMemoryCardFv(void *arg0, s16 arg1);
}

#endif
